#pragma once
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
typedef char StackType; 
typedef struct SeqStack
{
    StackType* data;
    size_t size;
    size_t capacity;
}SeqStack;

void SeqStackInit(SeqStack* seqstack);

void SeqStackDestroy(SeqStack* seqstack);

void SeqStackPush(SeqStack* seqstack,StackType value);

void SeqStackPop(SeqStack* seqstack);

int SeqStackTop(SeqStack* seqstack,StackType* value);
