#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ITEM_NAME_MAX_LEN 64

struct Item {
    int number;
    char name[ITEM_NAME_MAX_LEN + 1];
    int quantity;
};

#define MAX_NUM_ITEMS 1000

extern struct Item item_database[MAX_NUM_ITEMS];
extern int num_items;


int ReadLine(char* str, int max_size);
int ItemDB_FindItem(int item_number);
int ItemDB_IsFull(void);
int ItemDB_IsEmpty(void);
void ItemDB_AddItem(const struct Item* p_item);
void ItemDB_DeleteItem(int item_index);
struct Item* ItemDB_GetItemPointer(int item_index);
void ItemDB_Clear(void);
int ItemDB_GetNumItems(void);
void UI_AddItem(void);
void UI_DeleteItem(void);
void UI_SearchItem(void);
void UI_UpdateItem(void);
void UI_ClearDatabase(void);
void UI_PrintDatabase(void);
