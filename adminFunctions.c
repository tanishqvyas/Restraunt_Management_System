#include "headers.h"

/*

struct menu
{
	int itemId;
	char itemName[100];
	float itemPrice;

	struct menu* next;
};
typedef struct menu menu;


*/



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
		
		printf("Enter the Dish Id : ");
		scanf("%d",&itemID);
		printf("\nEnter the Dish Name : ");
		scanf("%s",itemNAME);
		printf("\nEnter the cost price of Dish : ");
		scanf("%f",&itemCOST);

		menu* newDish = create_dish(itemID, itemNAME, itemCOST);
		head = insert_dish(head, newDish);

		clearScreen();

	}
	delay(2);
	return;
}


/*
initialize one more structure to keep track of number of items in menu 
and automatically update id when and where needed
*/


void removeDish(menu* head)
{
	//todo
}

void showMenu(menu* head)
{

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