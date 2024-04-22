#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

void writeToFile(Node* head)
{
    FILE* data;
    data = fopen("saveData.txt", "w");
    Node* current = head;

    if(data == NULL) //Check to see if file opened
    {
        printf("List did not save, could not open save file.");
        exit(1);
    }

    while (current != NULL) //Prints all nodes from link list to txt file
    {
        fprintf(data, "%d %s %s ", current->taskData.charId, current->taskData.date, current->taskData.time);
        fputs(current->taskData.task, data);
        fprintf(data, "\n");
        current = current->next;
    }
    fclose(data);
}