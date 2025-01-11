#include "../include/headerA3.h"

//Menu option 9
void oneLessCar(a3Car **headLL, int whichOne) {

    //Check to see that if the linked list in empty or not
    if (*headLL == NULL) {
        return; 
    }

    a3Car *deleteCar = NULL; 

    if (whichOne == 1) {
       //The case of removing the head node of the linked list
        deleteCar = *headLL; 
        *headLL = (*headLL)->nextCar; 
        free(deleteCar); 
    } else {
        //The case of removing the node of the linked list other than head node
        a3Car *current = *headLL;
        int pos = 1; 
        
        while (current != NULL && current->nextCar != NULL && pos < whichOne - 1) {
            current = current->nextCar;
            pos = pos + 1;
        }

        //Check to see that if we're not at the end of it and next code isn't empty
        if (current == NULL || current->nextCar == NULL) {
            return; 
        }

        //Remove the selected node from the linked list
        deleteCar = current->nextCar; 
        current->nextCar = deleteCar->nextCar;
        free(deleteCar); //Free the memory allocated for the removed node to avoid memory leak
    }
}
