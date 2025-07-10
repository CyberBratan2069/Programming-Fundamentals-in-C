/**********************************************************************************************************************/
/** @Autor Christian Reiswich
 * Created on 7/9/25
 * Compiled with gcc IndustrialPlant.c -o IndustrialPlant
 */
/**********************************************************************************************************************/


#include "IndustrialPlant.h"
#include <stdio.h>
#include <math.h>

#define MAX_SENSOR_VALUES 100


int datInput(float fValues[]) {
    printf("Tip in the Sensor Values (Max. 100 Values):\n");
    int countedValues = 0;

    for(int i=0; i< MAX_SENSOR_VALUES; i++) {
        printf("Value %i: ", i+1);
        scanf ("%f", &fValues[i]);
        if(fValues[i] <= 0) break;
        countedValues++;
    }

    return countedValues;
}


float datMean(float fValues[], int iNumber) {
    float addAllValues = 0;

    for(int i=0; i< iNumber; i++) {
        addAllValues += fValues[i];
    }

    return addAllValues / iNumber;
}


float datStandart(float fValues[], int iNumber, float fMean) {
    float variance = 0;
    for(int i=0; i< iNumber; i++) {
        variance += (fValues[i] - fMean) * (fValues[i] - fMean);
    }
    variance /= (iNumber -1);

    float stddev = sqrt(variance);
    return stddev;
}


int main(void) {

    printf("** Evaluate sensor values **");

    float sensorValues[MAX_SENSOR_VALUES];
    int   values = datInput(sensorValues);
    float mean   = datMean(sensorValues, values);
    float stddev = datStandart(sensorValues, values, mean);

    printf("Sensor Values: \n");
    printf("Number of Values = %i\n",   values);
    printf("Mean             = %.2f\n", mean);
    printf("Stddev.          = %.2f\n", stddev);

    return 0;
}