#include"Itemdatabase.h"
#include<stdlib.h>

#if 1
#define ENABLE_LOG
#endif

//动态存储分配子块大小 
#define CHUNK_SIZE 5

int num_items = 0;//物品总数 
int max_capacity = 0; //物品数据库的最大容量 

//物品数据库
struct Item *item_database = NULL; 

ItemIterator ItemDB_GetFirstItemIterator(void)
{
    ItemIterator iter;
    iter.i = 0;
    return iter;
}

//返回下一个物品的迭代器 
ItemIterator ItemDB_GetNextItemIterator(ItemIterator iter)
{
    ItemIterator iter_next;
    iter_next.i = iter.i+1;
    return iter_next;
}

//检查物品迭代器iter是否有效 
int ItemDB_IsItemIteratorValid(ItemIterator iter)
{
    return iter.i >= 0 && iter.i < num_items;
}

//在数据库中搜索编号为item_number的物品 
//找到返回物品迭代器 
//否则返回一个无效的迭代器 
ItemIterator ItemDB_FindItem(int item_number)
{
    ItemIterator iter;
    int i;
    for(i = 0; i < num_items; i ++)
    {
        if(item_database[i].number == item_number)
        {
            iter.i = i;
            return iter;
        }
    }
    iter.i = -1;
    return iter;
}

int ItemDB_IsEmpty(void)
{
    return !num_items;
}

//返回指向数据库中迭代器iter对应的物品的指针 
struct Item* ItemDB_GetItemPointer(ItemIterator iter)
{
    return item_database + iter.i;
}

//检查数据是否需要扩大容量 
int ItemDB_AddItem(const struct Item *p_item)
{ 
    if(num_items == max_capacity)
    {
        //计算新容量 
        int new_max_capacity = max_capacity + CHUNK_SIZE;
        //扩大数据库容量 
        item_database = (struct Item *)realloc(item_database,new_max_capacity*sizeof(struct Item));

        //检查容量扩大是否成功 
        if(item_database == NULL) return 0;

#ifdef ENABLE_LOG
    printf("数据库容量扩大：%d -> %d\n",max_capacity,new_max_capacity);
#endif 
        //把新容量设置为当前容量 
        max_capacity = new_max_capacity;
    }

    //将p_item指向的物品加入数据库中 
    //将物品存入数据库结尾 
    //成功返回1，否则返回0 
    item_database[num_items] = *p_item;
    ++num_items; //物品总数+1 
    return 1;
}

//将数据库中索引值为item_index的元素删除
void ItemDB_DeleteItem(ItemIterator iter)
{ 
    int j = iter.i;
    while(j < num_items-1)
    {
        item_database[j] = item_database[++j];
    }
    //物品总数-1 
    -- num_items;

    //检查数据库是否需要缩小容量 
    if(num_items == max_capacity - CHUNK_SIZE)
    {

#ifdef ENABLE_LOG
    printf("数据库容量缩小：%d -> %d\n",max_capacity,num_items);
#endif // ENABLE_LOG

        if(num_items == 0)
        {
            //释放数据库存储空间 
            free(item_database);
            item_database = NULL;
            max_capacity = 0;
        }
        else
        {
            //缩小数据库容量 
            item_database = (struct Item *)realloc(item_database,num_items*sizeof(struct Item));
            max_capacity = num_items;
        }
    }
}

void ItemDB_Clear(void)
{
    num_items = 0;
    max_capacity = 0;
    if(item_database != NULL)
    {
        free(item_database);
        item_database = NULL;
    }
}

//返回物品总数
int ItemDB_GetNumItems()
{ 
    return num_items;
}
