#include <iostream>
#include <ctime>
using namespace std;

//****************************************************************************************************************************

void mergeSort(int *&tab, int size);
void set(int * &array_first, int * &array_second, int g, int h);
void copy(int *tab, int g, int h, int *array);
void merge(int * &tab, int *array_first, int *array_second, int g, int h);
void show(int *tab, int size);

//****************************************************************************************************************************
                                                                                                                     
int main()
{
	srand(time(NULL));
	int size, choice;

	do
	{
		cout << "Enter array size: ";
		cin >> size;
	} while (size <= 0);

	int *tab = new int[size];
	
	for (int i = 0; i < size; i++)
	{
		tab[i] = rand() % 100;
	}

	do
	{
		   cout << "\n1. Mergesort" << endl
				<< "2. Print array" << endl;

			cin >> choice;
			switch (choice)
			{
			case 1:
				mergeSort(tab, size);                                                                
				break;

			case 2:
				show(tab, size);                                                                      
				break;
			}

		
	} while (choice != 0);
}

//****************************************************************************************************************************
                                                                                                    
void mergeSort(int *&tab, int size)
{
	if (size > 1)
	{
		int *array_first = NULL;
		int *array_second = NULL;
		int g = size / 2;
		int h = size - g;
		set(array_first, array_second, g ,h);
		copy(tab, 0, g, array_first);
		copy(tab, g, size, array_second);
		mergeSort(array_first, g);
		mergeSort(array_second, h);
		merge(tab, array_first, array_second, g, h);
		delete[] array_first;
		delete[] array_second;
	}
}

//****************************************************************************************************************************
                                                                                                
void set(int * &array_first, int * &array_second, int g, int h)
{
	array_first = new int[g];
	array_second = new int[h];
}

//****************************************************************************************************************************
                                                                        
void copy(int *tab, int g, int h, int *array)
{
	int k = g;
	for (int i = 0; i < (h-g); i++, k++)
		array[i] = tab[k];
}

//****************************************************************************************************************************
                                                                                     
void merge(int * &tab, int *array_first, int *array_second, int g, int h)
{
	int i = 0, j = 0, k = 0;

	for (;i < g && j < h; k++)
	{
		if (array_first[i] < array_second[j])
		{
			tab[k] = array_first[i];
			i++;
		}

		else
		{
			tab[k] = array_second[j];
			j++;
		}
	}

	if (j < h)
		for (; j < h; k++, j++)
			tab[k] = array_second[j];

	else
		for (; i < g; k++, i++)
			tab[k] = array_first[i];
}

//****************************************************************************************************************************
                                                                                                   
void show(int *tab, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "tab[" << i << "]= " << tab[i] << endl;
	}
}

//****************************************************************************************************************************