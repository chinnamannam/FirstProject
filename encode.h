#ifndef ENCODE_H
#define ENCODE_H
#include<stdio.h>
#include"types.h"

typedef struct Encoding_Info{
    // Source image
    char *src_image_fname;
    FILE *fptr_src_image;
    // secret Txt
    char *secret_fname;
    FILE *fptr_secret;
    // Stego image
    char *stego_image_fname;
    FILE *fptr_stego_image;
}Encodeinfo;

Type Check_Operation_Type(char *argv);

Status file_open(Encodeinfo *info);

#endif