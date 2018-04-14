#include "seqstack.h"
#define TEST_HEADER printf("\n======================%s====================\n",__FUNCTION__)
void SeqStackInit(SeqStack* seqstack)
{
    if(seqstack==NULL)
    {
        return;//非法输入
    }
   seqstack->size=0;
   seqstack->capacity=1024;
   seqstack->data=(StackType*)malloc(seqstack->capacity*sizeof(StackType));
}
void SeqStackDestroy(SeqStack* seqstack)
{   
    if(seqstack==NULL)
    {
        return;//非法输入
    }
   seqstack->size=0;
    free(seqstack->data);
}
void SeqStackReSize(SeqStack* seqstack)
{
    if(seqstack==NULL)
    {
        return;
    }
    StackType* new_ptr=NULL;
    if(seqstack->size>=seqstack->capacity)
    {
        new_ptr=(StackType*)malloc(seqstack->capacity*sizeof(StackType)*2+1);
    }
    size_t i=0;
    for(i=0;i<seqstack->size;i++)
    {
        new_ptr[i]=seqstack->data[i];
    }
    free(seqstack->data);
    seqstack->data = new_ptr;
}
void SeqStackPush(SeqStack* seqstack,StackType value)
{
    if(seqstack==NULL)
    {
        return;//非法输入
    }
    if(seqstack->size>=seqstack->capacity)
    {
        SeqStackReSize(seqstack);
    }
    seqstack->data[seqstack->size++]=value;
}
void SeqStackPop(SeqStack* seqstack)
{
    if(seqstack==NULL)
    {
        return;
    }
    if(seqstack->size==0)
    {
        return;
    }
    --seqstack->size;
}

int SeqStackTop(SeqStack* seqstack,StackType* value)
{
    if(seqstack==NULL)
    {
        return 0;
    }
    if(seqstack->size==0)
    {
        return 0;
    }
    *value=seqstack->data[seqstack->size-1];//注意：这里是减一，不能减减
    return 1;
}
void SeqStackPrintChar(SeqStack* seqstack,const char* msg)
{
    printf("%s\n",msg);
    size_t i=0;
    for(;i<seqstack->size;i++)
    {
        printf("[%c] ",seqstack->data[i]);
    }
    printf("\n");
}
///////////////////////////////////////////////////////////////
//以下是测试函数
///////////////////////////////////////////////////////////////
#if 0
void TestInit()
{
    TEST_HEADER;
    SeqStack seqstack;
    SeqStackInit(&seqstack);
    printf("size expect 0,actual %lu\n",seqstack.size);
}
void TestPush()
{
    TEST_HEADER;
    SeqStack seqstack;
    SeqStackInit(&seqstack);
    SeqStackPush(&seqstack,'a');
    SeqStackPush(&seqstack,'b');
    SeqStackPush(&seqstack,'c');
    SeqStackPush(&seqstack,'d');
    SeqStackPrintChar(&seqstack,"入栈四个元素");

}
void TestTop()
{
    TEST_HEADER;
    SeqStack seqstack;
    StackType value;
    SeqStackInit(&seqstack);
    SeqStackPush(&seqstack,'a');
    SeqStackPush(&seqstack,'b');
    SeqStackPush(&seqstack,'c');
    SeqStackPush(&seqstack,'d');
    SeqStackPrintChar(&seqstack,"入栈四个元素");
    int ret=SeqStackTop(&seqstack,&value);
    printf("ret expect 1,actual %d\n",ret);
    printf("top expect d,actual %c\n",value);

    printf("\n");
    SeqStackInit(&seqstack);
    ret=SeqStackTop(&seqstack,&value);
    printf("ret expect 0,actual %d\n",ret);
}
void TestPop()
{
    TEST_HEADER;
    SeqStack seqstack;
    SeqStackInit(&seqstack);
    SeqStackPush(&seqstack,'a');
    SeqStackPush(&seqstack,'b');
    SeqStackPush(&seqstack,'c');
    SeqStackPush(&seqstack,'d');
    SeqStackPrintChar(&seqstack,"入栈四个元素");
    SeqStackPop(&seqstack);
    SeqStackPrintChar(&seqstack,"出栈一个元素");
    SeqStackPop(&seqstack);
    SeqStackPrintChar(&seqstack,"出栈二个元素");
    SeqStackPop(&seqstack);
    SeqStackPrintChar(&seqstack,"出栈三个元素");
    SeqStackPop(&seqstack);
    SeqStackPrintChar(&seqstack,"出栈四个元素");
    SeqStackPop(&seqstack);
    SeqStackPrintChar(&seqstack,"尝试对空栈出栈");
}
void TestDestroy()
{
    TEST_HEADER;
    SeqStack seqstack;
    SeqStackDestroy(&seqstack);
    printf("size expect 0,actual %lu\n",seqstack.size);
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
