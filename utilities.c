#include "headers.h"


/* Printing related utils functions */

void clearScreen()
{
	// Clearing the current screen
	system("clear");
	return;
}


// FunctloginAsAdminion to cause approximate delay in seconds 
void delay(int number_of_seconds) 
{ 

	for (int i = 0; i < 2000000069*number_of_seconds; ++i)
	{
		continue;
	}
	return;
}


/* Admin verification functions */


int isAdmin(char* username, char* password)
{
	int flag1 = 0, flag2 = 0;

	if(strcmp(username, "thanos") == 0)
	{
		flag1 = 1;
	}

	if(strcmp(password, "infinity") == 0)
	{
		flag2 = 1;
	}

	return flag2 && flag1;
	
}



void loginAsAdmin()
{
	// Clearing the screen before printing stuff
	clearScreen();

	printf("RESTRAUNT MANAGEMENT SYSTEM\n\n");

	// Variables to hld username and password 
	char username[100];
	char password[100];

	// Asking for username and password
	printf("Enter your username : ");
	//scanf("%[^\n]%*c",username);
	scanf("%s", username);

	printf("\nEnter your password : ");
	//scanf("%[^\n]%*c",password);
	scanf("%s", password);


	if( isAdmin(username, password) )
	{
		//todo
		adminMenu();
	}

	else
	{
		printf("\n\nUsername and password entered does not match with the database.\n");
		delay(20);
		printf("Exiting\n");
		delay(5);
		printMainMenu();
	}

	return;
}
