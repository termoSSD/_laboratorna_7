#include "hdr.h"

int main()
{
	ifstream infile("data.txt");
	ofstream onfile("output.txt");
	int count;
	int choise;

	if (!infile.is_open()) {
		cout << "Error opening file!" << endl;
		return 1;
	}

	do
	{
		cout << "How many receipts(>0) in file: ";
		cin >> count;
	} while (count <= 0);

	do 
	{
		cout << "\nSort by:";
		cout << "\n1.Name";
		cout << "\n2.ID";
		cout << "\n3.Cost";
		cout << "\nEnter choise: ";
		cin >> choise;
	} while (choise != 1 && choise != 2 && choise != 3);

	// створоення динамічного масиву
	receipt* mass_receipts = new receipt[count];

	// цикл читає та записує дані в масив
	for (int i = 0; i < count; i++)
	{
		mass_receipts[i].data_input(infile);
	}
	infile.close();

	// цикл виводить дані в консоль і в файл
	for (int i = 0; i < count; i++)
	{
		mass_receipts[i].print();
		mass_receipts[i].fprint(onfile);
	}

	delete[] mass_receipts;

	/*

	*/
}