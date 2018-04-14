#include "seqstack.h"
#include <string.h>

//实现一个栈要求，出栈入栈，返回最小值的时间复杂度是O(1)
typedef struct min_stack
{
    SeqStack stack; 
}min_stack;
void MinStackPush(min_stack* s,StackType value)
{
    if(s==NULL)
    {
        return;
    }
    StackType n;
    StackType min=value;
    int ret=SeqStackTop(&s->stack,&n);
    if(ret==0)
    {
        SeqStackPush(&s->stack,value);
        SeqStackPush(&s->stack,min);
        return;
    }
    if(value>n)
    {
        min=n;    
    }
    SeqStackPush(&s->stack,value);
    SeqStackPush(&s->stack,min);
}
void MinStackPop(min_stack* s)
{
    if(s==NULL)
    {
        return;
    }
    if(s->stack.size==0)
    {
        return;
    }
    SeqStackPop(&s->stack);
    SeqStackPop(&s->stack);
}
int MinStackTop(min_stack* s,StackType* value)
{
    if(s==NULL)
    {
        return 0;
    }
    if(s->stack.size==0)
    {
        return 0;
    }
    SeqStackTop(&s->stack,value);
    return 1;
}
//使用两个栈实现一个队列

typedef struct Queby2stack
{
    SeqStack input;
    SeqStack output;

}Queby2stack;

void Queueby2stackPush(Queby2stack* q,StackType value)
{
    if(q==NULL)
    {
        return;//非法输入
    }
    StackType top;
    while(q->output.size!=0)
    {
        SeqStackTop(&q->output,&top);
        SeqStackPop(&q->output);
        SeqStackPush(&q->input,top);
    }
    SeqStackPush(&q->input,value);
    while(q->input.size!=0)
    {
        SeqStackTop(&q->input,&top);
        SeqStackPop(&q->input);
        SeqStackPush(&q->output,top);
    }
}
void Queby2stackPop(Queby2stack* q)
{
    if(q==NULL)
    {
        return;
    }
    if(q->output.size==0)
    {
        return;
    }
    SeqStackPop(&q->output);
}

int Queby2stackTop(Queby2stack* q,StackType* value)
{
    if(q==NULL)
    {
        return 0;
    }
    if(q->output.size==0)
    {
        return 0;
    }
    SeqStackTop(&q->output,value);
    return 1;
}

int StackCorrect(SeqStack* stack,char* str1,char *str2,int len)
{
    if(stack==NULL||str1==NULL||str2==NULL)
    {
        return 0;
    }
    int i=0;
    for(;i<len;i++)
    {
        //入栈一个元素，取栈顶元素与比较序列的元素比较
        StackType top;
        SeqStackPush(stack,*str1);
        SeqStackTop(stack,&top);
        while(top==*str2)
        {
            //如果栈顶元素与比较序列相等，就出栈，然后比较下一个
            SeqStackPop(stack);
            SeqStackTop(stack,&top);
            str2++;
        }
        str1++;
    }
    if(*str2=='\0')
    {
        return 1;
    }
    return 0;
}
///////////////////////////////////////
//测试函数
///////////////////////////////////////
void TestStackCorrect()
{
    SeqStack stack;
    SeqStackInit(&stack);
    char str1[]="abcde";
    char str2[]="bcdea";
    char str3[]="ceabd";
    int len=strlen(str1);

    int ret=StackCorrect(&stack,str1,str2,len);
    printf("ret expect 1,actual %d\n",ret);
    ret=StackCorrect(&stack,str1,str3,len);
    printf("ret expect 0,actual %d\n",ret);

}
void Queby2stackPrint(Queby2stack* q,const char* msg)
{
    printf("%s\n",msg);
    size_t i=0;
    for(;i<q->output.size;i++)
    {
        printf("[%c] ",q->output.data[i]);
    }
    printf("\n");
}
void TestQueby2stack()
{
    Queby2stack q;
    StackType value;
    SeqStackInit(&q.input);
    SeqStackInit(&q.output);
    Queueby2stackPush(&q,'a');
    Queueby2stackPush(&q,'b');
    Queueby2stackPush(&q,'c');
    Queueby2stackPush(&q,'d');
    Queby2stackPrint(&q,"入队列");
    Queby2stackTop(&q,&value);
    printf("top expect a,actual %c\n",value);
    Queby2stackPop(&q);
    Queby2stackPop(&q);
    Queby2stackPrint(&q,"出队列");
    Queby2stackTop(&q,&value);
    printf("top expect c,actual %c\n",value);
    
}

void TestMin()
{
    min_stack s;
    StackType value;
    SeqStackInit(&s.stack);
    MinStackPush(&s,'d');
    int ret=MinStackTop(&s,&value);
    printf("ret expect 1,actual %d\n",ret);
    printf("top expect d,actual %c\n",value);
    MinStackPush(&s,'c');
    MinStackPush(&s,'b');
    MinStackPush(&s,'a');
    ret=MinStackTop(&s,&value);
    printf("ret expect 1,actual %d\n",ret);
    printf("top expect a,actual %c\n",value);
    MinStackPop(&s);
    ret=MinStackTop(&s,&value);
    printf("ret expect 1,actual %d\n",ret);
    printf("top expect b,actual %c\n",value);

}
int main()
{
//    TestMin();
//    TestQueby2stack();
    TestStackCorrect();
}
