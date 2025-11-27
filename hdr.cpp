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

void sort_by_name(receipt* arr, int count)
{
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {

			// Прямий доступ до private (service_name) дозволено, бо це friend функція
			if (arr[j].service_name > arr[j + 1].service_name) {
				// Ручний обмін
				receipt temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void sort_by_id(receipt* arr, int count)
{
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {

			// Прямий доступ до private (id_receipt)
			if (arr[j].id_receipt > arr[j + 1].id_receipt) {
				receipt temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void sort_by_amount(receipt* arr, int count)
{
	for (int i = 0; i < count - 1; i++) {
		for (int j = 0; j < count - i - 1; j++) {

			// Прямий доступ до private (paid_amount)
			if (arr[j].paid_amount > arr[j + 1].paid_amount) {
				receipt temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
