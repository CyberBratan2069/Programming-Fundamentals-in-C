/**********************************************************************************************************************/
/** @Autor Christian Reiswich                                                                                        **/
/** Created on 7/9/25                                                                                                **/
/**********************************************************************************************************************/


#include <stdio.h>

#define USMILE   1.6093
#define USGALLON 3.785

int main(void) {

    char  location;
    int   odometerReadingLASTRefueling;
    int   odometerReadingCURRENTRefueling;
    int   amountOfPetrolFilled;
    float distanceTraveled;
    float consumption;


    printf("** Gasoline Consumption **\n");
    printf("Location US (u) or EU (e): ");
    scanf("%c", &location);


    if(location == 'u') {
        printf("Odometer reading LAST refueling in Miles: ");
        scanf("%i", &odometerReadingLASTRefueling);

        printf("Odometer reading CURRENT refueling in Miles: ");
        scanf("%i", &odometerReadingCURRENTRefueling);

        printf("Amount of petrol filled in gal: ");
        scanf("%i", &amountOfPetrolFilled);

        printf("-> distance traveled: ");
        distanceTraveled = odometerReadingCURRENTRefueling - odometerReadingLASTRefueling;
        printf("%.2f miles\n", distanceTraveled);

        printf("-> consumption: ");
        consumption = amountOfPetrolFilled / (distanceTraveled/100);
        printf("%.2f miles/gal\n", consumption);
    }


    if(location == 'e') {
        printf("Odometer reading LAST refueling in Kilometer: ");
        scanf("%i", &odometerReadingLASTRefueling);

        printf("Odometer reading CURRENT refueling in Kilometer: ");
        scanf("%i", &odometerReadingCURRENTRefueling);

        printf("Amount of petrol filled in l: ");
        scanf("%i", &amountOfPetrolFilled);

        printf("-> distance traveled: ");
        distanceTraveled = odometerReadingCURRENTRefueling - odometerReadingLASTRefueling;
        printf("%.2f km\n", distanceTraveled);

        printf("-> consumption: ");
        consumption = amountOfPetrolFilled / (distanceTraveled/100);
        printf("%.2f l/km\n", consumption);
    }

    return 0;
}