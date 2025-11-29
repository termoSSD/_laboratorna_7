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
	cout << "Paid amount: " << paid_amount << "\n\n";
}

void receipt::fprint(ofstream& onf)
{
	onf << "Service name: " << service_name << "\n";
	onf << "Receipt ID: " << id_receipt << "\n";
	onf << "Paid amount: " << paid_amount << "\n\n";
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

/*
Зовнішній цикл відповідає за кількість проходів по масиву
	Після кожного виконання циклу гарантується
	що найбільший (або "найважчий") елемент з тих
	що залишилися перейде в кінець масиву
Внутрішній цикл проходить по елементах, порівнюючи пари сусідів
	j - це індекс поточного елементу 
	який порівнюється з наступним (j + 1)

	(count - i - 1):
		(- 1): тому що всередині ми звертаємось до arr[j + 1]. 
		Якби ми йшли до самого кінця (count)
		то j + 1 вийшов би за межі масиву
		
		(- i): оскільки після кожного проходу зовнішнього циклу (i)
		найбільші елементи вже відсортувалися в кінець
		немає сенсу їх знову перевіряти

		інші функції по сортуванні по аналогії
*/

void sort_by_name(receipt* arr, int count)
{
	for (int i = 0; i < count - 1; i++) 
	{
		for (int j = 0; j < count - i - 1; j++) 
		{
			// якщо лівий елемент більший за правий
			if (arr[j].service_name > arr[j + 1].service_name) 
			{
				receipt temp = arr[j];	// зберігаємо лівий елемент у тимчасову змінну
				arr[j] = arr[j + 1];	// на місце лівого ставимо правий (менший)
				arr[j + 1] = temp;		// на місце правого ставимо збережений лівий 
			}
		}
	}
}

void sort_by_id(receipt* arr, int count)
{
	for (int i = 0; i < count - 1; i++) 
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			if (arr[j].id_receipt > arr[j + 1].id_receipt) 
			{
				receipt temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void sort_by_amount(receipt* arr, int count)
{
	for (int i = 0; i < count - 1; i++) 
	{
		for (int j = 0; j < count - i - 1; j++) 
		{
			if (arr[j].paid_amount > arr[j + 1].paid_amount) 
			{
				receipt temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
