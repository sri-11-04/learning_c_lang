#include <stdio.h>

int main(void){
    // ! in C int is usually 4 bytes (32 bits) signed (both positive and negative)
    int neg_int = -2147483648; // if added more means it will wrap around and give the nearest even number
    int pos_int = 2147483647;

    // ! int quirk
    int int_quirk = pos_int+1; // as the pos_int is the INT_MAX adding numbers will make it circular to controll the overflow meaning now it will become INT_MIN
    printf("%d\n",int_quirk);
    printf("%d\n",pos_int+2); // as it was circular it will try to add from the INT_MIN

    // ! unsigned (0 and positive only values 2^32) to print it we use a placeholder like %u 
    unsigned int max_unsigned_value = 4294967295; // ? 2147483648 (INT_MIN) + 2147483647 (INT_MAX) 0 - 4294967295
    
    // ! unsigned int quirk
    unsigned int unsigned_int_quirk = 0; 
    printf("%u\n",unsigned_int_quirk);
    unsigned_int_quirk-=1;
    printf("%u\n",unsigned_int_quirk); 
    /* comment is about the unsigned
    * That’s the magic of unsigned integers in C:
    *  They never go negative.
    *  Instead, they wrap around modulo 2^n where n = number of bits.
    *  For unsigned int (32-bit), it’s modulo 2^32.
    */

    // ! char is tiny int. it always be 1 byte (8 bits).
    /* 
    But range depends on whether your compiler treats it as signed or unsigned by default:
    signed char: -128 to 127
    unsigned char: 0 to 255
    You can do math with char just like with int.
    */

    char ch = 127;   // signed char max as most compilers makes the default as signed
    printf("%d\n", ch);  // prints 127
    ch += 1;      // now it overflows and makes a circular thing and converts to MIN_CHAR
    printf("%d\n", ch); //  prints -128 That’s because unsigned char is modulo 2^8 = 256.

    /* 
    ! Quick recap so far:
        int (32-bit signed): wraps at ±2,147,483,647
        unsigned int (32-bit): wraps modulo 2³²
        char (8-bit): can be signed (-128..127) or unsigned (0..255)
        All arithmetic is modular in C when you hit the limits!
    */


    // ! floating points
    /* 
    ! Quick facts about floats in C:
     *   float: typically 4 bytes (32 bits), ~7 decimal digits of precision.
        float (IEEE 754, 32-bit) has 24 bits of precision (~7 decimal digits).
        That means it can represent every integer exactly up to 16,777,216 (2²⁴).
        But 16777217 (2²⁴ + 1) is too big for a float to distinguish from 16777216.
        So when big is cast to float, it gets rounded to 16777216.0.
     *   double: typically 8 bytes (64 bits), ~15–16 decimal digits of precision.
         double → exact only up to 2⁵³ (~9e15)
     *   They cannot exactly represent most decimals (like 0.1) because they’re stored in binary fractions.
     *   So you’ll often see rounding errors when printing or comparing.
    */

    float x = 0.1f;   // note the 'f' makes it a float
    if (x == 0.1) {
        printf("Equal %.20f\n",0.1f);
    } else {
        printf("Not Equal %.30lf\n",0.1);
    }

    /* 
    Most programming languages use the IEEE 754 standard for floating-point arithmetic. 
    This means numbers like 0.1 are stored in binary as approximations—not exact values.
    Decimal 0.1 looks simple to us.
    But in binary, 0.1 becomes a repeating fraction: 0.00011001100110011... (and so on, infinitely).
    Since computers have limited bits to store numbers (usually 64 bits for a double), they truncate this repeating binary. That introduces a tiny rounding error.

    0.1 in C (without the f) is a double literal.
    0.1f is a float literal.
    When you compare x == 0.1, the float x gets promoted to double for the comparison.
    Now the problem:
    0.1f (float) is stored with ~7 digits of precision → it’s actually something like 0.10000000149011612.
    0.1 (double) is stored with ~16 digits of precision → it’s actually 0.10000000000000000555....
    So when promoted, they’re not exactly the same bit pattern → == fails.

    👉 In C (and most languages), you usually don’t compare floats with ==.
    Instead, you check if they’re “close enough”:

    #include <math.h>
    if (fabs(x - 0.1) < 1e-6) { ... }
    */

    double y = 0.1;
    double sum = y + y + y + y + y + y + y + y + y + y; // add 0.1 ten times
    printf("%.20f\n", sum); // ?(Exact trailing digits depend on compiler/architecture, but definitely not a clean 1.0).


    double a = 1.0/0.0;   // positive divided by zero is inf
    double b = -1.0/0.0;  // negative divided by zero is -inf
    double c = 0.0/0.0;   // zero divided by zero is undefined and known as NaN

    // NaN != NaN
    // isnan(NaN) => True

    // * 0.0 == -0.0 
    /* 
    But here’s the mind-bender:
    IEEE 754 floating-point does have +0.0 and -0.0 as distinct bit patterns.
    They compare equal with ==, but they can behave differently in some operations!
    eg: 1.0/-0.0 is -inf where 1.0/0.0 is inf
    */

    // ! Type Promotions & Conversions

    /* 
    ! Key idea:
        When you mix different data types in an expression, C follows usual arithmetic conversions (aka type promotion rules):
        Smaller types (char, short) get promoted to int before doing arithmetic.
        If one operand is float and the other is int, the int gets promoted to float.
        If one is double and the other is float, the float gets promoted to double.
        If one is long double, everything else upgrades to long double.
        So C always promotes to the “wider” type.

        When you compare a signed and an unsigned in C:
        If the unsigned type’s rank is >= the signed type’s rank (true here, both are 32-bit),
        Then the signed value gets converted to unsigned before the comparison.
        So s = -20 becomes an unsigned int.
        On a 32-bit system, that means:
    */

    // ! bool (_Bool , bool from stdbool.h has true false)
    _Bool true = 0;
    _Bool false = 100; // like in python truthy value 0 false 1 and above true or less than -1 also true

    printf("%d\n",true); // these bools will be always promoted to int
    printf("%d\n",false);

    printf("%d\n",(5<6)); // 0 or 1 only


    return 0;
}