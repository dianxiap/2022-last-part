#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDataType;  //可以是int，double，结构体，按照要求来
#define INIT_CAPACITY 4  //初始化大小为4

typedef struct Seqlist
{
	SLDataType* a;   //指向存放数据的每一个内存空间
	int size;        //有效数据个数
	int capacity;    //空间容量
}SL;

//初始化
void SLInit(SL* pc);
//销毁
void SLDestory(SL* pc);
//打印
void SLPrint(SL* pc);
//尾插
void SLPushBack(SL* pc,SLDataType x);
//尾删
void SLPopBakc(SL* pc);
//头插
void SLPushFront(SL* pc);
//头删
void SLPopFront(SL* pc);