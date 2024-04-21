#include <stdio.h>
#include <stdlib.h>
#include "isValid.h"
#include "structure.h"
#include "add_task.h"
#include "read_task.h"
#include "delete_task.h"
#include "update_task.h"

// void updateTasks(Node** head); // Assuming this function is defined elsewhere
int main(int argc, char *argv[]) {
    Node* head = NULL;  // Start with an empty list
    int choice;

    printf("Welcome to the ToDo List Application!\n");

    do {
        printf("\nSelect an option:\n");
        printf("0 - Add Task\n");
        printf("1 - Update Task\n");
        printf("2 - List Tasks \n");
        printf("3 - Delete Task\n");
        printf("4 - Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                getUserInput(&head);    // Handle user input for adding tasks
                break;
            case 1:
                update_task(&head);     // Update tasks, assuming function is defined
                break;
            case 2:
                printf("\nlisting tasks. \n");  //Lists tasks
                read_tasks(head);
                break;
            case 3:
                delete_task(&head);     //Deletes task
                break;
            case 4:
                printf("exiting application\n"); //Tells the user that the app is exiting
                break;
             
            default:
                printf("Invalid choice, please try again.\n"); //Lets the user know that they did not enter a listed number (0-4)
        }
    } while (choice != 4);


    return 0;  // Exit status of the program
}
