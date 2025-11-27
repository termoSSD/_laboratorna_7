#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class receipt
{
private:
	string service_name;	// назва послуги
	int id_receipt;			// номер квитанції
	float paid_amount;		// оплачена сума
public:

	string GetSN();
	int GetID();
	float GetPA();

	void SetSN(string);
	void SetID(int);
	void SetPA(float);

	// ввід даних з файлу
	void data_input(ifstream& inf);		

	// вивід даних на консоль
	void print();			

	// вивід даних в файл
	void fprint(ofstream&);

	/* 
	Методи сортування викликані friend бо:
		- Вони є глобальними 
		- Мають доступ до приватних полів 
	*/

	friend void sort_by_name(receipt*, int);
	friend void sort_by_id(receipt*, int);
	friend void sort_by_amount(receipt*, int);
	
	// констурктор і деструктор(~)
	receipt();
	~receipt();
};