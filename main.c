#include<stdio.h>
#include"types.h"
#include"encode.h"
#include"decode.h"
#include"common.h"

int main(int argc, char **argv){
    Type Operation;
    if(argc < 2)
    {
        printf("Usage:\n");
        printf("Encoding: ./a.out -e source.bmp secret.txt stego.bmp\n");
        printf("Decoding: ./a.out -d stego.bmp decoded.txt\n");
        return 1;
    }
    Operation = Check_Operation_Type(argv[1]);

    if(Operation == STG_Encode){
         if(argc != 5){
            printf("Usage: ./a.out -e source.bmp secret.txt stego.bmp\n");
            return 1;
         }
         Encodeinfo encode_info;
         printf("*******************Start Encoding.********************\n");
         encode_info.src_image_fname = argv[2];
         encode_info.secret_fname = argv[3];
         encode_info.stego_image_fname = argv[4];
         if(open_encode_files(&encode_info) == STG_Failure){
            printf("Failed to open the files.\n");
            return 1;
         }
         else{
            printf("Files opened Successfully.\n");
         }
         if(check_bmp_header(&encode_info) == STG_Failure){
            printf("Invalid BMP File.\n");
            return 1;
         }
         else{
            printf("Valid BMP FIle.\n");
         }
         if(get_image_capacity(&encode_info) == STG_Failure){
             printf("Failed to get image capacity.\n");
            return 1;
         }
         else{
            printf("Image Capacity = %u bytes\n", encode_info.image_capacity);
         }
         if(get_secret_file_size(&encode_info) == STG_Failure){
            printf("Failed to get secret file size.\n");
            return 1;
         }
         if(get_secret_file_extension(&encode_info) == STG_Failure){
            printf("Failed to get secret file extension.\n");
            return 1;
         }
         else{
            printf("Secret File Extension : %s\n",
           encode_info.secret_file_extn);
         }
         if (check_bmp_capacity(&encode_info) == STG_Failure) {
            printf("Error: Source image capacity insufficient for steganography.\n");
            return 1;
        }
        printf("BMP Capacity Verification Passed.\n");
        if(copy_bmp_header(&encode_info) == STG_Failure){
            printf("Failed to copy BMP header.\n");
            return 1;
         }
         else{
          printf("BMP Header copied successfully.\n");
         }
         if(encode_magic_string(MAGIC_STRING, &encode_info) == STG_Failure){
            printf("Failed to encode magic string.\n");
            return 1;
         }
         else{
            printf("Magic String encoded successfully.\n");
         }
         if(encode_secret_file_extn_size(&encode_info) == STG_Failure){
            printf("Failed to encode secret file extension size.\n");
            return 1;
         }
         else{
            printf("Secret File Extension Size encoded successfully.\n");
         }
         if(encode_secret_file_extn(&encode_info) == STG_Failure){
            printf("Failed to encode secret file extension.\n");
            return 1;
         }
         else{
            printf("Secret File Extension encoded successfully.\n");
         }
         if(encode_secret_file_size(&encode_info) == STG_Failure){
            printf("Failed to encode secret file size.\n");
            return 1;
         }
         else{
            printf("Secret File Size encoded successfully.\n");
         }
         if(encode_secret_file_data(&encode_info) == STG_Failure){
            printf("Failed to encode secret file data.\n");
            return 1;
         }
         else{
            printf("Secret File Data encoded successfully.\n");
         }
         if(copy_remaining_bmp_data(&encode_info) == STG_Failure){
         printf("Failed to copy remaining BMP data.\n");
         return 1;
         }
         else{
            printf("Remaining BMP data copied successfully.\n");
         }
         fclose(encode_info.fptr_src_image);
         fclose(encode_info.fptr_secret);
         fclose(encode_info.fptr_stego_image);
         printf("*********Encoding completed successfully.***************\n");
         
}
else if(Operation == STG_Decode){
      if(argc != 4){
        printf("Usage: ./a.out -d stego.bmp decoded.txt\n");
        return 1;
      }
      Decodeinfo decode_info;

      printf("************Start Decoding.*********************\n");

        decode_info.stego_image_fname = argv[2];
        decode_info.secret_fname = argv[3];

      if(open_decode_files(&decode_info) == STG_Failure){
         printf("Failed to open stego image.\n");
         return 1;
      }
      else{
         printf("Stego image opened successfully.\n");
      }

      fseek(decode_info.fptr_stego_image, 54, SEEK_SET);
      char data;
      if(decode_byte_from_lsb(&data, &decode_info) == STG_Failure){
         printf("Failed to decode byte.\n");
         fclose(decode_info.fptr_stego_image);
         return 1;
      }
      printf("Decoded character = %c\n", data);

      /* Reset position before decoding complete magic string */
      fseek(decode_info.fptr_stego_image, 54, SEEK_SET);

      if(decode_magic_string(&decode_info) == STG_Failure){
         printf("Invalid Magic String.\n");
         fclose(decode_info.fptr_stego_image);
         return 1;
      }
      else{
         printf("Magic String decoded successfully.\n");
      }
      if(decode_secret_file_extn_size(&decode_info) == STG_Failure){
         printf("Failed to decode secret file extension size.\n");
         fclose(decode_info.fptr_stego_image);
         return 1;
      }
      else{
         printf("Secret File Extension Size : %u\n",
               decode_info.extn_size);
      }
      if(decode_secret_file_extn(&decode_info) == STG_Failure){
         printf("Failed to decode secret file extension.\n");
         fclose(decode_info.fptr_stego_image);
         return 1;
      }
      else{
         printf("Secret File Extension : %s\n",
               decode_info.secret_file_extn);
      }

      if(decode_secret_file_size(&decode_info) == STG_Failure){
         printf("Failed to decode secret file size.\n");
         fclose(decode_info.fptr_stego_image);
         return 1;
      }
      else{
         printf("Secret File Size : %u bytes\n",decode_info.secret_file_size);
      }

      if(decode_secret_file_data(&decode_info) == STG_Failure){
        printf("Failed to decode secret file data.\n");
        fclose(decode_info.fptr_stego_image);
        fclose(decode_info.fptr_secret);
        return 1;
       }
       else{
         printf("Secret File Data decoded successfully.\n");
       }
        

      fclose(decode_info.fptr_stego_image);
      fclose(decode_info.fptr_secret);
      printf("************Decoding completed successfully.*************\n");
}
else{
        printf("Invalid Argument.\n");
        printf("For Encoding use ./a.out -e .bmp .txt .bmp\n");
        printf("For Decoding use ./a.out -d .bmp\n");
    }
    return 0;
}

