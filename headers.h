#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>
#include <time.h> 
#include<unistd.h>
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


struct myOrder
{
	int itemId;
	char itemName[100];
	float itemPrice;
	int quantity;
	struct myOrder* next;	
};
typedef struct myOrder myOrder;


struct records
{
	char customerName[30];
	float totalBill;
	struct order* myOrder;
};
typedef struct records records;


menu* buildMenuCard();


/* MENU Functions */
void printMainMenu(menu* head);
void adminMenu(menu* head);
void customerMenu(menu* head);



/* UTILITIES */
void clearScreen();
void delay(int number_of_seconds);

int isAdmin(char* username, char* password);
void loginAsAdmin(menu* head);



/* Admin functions */
menu* create_dish(int dishID, char* name, int cost);
void addDish(menu* head);
void removeDish(menu* head);
menu* insert_dish(menu* head, menu* dish);
void showMenu(menu* head);

/* customer functions */
void placeOrder(menu* head);
float fetch_price(menu* head, float id);
char fetch_dishname(menu* head, float id);