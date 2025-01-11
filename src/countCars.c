#include "../include/headerA3.h"

//Menu option 7
int countCars(a3Car * headLL) {
    int count = 0; //Variable to sum up all the nodes of the linked list

    //Counting until it's end of the linked list
    while (headLL != NULL) {
        count = count + 1;
        headLL = headLL->nextCar;
    }
    return count; //Return the total number of nodes exist in the linked list
}