#include "hdr.h"

int main()
{
	ifstream infile("data.txt");
	ofstream onfile("output.txt");

	string name;

	bool found = false;

	int count;
	int action;
	int choise;

	// перевірка чи є файл
	if (!infile.is_open()) {
		cout << "Error opening file!" << endl;
		return 1;
	}

	cout << "--- WELLCOME ---\n";
	
	// введення кількості послуг які є у файлі
	do
	{
		cout << "How many receipts(>0) in file: ";
		cin >> count;
	} while (count <= 0);

	// створоення динамічного масиву
	receipt* mass_receipts = new receipt[count];

	// цикл читає та записує дані в масив 
	// після циклу файл закривається
	for (int i = 0; i < count; i++)
	{
		mass_receipts[i].data_input(infile);
	}
	infile.close();

	// меню програми
	cout << "\n--- Sellect action ---";
	do 
	{
		cout << "\n1.Find by name";
		cout << "\n2.Sort and show";
		cout << "\nEnter choise: ";
		cin >> action;
	} while (action != 1 && action != 2);

	// якщо був вибір 1
	if (action == 1) 
	{
		cout << "Enter service name: ";
		cin >> name;

		cout << "\n--- Search Results ---\n";

		onfile << "--- Search Results ---\n\n";

		/*	
		цикл який перевіряє кожне імя 
		виводить його на екран 
		якщо воно співпадає з введеним з клавіатури
		*/
		for (int i = 0; i < count; i++)
		{
			if (mass_receipts[i].GetSN() == name)
			{
				mass_receipts[i].print();
				mass_receipts[i].fprint(onfile);
				found = true;
			}
		}
		/*
		вивід на екран повідомлення 
		про те що у файлі нема послуги
		яку ввели з клавіатури
		*/
		if (!found) 
		{
			cout << "\nNo services with name " << name;
		}
		return 0;
	}

	// якщо був вибір 2
	if (action == 2)
	{
		do
		{
			cout << "\nSort by:";
			cout << "\n1.Name";
			cout << "\n2.ID";
			cout << "\n3.Cost";
			cout << "\nEnter choise: ";
			cin >> choise;
		} while (choise != 1 && choise != 2 && choise != 3);

		cout << "\n--- Sorted list ---\n\n";
		onfile << "--- Sorted list ---\n\n";
	}

	// сортування за назвою послуги
	if (choise == 1)
	{
		sort_by_name(mass_receipts, count);
	}

	// сортування за номером квитанції
	if (choise == 2)
	{
		sort_by_id(mass_receipts, count);
	}

	// сортування за оплаченою сумою
	if (choise == 3)
	{
		sort_by_amount(mass_receipts, count);
	}

	// цикл виводить дані в консоль і в файл
	for (int i = 0; i < count; i++)
	{
		mass_receipts[i].print();
		mass_receipts[i].fprint(onfile);
	}

	// очищення памяті
	delete[] mass_receipts;

	return 0;
	/*

	*/
}
