#include "stdio.h"
#include "stdlib.h"
#include "structure.h"

//Function to print all tasks in link list
int printNodes(struct Node* head, char date[], char time[], char taskTitle[], char taskDescription[])
{
    int counter = 0;
    struct Node* current = head;

    //Loop to print each node in link list
    while(current != NULL)
    {
        counter++;
        
        printf("%d: %s, %s\n", counter, date, time);    //Prints the number of the node, date and time
        puts(taskTitle);    //Prints the title of the task
        printf("\n");
        puts(taskDescription);  //Prints the descripton of the task
        printf("\n\n");

        current = current->next;
    }
    return counter;
}

//Main function to update task
void update_task(struct Node* head, char date[], char time[], char taskTitle[], char taskDescription[])
{
    int choice = 0, updateDate = 0, updateTime = 0, updateTitle = 0, updateDescription = 0, maxNodes;
    struct Node* current = head;

    //Asks user for which node they desire to update
    maxNodes = printNodes(head, date, time, taskTitle, taskDescription);
    printf("Please enter the corresponding number for the task you would like to update: ");
    scanf("%d", &choice);

    //Make sure user enters an actual node
    while((choice > maxNodes) || (choice < 0))
    {
        printf("That was not an option, please enter one of the listed numbers (0-%d): ", maxNodes);
        scanf("%d", &choice);
    }

    //Navigates to the desired node
    for(int i = 1; i < choice; i++)
    {
        current = current->next;
    }

    //Prints the information of the selected task
    printf("Date: %s\nTime: %s\nTitle: ", current->taskData.date, current->taskData.time);
    puts(current->taskData.taskTitle);
    printf("\nDescription: ");
    puts(current->taskData.taskDescription);

    //Asks if the user wants to update the date
    printf("\n\nDo you want to update the date? (enter 1 for yes or 2 for no)\n");
    scanf("%d", &updateDate);
    if(updateDate == 1)
    {
        printf("\nPlease enter the new date: ");
        scanf("%s", current->taskData.date);
    }

    //Asks if the user wants to update the time
    printf("\n\nDo you want to update the time? (enter 1 for yes or 2 for no)\n");
    scanf("%d", &updateTime);
    if(updateDate == 1)
    {
        printf("\nPlease enter the new time: ");
        scanf("%s", current->taskData.time);
    }

    //Asks if the user wants to update the title
    printf("\n\nDo you want to update the title? (enter 1 for yes or 2 for no)\n");
    scanf("%d", &updateTitle);
    if(updateDate == 1)
    {
        printf("\nPlease enter the new title: ");
        scanf("%s", current->taskData.taskTitle);
    }

    //Asks if the user wants to update the description
    printf("\n\nDo you want to update the description? (enter 1 for yes or 2 for no)\n");
    scanf("%d", &updateDescription);
    if(updateDate == 1)
    {
        printf("\nPlease enter the new description: ");
        scanf("%s", current->taskData.taskDescription);
    }
}

// this section works on updating task on the  todo list
// please read the documentation section for more information
