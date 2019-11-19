#include "headers.h"



void main()
{
	records* record_head = NULL;
	recordCount* record_count;
	record_count->count = 0;
	record_count->next = NULL;
	menu* head = buildInit();
	printMainMenu(head, record_head, record_count);

}