#include "../include/headerA3.h"

//Menu option 2
void loadCarData(struct car ** headLL, char fileName[MAX_LENGTH]) {
    char *token;
    FILE *fptr = fopen(fileName, "r");
    //Check if the file opens successfully or not
    if (fptr == NULL) {
        printf("Error! Can't open the file.\n");
        return;
    }

    char storage[1024]; //Storage to store lines from the file
    while (fgets(storage, sizeof(storage), fptr) != 0) {
        a3Car *newCar = malloc(sizeof(a3Car)); //Allocating memory for a new Car information
        //Check if the memory allocation fails or success
        if (newCar == NULL) {
            printf("Error! Memory allocation failed for new car.\n");
            fclose(fptr);
            exit(-1);
        }

        //Parse the line for car information separated by commas
        token = strtok(storage, ",");
        if(token != NULL) {
            int numID = atoi(token);
            newCar->carId = numID;
            token = strtok(NULL, ",");
            if(token != NULL) {
                strcpy(newCar->model, token);
                token = strtok(NULL, ",");
                if(token != NULL) {
                    strcpy(newCar->type, token);
                    token = strtok(NULL, ",");
                    if(token != NULL){
                        numID = atoi(token);
                        newCar->year = numID;
                        token = strtok(NULL, ",");
                        if(token != NULL){
                            float price = atof(token);
                            newCar->price = price;
                        } else {
                            free(newCar);
                            newCar = NULL;
                        }
                    } else {
                        free(newCar);
                        newCar = NULL;
                    }
                } else {
                    free(newCar);
                    newCar = NULL;
                }
            } else {
                free(newCar);
                newCar = NULL;
            }
        } else {
            free(newCar);
            newCar = NULL;
        }
        
        if(newCar != NULL){
            //Ensure the carId is unique
            a3Car *current = *headLL;

            while (current != NULL) {
            if (current->carId == newCar->carId) {
                newCar->carId = newCar->carId  + (rand() % 900 + 1); //Adding random value between 1 and 999 if it's not unique
                current = *headLL;
            } else {
                current = current->nextCar;
            }
            }

            // Add the new car to the end of the linked list
            newCar->nextCar = NULL; 

            if (*headLL != NULL) {
                current = *headLL;
                while (current->nextCar != NULL) {
                    current = current->nextCar; 
                }
                current->nextCar = newCar;
            } else {
                *headLL = newCar; 
            }
        }
    }

    fclose(fptr);
}