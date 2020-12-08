//单链表
//基本操作： 初始化
//建立（头插法，尾插法）
//初始化，增删改查

#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct LNode
{
	ElemType Data;
	struct LNode* next;
}LNode,*LinkList;

//初始化
//bool InitLinkList(LinkList& L) {  //不带头结点的单链表
//	L = NULL;  //空表，暂时没有任何结点
//	return true;
//}

bool InitLinkList(LinkList& L) {  //带头结点的单链表
	L = (LNode*)malloc(sizeof(LNode)); //生成一个头结点
	if (L == NULL) {    //内存不足，分配失败
		return false;
	}
	L->next = NULL;  //头结点之后暂时没有任何结点
	return true;
}


//判断单链表是否为空
bool IsEmpty(LinkList L) {
	return L == NULL;
}

//单链表的建立（头插法）
bool CreateLinkList_H(LinkList& L, int n) {
	L = new LNode;
	L->next = NULL;  //创建一个带头结点的空链表
	for (int i = 0; i < n; i++) {
		LNode* p = new LNode;   //新建一个结点
		cin >> p->Data;

		p->next = L->next;  //头结点后插入新结点
		L->next = p;		
	}
	return true;
 }


//单链表的建立（尾插法）   设置一个表尾指针
bool CreateLinkList_R(LinkList& L,int n) {
	L = new LNode;
	L->next = NULL;
	LNode* r = new LNode;
	r = L;   //尾结点指向头结点
	for (int i = 0; i < n; i++) {
		LNode* p = new LNode;  //生成新结点
		cin >> p->Data;

		p->next = NULL;  //将新结点插入最后面
		r->next = p;

		r = p;  //将尾结点指向最后面的结点，始终保持是尾结点
	}
	return true;
}

// 链表插入
bool InsertLinkList(LinkList& L, int i, ElemType e) {
	LNode*p = new LNode;  //生成新结点
	p = L; //新结点指向头结点
	int j = 0;
	while (p != NULL && j < i-1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL) {
		return false;
	}
	LNode* q = new LNode;
	q->next = p->next;
	p->next = q;
	q->Data = e;
	return true;
}

// 链表删除
bool DeleteLinkList(LinkList& L, int i) {
	LNode* p = new LNode;  //生成新结点
	p = L; //新结点指向头结点
	int j = 0;
	while ( p->next && j < i - 1)  //p->next 而不是 p ，如果是p 的话，return false，跳出循环
	{
		p = p->next;
		j++;
	}
	if (p == NULL) {
		return false;
	}
	LNode* q = new LNode;  //生成一个新的结点
	q = p->next;   //指向p 后面的一个结点，即要删除的结点
	p->next = q->next;  //p的后继为 q的后继  ，即 p后面两个的结点
	delete q;     //结束时释放
	return true;
}


//取值
ElemType GetElem(LinkList& L, int i,ElemType& e) {
	LNode* p = new LNode;
	p = L;
	int j = 1;
	while (p && j < i) {
		p = p->next;
		j++;
	}
	e = p->Data;
	if (!p || j > i)
		return false;
	return e;
}

//查找   返回的是一个结点
LNode* LocateElem(LinkList& L, ElemType e) {
	LNode* p = new LNode;
	p = L->next;
	while (p && p->Data != e) {
		p = p->next;
	}
	return p;
}

//显示链表所有结点信息
void Display(LinkList& L) {
	LNode* p = new LNode;
	p = L->next;    //结点指向头结点的后一个结点，也就是第一个有数的结点
	while (p) {
		cout << p->Data << " ";
		p = p->next;		
	}
	cout << endl;
}



void Menu()//菜单函数
{
	cout << "1.建立\n";
	cout << "2.输入\n";
	cout << "3.查找\n";
	cout << "4.插入\n";
	cout << "5.删除\n";
	cout << "6.输出\n";
	cout << "0.退出\n";
	printf("请输入你想要选择的选项：\n");

}

int main() {
	void Menu();
	int a, e, choose;
	LinkList L;
	Menu();
	choose = -1;
	while (choose != 0)
	{
		cin >> choose;
		switch (choose)
		{
		case 1: //建立一个单链表
			if (CreateLinkList_H(L,5))
				cout << "成功建立顺序表!\n\n";
			Menu();
			printf("\n");
			break;

		case 2://往顺序表中输入数据
			(L);
			printf("输入数据完毕\n");
			printf("\n");
			Menu();
			break;

		case 3://查找顺序表中的值
			printf("请输入你想要查找的数值\n");
			cin >> e;
			if (LocateElem(L, e)) {
				cout << "数据的位置为：" << LocateElem(L, e) << endl;
			}
			else {
				cout << "查找失败" << endl;
			}
			Menu();
			printf("\n");
			break;

		case 4://在顺序表中插入数据
			printf("请输入你要输入的位置和数据\n");
			cin >> a >> e;
			if (InsertLinkList(L, a, e))
				cout << "插入成功.\n\n";
			else
				cout << "插入失败!\n\n";
			Menu();
			printf("\n");
			break;

		case 5://删除顺序表中的数据
			cout << "请输入所要删除的数据的位置:";
			cin >> a;
			if (DeleteLinkList(L, a))
				cout << "删除成功!\n\n";
			else
				cout << "删除失败!\n\n";
			Menu();
			printf("\n");
			break;

		case 6://将顺序表中的数据全部显示出来
			Display(L);
			Menu();
			printf("\n");
			break;
		}
		printf("\n");
	}
	return 0;
}