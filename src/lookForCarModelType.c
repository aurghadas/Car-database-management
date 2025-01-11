#include "../include/headerA3.h"

//Menu option 6
int lookForCarModelType(struct car * headLL, char key[100]) {
    char *model, *type;
    int position = 1;

    //Tokenize the key to separate model and type
    model = strtok(key, " ");
    type = strtok(NULL, "\0");

    while (1) {
        if (headLL == NULL){
            break;
        }
        else if (strcmp(headLL->model, model) == 0 && strcmp(headLL->type, type) == 0) {
            return position; //Return the position of the node if model and type is matched
        }
        else{
            headLL = headLL->nextCar;
            position = position + 1;
        }
        
    }

    return -1; //If match is not found
}