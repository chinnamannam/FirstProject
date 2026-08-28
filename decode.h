#ifndef DECODE_H
#define DECODE_H
#include<stdio.h>
#include"types.h"


typedef struct Decoding_Info{
    
    // Stego image
    char *stego_image_fname;
    char *secret_fname;

    FILE *fptr_stego_image;
    FILE *fptr_secret;

    unsigned int extn_size;
    char secret_file_extn[20];

    unsigned int secret_file_size;

}Decodeinfo;

Status open_decode_files(Decodeinfo *info);

Status decode_byte_from_lsb(char *data, Decodeinfo *info);

Status decode_magic_string(Decodeinfo *info);

Status decode_secret_file_extn_size(Decodeinfo *info);

Status decode_secret_file_extn(Decodeinfo *info);

Status decode_secret_file_size(Decodeinfo *info);

Status decode_secret_file_data(Decodeinfo *info);
#endif