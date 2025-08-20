/***********************************************************************************************************************
 * @author Christian Reiswich
 * @created on 20 August 2025
 * @info Task was generated using chatGPT
 **********************************************************************************************************************/

#include "tools.h"
#include <stdio.h>   // Standard I/O functions (printf, scanf, etc.)
#include <stdlib.h>  // General utilities (malloc, free, exit, etc.)
#include <string.h>  // String handling functions (strlen, strcpy, etc.)
#include <ctype.h>


char *readFile(char *filename) {
    FILE *file = fopen(filename, "r");
    if(!file) {
        fprintf(stderr, "ERROR: File not found!\n");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long stringLength = ftell(file);
    rewind(file);

    char* string = malloc(stringLength + 1);

    int chars;
    int i = 0;
    while ((chars = fgetc(file)) != EOF) {
        string[i++]  = (char)chars;
    }

    string[i] = '\0';
    fclose(file);
    return string;
}


int countLines(char *string) {
    int count = 0;

    while(*string != '\0') {
        if(*string == '\n') count++;
        string++;
    }
    return count;
}


int countWords(char *text) {
    char *specialCharacters = "!§$%&/()=?`*'_:;¡¶¢[]|{}≠¿'±‘–…∞´+#-.,";
    char *string = malloc(1);

    stringArray = NULL;

    int arraySize = sizeof(stringArray) / sizeof(stringArray[0]);

    string[0] = '\0';

    while(*text != '\0') {
        string = realloc(string, strlen(string) + 1);
        string[strlen(string)] = *text;
        text++;

        if(isspace(*text) || strchr(specialCharacters, *text)) {
            string[strlen(string) + 1] = '\0';
            stringArray = realloc(stringArray, (arraySize + 1) * sizeof *stringArray);

            if(!isalpha((string[strlen(string) - 1]))) {
                text++;
            }

            else {
                stringArray[arraySize] = strdup(string);
                arraySize++;
                text++;
            }
        }
    }

    return arraySize;
}


int countChars (char *string) {
    int countChars = 0;

    while(*string != '\0') {
        if(isalpha(*string)) {
            countChars++;
        }
        string++;
    }
    return countChars;
}


int countDigits(char *string) {
    int countDigits = 0;

    while(*string != '\0') {
        if(isdigit(*string)) {
            countDigits++;
        }
        string++;
    }
    return countDigits;
}


int countSpecialChars(char *string) {
    int countSpecialChars = 0;

    while(*string != '\0') {
        if(ispunct(*string)) {
            countSpecialChars++;
        }

        string++;
    }
    return countSpecialChars;
}


int countUndefChars(char *string) {
    int countUndefChars = 0;

    while(*string != '\0') {
        if(!isascii(*string)) {
            countUndefChars++;
        }
        string++;
    }
    return countUndefChars;
}


void filterFile(char *infile, char *outfile, char c) {
    FILE *out = fopen(outfile, "w");
    if(!out) {
        fprintf(stderr, "ERROR: File not found!\n");
        return;
    }

    while(*infile != '\0') {
        if(*infile == c) {
            while(isalpha(*infile)) {
                *outfile = *infile;
                infile++;
                outfile++;
            }
        }
        else infile++;
    }

    fclose(out);
}















