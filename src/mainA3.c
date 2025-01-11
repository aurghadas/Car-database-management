#include "../include/headerA3.h"

int main() {

    a3Car *headLL = NULL;
    char carName[100];
    int n, m, p, q, carId, total;
    int currentPos = 1;
    int carIDFound = 0;

    while (1) {
        int choice;
        printf("\n");
        printf("1. Add data on a new car\n");
        printf("2. Load data on cars from a given text file\n");
        printf("3. Print data of all cars\n");
        printf("4. Print data of the nth car\n");
        printf("5. Search car data based on carId\n");
        printf("6. Search car data based on model and type\n");
        printf("7. Count the total number of cars in the list\n");
        printf("8. Sort the cars in the list based on carId\n");
        printf("9. Remove data of the nth car\n");
        printf("10. Remove all car data\n");
        printf("11. Exit\n");
        printf("Choose a menu option: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                addNewCar(&headLL);
                break;
            case 2:
                loadCarData(&headLL, "inputFile.txt");
                break;
            case 3:
                printAll(headLL);
                break;
            case 4:
                total = countCars(headLL);

                while(1){
                printf("Enter a position: ");
                scanf("%d", &n);
                printf("\n");
                
                if (n < 1) {
                    printf("Invalid position. Position starts at 1.\n");
                }else if(n > total){
                    printf("Position %d is not in the list. Enter position within %d\n", n, total);
                }else{
                    printOne(headLL, n);
                    break;
                }
            }
                break;
            case 5:
                printf("Enter a car ID: ");
                scanf("%d", &carId);
                printf("\n");

                m = lookForCarId(headLL, carId);

                if(m != -1){
                    printOne(headLL, m);
                }else{
                    printf("Car ID: %d is not found !", carId);
                }
                break;
            case 6:
                getchar();
                printf("Enter the model and type (separated by a space): ");
                fgets(carName, 100, stdin);
                printf("\n");
                
                //Remove the newline character if it's present
                carName[strcspn(carName, "\n")] = 0;
                p = lookForCarModelType(headLL, carName);

                if(p != -1){
                    printOne(headLL, p);
                }else{
                    printf("Entered car model and type: %s is not found!\n", carName);
                }
                break;
            case 7:
                q = countCars(headLL);
                printf("Total number of cars = %d\n", q);
                break;
            case 8:
                sortCarId(&headLL);
                break;
            case 9:

                total = countCars(headLL);
                printf("Currently there are %d cars.\n", total);
                printf("Which car do you wish to remove - enter a value between 1 and %d:", total);
                scanf("%d", &n);

                while(n <= 0 || n > total){
                    printf("Invalid value! This value is out of the range!\n");
                    printf("Which car do you wish to remove - enter a value between 1 and %d:", total);
                    scanf("%d", &n);
                }

                //Find the car ID before removing it
                a3Car *current = headLL;

                while (current != NULL && currentPos < n) {
                    current = current->nextCar;
                    currentPos = currentPos + 1;
                }

                if (current != NULL && currentPos == n) {
                    carIDFound = current->carId;
                }

                oneLessCar(&headLL, n);
                printf("\n\nCar [Id: %d] removed.\n", carIDFound);
                printf("There are now %d cars remaining.\n", (total - 1));
                
                break;
            case 10:
                noMoreCars(&headLL);
                break;
            case 11:
                printf("Exiting the program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        
    }
    return 0;
}
