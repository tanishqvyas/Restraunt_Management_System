#include "headers.h"



void printMainMenu(menu* head, records* record_head, recordCount* record_count)
{	

	// goto label to loop the menu in case of wrong choice
	XY:

	clearScreen();

	printf("RESTRAUNT MANAGEMENT SYSTEM\n\n");

	int choice;

	printf("1. Login as Admin\n");
	printf("2. Login as Coustomer\n");
	printf("3. Exit\n");
	printf("\nEnter your choice ( 1, 2 or 3) : ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
			loginAsAdmin(head, record_head, record_count);
			break;
		
		case 2:
			customerMenu(head, record_head, record_count);
			break;

		case 3:
			printf("\n\nThanks for using our system\n");
			delay(3);
			clearScreen();
			break;

		default:

			// Redirecting the user to take input again
			printf("\n\nInvalid choice. Please enter choices as 1, 2 or 3\n");
			
			// dealying some secs before redirecting
			delay(3);
			goto XY;
			break;

	}
}


void adminMenu(menu* head, records* record_head, recordCount* record_count)
{
	// goto label to loop the menu in case of wrong choice
	XY:

	clearScreen();

	printf("RESTRAUNT MANAGEMENT SYSTEM\n\n");

	int choice;

	printf("1. Add Dish in the menu\n");
	printf("2. Remove Dish from the menu\n");
	printf("3. Order Records\n");
	printf("4. Show Menu\n");
	printf("5. Exit\n");
	printf("\nEnter your choice ( 1, 2 or 3) : ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:

			head = addDish(head);
			goto XY;
			break;
		
		case 2:
			head = removeDish(head);
			goto XY;
			break;

		case 3:
		
			display_records(record_head, record_count);
			delay(3);
			goto XY;
			break;

		case 4: 
			showMenu(head);
			clearScreen();
			goto XY;
			break;

		case 5:
			
			clearScreen();
			printMainMenu(head, record_head, record_count);
			break;

		default:

			// Redirecting the user to take input again
			printf("\n\nInvalid choice. Please enter choices as 1, 2, 3, 4 or 5\n");
			
			// dealying 5 secs before redirecting
			delay(3);
			goto XY;
			break;

	}

}


void customerMenu(menu* head, records* record_head, recordCount* record_count)
{
	// goto label to loop the menu in case of wrong choice
	XY:

	clearScreen();

	printf("RESTRAUNT MANAGEMENT SYSTEM\n\n");

	int choice;

	printf("1. Display Menu Card\n");
	printf("2. Place Order\n");
	printf("3. Cancel Order\n");
	printf("4. Add to current order\n");
	printf("5. Back\n");
	printf("\nEnter your choice ( 1, 2, 3, 4 or 5) : ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
			showMenu(head);
			goto XY;
			break;
		
		case 2:
			record_head = placeOrder(head, record_head, record_count);
			delay(1);
			goto XY;
			break;

		case 3:
			record_head = cancelOrder(head, record_head, record_count);
			goto XY;
			break;

		case 4:
			
			record_head = addToExistingOrder(head, record_head, record_count);
			goto XY;
			break;	

		case 5:
			clearScreen();
			printMainMenu(head, record_head, record_count);
			break;

		default:

			// Redirecting the user to take input again
			printf("\n\nInvalid choice. Please enter choices as 1, 2, 3, 4 or 5\n");
			
			// dealying 5 secs before redirecting
			delay(3);
			goto XY;
			break;

	}

}