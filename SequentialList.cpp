//顺序表
//基本操作：创建销毁，初始化，增删改查
#include <iostream>
#include <stdlib.h>
using namespace std;

//静态方法实现
#define MAXSIZE 100   //定义宏 ， 后面不能加逗号

typedef int ElemType;   //将int 定义为ElemType    typedef：类型定义
typedef int Status;

typedef struct {
	ElemType Data[MAXSIZE];
	ElemType length;
}Seqlist;

//动态方法实现
//#define  InitSize 10
//typedef int ElemType;
//
//typedef struct SeqList {
//	ElemType* elem;
//	int length;
//	int MaxSize;
//}SeqList;
//
////初始化顺序表
//void InitSeqList(SeqList &L) {
//	L.elem = (ElemType*)malloc(sizeof(ElemType) * InitSize);
//	L.elem = new ElemType[InitSize];   //C++动态分配
//	L.length = 0;
//	L.MaxSize = InitSize;
//
//}
//
////增加动态数组的长度
//void IncreaseSize(SeqList &L, int len) {
//	ElemType* p = L.elem;  //新建指针指向数组首部
//	L.elem = (ElemType*)malloc(sizeof(ElemType) * (L.MaxSize + len));  //在别处开辟(MaxSize+len)*sizeof(ElemType)连续的空间
//	for (int i = 0; i < L.length; i++) {
//		L.elem[i] = p[i];
//	}
//	L.MaxSize += len;
//	free(p);
//}

//初始化顺序表
Status InitSeqList(Seqlist &L) {
	for (int i = 0; i < MAXSIZE; i++) {
		L.Data[i] = 0;
	}
	if (!L.Data)
		exit(OVERFLOW);
	L.length = 0;
	return true;
}

//在顺序表中输入数据
Status InputSeqlist(Seqlist &L) {
	int j, i;
	printf("请输入顺序表的元素个数\n");
	cin >> i;
	for (j = 0; j < i; j++)
	{
		cin >> L.Data[j];
		L.length++;
	}
	return 0;
}
//按位序查找
Status GetElemValueById(Seqlist &L, ElemType i) {
	return L.Data[i-1];
}

//按值查找
Status GetElemValueByValue(Seqlist &L, ElemType &e) {
	for (int i = 0; i < L.length; i++) {
		if (L.Data[i] == e) {
			return i + 1;
		}
	}
	return -1;
}


//插入
bool Insert(Seqlist &L, ElemType i, ElemType e) {
	if (i<1 || i>L.length + 1) {
		return false;
	}
	for (int j = L.length; j >= i; j--) {
		L.Data[j] = L.Data[j - 1];
	}	
	L.Data[i - 1] = e;	
  L.length++;   //一定要记住 长度加一
	return true;
}


//删除
bool Delete(Seqlist &L, ElemType i) {
	if (i<1 || i>L.length) {
		return false;
	}
	for (int j = i; j < L.length; j++) {
		L.Data[j-1] = L.Data[j];
	}
	L.length--;   //一定要记住 长度减一
	return true;
}

//输出顺序表所有元素
void GetElemValue(Seqlist &L) {
	for (int i = 0; i < L.length; i++) {
		cout << L.Data[i] << " ";
	}
	cout << endl;
}
//
//void Menu()//菜单函数
//{
//	cout << "1.建立\n";
//	cout << "2.输入\n";
//	cout << "3.查找\n";
//	cout << "4.插入\n";
//	cout << "5.删除\n";
//	cout << "6.输出\n";
//	cout << "0.退出\n";
//	printf("请输入你想要选择的选项：\n");
//
//}
//
//int main() {
//	void Menu();
//	int a, e, choose;
//	Seqlist L;
//	Menu();
//	choose = -1;
//	while (choose != 0)
//	{
//		cin >> choose;
//		switch (choose)
//		{
//		case 1: //建立一个顺序表
//			if (InitSeqList(L))
//				cout << "成功建立顺序表!\n\n";
//			Menu();
//			printf("\n");
//			break;
//
//		case 2://往顺序表中输入数据
//			InputSeqlist(L);
//			printf("输入数据完毕\n");
//			printf("\n");
//			Menu();
//			break;
//
//		case 3://查找顺序表中的值
//			printf("请输入你想要查找的数值\n");
//			cin >> e;
//			if (GetElemValueByValue(L, e)) {
//				cout << "数据的位置为：" << GetElemValueByValue(L, e) << endl;
//			}
//			else {
//				cout << "查找失败" << endl;
//			}
//			Menu();
//			printf("\n");
//			break;
//
//		case 4://在顺序表中插入数据
//			printf("请输入你要输入的位置和数据\n");
//			cin >> a >> e;
//			if (Insert(L, a, e))
//				cout << "插入成功.\n\n";
//			else
//				cout << "插入失败!\n\n";
//			Menu();
//			printf("\n");
//			break;
//
//		case 5://删除顺序表中的数据
//			cout << "请输入所要删除的数据的位置:";
//			cin >> a;
//			if (Delete(L, a))
//				cout << "删除成功!\n\n";
//			else
//				cout << "删除失败!\n\n";
//			Menu();
//			printf("\n");
//			break;
//
//		case 6://将顺序表中的数据全部显示出来
//			GetElemValue(L);
//			Menu();
//			printf("\n");
//			break;
//		}
//		printf("\n");
//	}
//	return 0;
//}

