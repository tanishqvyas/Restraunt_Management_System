#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>
#include <time.h> 

#include<string.h>

// to use getch()
//#include<curses.h>

struct menu
{
	int itemId;
	char itemName[100];
	float itemPrice;

	struct menu* next;
};
typedef struct menu menu;




/* MENU Functions */
void printMainMenu();
void adminMenu();
void customerMenu();



/* UTILITIES */
void clearScreen();
void delay(int number_of_seconds);

int isAdmin(char* username, char* password);
void loginAsAdmin();