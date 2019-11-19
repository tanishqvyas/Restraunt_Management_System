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


struct recordCount
{
	int count;
};
typedef struct recordCount* recordCount;


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
	struct myOrder* order;
	struct records* next;
};
typedef struct records records;


menu* buildInit();


/* MENU Functions */
void printMainMenu(menu* head, records* record_head);
void adminMenu(menu* head,records* record_head);
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
void placeOrder(menu* head, records* record_head);
float fetch_price(menu* head, int id);
char fetch_dishname(menu* head, int id);