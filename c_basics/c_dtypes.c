#include <stdio.h>

int main(void){
    // * in C int is usually 4 bytes (32 bits) signed (both positive and negative)
    int neg_int = -2147483648; // if added more means it will wrap around and give the nearest even number
    int pos_int = 2147483647;
    return 0;
}