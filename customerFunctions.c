#include "headers.h"

float fetch_price(menu* head, int id)
{
	menu* cur = head;
	while(cur->itemId != id)
	{
		cur = cur->next;
	}
	return cur->itemPrice;
}

char fetch_dishname(menu* head, int id)
{
	menu* cur = head;
	while(cur->itemId != id)
	{
		cur = cur->next;
	}
	return cur->itemName;
}



records* create_record(myOrder* head, char* name, float bill)
{
	records* temp = (records*)malloc(sizeof(struct records));
	strcpy(temp->customerName, name);
	temp->totalBill = bill;
	temp->order = head;
	temp->next = NULL;

	return temp;
}

records* insert_record(records* order, records* new_order)
{
	if(order == NULL)
	{
		return new_order;
	}

	else
	{
		new_order->next = order;
		order = new_order;
		return order;
	}
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

myOrder* insert_order(myOrder* head, myOrder* new_order)
{
	if(head == NULL)
	{
		return new_order;
	}

	else
	{
		new_order->next = head;
		head = new_order;
		return head;
	}
}


void placeOrder(menu* head, records* record_head)
{
	int id;
	int qty;
	int numOfDishes;
	float billAmount;
	char customer_name[50];
	myOrder* new_order_head = NULl;


	printf("\nEnter the name for Booking : ");
	scanf("%s",customer_name);
	printf("\nEnter the Number of Dishes you want to order : ");
	scanf("%d",&numOfDishes);
	printf("\n\n");


	for (int i = 0; i < numOfDishes; i++)
	{

		showMenu(head);
		printf("\nEnter the dish Id : ");
		scanf("%d",&id);
		printf("\nEnter the quantity : ");
		scanf("%d",&qty);

		float cost = fetch_price(head, id);
		char dish_name[100];
		strcpy(dish_name,fetch_dishname(head, id));

		// Increase bill amount
		billAmount += cost*qty;

		myOrder* new_order = create_order(id, dish_name, cost, qty);
		new_order_head = insert_order(new_order_head, new_order);
		


	}

	
}