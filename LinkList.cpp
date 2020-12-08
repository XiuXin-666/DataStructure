//������
//���������� ��ʼ��
//������ͷ�巨��β�巨��
//��ʼ������ɾ�Ĳ�

#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct LNode
{
	ElemType Data;
	struct LNode* next;
}LNode,*LinkList;

//��ʼ��
//bool InitLinkList(LinkList& L) {  //����ͷ���ĵ�����
//	L = NULL;  //�ձ���ʱû���κν��
//	return true;
//}

bool InitLinkList(LinkList& L) {  //��ͷ���ĵ�����
	L = (LNode*)malloc(sizeof(LNode)); //����һ��ͷ���
	if (L == NULL) {    //�ڴ治�㣬����ʧ��
		return false;
	}
	L->next = NULL;  //ͷ���֮����ʱû���κν��
	return true;
}


//�жϵ������Ƿ�Ϊ��
bool IsEmpty(LinkList L) {
	return L == NULL;
}

//������Ľ�����ͷ�巨��
bool CreateLinkList_H(LinkList& L, int n) {
	L = new LNode;
	L->next = NULL;  //����һ����ͷ���Ŀ�����
	for (int i = 0; i < n; i++) {
		LNode* p = new LNode;   //�½�һ�����
		cin >> p->Data;

		p->next = L->next;  //ͷ��������½��
		L->next = p;		
	}
	return true;
 }


//������Ľ�����β�巨��   ����һ����βָ��
bool CreateLinkList_R(LinkList& L,int n) {
	L = new LNode;
	L->next = NULL;
	LNode* r = new LNode;
	r = L;   //β���ָ��ͷ���
	for (int i = 0; i < n; i++) {
		LNode* p = new LNode;  //�����½��
		cin >> p->Data;

		p->next = NULL;  //���½����������
		r->next = p;

		r = p;  //��β���ָ�������Ľ�㣬ʼ�ձ�����β���
	}
	return true;
}

// �������
bool InsertLinkList(LinkList& L, int i, ElemType e) {
	LNode*p = new LNode;  //�����½��
	p = L; //�½��ָ��ͷ���
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

// ����ɾ��
bool DeleteLinkList(LinkList& L, int i) {
	LNode* p = new LNode;  //�����½��
	p = L; //�½��ָ��ͷ���
	int j = 0;
	while ( p->next && j < i - 1)  //p->next ������ p �������p �Ļ���return false������ѭ��
	{
		p = p->next;
		j++;
	}
	if (p == NULL) {
		return false;
	}
	LNode* q = new LNode;  //����һ���µĽ��
	q = p->next;   //ָ��p �����һ����㣬��Ҫɾ���Ľ��
	p->next = q->next;  //p�ĺ��Ϊ q�ĺ��  ���� p���������Ľ��
	delete q;     //����ʱ�ͷ�
	return true;
}


//ȡֵ
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

//����   ���ص���һ�����
LNode* LocateElem(LinkList& L, ElemType e) {
	LNode* p = new LNode;
	p = L->next;
	while (p && p->Data != e) {
		p = p->next;
	}
	return p;
}

//��ʾ�������н����Ϣ
void Display(LinkList& L) {
	LNode* p = new LNode;
	p = L->next;    //���ָ��ͷ���ĺ�һ����㣬Ҳ���ǵ�һ�������Ľ��
	while (p) {
		cout << p->Data << " ";
		p = p->next;		
	}
	cout << endl;
}



void Menu()//�˵�����
{
	cout << "1.����\n";
	cout << "2.����\n";
	cout << "3.����\n";
	cout << "4.����\n";
	cout << "5.ɾ��\n";
	cout << "6.���\n";
	cout << "0.�˳�\n";
	printf("����������Ҫѡ���ѡ�\n");

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
		case 1: //����һ��������
			if (CreateLinkList_H(L,5))
				cout << "�ɹ�����˳���!\n\n";
			Menu();
			printf("\n");
			break;

		case 2://��˳�������������
			(L);
			printf("�����������\n");
			printf("\n");
			Menu();
			break;

		case 3://����˳����е�ֵ
			printf("����������Ҫ���ҵ���ֵ\n");
			cin >> e;
			if (LocateElem(L, e)) {
				cout << "���ݵ�λ��Ϊ��" << LocateElem(L, e) << endl;
			}
			else {
				cout << "����ʧ��" << endl;
			}
			Menu();
			printf("\n");
			break;

		case 4://��˳����в�������
			printf("��������Ҫ�����λ�ú�����\n");
			cin >> a >> e;
			if (InsertLinkList(L, a, e))
				cout << "����ɹ�.\n\n";
			else
				cout << "����ʧ��!\n\n";
			Menu();
			printf("\n");
			break;

		case 5://ɾ��˳����е�����
			cout << "��������Ҫɾ�������ݵ�λ��:";
			cin >> a;
			if (DeleteLinkList(L, a))
				cout << "ɾ���ɹ�!\n\n";
			else
				cout << "ɾ��ʧ��!\n\n";
			Menu();
			printf("\n");
			break;

		case 6://��˳����е�����ȫ����ʾ����
			Display(L);
			Menu();
			printf("\n");
			break;
		}
		printf("\n");
	}
	return 0;
}