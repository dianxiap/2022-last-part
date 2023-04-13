#ifndef ITEMDATABASE_H_INCLUDED
#define ITEMDATABASE_H_INCLUDED

#define ITEM_NAME_MAX_LEN 64//物品名称的最大长度 


struct Item
{
	int number;//编号 
	char name[ITEM_NAME_MAX_LEN + 1];//名称 
	int quantity; //数量 
};

//物品迭代器 
typedef struct
{
	int i;//物品在数组中的索引 
}ItemIterator;

//返回第一个物品的迭代器 
ItemIterator ItemDB_GetFirstItemIterator(void);

//返回下一个物品的迭代器 
ItemIterator ItemDB_GetNextItemIterator(ItemIterator iter);

//检查物品迭代器iter是否有效，有效则返回1，否则返回0 
int ItemDB_IsItemIteratorValid(ItemIterator iter);

//在数据库中搜索编号为item_number的物品 
//找到返回物品迭代器 
//否则返回一个无效的迭代器 
ItemIterator ItemDB_FindItem(int item_number);

int ItemDB_IsEmpty(void);

//返回指向数据库中迭代器iter对应的物品的指针 
struct Item* ItemDB_GetItemPointer(ItemIterator iter);

//将p_item指向的物品加入数据库中 
//将物品存入数据库结尾 
//成功返回1，否则返回0 
int ItemDB_AddItem(const struct Item* p_item);

//将数据库中迭代器iter对应的物品删除 
//物品总数-1 
void ItemDB_DeleteItem(ItemIterator iter);

//清除数据库 
void ItemDB_Clear(void);

int ItemDB_GetNumItems();

#endif 
