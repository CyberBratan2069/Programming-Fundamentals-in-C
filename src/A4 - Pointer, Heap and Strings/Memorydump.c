/***********************************************************************************************************************
 * @author Christian Reiswich
 * @created on 10 July 2025
 **********************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CHARS_LENGTH 16


void memdump(unsigned char *string, int lines) {
    printf("ADDR\t\t 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F 0123456789ABCDEF\n");

    for(int i=0; i< lines; i++) {
        unsigned char *ptr = (string + (i * CHARS_LENGTH));
        printf("%p\t", (void *)ptr);

        for(int j=0; j< CHARS_LENGTH; j++) {
            printf(" %02X", ptr[j]);
        }

        printf(" ");

        for(int n=0; n< CHARS_LENGTH; n++) {
            unsigned char c = isprint(ptr[n]) ? ptr[n] : '.';
            printf("%c", c);
        }

        printf("\n");
    }
}


int memreplace(char *string, char cin, char cout, char **caddr) {
    int count     = 0;
    char *lastAdr = NULL;

    while(*string != '\0') {
        if(*string == cin) {
            *string = cout;
            lastAdr = string;
            count++;
        }
        string++;
    }

    *caddr = lastAdr + 1;
    return count;
}


int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <string> <cin> <cout> <lines>\n", argv[0]);
        return 1;
    }

    char *input = argv[1];
    char cin    = argv[2][0];
    char cout   = argv[3][0];
    int lines   = atoi(argv[4]);


    char *copy = malloc(strlen(input) + 1);
    if (!copy) {
        perror("malloc failed");
        return 1;
    }

    strcpy(copy, input);

    printf("Length of String (incl. \\0): %to Byte(s)\n", strlen(copy) + 1);
    printf("Replaces: '%c' with '%c'\n", cin, cout);

    char *caddr = NULL;
    int count = memreplace(copy, cin, cout, &caddr);

    printf("The chars were %d times found and replaced\n", count);
    if (caddr)
        printf("The last time in the address %p\n\n", (void *)caddr);

    memdump((unsigned char *)copy, lines);

    free(copy);
    return 0;
}
