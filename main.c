/*
NAME: VINAY K
DATE: 11-11-2024
DESCRIPTION: LSB (Least Significant Bit) steganography is a technique for hiding secret information in digital media,
 such as images or audio, by altering the least significant bits of the data, which causes minimal perceptible changes to the file.
*/

#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "decode.h"
#include "decode.h"
#include "types.h"

int main(int argc, char *argv[])
{
      EncodeInfo encInfo;                              // Structs for encoding information
      DecodeInfo decInfo;                                  // Structs for decoding information
    if (argc > 1)                                 // Check if command line arguments greater than 1 
    {                                                       
        if (check_operation_type(argv[1]) == e_encode)         //check first argument is encode or not
        {
            if (read_and_validate_encode_args(argc, argv, &encInfo) == e_failure)        // Validate encoding arguments
            { 
                return e_failure;
            }
            do_encoding(&encInfo);                      //check first argument is decode or not
        }
        else if (check_operation_type(argv[1]) == e_decode)
        {
            if (read_and_validate_decode_args(argc, argv, &decInfo) == e_failure)                // Validate decoding arguments
            {
                return e_failure;
            }
            do_decoding(&decInfo);                                              // Perform the decoding operation
        }
        else
        {
            printf("Invalid input\n");
        }
    }
    else
    {
        printf("Encoding: ./lsb_steg -e <.bmp file> <.txt file> [output file]\n");
        printf("Decoding: ./lsb_steg -d <.bmp file> [output file]\n");
    }

    return 0;
}
OperationType check_operation_type(char *argv)           //Function: check_operation_type
{
    
    if (strcmp(argv, "-e") == 0)                          // Compare the input argument encode or not
    {
        return e_encode;                                  // Return  encoding operation
    }
    else if (strcmp(argv, "-d") == 0)                      // Compare the input argument decode or not
    {
        return e_decode;                                   // Return  decoding operation
    }
    else
    {
        return e_unsupported;                               // Return  invalid input
    }
}
