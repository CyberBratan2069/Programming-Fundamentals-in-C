/***********************************************************************************************************************
 * @author Christian Reiswich                                                                                          *
 * @created on 20 August 2025                                                                                          *
 * @info Task was generated using chatGPT                                                                              *
 **********************************************************************************************************************/

#include "tools.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define RED   "\033[0;31m"
#define GREEN "\033[0;32m"
#define WHITE "\033[0;37m"


int main(int argc, char **argv) {

    clock_t start = clock();

    if(argc != 3 || argv[2][0] != '-') {
        fprintf(stderr, "Usage: %s <file> <cin>\n", argv[0]);
        return 1;
    }

    char *filename  = argv[1];
    char *cin       = argv[2];

    char *string     = readFile(filename);
    int lines        = countLines(string);
    int words        = countWords(string);
    int chars        = countChars(string);
    int digits       = countDigits(string);
    int specialChars = countSpecialChars(string);
    int undefChars   = countUndefChars(string);

    printf(GREEN"File: %s\n"WHITE, filename);

    if(strcmp(cin, "-help") == 0) {
        printf(GREEN"_________________________________________________\n"WHITE);
        printf(GREEN"| Syntax Info:                                  |\n"WHITE);
        printf(GREEN"|_______________________________________________|\n"WHITE);
        printf(GREEN"| Counted lines        :<infile> <-lines>       |\n"WHITE);
        printf(GREEN"| Counted words        :<infile> <-words>       |\n"WHITE);
        printf(GREEN"| Counted chars        :<infile> <-chars>       |\n"WHITE);
        printf(GREEN"| Counted digits       :<infile> <-digits>      |\n"WHITE);
        printf(GREEN"| Counted special chars:<infile> <-sc>          |\n"WHITE);
        printf(GREEN"| Counted undef chars  :<infile> <-uc>          |\n"WHITE);
        printf(GREEN"| Counted all          :<infile> <-all>         |\n"WHITE);
        printf(GREEN"| Filter file          :<infile> <-filter>      |\n"WHITE);
        printf(GREEN"|_______________________________________________|\n"WHITE);
    }

    else if(strcmp(cin, "-lines")  == 0) printf(GREEN"Lines        : %i\n"WHITE, lines);
    else if(strcmp(cin, "-words")  == 0) printf(GREEN"Words        : %i\n"WHITE, words);
    else if(strcmp(cin, "-chars")  == 0) printf(GREEN"Chars        : %i\n"WHITE, chars);
    else if(strcmp(cin, "-digits") == 0) printf(GREEN"Digits       : %i\n"WHITE, digits);
    else if(strcmp(cin, "-sc")     == 0) printf(GREEN"Special chars: %i\n"WHITE, specialChars);
    else if(strcmp(cin, "-uc")     == 0) printf(GREEN"Undef chars  : %i\n"WHITE, undefChars);
    else if(strcmp(cin, "-all")    == 0) {
        printf(GREEN"Lines        : %i\n"WHITE, lines);
        printf(GREEN"Words        : %i\n"WHITE, words);
        printf(GREEN"Chars        : %i\n"WHITE, chars);
        printf(GREEN"Digits       : %i\n"WHITE, digits);
        printf(GREEN"Special chars: %i\n"WHITE, specialChars);
        printf(GREEN"Undef chars  : %i\n"WHITE, undefChars);
    }

    else if(strcmp(cin, "-filter") == 0) {
        char *outfile = malloc(100);
        char c;

        printf(GREEN"Filter file: <outfile> <c>\n : " WHITE);
        scanf("%s %c", outfile, &c);
        filterFile(string, outfile, c);
    }

    else printf(RED"ERROR: Input was Invalid!\n");

    clock_t end = clock();
    double runtime = (double)(end - start) / CLOCKS_PER_SEC;
    printf(GREEN"Run time     : %.8f s\n"WHITE, runtime);

    return 0;
}
