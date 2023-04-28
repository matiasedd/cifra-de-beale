#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>

#include "lib_beale.h"

int main(int argc, char *argv[])
{
    int opt, encode, decode_with_book;
    char *book, *input, *output, *keyfile;

    srand(time(NULL));

    while ((opt = getopt(argc, argv, "deb:m:o:c:i:")) != -1)
    {
        switch (opt)
        {
            case 'b':
                book = optarg;
                decode_with_book = YES;
                break;
            case 'c':
                keyfile = optarg;
                decode_with_book = NO;
                break;
            case 'd':
                encode = NO;
                break;
            case 'e':
                encode = YES;
                break;
            case 'm':
                input = optarg;
                break;
            case 'o':
                output = optarg;
                break;
            case 'i':
                input = optarg;
                break;
            default:
                fprintf(stderr, "Uso: %s -b <LivroCifra> -m <MensagemOriginal> -o <MensagemCodificada> -c <ArquivoDeChaves>\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (encode)
        encode_message(book, input, output, keyfile);
    else if (decode_with_book)
        decode_using_book(input, book, output);
    else
        decode_using_keyfile(input, keyfile, output);
        
    return EXIT_SUCCESS;
}
