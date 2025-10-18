#include <stdio.h>
#include <string.h>

#define FILE_NAME "./test.bin"

typedef struct Temp{
    int id;
    char name[100];
}Temp;


int main(void){
    FILE *file = fopen(FILE_NAME,"rb");
    Temp temp;
    char n[100];
    // temp.id = 1;
    // strcpy(temp.name,"sri annamalai");
    // size_t res = fwrite(&temp,sizeof(Temp),1,file);
    size_t res = fread(n,sizeof(n),1,file);
    // printf("%s\n",temp.name);
    printf(" n = %s\n",n);
    printf("res = %zu\n",res);
    fclose(file);
    return 0;
}