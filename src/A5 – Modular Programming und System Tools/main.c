/***********************************************************************************************************************
 * @author Christian Reiswich
 * @created on 20 August 2025
 * @info Task was generated using chatGPT
 **********************************************************************************************************************/

#include "tools.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define RED   "\033[0;31m"
#define GREEN "\033[0;32m"
#define WHITE "\033[0;37m"


int main(int argc, char **argv) {

    if(argc != 3 || argv[2][0] != '-') {
        fprintf(stderr, "Usage: %s <file> <cin>\n", argv[0]);
        return 1;
    }

    char *filename  = argv[1];
    char *cin       = argv[2];

    char* string     = readFile(filename);
    int lines        = countLines(string);
    int words        = countWords(string);
    int chars        = countChars(string);
    int digits       = countDigits(string);
    int specialChars = countSpecialChars(string);
    int undefChars   = countUndefChars(string);

    printf(GREEN"File: %s\n"WHITE, filename);
    if     (strcmp(cin, "-lines")  == 0) printf(GREEN"Lines: %i\n"WHITE, lines);
    else if(strcmp(cin, "-words")  == 0) printf(GREEN"Words: %i\n"WHITE, words);
    else if(strcmp(cin, "-chars")  == 0) printf(GREEN"Chars: %i\n"WHITE, chars);
    else if(strcmp(cin, "-digits") == 0) printf(GREEN"Digits: %i\n"WHITE, digits);
    else if(strcmp(cin, "-sc")     == 0) printf(GREEN"Special chars: %i\n"WHITE, specialChars);
    else if(strcmp(cin, "-uc")     == 0) printf(GREEN"Undef chars: %i\n"WHITE, undefChars);
    else if(strcmp(cin, "-all")    == 0) {
        printf(GREEN"Lines: %i\n"WHITE, lines);
        printf(GREEN"Words: %i\n"WHITE, words);
        printf(GREEN"Chars: %i\n"WHITE, chars);
        printf(GREEN"Digits: %i\n"WHITE, digits);
        printf(GREEN"Special chars: %i\n"WHITE, specialChars);
        printf(GREEN"Undef chars: %i\n"WHITE, undefChars);
    }


    else printf(RED"ERROR: Input was Invalid!\n");



    return 0;
}
