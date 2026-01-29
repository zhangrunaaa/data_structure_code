#include<stdio.h>
#include<stdlib.h>

#define Maxsize 100
typedef int Mytype;

typedef struct
{
	Mytype arr[Maxsize]; // 利用顺序表进行实现栈
	int top; // 下标，用来指向数组中的相关元素
}Stack;

// 1: 初始化栈的结构 
void Stack_Init(Stack* p)
{
	p->top = -1;
}

// 2：进栈
void Add_Stack(Stack* p,Mytype num)
{
	if (p->top == Maxsize - 1)
	{
		printf("栈满！\n");
	}
	else
	{
		p->top++;
		p->arr[p->top] = num;
	}
}
//3: 出栈
void Pop_Stack(Stack* p)
{
	if (p->top == -1)
	{
		printf("此栈中无元素\n");
	}
	else
	{
		printf("此时栈顶的元素为%d\n",p->arr[p->top]);
		p->top = p->top--;
	}
}
// 4: 获取栈顶元素：
void Stack_Get_num(Stack* p)
{
	printf("栈顶元素为%d\n", p->arr[p->top]);
}
void Stack_check(Stack* p)
{
	if (p->top == -1)
	{
		printf("此栈为空栈\n");
	}
}
int main()
{
	Stack p;
	Stack_Init(&p);
	Stack_check(&p);
	Add_Stack(&p,1);
	Add_Stack(&p,0);
	Add_Stack(&p,2);
	Add_Stack(&p,8);
	Stack_Get_num(&p);
	Pop_Stack(&p);
	Pop_Stack(&p);
	Pop_Stack(&p);
	Stack_Get_num(&p);
	return 0;
}
