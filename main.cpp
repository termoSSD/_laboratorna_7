#include "hdr.h"

int main()
{
	ifstream infile("data.txt");
	ofstream onfile("output.txt");
	int count;

	cout << "How many receipts in file: ";
	cin >> count;

	receipt* mass_receipts = new receipt[count];

	for (int i = 0; i < count; i++)
	{
		mass_receipts[i].data_input(infile);
	}
	infile.close();

	for (int i = 0; i < count; i++)
	{
		mass_receipts[i].fprint(onfile);
	}

	for (int i = 0; i < count; i++)
	{
		mass_receipts[i].print();
	}


	/*

	*/
}