#pragma once
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
typedef char SeqQueType;
#define MaxSize 100
typedef struct SeqQueue{
    SeqQueType data[MaxSize];
    size_t size;
    size_t head;
    size_t tail;
}SeqQueue;

void SeqQueueInit(SeqQueue *sq);
void SeqQueuePush(SeqQueue *sq,SeqQueType value);//尾插
void SeqQueuePop(SeqQueue *sq);//头删
int  SeqQueueTop(SeqQueue *sq,SeqQueType* value);
void SeqQueueDestroy(SeqQueue *sq);
