/*Для двунаправленного списка написать функцию таким образом, что
элемент списка добавляется в порядке убывания ключевого поля.
*/
#include<string>
#include <iostream>
#include<iomanip>
using namespace std;
#include "Header.h"

int main()
{
	int lenghtar;//array lenght
	setlocale(LC_ALL, "Russian");
	cout << "   Сколько ноутбуков будем регистрировать : ";
	cin >> lenghtar;
	TRecord*r =new TRecord[lenghtar];
	//Наполняем список
	in(r, lenghtar);
	out(r, lenghtar);
	//Крутим список так и сяк
	cout << "Исходный список:" << endl ;Write();
	//cout << "x (A->Z):" << endl; Sort("x", "asc"); Write();
	//cout << "s (A->Z):" << endl; Sort("s", "asc"); Write();
	cout << "company (Z->A):" << endl; Sort("s", "desc"); Write();
	cout << "price (Z->A):" << endl; Sort("x", "desc"); Write();
	cout << "weight (Z->A):" << endl;Sort("w", "desc");Write();

	//Освобождаем список
	Clear();

	cin.get();
	return 0;
}