#include<stdio.h>
#include<string.h>
#include"decode.h"
#include"encode.h"
#include"types.h"
#include"common.h"

Status open_decode_files(Decodeinfo *info){
    info->fptr_stego_image = fopen(info->stego_image_fname, READ_MODE);
    if(info->fptr_stego_image == NULL){
        return STG_Failure;
    }
    info->fptr_secret = fopen(info->secret_fname, WRITE_MODE);
    if(info->fptr_secret == NULL){
        fclose(info->fptr_stego_image);
        return STG_Failure;
    }
    return STG_Success;
}

Status decode_byte_from_lsb(char *data, Decodeinfo *info){
    unsigned char image_byte;
    unsigned char secret_byte = 0;
    int i;
    for(i = 7; i >= 0; i--){
        if(fread(&image_byte, 1, 1, info->fptr_stego_image) != 1){
            return STG_Failure;
        }
        secret_byte = secret_byte | ((image_byte & 1) << i);
    }
    *data = secret_byte;
    return STG_Success;
}

Status decode_magic_string(Decodeinfo *info){
    char decoded_char;
    char magic_string[20];
    int i;
    for(i = 0; MAGIC_STRING[i] != '\0'; i++){
        if(decode_byte_from_lsb(&decoded_char, info) == STG_Failure){
            return STG_Failure;
        }
        magic_string[i] = decoded_char;
    }
    magic_string[i] = '\0';
    if(strcmp(magic_string, MAGIC_STRING) == 0){
        return STG_Success;
    }
    return STG_Failure;
}

Status decode_secret_file_extn_size(Decodeinfo *info){
    unsigned char image_byte;
    unsigned int extn_size = 0;
    int i;
    for(i = 31; i >= 0; i--){
        if(fread(&image_byte, 1, 1,info->fptr_stego_image) != 1){
            return STG_Failure;
        }
        extn_size = extn_size | ((image_byte & 1) << i);
    }
    info->extn_size = extn_size;
    return STG_Success;
}

Status decode_secret_file_extn(Decodeinfo *info){
    char data;
    unsigned int i;
    for(i = 0; i < info->extn_size; i++){
        if(decode_byte_from_lsb(&data, info) == STG_Failure){
            return STG_Failure;
        }
        info->secret_file_extn[i] = data;
    }
    info->secret_file_extn[i] = '\0';
    return STG_Success;
}

Status decode_secret_file_size(Decodeinfo *info){
    unsigned char image_byte;
    unsigned int secret_file_size = 0;
    int i;
    for(i = 31; i >= 0; i--){
        if(fread(&image_byte, 1, 1,info->fptr_stego_image) != 1){
            return STG_Failure;
        }
        secret_file_size = secret_file_size |((image_byte & 1) << i);
    }
    info->secret_file_size = secret_file_size;
    return STG_Success;
}

Status decode_secret_file_data(Decodeinfo *info){
    char data;
    unsigned int i;
    for(i = 0; i < info->secret_file_size; i++){
        if(decode_byte_from_lsb(&data, info) == STG_Failure){
            return STG_Failure;
        }
        fwrite(&data, 1, 1, info->fptr_secret);
    }

    return STG_Success;
}