#include<stdio.h>
#include<string.h>
#include"encode.h"
#include"types.h"


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

Status file_open(Encodeinfo *info){
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