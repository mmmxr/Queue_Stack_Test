#include "seqqueue.h"
#define TEST_HEADER printf("\n===================%s====================\n",__FUNCTION__)

void SeqQueueInit(SeqQueue *sq)
{
    if(sq==NULL)
    {
        return;//非法输入
    }
    sq->size=0;
    sq->head=0;
    sq->tail=0;
}
void SeqQueuePush(SeqQueue *sq,SeqQueType value)
{
    if(sq==NULL)
    {
        return;//非法输入
    }
    if(sq->size>=MaxSize)
    {
        return;//队列满了
    }
    if(sq->size==0)
    {
        //空队列
        sq->data[sq->head]=value;
        sq->tail++;
        sq->size++;
    }
    else
    {
        sq->data[sq->tail]=value;
        sq->tail++;
        sq->size++;
    }
    if(sq->tail>=MaxSize)
    {
        sq->tail=0;
    }
}

void SeqQueuePop(SeqQueue *sq)
{
    if(sq==NULL)
    {
        return;
    }
    if(sq->size==0)
    {
        return;//空队列
    }

    ++sq->head;
    if(sq->head>=MaxSize)
    {
        sq->head=0;
    }
    --sq->size;
}
int  SeqQueueTop(SeqQueue *sq,SeqQueType* value)
{
    if(sq==NULL)
    {
        return 0;
    }
    if(sq->size==0)
    {
        return 0;
    }
    *value=sq->data[sq->head];
    return 1;
}

void SeqQueueDestroy(SeqQueue *sq)
{
    if(sq==NULL)
    {
        return;
    }
    sq->head=0;
    sq->tail=0;
    sq->size=0;
}
///////////////////////////////////////////////
//以下是测试函数·
///////////////////////////////////////////////
void SeqQueuePrintChar(SeqQueue *sq,const char* msg)
{
    if(sq==NULL)
    {
        return;
    }
    printf("%s\n",msg);
    size_t i=sq->head;
    for(;i!=sq->tail;i++)
    {
        if(i>=MaxSize)
        {
            i=0;
        }
        printf("[%c] ",sq->data[i]);
    }
    printf("\n");
}
#if 0
void TestInit()
{
    TEST_HEADER;
    SeqQueue sq;
    SeqQueueInit(&sq);
    printf("size expect 0,actual %lu\n",sq.size);
}
void TestPush()
{
    TEST_HEADER;
    SeqQueue sq;
    SeqQueueInit(&sq);
    SeqQueuePush(&sq,'a');
    SeqQueuePush(&sq,'b');
    SeqQueuePush(&sq,'c');
    SeqQueuePush(&sq,'d');
    SeqQueuePrintChar(&sq,"入队列四个元素");
}
void TestPop()
{
    TEST_HEADER;
    SeqQueue sq;
    SeqQueueInit(&sq);
    SeqQueuePush(&sq,'a');
    SeqQueuePush(&sq,'b');
    SeqQueuePush(&sq,'c');
    SeqQueuePush(&sq,'d');
    SeqQueuePrintChar(&sq,"入队列四个元素");
    SeqQueuePop(&sq);
    SeqQueuePrintChar(&sq,"出队列一个元素");
    SeqQueuePop(&sq);
    SeqQueuePrintChar(&sq,"出队列二个元素");
    SeqQueuePop(&sq);
    SeqQueuePrintChar(&sq,"出队列三个元素");
    SeqQueuePop(&sq);
    SeqQueuePrintChar(&sq,"出队列四个元素");
    SeqQueuePop(&sq);
    SeqQueuePrintChar(&sq,"尝试对空队列出队列");
}
void TestTop()
{
    TEST_HEADER;
    SeqQueue sq;
    SeqQueType value;
    SeqQueueInit(&sq);
    SeqQueuePush(&sq,'a');
    SeqQueuePush(&sq,'b');
    SeqQueuePush(&sq,'c');
    SeqQueuePush(&sq,'d');
    SeqQueuePrintChar(&sq,"入队列四个元素");
    printf("取队首元素\n");
    int ret=SeqQueueTop(&sq,&value);
    printf("ret expect 1,actual %d\n",ret);
    printf("value expect a,actual %c\n",value);
    printf("尝试对空队列取队首元素\n");
    SeqQueueInit(&sq);
    ret=SeqQueueTop(&sq,&value);
    printf("ret expect 0,actual %d\n",ret);
}
void TestDestroy()
{
    TEST_HEADER;
    SeqQueue sq;
    SeqQueueInit(&sq);
    SeqQueuePush(&sq,'a');
    SeqQueuePush(&sq,'b');
    SeqQueuePush(&sq,'c');
    SeqQueuePush(&sq,'d');
    SeqQueuePrintChar(&sq,"入队列四个元素");
    SeqQueueDestroy(&sq);
    SeqQueuePrintChar(&sq,"销毁队列");
    printf("size expect 0,actual %lu\n",sq.size);
}
int main()
{
    TestInit();
    TestPush();
    TestPop();
    TestTop();
    TestDestroy();
    return 0;
}
#endif
