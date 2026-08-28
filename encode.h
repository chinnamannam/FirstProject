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

    unsigned int image_capacity;
    //unsigned int bits_per_pixel;

    unsigned int secret_file_size;
    char secret_file_extn[MAX_FILE_SUFFIX];

}Encodeinfo;

Type Check_Operation_Type(char *argv);

Status open_encode_files(Encodeinfo *info);

Status check_bmp_header(Encodeinfo *info);

Status get_image_capacity(Encodeinfo *info);

Status get_secret_file_size(Encodeinfo *info);

Status get_secret_file_extension(Encodeinfo *info);

Status check_bmp_capacity(Encodeinfo *info);

Status copy_bmp_header(Encodeinfo *info);

Status encode_magic_string(const char *magic_string, Encodeinfo *info);

Status encode_byte_to_lsb(char data, Encodeinfo *info);

Status encode_int_to_lsb(unsigned int data, Encodeinfo *info);

Status encode_int_to_lsb(unsigned int data, Encodeinfo *info);

Status encode_secret_file_extn_size(Encodeinfo *info);

Status encode_secret_file_extn(Encodeinfo *info);

Status encode_secret_file_size(Encodeinfo *info);

Status encode_secret_file_data(Encodeinfo *info);

Status copy_remaining_bmp_data(Encodeinfo *info);
#endif