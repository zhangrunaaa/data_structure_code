#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
typedef int Mytype;

typedef struct
{
	Mytype arr[MaxSize]; // 用来代表整个整个数组的最大长度
	Mytype length;  // 这里用来代表的是整个列表的长度
}List;

// 1:初始化顺序表
void List_init(List* p)
{
	p->length = 0; // 初始化即是将数组的长度 = 0;
}
// 2：遍历整个顺序表的相关内容
void Print_List(List* p)
{
	for (int i = 0; i < p->length; i++)
	{
		printf("%d ", p->arr[i]);
	}
}
// 3：查找相关元素:输入要查找的位置的相关信息，返回在该列表中的数值
void Check(List* p,int postion)
{
	if (postion > p->length)
	{
		return -1;
	}
	else if (postion < p->length && postion >= 0)
	{
		printf("%d", p->arr[postion - 1]);
	}
}
// 4： 在具体的位置上进行增加元素
int  Add_goal_num(List* p,int postion,int num) // 列表的的指针、位置信息、以及要添加的元素
{
	if (postion > p->length)
	{
		return -1; // 此时代表无法插入相关的信息
	}
	else if(postion<=p->length)
	{
		for (int i = p->length-1; i>=postion-1; i--) // 注意：这个地方：与正向的循环是不一样的： i>postion，当i++的时候与条件等效，但是i--不同，会少一次相关的循环
		{
			p->arr[i+1] = p->arr[i];
		}
		p->arr[postion-1] = num;
		p->length++;
	}
}
// 5: 删除：给到具体的位置信息，然后进行删除，返回被删除的数值信息
void Delete_num(List* p, int postion)
{
	Mytype num = p->arr[postion - 1]; // 返回要删除的相关元素
	for (int i = postion - 1; i < p->length-1; i++)
	{
		p->arr[i] = p->arr[i+1]; // 将要删除的位置的元素进行往前面进行覆盖的操作
	}
	p->length--;
	printf("%d\n", num);
}
// 6: 因本身顺序表的问题，只能按照固定的顺序进行插入的相关操作。
void Add_Num(List* p,Mytype num)
{
	p->arr[p->length] = num;
	p->length++;
}

// 定义的相关函数全部实现：
int main()
{
	List node;
	List_init(&node);
	Add_Num(&node,1);
	Add_Num(&node,0);
	Add_Num(&node,2);
	Add_Num(&node,8);
	printf("遍历：\n");
	Print_List(&node);
	printf("\n");
	printf("在目标位置上进行插入相关元素：\n");
	Add_goal_num(&node, 2, 9);
	Print_List(&node);
	printf("\n");
	printf("删除目标位置的相关元素:\n");
	Delete_num(&node, 2); 
	Print_List(&node);
	printf("\n");
	printf("查找目标位置的元素:\n");
	Check(&node, 2);
}
