//˳���
//�����������������٣���ʼ������ɾ�Ĳ�
#include <iostream>
using namespace std;

//��̬����ʵ��
#define MaxSize 10   //����� �� ���治�ܼӶ���

typedef int ElemType;   //��int ����ΪElemType    typedef�����Ͷ���
typedef int Status;

typedef struct {
	ElemType Data[MaxSize];
	ElemType length;
}Seqlist;


//��ʼ��˳���
Status InitSeqList(Seqlist& L) {
	for (int i = 0; i < MaxSize; i++) {
		L.Data[i] = 0;
	}
	if (!L.Data)
		exit(OVERFLOW);
	L.length = 0;
	return true;
}

//��˳�������������
Status InputSeqlist(Seqlist& L) {
	int j, i;
	printf("������˳����Ԫ�ظ���\n");
	cin >> i;
	for (j = 0; j < i; j++)
	{
		cin >> L.Data[j];
		L.length++;
	}
	return 0;
}
//��λ�����
Status GetElemValueById(Seqlist L, ElemType i) {
	return L.Data[i-1];
}

//��ֵ����
Status GetElemValueByValue(Seqlist L, ElemType &e) {
	for (int i = 0; i < L.length; i++) {
		if (L.Data[i] == e) {
			return i + 1;
		}
	}
	return -1;
}


//����
bool Insert(Seqlist& L, ElemType i, ElemType e) {
	if (i<1 || i>L.length + 1) {
		return false;
	}
	L.length++;   //һ��Ҫ��ס ���ȼ�һ
	for (int j = L.length; j >= i; j--) {
		L.Data[j] = L.Data[j - 1];
	}	
	L.Data[i - 1] = e;	
	return true;
}


//ɾ��
bool Delete(Seqlist& L, ElemType i) {
	if (i<1 || i>L.length) {
		return false;
	}
	for (int j = i; j < L.length; j++) {
		L.Data[j-1] = L.Data[j];
	}
	L.length--;   //һ��Ҫ��ס ���ȼ�һ
	return true;
}

//���˳�������Ԫ��
void GetElemValue(Seqlist L) {
	for (int i = 0; i < L.length; i++) {
		cout << L.Data[i] << " ";
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
	Seqlist L;
	Menu();
	choose = -1;
	while (choose != 0)
	{
		cin >> choose;
		switch (choose)
		{
		case 1: //����һ��˳���
			if (InitSeqList(L))
				cout << "�ɹ�����˳���!\n\n";
			Menu();
			printf("\n");
			break;

		case 2://��˳�������������
			InputSeqlist(L);
			printf("�����������\n");
			printf("\n");
			Menu();
			break;

		case 3://����˳����е�ֵ
			printf("����������Ҫ���ҵ���ֵ\n");
			cin >> e;
			if (GetElemValueByValue(L, e)) {
				cout << "���ݵ�λ��Ϊ��" << GetElemValueByValue(L, e) << endl;
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
			if (Insert(L, a, e))
				cout << "����ɹ�.\n\n";
			else
				cout << "����ʧ��!\n\n";
			Menu();
			printf("\n");
			break;

		case 5://ɾ��˳����е�����
			cout << "��������Ҫɾ�������ݵ�λ��:";
			cin >> a;
			if (Delete(L, a))
				cout << "ɾ���ɹ�!\n\n";
			else
				cout << "ɾ��ʧ��!\n\n";
			Menu();
			printf("\n");
			break;

		case 6://��˳����е�����ȫ����ʾ����
			GetElemValue(L);
			Menu();
			printf("\n");
			break;
		}
		printf("\n");
	}
	return 0;
}