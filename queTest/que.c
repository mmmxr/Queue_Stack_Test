#include <stdio.h>
#include "seqqueue.h"
//用两个队列实现一个栈
typedef struct Stackby2que
{
    SeqQueue que1;
    SeqQueue que2;
}Stackby2que;
void Stackby2quePush(Stackby2que* s,SeqQueType value)
{
    if(s==NULL)
    {
        return;
    }
    if(s->que1.size!=0)
    {
        SeqQueuePush(&s->que1,value);
    }
    else
    {
        SeqQueuePush(&s->que2,value);
    }
}
void Stackby2quePop(Stackby2que* s)
{
    if(s==NULL)
    {
        return;
    }
    if(s->que1.size==0&&s->que2.size==0)
    {
        return;
    }
    if(s->que1.size!=0)
    {
        SeqQueType top;
        while(s->que1.size!=1)
        {
            SeqQueueTop(&s->que1,&top);
            SeqQueuePop(&s->que1);
            SeqQueuePush(&s->que2,top);
        }
        SeqQueuePop(&s->que1);
    }
    else if(s->que2.size!=0)
    {
        SeqQueType top;
        while(s->que2.size!=1)
        {
            SeqQueueTop(&s->que2,&top);
            SeqQueuePop(&s->que2);
            SeqQueuePush(&s->que1,top);
        }
        SeqQueuePop(&s->que2);
    }
}
int Stackby2queTop(Stackby2que* s,SeqQueType* value)
{
    if(s==NULL||value==NULL)
    {
        return 0;
    }
    if(s->que1.size==0&&s->que2.size==0)
    {
        return 0;
    }
    if(s->que1.size!=0)
    {
        while(1)
        {
            SeqQueueTop(&s->que1,value);
            SeqQueuePush(&s->que2,*value);
            SeqQueuePop(&s->que1);
            if(s->que1.size==0)
            {
                return 1;
            }
        }
    }
    else if(s->que2.size!=0)
    {
        while(1)
        {
            SeqQueueTop(&s->que2,value);
            SeqQueuePush(&s->que1,*value);
            SeqQueuePop(&s->que2);
            if(s->que2.size==0)
            {
                return 1;
            }
        }
    }
    return 0;
}
/////////////////////////////////////////////
//测试
////////////////////////////////////////////
void Stackby2quePrint(Stackby2que* s,const char* msg)
{
    printf("%s\n",msg);
    if(s->que1.size!=0)
    {
        size_t i=s->que1.head;
        for(;i!=s->que1.tail;i++)
        {
            if(i>=MaxSize)
            {
                i=0;
            }
            printf("[%c] ",s->que1.data[i]);
        }
        printf("\n");
    }
    else if(s->que2.size!=0)
    {
        size_t i=s->que2.head;
        for(;i!=s->que2.tail;i++)
        {
            if(i>=MaxSize)
            {
                i=0;
            }
            printf("[%c] ",s->que2.data[i]);
        }
        printf("\n");
    }
}

void TestStackby2que()
{
    Stackby2que s;
    SeqQueType value;
    SeqQueueInit(&s.que1);
    SeqQueueInit(&s.que2);
    Stackby2quePush(&s,'a');
    Stackby2quePush(&s,'b');
    Stackby2quePush(&s,'c');
    Stackby2quePush(&s,'d');
    Stackby2quePrint(&s,"入栈");
    Stackby2queTop(&s,&value);
    printf("top expect d,actual %c\n",value);
    Stackby2quePop(&s);
    Stackby2quePrint(&s,"出栈");
    Stackby2quePop(&s);
    Stackby2quePrint(&s,"出栈");
    Stackby2queTop(&s,&value);
    printf("top expect b,actual %c\n",value);

}
int main()
{
    TestStackby2que();
    return 0;
}
