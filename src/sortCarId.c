#include "../include/headerA3.h"

//Menu option 8
void sortCarId(struct car **headLL) {
    //Check for cases where no sorting is needed
    if (*headLL == NULL || (*headLL)->nextCar == NULL) {
        return;
    }

    int swap = 1; //Variable to track the swaps
    struct car *currentNode, *nextNode, *prevNode, *temp;

    while (swap) {
        swap = 0; //Reset for the new pass
        prevNode = NULL;
        currentNode = *headLL;

        //Traverse the linked list until its the end of it
        while (currentNode->nextCar != NULL) {
            nextNode = currentNode->nextCar;

            //Check to see that the current carID is greater than the next one or not
            if (currentNode->carId > nextNode->carId) {
                swap = 1;

                //Adjusting previous nodes nextCar when it's not the beginning of the list
                if (prevNode != NULL) {
                    prevNode->nextCar = nextNode;
                } else {
                    *headLL = nextNode; 
                }

                //Perform the Swap 
                temp = nextNode->nextCar;
                nextNode->nextCar = currentNode;
                currentNode->nextCar = temp;

                //Updating the prevNode after the swap
                if (prevNode != NULL) {
                    prevNode = nextNode;
                }

                continue;
            } else {
            //Case where no swap is needed
            prevNode = currentNode;
            currentNode = nextNode;
            }

        }
    } 
}