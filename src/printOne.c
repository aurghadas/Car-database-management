#include "../include/headerA3.h"

//Menu option 4
void printOne(struct car * headLL, int whichOne) {

    int position = 1;
    struct car * currentCar = headLL;
    //Traverse through the linked list until the end of it or the desired position is reached
    while (position < whichOne  && currentCar != NULL) { 
        currentCar = currentCar->nextCar;
        position = position + 1;
    }

    //Print the car details if its position exist
    if (currentCar != NULL && position == whichOne) {
        printf("Car id: %d\n", currentCar->carId);
        printf("Model: %s\n", currentCar->model);
        printf("Type: %s\n", currentCar->type);

            //Format the price to include a comma and only two decimal places
            int thousands = (int)(currentCar->price) / 1000;
            int hundreds = (int)(currentCar->price) % 1000;
            int cents = (int)((currentCar->price - (int)(currentCar->price)) * 100);

            printf("Price: CDN $%d,%03d.%02d\n", thousands, hundreds, cents);

        
        printf("Year of Manufacture: %d\n", currentCar->year);
    } else {
        printf("No car found at position %d.\n", whichOne);
    }
}