#include <stdio.h>
#include <stdlib.h>
#include "structure.h"
#include <direct.h>
#include <string.h>

void readFromFile(Node** head)
{
    FILE* data;
    int charId;
    char directory[256], filename[] = "\\saveData.txt", char date[25], time[25], task[256];

    getcwd(directory, 256); //Gets the current directory
    strcat(directory, filename); //Appends the filename to the end of the directory link
    
    data = fopen(directory, "a+");

    if(data == NULL) //Check to see if file opened
    {
        printf("Could not open save file.");
        exit(1);
    }

    int charId;

    //Reads the tasks from the txt file and puts them into the link list (changes charId to make the list look clean)
    while(fscanf(data, "%d %s %s %99[^\n]", &charId, date, time, task) != EOF)
    {
        addTask(head, date, time, task);
    }

    fclose(data);
}