#include "headers.h"


void showMenu(menu* head)
{

	printf("MENU\tCARD\n\n");
	if(head == NULL)
	{
		printf("Empty MENU CARD");
		delay(5);
		return;
	}
				
	else
	{
		menu* cur = head;

		while(cur!=NULL)
		{
			printf("Id : %d,  Name : %s,  Cost : %.2f$\n",cur->itemId, cur->itemName, cur->itemPrice);
			cur = cur->next;
		}

		printf("Press 1 to return back\n");
		int hold;
		scanf("%d",&hold);
		return;
	}

}


int is_New_dish(menu* head, int id, char* name)
{
	if(head == NULL)
	{
		return 1;
	}

	menu* cur = head;
	while(cur != NULL)
	{
		if((strcmp(name, cur->itemName) == 0 ) && id == cur->itemId )
		{
			return 0;
		}

		cur = cur->next;
	}

	return 1;
}




menu* create_dish(int dishID, char* name, int cost)
{
	menu* temp = (menu*)malloc(sizeof(struct menu));
	temp->next = NULL;
	temp->itemId = dishID;
	temp->itemPrice = cost;
	strcpy(temp->itemName, name);

	return temp;
}


menu* insert_dish(menu* head, menu* dish)
{
	if(head == NULL)
	{
		return dish;
	}	

	else
	{
		menu* cur = head;
		while(cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = dish;
		return head;
	}
}

void addDish(menu* head)
{
	int numOfDish = 0;
	int itemID;
	char itemNAME[100];
	float itemCOST;

	clearScreen();
	printf("Enter the Number of Dishes you want to enter : ");
	scanf("%d",&numOfDish);

	for (int i = 0; i < numOfDish; i++)
	{
		
		showMenu(head);

		printf("\nEnter the Dish Id : ");
		scanf("%d",&itemID);
		printf("\nEnter the Dish Name : ");
		scanf("%s",itemNAME);
		printf("\nEnter the cost price of Dish : ");
		scanf("%f",&itemCOST);

		if(is_New_dish(head, itemID, itemNAME))
		{
			menu* newDish = create_dish(itemID, itemNAME, itemCOST);
			head = insert_dish(head, newDish);
		}

		else
		{
			printf("Dish already exists. Cannot add same dish.\n");
			delay(3);
		}

		clearScreen();

	}
	delay(2);
	return;
}


/*
initialize one more structure to keep track of number of items in menu 
and automatically update id when and where needed
*/


menu* removeDish(menu* head)
{
	int id;
	char dishName[100];
	printf("Enter the id : \n");
	scanf("%d",&id);
	printf("Enter the name : \n");
	scanf("%s",dishName);

	menu* cur = head;
	menu* prev = NULL;

	while(cur != NULL)
	{
		if(id == cur->itemId && (strcmp(dishName, cur->itemName)==0) )
		{
			if(prev == NULL)
			{
				menu* hold = cur;
				cur = cur->next;
				free(hold);
				printf("Successful deletion !!\n");
				delay(3);
				return cur;
			}

			else
			{
				menu* hold = cur;
				cur = cur->next;
				prev->next = cur;
				free(hold);
				printf("Successful deletion !!\n");
				delay(3);
				return head;
			}
		}

		else
		{
			printf("No such dish found !!\n");
			delay(3);
			return head;
		}
	}
}
