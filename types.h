#ifndef TYPES_H
#define TYPES_H

#define READ_MODE "rb"
#define WRITE_MODE "wb"

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