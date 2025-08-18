/***********************************************************************************************************************
 * @author Christian Reiswich
 * @created on 9 July 2025
 **********************************************************************************************************************/


#include <stdio.h>


int main(void) {
    int a;
    int b;

    printf("Input a:");
    scanf("%i", &a);

    printf("Input b:");
    scanf("%i", &b);

    printf("Hallo Emden! \n");
    printf("\t %i + %i = %i\n", a, b, a+b);
    printf("\t %i / %i = %i\n", a, b, a/b);
    printf("\t %i %% %i = %i\n", a, b, a%b);
    printf("\t %x * 5 - %x = %i\n", b, a, b*5-a);


    return (0);
}