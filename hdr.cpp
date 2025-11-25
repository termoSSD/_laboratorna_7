#include "hdr.h"


string receipt::GetSN()
{
	return service_name;
}

int receipt::GetID()
{
	return id_receipt;
}

float receipt::GetPA()
{
	return paid_amount;
}

void receipt::SetSN(string N)
{
	service_name = N;
}

void receipt::SetID(int A)
{
	id_receipt = A;
}

void receipt::SetPA(float P)
{
	paid_amount = P;
}

void receipt::data_input(ifstream& inf)
{
	inf >> service_name;
	inf >> id_receipt;
	inf >> paid_amount;
}

void receipt::print()
{
	cout << "Service name: " << service_name << "\n";
	cout << "Receipt ID: " << id_receipt << "\n";
	cout << "Paid amount: " << paid_amount << "\n";
}

void receipt::fprint(ofstream& onf)
{
	onf << service_name << " "
		<< id_receipt << " "
		<< paid_amount << "\n";
}

receipt::receipt()
{
	service_name = "Nothing";
	id_receipt = 0;
	paid_amount = 0;
}

receipt::~receipt() 
{
}