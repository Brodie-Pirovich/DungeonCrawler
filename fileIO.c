#include "fileIO.h"
#include "ai.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

world_t* loadWorld()
{
    world_t* newWorld = calloc(1, sizeof(world_t));

    FILE* worldFile = fopen("easy.World", "r");
    if(worldFile == NULL)
    {
        perror ("ERROR READING WORLD FILE");
        return NULL;
    }
    fscanf(worldFile, "%dx%d", &newWorld->width, &newWorld->height);

    //create the 2D array
    //create the array of rows
    newWorld->map = calloc(newWorld->height, sizeof(item_t*));
    //create each row
    int i;
    for(i=0; i < newWorld->height; i++)
    {
        newWorld->map[i] = calloc(newWorld->width, sizeof(item_t));
    }

    do
    {
        int x, y;
        fscanf(worldFile, "%d,%d", &x, &y);
        newWorld->map[y][x] = malloc(1*sizeof(item_t));
        char aiText[20];
        fscanf(worldFile, " %c %19s %19s", &newWorld->map[y][x]->graphics, aiText, newWorld->map[y][x]->name);
        newWorld->map[y][x]->aiBehaviour = textToBehaviour(aiText);
        fgets(newWorld->map[y][x]->description, 256, worldFile);
        newWorld->map[y][x]->description[strlen(newWorld->map[y][x]->description)-1] = '\0';
    } while (!feof(worldFile));
    fclose(worldFile);
    return newWorld;
}