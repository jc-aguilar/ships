/*
 * University of Central Florida 
 * COP 3502C - Fall 2019 
 * Author: Jose Aguilar 
 */ 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct SHIP
{
	char** items;
	int numItems;
	int id;
}SHIP;

int main(void)
{
	SHIP** ships = NULL;
	SHIP* ptr = NULL;
	int userChoice, tempId, count = 0, shipCapacity = 0;
	 
	while(userChoice != -1)
	{
		scanf("%d", &userChoice);
		
		if (userChoice == 0)
		{
			int temp;
			
			if (ships == NULL)
				printf("-1\n");
				
			scanf("%d", &temp);
			
			if (ships[temp - 1] == NULL)
				printf("-1\n");
			
			else if (temp == ships[temp - 1]->id && ships[temp - 1] != NULL)
			{
				if (temp == shipCapacity)
				{
					for (int j = 0; j < ships[temp - 1]->numItems; j++)
					{
						free(ships[temp - 1]->items[j]);
					}
					free(ships[temp - 1]->items);
					free(ships[temp - 1]);
							
					ships[temp - 1]->items = NULL;
					ships[temp - 1] = NULL;
					shipCapacity--;
					
				}
				
			}
			else
				printf("-1\n");
		}
			
		if (userChoice == 1)
		{
			
			if (count == shipCapacity)
			{
				SHIP** newArray = (SHIP**)calloc(shipCapacity * 2 + 1, sizeof(SHIP*));
					
				for (int i = 0; i < count; i++)
				{
					newArray[i] = ships[i];
				}
				free(ships);
				ships = newArray;
				shipCapacity = shipCapacity * 2 + 1;
			}
				
				ships[count] = (SHIP*)calloc(1, sizeof(SHIP));
				ptr = ships[count];
				
				int wordLength, i;
				scanf("%d", &ptr->numItems);
	
				ptr->items = (char**)calloc(ptr->numItems, sizeof(char*));
	
				for (i = 0; i < ptr->numItems; i++)
				{
					scanf("%d", &wordLength);
					ptr->items[i] = (char*)calloc(wordLength + 1, sizeof(char));
					scanf("%s", ptr->items[i]);
				
					if (strlen(ptr->items[i]) > wordLength)
					{
						printf("-1\n");
					}
				}
				ptr->id = 1 + count;
				count++;
		}// end if userChoice == 1
			
		if (userChoice == 2)
		{
			int tempId;
			
			if (ships == NULL)
				printf("-1\n");
			
			scanf("%d", &tempId);
			tempId = tempId - 1;
			
			if (tempId < count && ships[tempId] != NULL)
			{
				printf("%d\n", ships[tempId]->id);
			}
			else
			{
				printf("-1\n");
			}
		}
		
		if (userChoice == 3)
		{
			int shipPosition;
			int contentPosition;
			
			if (ships == NULL)
				printf("-1\n");
			
			scanf("%d", &shipPosition);
			scanf("%d", &contentPosition);
			shipPosition = shipPosition - 1;
			contentPosition = contentPosition - 1;
			
			if (shipPosition > count || ships[shipPosition] == NULL || contentPosition >= ships[shipPosition]->numItems)
			{
				printf("-1\n");
			}
			else
			{
				if (ships[shipPosition] != NULL && ships[shipPosition]->items[contentPosition] != NULL)
				{
						printf("%s\n", ships[shipPosition]->items[contentPosition]);
				}
			}
		}
		
		if (userChoice < -1 || userChoice > 3)
		{
			printf("-1\n"); 
		}
	}
				
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < ships[i]->numItems; j++)
			free(ships[i]->items[j]);
		
		free(ships[i]->items);
		free(ships[i]);
	}
	free(ships);
				
	return EXIT_SUCCESS;
}