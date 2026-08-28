#include<stdio.h>
#include<string.h>
#include"encode.h"
#include"types.h"
#include"common.h"


Type Check_Operation_Type(char *argv){

    if(strcmp(argv,"-e") == 0){
        return STG_Encode;
    }
    else if((strcmp(argv,"-d") == 0)){
        return STG_Decode;
    }
    else{
        return STG_UnSupported;
    }

}

Status open_encode_files(Encodeinfo *info){
    // Opening Source image
    info->fptr_src_image = fopen(info->src_image_fname,READ_MODE);
    if(info->fptr_src_image == NULL){
        return STG_Failure;
    }
    // Opening Secret.txt file
    info->fptr_secret = fopen(info->secret_fname,READ_MODE);
    if(info->fptr_secret == NULL){
        return STG_Failure;
    }
    // Opening Stegoimage
    info->fptr_stego_image = fopen(info->stego_image_fname,WRITE_MODE);
    if(info->fptr_stego_image == NULL){
        return STG_Failure;
    }
    return STG_Success;
}

Status check_bmp_header(Encodeinfo *info){
    char header[2];
    fread(header,1,2,info->fptr_src_image);
    if((header[0] == 'B') && (header[1] == 'M')){
        return STG_Success;
    }
    else{
        return STG_Failure;
    }

}

Status get_image_capacity(Encodeinfo *info){
    unsigned int width;
    unsigned int height;
    fseek(info->fptr_src_image,18,SEEK_SET);

    fread(&width,sizeof(unsigned int),1,info->fptr_src_image);

    fread(&height,sizeof(unsigned int),1,info->fptr_src_image);

   // info->image_capacity = width * height * (info->bits_per_pixel / 8);

     info->image_capacity = width * height * 3;
     return STG_Success;
}

Status get_secret_file_size(Encodeinfo *info){
    long current_position;
    long end_position;

    current_position = ftell(info->fptr_secret);
    fseek(info->fptr_secret, 0, SEEK_END);
    end_position = ftell(info->fptr_secret);
    info->secret_file_size = end_position;
    fseek(info->fptr_secret, current_position, SEEK_SET);

    printf("Secret File Size : %u bytes\n",
           info->secret_file_size);

    return STG_Success;
}

Status get_secret_file_extension(Encodeinfo *info)
{
    char *dot;

    /* Find the last '.' in the secret file name */
    dot = strrchr(info->secret_fname, '.');

    /* Check whether extension exists */
    if(dot == NULL)
    {
        return STG_Failure;
    }

    /* Copy extension into structure */
    strcpy(info->secret_file_extn, dot);

    return STG_Success;
}

Status check_bmp_capacity(Encodeinfo *info) {
    unsigned int extn_len;
    unsigned int total_bytes_needed;
    extn_len = strlen(info->secret_file_extn);
    total_bytes_needed = (strlen(MAGIC_STRING) + 4 + extn_len + 4 + info->secret_file_size) * 8;

    if (info->image_capacity >= total_bytes_needed) {
        return STG_Success;
    } else {
        return STG_Failure;
    }
}

Status copy_bmp_header(Encodeinfo *info)
{
    char header[54];
    rewind(info->fptr_src_image);
    if(fread(header, 1, 54, info->fptr_src_image) != 54){
        return STG_Failure;
    }
    if(fwrite(header, 1, 54, info->fptr_stego_image) != 54){
        return STG_Failure;
    }
    return STG_Success;
}

Status encode_byte_to_lsb(char data, Encodeinfo *info)
{
    unsigned char image_buffer;
    int i;

    for(i = 7; i >= 0; i--){
        /* Read one byte from image */
        if(fread(&image_buffer, 1, 1,info->fptr_src_image) != 1){
            return STG_Failure;
        }
        /* Clear the LSB */
        image_buffer = image_buffer & 0xFE;

        /* Put one bit of secret data into LSB */
        image_buffer = image_buffer |((data >> i) & 1);

        /* Write modified byte into stego image */
        if(fwrite(&image_buffer, 1, 1,info->fptr_stego_image) != 1){
            return STG_Failure;
        }
    }
    return STG_Success;
}

Status encode_magic_string(const char *magic_string, Encodeinfo *info)
{
    int i;
    for(i = 0; magic_string[i] != '\0'; i++){
        if(encode_byte_to_lsb(magic_string[i], info)
           == STG_Failure){
            return STG_Failure;
        }
    }
    return STG_Success;
}

Status encode_int_to_lsb(unsigned int data, Encodeinfo *info)
{
    unsigned char image_byte;
    int i;
    for(i = 31; i >= 0; i--){
        /* Read one byte from source image */
        if(fread(&image_byte, 1, 1, info->fptr_src_image) != 1){
            return STG_Failure;
        }
        /* Clear LSB */
        image_byte = image_byte & 0xFE;
        /* Put secret bit into LSB */
        image_byte = image_byte | ((data >> i) & 1);
        /* Write modified byte to stego image */
        if(fwrite(&image_byte, 1, 1, info->fptr_stego_image) != 1){
            return STG_Failure;
        }
    }

    return STG_Success;
}

Status encode_secret_file_extn_size(Encodeinfo *info)
{
    unsigned int extn_size;
    extn_size = strlen(info->secret_file_extn);
    if(encode_int_to_lsb(extn_size, info) == STG_Failure){
        return STG_Failure;
    }
    return STG_Success;
}

Status encode_secret_file_extn(Encodeinfo *info)
{
    int i;
    for(i = 0; info->secret_file_extn[i] != '\0'; i++){
        if(encode_byte_to_lsb(info->secret_file_extn[i], info)
           == STG_Failure){
            return STG_Failure;
        }
    }

    return STG_Success;
}

Status encode_secret_file_size(Encodeinfo *info)
{
    if(encode_int_to_lsb(info->secret_file_size, info)
       == STG_Failure){
        return STG_Failure;
    }
    return STG_Success;
}

Status encode_secret_file_data(Encodeinfo *info)
{
    unsigned char ch;
    unsigned int i;

    for(i = 0; i < info->secret_file_size; i++)
    {
        if(fread(&ch, 1, 1, info->fptr_secret) != 1)
        {
            return STG_Failure;
        }

        if(encode_byte_to_lsb(ch, info) == STG_Failure)
        {
            return STG_Failure;
        }
    }

    return STG_Success;
}

Status copy_remaining_bmp_data(Encodeinfo *info)
{
    unsigned char image_byte;

    while(fread(&image_byte, 1, 1, info->fptr_src_image) == 1)
    {
        if(fwrite(&image_byte, 1, 1, info->fptr_stego_image) != 1)
        {
            return STG_Failure;
        }
    }

    return STG_Success;
}
