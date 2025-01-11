#include "../include/headerA3.h"

//Menu option 1
void addNewCar(struct car ** headLL) {
    //Allocate memory for the new car
    a3Car * carPtr;
    carPtr = malloc(sizeof(a3Car));

    //Check for identifying if the memory allocation is successful or not
    if (carPtr == NULL) {
        printf("Memory allocation failed for new car.\n");
        exit(-1);
    }
    
    //Ask the user to enter car details and store them to the linked list
    printf("Enter the car model: ");
    scanf("%s", carPtr->model);
    
    printf("Enter the car type: ");
    scanf("%s", carPtr->type);
    printf("\n");
    
    printf("Enter its year of manufacture: ");
    scanf("%d", &carPtr->year);
    
    printf("Enter its price: CDN $");
    scanf("%lf", &carPtr->price);
    printf("\n");

    //Calculate carId following the given rule
    int asciiSum = 0;
    for (int i = 0; carPtr->model[i] != '\0'; i++) {
    asciiSum = asciiSum + carPtr->model[i];
    }

    int typeLength = strlen(carPtr->type);
    carPtr->carId = asciiSum + typeLength;
    
    //Ensure the carId is unique
    a3Car *current = *headLL;

    while (current != NULL) {
    if (current->carId == carPtr->carId) {
        carPtr->carId = carPtr->carId  + (rand() % 900 + 1); //Adding random value between 1 and 999 if it's not unique
        current = *headLL;
    } else {
        current = current->nextCar;
    }
    }

    printf("Your computer-generated carId is %d\n\n", carPtr->carId);
    
    //Insert the new car at the end of the linked list
    carPtr->nextCar = NULL;

    if (*headLL != NULL) {
        current = *headLL;
        while (current->nextCar != NULL) {
            current = current->nextCar;
        }
        current->nextCar = carPtr;
    } else {
       *headLL = carPtr;
    }
}