#include<string>
#include <iostream>
#include<iomanip>
using namespace std;
#include "Header.h"
TList* Head;
TList* Last;
void adfun(TRecord& p) { //�������� p[i] �������� ��� ��������� � ������

	Add(p.s, p.x,p. w);
}
void out(TRecord* p, int n) { // ������� p[i] ��������� � �������� � adfun

	for (int i = 0;i < n;i++) {
		adfun(p[i]);
	}
	cout << endl;
	return;
}

void input(TRecord& p) { //����� p[i] �������� � ������ ��������
	cout << " �������� �����: ";
	cin.ignore();
	getline(cin, p.s);
	cout << " ����: ";
	cin >> p.x;
	cout << " ���: ";
	cin >> p.w;


}
void in(TRecord* p, int n) { //������� p[i] �������� ��� input
	int count = 0;

	for (int i = 0;i < n;i++) {
		count++;
		cout << "������� � " << count << endl;
		input(p[i]);
	}
	return;

}
void Add(string s, double x, double w) { //���� p[i] �������� � ������

	//�������� �������
	TList* r = new TList;
	//�������� ��� �������
	r->Rec.s = s; r->Rec.x = x; r->Rec.w = w;
	//������� ��������� �� ������� ���� ������
	//�� �������� ������
	r->Next = 0; r->Prev = 0;
	//���� ���� ������� �� ������ - ������ ���
	//� ���������� ������� 
	if (Last) { Last->Next = r; r->Prev = Last; }
	//� ���� ��� ������ - �������� ��
	if (!Head) Head = r;
	// ����� ���� ����� ������ ���������
	//��� ��������� ������� ������ ����� ���������
	Last = r;
}

void Clear() { //������ ������
	//���� �� ������ ����������
	if (!Head) return;
	//� ����� ������� ��������������� �� ���������
	for (Last = Head->Next; Last; Last = Last->Next) {
		//���������� �� ������� �����.
		//�.�. ������ ����������
		delete Last->Prev;
		Head = Last;
	}
	delete Head;
}

void Write() { //�����
	//��� �� � �����

	for (Last = Head; Last; Last = Last->Next) {
		//������� �� ����� �������� ������
		cout.width(10);
		cout.setf(ios_base::right);
		cout <<  Last->Rec.s;
	};
	cout << endl;
	for (Last = Head; Last; Last = Last->Next) {
		//������� �� ����� �������� ������
		cout.width(10);
		cout << Last->Rec.x;
	}
	cout << endl;
	for (Last = Head; Last; Last = Last->Next) {
		//������� �� ����� �������� ������
		cout.width(10);
		cout  << Last->Rec.w;
	}
	cout << endl;
}


bool Condition(string Direct, string FieldName, TRecord a, TRecord b) //�������� ����������
{
	return 
		(Direct == "desc" && FieldName == "s" && a.s > b.s)
		|| (Direct == "desc" && FieldName == "x" && a.x > b.x) ||
		(Direct == "desc" && FieldName == "w" && a.w > b.w);
}


void Sort(string FieldName, string Direct) { //bubble sort 

	//����������� ��������� ��������� �� ��������� ������
	for (TList* i = Head; i; i = i->Next) {
		for (TList* j = Head; j; j = j->Next) {
			//� ����������� �� ���������� �����������
			if (Condition(Direct, FieldName, i->Rec, j->Rec)) {
				//���������� ����� ���������� ������
				TRecord r = i->Rec;
				i->Rec = j->Rec;
				j->Rec = r;
			}
		}
	}
}