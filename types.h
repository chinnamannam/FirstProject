#ifndef TYPES_H
#define TYPES_H

#define READ_MODE "rb"
#define WRITE_MODE "wb"
#define MAX_FILE_SUFFIX 10

typedef enum{
    STG_Encode,
    STG_Decode,
    STG_UnSupported
} Type;

typedef enum{
    STG_Success,
    STG_Failure
}Status;

#endif