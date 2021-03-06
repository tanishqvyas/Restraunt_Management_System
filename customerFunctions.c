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

char* fetch_dishname(menu* head, int id)
{
	menu* cur = head;
	while(cur->itemId != id)
	{
		cur = cur->next;
	}
	return cur->itemName;
}


int is_New_customer(records* record, char* name, recordCount* record_count)
{
	if(record == NULL)
	{
		return 1;
	}

	records* cur = record;
	int i = record_count->count;
	while(i > 0)
	{
		printf("%d\n",strcmp(name, cur->customerName));
		if(strcmp(name, cur->customerName) == 0)
		{
			return 0;
		}

		cur = cur->next;
		i--;
	}

	return 1;
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

void display_orders(myOrder* order)
{
	if(order == NULL)
	{
		printf("No order data present\n");
		return;
	}

	else
	{
		myOrder* cur = order;
		while(cur != NULL)
		{
			printf("%d\t\t %s\t\t %.2f\t\t  %d\n",cur->itemId, cur->itemName, cur->itemPrice, cur->quantity);
			cur = cur->next;
		}
	}
}

void display_records(records* record, recordCount* record_count)
{
	if(record == NULL)
	{
		printf("No Orders have been placed yet\n");
	}

	else
	{
		records* cur = record;
		while(cur != NULL)
		{
			printf("The customer name is : %s\n",cur->customerName);
			printf("\nOrder : \n\n");
			printf("Item ID\t\t Name\t\t Price\t\t Quatity\n");
			display_orders(cur->order);
			printf("Total Bill : %.2f$\n\n\n",cur->totalBill);
			cur = cur->next;
		}

		char holdd;
		printf("Press Enter");
		scanf("%c",&holdd);
	}

	return;
}



myOrder* create_order(int id, char* dish_name, int cost, int qty)
{
	myOrder* temp = (myOrder*)malloc(sizeof(struct myOrder));
	temp->itemId = id;
	strcpy(temp->itemName, dish_name);
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


records* placeOrder(menu* head, records* record_head, recordCount* record_count)
{
	int id;
	int qty;
	int numOfDishes;
	float billAmount;
	char customer_name[100];
	myOrder* new_order_head = NULL;


	printf("\nEnter the name for Booking : ");
	char hold;
	scanf("%c",&hold);
	fgets(customer_name, 100, stdin);//scanf("%s",customer_name);

	// test
	if( is_New_customer(record_head, customer_name, record_count))
	{

		printf("\nEnter the Number of Dishes you want to order : ");
		scanf("%d",&numOfDishes);
		printf("\n\n");


		for (int i = 0; i < numOfDishes; i++)
		{
			clearScreen();
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

		records* hold = create_record(new_order_head, customer_name, billAmount);
		record_head = insert_record(record_head, hold);
		printf("Successful placement of order for Customer : %s\n",customer_name);
		record_count->count++;
		return record_head;
	}


	else
	{
		printf("Username Already Taken. Please enter another name.\n");
		return record_head;
	}
}



records* cancelOrder(menu* head, records* record_head, recordCount* record_count)
{
	char customer_name[100];
	
	printf("\nEnter the name for Booking : ");
	char hold;
	scanf("%c",&hold);
	fgets(customer_name, 100, stdin);//scanf("%s",customer_name);

	int count = record_count->count;
	int found = 0;

	records* cur = record_head;
	records* prev = NULL;

	while(count > 0)
	{
		if(strcmp(customer_name, cur->customerName) == 0)
		{
			found = 1;
			break;
		}
		count--;
		prev = cur;
		cur = cur->next;
	}


	if(found == 1)
	{
		record_count->count--;
		printf("Successful cancelation of the order for Customer : %s\n",customer_name);
		delay(3);
	}
	else
	{
		printf("No Customer entry by the Name : %s was found\n",customer_name);
		delay(3);	
	}

	if(prev == NULL && found == 1)
	{
		records* temp = cur;
		cur = cur->next;
		free(temp);
		return cur;
	}

	else if(prev != NULL && found == 1)
	{
		records* temp = cur;
		cur = cur->next;
		prev->next = cur;
		free(temp);
		return record_head;
	}
		
	return record_head;
	
}



records* addToExistingOrder(menu* head, records* record_head, recordCount* record_count)
{
	char customer_name[100];
	int id;
	int qty;
	int numOfDishes;
	
	printf("\nEnter the name corresponding to existing order : ");
	char hold;
	scanf("%c",&hold);
	fgets(customer_name, 100, stdin);//scanf("%s",customer_name);

	int count = record_count->count;
	int found = 0;

	records* cur = record_head;
	records* prev = NULL;

	while(count > 0)
	{
		if(strcmp(customer_name, cur->customerName) == 0)
		{
			found = 1;
			break;
		}
		count--;
		prev = cur;
		cur = cur->next;
	}


	if(found == 1)
	{
			
		printf("\nEnter the Number of Dishes you want to add to current order : ");
		scanf("%d",&numOfDishes);
		printf("\n\n");


		for (int i = 0; i < numOfDishes; i++)
		{
			clearScreen();
			showMenu(head);
			printf("\nEnter the dish Id : ");
			scanf("%d",&id);
			printf("\nEnter the quantity : ");
			scanf("%d",&qty);

			float cost = fetch_price(head, id);
			char dish_name[100];

			strcpy(dish_name,fetch_dishname(head, id));

			cur->totalBill += cost*qty;

			myOrder* new_order = create_order(id, dish_name, cost, qty);
			cur->order = insert_order(cur->order, new_order);

		}
		printf("Successful placement of additional order for Customer : %s\n",customer_name);
		delay(3);
		
	}

	else
	{
		printf("No Customer entry by the Name : %s was found\n",customer_name);
		delay(3);	
	}

	return record_head;

}