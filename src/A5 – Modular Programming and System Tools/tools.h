/***********************************************************************************************************************
 * @author Christian Reiswich
 * @created on 20 August 2025
 * @info Task was generated using chatGPT
 **********************************************************************************************************************/

#ifndef PROGRAMMING_FUNDAMENTALS_IN_C_TOOLS_H
#define PROGRAMMING_FUNDAMENTALS_IN_C_TOOLS_H

#include <stddef.h>

char* readFile       (char *filename);
int countLines       (char *string);
int countWords       (char *text);
int countChars       (char *string);
int countDigits      (char *string);
int countSpecialChars(char *string);
int countUndefChars  (char *string);
void filterFile(char *infile, char *outfile, char c);

//extern char **stringArray;
//extern size_t g_words_count;

void freeStoredWords(void);

#endif //PROGRAMMING_FUNDAMENTALS_IN_C_TOOLS_H
