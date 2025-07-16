/***********************************************************************************************************************
 * @Autor Christian Reiswich
 * @Created on 7/10/25
 * @Compiled with gcc ASCIIPlotter.c -o ASCIIPlotter
 **********************************************************************************************************************/


#include <stdio.h>

#define HEIGHT_LENGTH 10
#define WIDTH_LENGTH  10
#define MAX_POINTS    100


struct point {
    int x;
    int y;
    char des[20];
};


int checkValidInput(int xPoint, int yPoint) {
    if((xPoint < 0 || xPoint > 10) ||
       (yPoint < 0 || yPoint > 10)) {
        fprintf(stderr, "ERROR: Input was Invalid!\n");
        return -1;
    }
    else return 0;
}


int dataInput(struct point points[]) {
    int enteredPoints = 0;

    printf("Coordination   = x y des\n");
    for(int i=0; i< MAX_POINTS; i++) {
        printf("Enter points %i = ", i+1);
        scanf("%i %i %s", &points[i].x, &points[i].y, points[i].des);

        checkValidInput(points[i].x, points[i].y);

        if(points[i].x == 0 && points[i].y == 0 && points[i].des[0] == '0') {
            printf("-> ENTRY HAS ENDED");
            return enteredPoints; // Break
        }
        else enteredPoints++;
    }

    return enteredPoints;
}


void drawGraph(struct point points[], int enteredPoints) {
    printf("\n** ASCII Plotter **\n");

    for(int y=0; y<= HEIGHT_LENGTH; y++) {
        if     (y ==  0) printf("10|");
        else if(y ==  5) printf("05|");
        else if(y == 10) printf("00|");
        else             printf("  |");

        for(int x=0; x<= WIDTH_LENGTH; x++) {
            for(int p=0; p< enteredPoints; p++) {
                if(points[p].x == x && (HEIGHT_LENGTH - points[p].y == y)) {
                    printf("x");
                }
            }
            if(y == 10) printf("__ ");
            else        printf("   ");
        }
        printf("\n");
    }

    for(int x=0; x<= WIDTH_LENGTH+1; x++) {
        if     (x == 1 ) printf("00 ");
        else if(x == 6 ) printf("05 ");
        else if(x == 11) printf("10 ");
        else             printf("   ");
    }
}


int main(void) {
    struct point points[MAX_POINTS];
    int enteredPoints = dataInput(points);
    drawGraph(points, enteredPoints);
    return 0;
}