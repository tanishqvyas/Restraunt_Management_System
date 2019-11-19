include "headers.h"

float fetch_price(menu* head, float id)
{
	menu* cur = head;
	while(cur->itemId != id)
	{
		cur = cur->next;
	}
	return cur->itemPrice;
}

char fetch_dishname(menu* head, float id)
{
	menu* cur = head;
	while(cur->itemId != id)
	{
		cur = cur->next;
	}
	return cur->itemName;
}



myOrder* create_order(int id, char* dish_name, int cost, int qty)
{
	myOrder* temp = (myOrder*)malloc(sizeof(struct myOrder));
	temp->itemId = id;
	temp->itemName = dish_name;
	temp->itemPrice = cost;
	temp->quantity = qty;
	temp->next = NULL;

	return temp;
}

myOrder* insert_order(myOrder* head)
{
	
}


void placeOrder(menu* head)
{
	int id;
	int qty;
	int numOfDishes;
	float billAmount;
	printf("Enter the Number of Dishes you want to order : \n");
	scanf("%d",&numOfDishes);
	printf("\n");

	for (int i = 0; i < numOfDishes; i++)
	{
		showMenu(head);
		printf("\nEnter the dish Id : ");
		scanf("%d",&id);
		printf("\nEnter the quantity : ");
		scanf("%d",&qty);

		float cost = fetch_price(head, id);
		char dish_name[100];
		strcpy(dish_name,fetch_dishname(menu* head, float id));

		// Increase bill amount
		billAmount += cost*qty;

		myOrder* new_order = create_order(id, dish_name, cost, qty);

		// push in the order

	}
}