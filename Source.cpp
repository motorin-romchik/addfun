#include<string>
#include <iostream>
#include<iomanip>
using namespace std;
#include "Header.h"
TList* Head;
TList* Last;
void adfun(TRecord& p) { //передача p[i] элемента для занесения в список

	Add(p.s, p.x,p. w);
}
void out(TRecord* p, int n) { // перебор p[i] элементов и передача в adfun

	for (int i = 0;i < n;i++) {
		adfun(p[i]);
	}
	cout << endl;
	return;
}

void input(TRecord& p) { //занос p[i] элемента в массив структур
	cout << " Название фирмы: ";
	cin.ignore();
	getline(cin, p.s);
	cout << " Цена: ";
	cin >> p.x;
	cout << " Вес: ";
	cin >> p.w;


}
void in(TRecord* p, int n) { //перебор p[i] элемента для input
	int count = 0;

	for (int i = 0;i < n;i++) {
		count++;
		cout << "Ноутбук № " << count << endl;
		input(p[i]);
	}
	return;

}
void Add(string s, double x, double w) { //внос p[i] элемента в список

	//Создадим элемент
	TList* r = new TList;
	//Наполним его данными
	r->Rec.s = s; r->Rec.x = x; r->Rec.w = w;
	//Обнулим указатели на соседей чтоб список
	//не содержал мусора
	r->Next = 0; r->Prev = 0;
	//Если этот элемент не первый - сцепим его
	//и предидущий элемент 
	if (Last) { Last->Next = r; r->Prev = Last; }
	//И если это голова - запомним ее
	if (!Head) Head = r;
	// После чего дадим понять программе
	//что чозданный элемент теперь будет хвостиком
	Last = r;
}

void Clear() { //чистка списка
	//Если он вообще существует
	if (!Head) return;
	//В цикле пройдем последовательно по элементам
	for (Last = Head->Next; Last; Last = Last->Next) {
		//Освобождая их соседей сзади.
		//т.е. убирая предыдущие
		delete Last->Prev;
		Head = Last;
	}
	delete Head;
}

void Write() { //вывод
	//Так же в цикле

	for (Last = Head; Last; Last = Last->Next) {
		//выводим на экран элементы списка
		cout.width(10);
		cout.setf(ios_base::right);
		cout <<  Last->Rec.s;
	};
	cout << endl;
	for (Last = Head; Last; Last = Last->Next) {
		//выводим на экран элементы списка
		cout.width(10);
		cout << Last->Rec.x;
	}
	cout << endl;
	for (Last = Head; Last; Last = Last->Next) {
		//выводим на экран элементы списка
		cout.width(10);
		cout  << Last->Rec.w;
	}
	cout << endl;
}


bool Condition(string Direct, string FieldName, TRecord a, TRecord b) //свойство сортировки
{
	return 
		(Direct == "desc" && FieldName == "s" && a.s > b.s)
		|| (Direct == "desc" && FieldName == "x" && a.x > b.x) ||
		(Direct == "desc" && FieldName == "w" && a.w > b.w);
}


void Sort(string FieldName, string Direct) { //bubble sort 

	//Сортировкой пузырьком пройдемся по элементам списка
	for (TList* i = Head; i; i = i->Next) {
		for (TList* j = Head; j; j = j->Next) {
			//В зависимости от указанного направления
			if (Condition(Direct, FieldName, i->Rec, j->Rec)) {
				//Произведем обмен контейнера списка
				TRecord r = i->Rec;
				i->Rec = j->Rec;
				j->Rec = r;
			}
		}
	}
}