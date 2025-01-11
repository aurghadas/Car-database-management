#include "../include/headerA3.h"

//Menu option 5
int lookForCarId(struct car * headLL, int key) {
    
    int nodePosition = 1;

    //Traverse the linked list until the end of it 
    while (headLL != NULL) { 
        if (headLL->carId == key) {
            return nodePosition; //Return the position if Car ID is found
        }
        headLL = headLL->nextCar;
        nodePosition = nodePosition + 1;
    }
    return -1; //Return -1 if Car ID is not found
}