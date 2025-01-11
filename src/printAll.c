#include "../include/headerA3.h"

//Menu option 3
void printAll(struct car * headLL) {

    if (headLL == NULL) {
        printf("No cars found.\n"); //Print this when the linked list is empty
    } else {
        int count = 0;
        while (headLL != NULL) {
            count = count + 1; //Counting the total number of cars in the linked link
            printf("Car #%d:\n", count);
            printf("Car id: %d\n", headLL->carId);
            printf("Model: %s\n", headLL->model);
            printf("Type: %s\n", headLL->type);

            //Format the price to include a comma and print two digits after decimal
            int thousands = (int)(headLL->price) / 1000; 
            int hundreds = (int)(headLL->price) % 1000;                  
            int cents = (int)((headLL->price - (int)(headLL->price)) * 100);

            printf("Price: CDN $%d,%03d.%02d\n", thousands, hundreds, cents);

            printf("Year of Manufacture: %d\n\n", headLL->year);
            headLL = headLL->nextCar; //Move to the next node
        }
        printf("Currently, there are %d cars.\n", count);
    }
} 