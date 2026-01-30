#include<stdio.h>
#include<stdlib.h>

// 利用顺序表进行实现循环队列，对于链式存储，不会存在溢出的情况
// 该存储数据的逻辑的方式是为了：解决上次要进行移动，挪动的问题

// 循环队列的最基本的区别是：front 与 rear 的相关指针的移动。

// 判断是否为满队列 ：(rear+1)%MaxSize == front;

// 判断是否为空队列： （rear==front）;

// 入队相关的指针移动： rear =（rear+1）%Maxsize;

// 出队相关的指针移动：front = (front+1)% Maxsize;


#define Maxsize 5
typedef int Mytype;

typedef struct
{
	Mytype arr[Maxsize];
	int rear ;
	int front;
}Queen;
// 1:初始化:
void Init_Queen(Queen* p)
{
	p->front = 0;
	p->rear = 0;
}
// 2:判空？
void Check_Queen(Queen* p)
{
	if (p->front==p->rear)
	{
		printf("此时的队列为空队列\n");
	}
}
// 3:出队：
void Get_Queen(Queen* p)
{
	printf("出队元素：%d\n", p->arr[p->front]);
	p->front = (p->front + 1)%Maxsize;
}

// 4: 入队：
void Add_Queen(Queen* p,Mytype num)
{
	if ((p->rear + 1) % Maxsize == p->front)
	{
		printf("入队失败，此时队列为满队列！\n");
		return 0;
	}
	p->arr[p->rear] = num;
	p->rear = (p->rear + 1) % Maxsize;
	printf("入队列成功！\n");
}

int main()
{
	Queen run;
	Init_Queen(&run);
	Check_Queen(&run);
	Add_Queen(&run,1);
	Add_Queen(&run,0);
	Add_Queen(&run,2);
	Add_Queen(&run,8);
	Add_Queen(&run,2);
	Get_Queen(&run);
	Add_Queen(&run, 2);
	return 0;
}
