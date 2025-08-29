#include <stdio.h>

int main(void){
    /* 
    ! short

        Typically 2 bytes (16 bits) on most systems.
        Range: -32768 to 32767 (signed), 0 to 65535 (unsigned).
        BUT — when used in arithmetic, short (and even char) get promoted to int before the operation.
        This is called integer promotion.
        it also owerflow and wraps arround like modulo
        ?⚡ This happens because signed integers in C use two’s complement representation.
        ?Adding 1 to the max value flips it around to the min.
        ?Modulo arithmetic on the bit pattern, just like you said.
    */

    short s1 = 30000;
    short s2 = 30000;

    short s3 = s1+s2;

    printf("%d\n",s3);

    /* 
    !🔹 long %ld and long long %lld (preview)

        long: usually 4 bytes on Windows, 8 bytes on Linux (depends on system).
        long long: guaranteed at least 8 bytes.
        Both can still overflow, just at larger ranges.
    */

    long long big = 9223372036854775807; // Max signed 64-bit
    printf("%lld\n",big); 

    big+=1; // Adding 1 to the max value flips it around to the min.

    printf("%lld\n",big);

    /* 
    ! unsigned long %lu and unsigned long long %llu (u=unsigned) and suffix of ull for llu and ul for lu
    range = 0 - 18446744073709551615ULL // max value of 64-bit unsigned 
    */

    unsigned long long x = 18446744073709551615ULL;  // max value of 64-bit unsigned
    printf("%llu\n", x);

    x = x + 1; // modulo arithmatic or two's complement makes it to 0
    printf("%llu\n", x);

    return 0;
}