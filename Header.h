#ifndef HEADER_H
#define HEADER_H
struct TRecord {
	//В котором есть некоторые поля

	string s; //company
	double x; //price
	double w;//weight
};

struct TList {
	TRecord Rec;
	TList* Next, * Prev;
};
void out(TRecord* p, int n);
void adfun(TRecord& p);
void input(TRecord& p);
void in(TRecord* p, int n);
void Add(string s, double x, double w);
void Clear();
void Write();
bool Condition(string Direct, string FieldName, TRecord a, TRecord b);
void Sort(string FieldName, string Direct);


#endif