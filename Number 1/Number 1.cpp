/*16. �������� ������� ������� ������� ���, ����� �������� ������ ������ ��������� ��������������.*/
#include "stdafx.h" 
#include <iostream> 
#include <time.h> 
#include <cmath> 
#include <locale> 
#include <fstream>
using namespace std;

void MatrixInit(int **A, int str, int col)//������������� ������� 
{
	srand(time(0));
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < str; j++)
			A[i][j] = rand() % 10;//��������� ���������� ������� �� 0 �� 9
	}
}

void PrintMatrix(int **A, int str, int col)//������ ������� 
{
	cout << endl << endl;
	cout << "�������:" << endl;
	for (int j = 0; j < str; j++)
		for (int i = 0; i < col; i++)
		{
			if (!(i%col)) cout << endl; //����� ������ �������� ��� ������ 
			cout << A[i][j] << '\t'; //��������� �������� 
		}
	cout << endl << endl;
}

void DeleteMatrix(int **A, int col)//������� ������ �� ���������� ���������� ������� 
{
	for (int i = 0; i < col; i++) delete[]A[i];
	delete[]A;
	A = NULL;
}

void EditMatrix(int **A, int str, int col)//�������
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
	string str; // ������ �������������� �������� ����������� ������ �� ����� 
	do
	{
		cout << " **����** " << endl;
		cout << "1:������ ������ �� ����� " << endl;
		cout << "2:������ ������ �� �������" << endl;
		cout << endl << endl;
		cout << "�����: ";
		cin >> choice;
	} while ((choice != 1) && (choice != 2));
	if (choice == 1)
	{
		ifstream fin("cppstudio.txt");

		if (!fin.is_open())
		{
			cout << "���� �� ������.";
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
			cout << "�������� �������";
			PrintMatrix(x, Str, Col);
			cout << endl;
			cout << "����������������� �������";
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
		cout << "������� Col (������ �������): ";
		cin >> Col;
		cout << "������� Str (������ �������): ";
		cin >> Str;
		a = new int*[Col];//������� ������ 
		for (int i = 0; i < Col; i++)
		{
			a[i] = new int[Str];
		}
		MatrixInit(a, Str, Col);
		cout << "�������� �������";
		PrintMatrix(a, Str, Col);
		cout << "����������������� �������";
		EditMatrix(a, Str, Col);
		PrintMatrix(a, Str, Col);
		DeleteMatrix(a, Col);
		system("pause");
	}
}