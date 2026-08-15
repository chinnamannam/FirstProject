#include<stdio.h>
#include"types.h"
#include"encode.h"

int main(int argc, char **argv){
    Type Operation;
    Encodeinfo info;
    if(argc < 2){
        printf("Usage: ./a.out -e/-d ...\n");
        return 1;
    }
    Operation = Check_Operation_Type(argv[1]);

    if(Operation == STG_Encode){
         printf("Start Encoding.\n");
         info.src_image_fname = argv[2];
         info.secret_fname = argv[3];
         info.stego_image_fname = argv[4];
         if(file_open(&info) == STG_Failure){
            printf("Failed to open the files.\n");
            return 1;
         }
         else{
            printf("Files opened Successfully.\n");
         }
    }
    else if(Operation == STG_Decode){
         printf("Start Decoding.\n");
    }
    else {
        printf("Invalid Argument.\n");
        printf("For Encoding use ./a.out -e .bmp .txt\n");
        printf("For Decoding use ./a.out -d .bmp\n");
    }
    return 0;
}

