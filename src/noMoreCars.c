#include "../include/headerA3.h"

//Menu option 10
void noMoreCars(a3Car ** headLL) {
    char letter;
    
        //Asking input from the user
        printf("Are you sure you want to remove all car data (enter y for yes, n for no): ");
        scanf(" %c", &letter);  
        
        // Check for invalid input. If it's invalid then asked for valid input repeatedly
        while (letter != 'y' && letter != 'n') {
            printf("Invalid input. Please enter ('y' for yes or 'n' for no): ");
            scanf(" %c", &letter);
        }         

    if (letter == 'y') {
        //When the user input is 'y' for yes, remove all cars from the list
        while (*headLL != NULL) {
            a3Car *delete = *headLL;
            *headLL = delete->nextCar;
            free(delete);
        }
        printf("All removed. Linked list is now empty.\n");
    } else {
        printf("Nothing is removed. Linked list is as same as before.\n"); //Print if the user input is 'n' for no
    }
}