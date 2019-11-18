#include "headers.h"



void printMainMenu(menu* head)
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
			loginAsAdmin(head);
			break;
		
		case 2:
			// todo
			customerMenu(head);
			break;

		case 3:
			printf("\n\nThanks for using our system\n");
			delay(3);
			clearScreen();
			break;

		default:

			// Redirecting the user to take input again
			printf("\n\nInvalid choice. Please enter choices as 1, 2 or 3\n");
			
			// dealying 5 secs before redirecting
			delay(3);
			goto XY;
			break;

	}
}


void adminMenu(menu* head)
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

			addDish(head);
			goto XY;
			break;
		
		case 2:
			// todo
			//removeDish(head);
			goto XY;
			break;

		case 3:
		
			// todo
			//printOrderRecords();
			break;

		case 4: 
			//todo
			showMenu(head);
			clearScreen();
			goto XY;
			break;

		case 5:
			
			delay(1);
			clearScreen();
			printMainMenu(head);
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


void customerMenu(menu* head)
{
	// goto label to loop the menu in case of wrong choice
	XY:

	clearScreen();

	printf("RESTRAUNT MANAGEMENT SYSTEM\n\n");

	int choice;

	printf("1. Display Menu Card\n");
	printf("2. Place Order\n");
	printf("3. Back\n");
	printf("\nEnter your choice ( 1, 2 or 3) : ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
			//
			break;
		
		case 2:
			// todo
			//
			break;

		case 3:
			delay(3);
			clearScreen();
			printMainMenu(head);
			break;

		default:

			// Redirecting the user to take input again
			printf("\n\nInvalid choice. Please enter choices as 1, 2 or 3\n");
			
			// dealying 5 secs before redirecting
			delay(3);
			goto XY;
			break;

	}

}