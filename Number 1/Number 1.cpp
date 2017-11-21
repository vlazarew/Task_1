/*16. Поменять местами столбцы матрицы так, чтобы элементы первой строки оказались упорядоченными.*/
#include "stdafx.h" 
#include <iostream> 
#include <time.h> 
#include <cmath> 
#include <locale> 
#include <fstream>
using namespace std;

void MatrixInit(int **A, int str, int col)//Инициализация матрицы 
{
	srand(time(0));
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < str; j++)
			A[i][j] = rand() % 10;//Заполение случайными числами от 0 до 9
	}
}

void PrintMatrix(int **A, int str, int col)//Печать матрицы 
{
	cout << endl << endl;
	cout << "Матрица:" << endl;
	for (int j = 0; j < str; j++)
		for (int i = 0; i < col; i++)
		{
			if (!(i%col)) cout << endl; //Чтобы массив выглядел как массив 
			cout << A[i][j] << '\t'; //Табуляция символов 
		}
	cout << endl << endl;
}

void DeleteMatrix(int **A, int col)//Очистка памяти от созданного двумерного массива 
{
	for (int i = 0; i < col; i++) delete[]A[i];
	delete[]A;
	A = NULL;
}

void EditMatrix(int **A, int str, int col)//Задание
{
	for (int i = 1; i < col; i++)
	{
		for (int j = 0; j < (col - 1); j++)
		{
			if (A[i][0] > A[j][0])
			{
				int* tmp;
				tmp = A[j];
				A[j] = A[i];
				A[i] = tmp;
			}
		}
	}
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	int Str, Col, **a, choice, i = 0, count = 0;
	string str; // буферы промежуточного хранения считываемых данных из файла 
	do
	{
		cout << " **МЕНЮ** " << endl;
		cout << "1:Чтение данных из файла " << endl;
		cout << "2:Чтение данных из консоли" << endl;
		cout << endl << endl;
		cout << "Выбор: ";
		cin >> choice;
	} while ((choice != 1) && (choice != 2));
	if (choice == 1)
	{
		ifstream fin("cppstudio.txt");

		if (!fin.is_open())
		{
			cout << "Файл не найден.";
		}
		else
		{
			int count = 0;
			int temp;
			while (!fin.eof())
			{
				fin >> temp;
				count++;
			}
			fin.seekg(0, ios::beg);
			fin.clear();
			int count_space = 0;
			char symbol;
			while (!fin.eof())
			{
				fin.get(symbol);
				if (symbol == ' ')
					count_space++;
				if (symbol == '\n')
					break;
			}
			fin.seekg(0, ios::beg);
			fin.clear();
			int Str = count / (count_space + 1);
			int Col = count_space + 1;
			int **x;
			x = new int*[Col];
			for (int i = 0; i < Col; i++) x[i] = new int[Str];
			for (int i = 0; i < Str; i++)
				for (int j = 0; j < Col; j++)
					fin >> x[j][i];
			cout << "Исходная матрица";
			PrintMatrix(x, Str, Col);
			cout << endl;
			cout << "Отредактированная матрица";
			cout << endl;
			EditMatrix(x, Str, Col);
			PrintMatrix(x, Str, Col);
			DeleteMatrix(x, Str);
			fin.close();
			system("pause");
		}
	}
	else
	{
		cout << "Введите Col (ширину матрицы): ";
		cin >> Col;
		cout << "Введите Str (высоту матрицы): ";
		cin >> Str;
		a = new int*[Col];//создаем массив 
		for (int i = 0; i < Col; i++)
		{
			a[i] = new int[Str];
		}
		MatrixInit(a, Str, Col);
		cout << "Исходная матрица";
		PrintMatrix(a, Str, Col);
		cout << "Отредактированная матрица";
		EditMatrix(a, Str, Col);
		PrintMatrix(a, Str, Col);
		DeleteMatrix(a, Col);
		system("pause");
	}
}