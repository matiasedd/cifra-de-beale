#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <time.h>

#include "lib_beale.h"

int main(int argc, char *argv[])
{
    int opt, encode;
    char *book, *input, *output, *keyfile;

    srand(time(NULL));

    while ((opt = getopt(argc, argv, "eb:m:o:c:")) != -1)
    {
        switch (opt)
        {
            case 'e':
                encode = 1;
                break;
            case 'b':
                book = optarg;
                break;
            case 'm':
                input = optarg;
                break;
            case 'o':
                output = optarg;
                break;
            case 'c':
                keyfile = optarg;
                break;
            default:
                fprintf(stderr, "Uso: %s -b <LivroCifra> -m <MensagemOriginal> -o <MensagemCodificada> -c <ArquivoDeChaves>\n", argv[0]);
                exit(EXIT_FAILURE);
        }
    }

    if (encode)
        encode_message(book, input, output, keyfile);
        
    return EXIT_SUCCESS;
}
