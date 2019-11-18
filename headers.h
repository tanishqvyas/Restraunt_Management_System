#include<stdlib.h>
#include<stdio.h>
#include <stdbool.h>
#include<string.h>

// to use getch()
//#include<curses.h>

struct menu
{
	int itemId;
	char itemName[100];
	float itemPrice;
};
typedef struct menu menu;