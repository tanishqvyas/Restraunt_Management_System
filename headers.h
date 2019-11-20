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
	struct recordCount* next;
};
typedef struct recordCount recordCount;


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
void printMainMenu(menu* head, records* record_head, recordCount* record_count);
void adminMenu(menu* head,records* record_head, recordCount* record_count);
void customerMenu(menu* head, records* record_head, recordCount* record_count);



/* UTILITIES */
void clearScreen();
void delay(int number_of_seconds);

int isAdmin(char* username, char* password);
void loginAsAdmin(menu* head, records* record_head, recordCount* record_count);



/* Admin functions */
menu* create_dish(int dishID, char* name, int cost);
void addDish(menu* head);
menu* removeDish(menu* head);
menu* insert_dish(menu* head, menu* dish);
void showMenu(menu* head);

/* customer functions */
int is_New_customer(records* record, char* name, recordCount* record_count);
records* placeOrder(menu* head, records* record_head, recordCount* record_count);
float fetch_price(menu* head, int id);
char* fetch_dishname(menu* head, int id);
records* create_record(myOrder* head, char* name, float bill);
records* insert_record(records* order, records* new_order);
void display_orders(myOrder* order);
void display_records(records* record, recordCount* record_count);
myOrder* create_order(int id, char* dish_name, int cost, int qty);
myOrder* insert_order(myOrder* head, myOrder* new_order);