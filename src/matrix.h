#include <iostream>
using namespace std;

class Matrix
{
private:
	int** arr;
	int n; // Строки
	int m; // Столбцы
public:
	Matrix() // Конструктор по умолчанию
	{
		n = 0;
		m = 0;
		arr = nullptr;
	}
	Matrix(int _n, int _m) // Конструктор с параметрами
	{
		n = _n;
		m = _m;
		arr = (int**) new int* [n]; // Выделение памяти под массив из указателей
		for (int i = 0; i < n; i++)
			arr[i] = (int*) new int[m];
		for (int i = 0; i < n; i++) // Заполняем массив рандомными числами в пределах 40
		{
			for (int j = 0; j < m; j++)
			{
				arr[i][j] = rand() % 40;
			}
		}
	}
	void copy(const Matrix& matr) // Конструктор копирования
	{
		for (int i = 0; i < n; i++) // Освобождаем память
			delete[] arr[i];
		delete[] arr;
		arr = new int* [n]; // Создаем новый массив
		for (int i = 0; i < n; i++)
			arr[i] = new int[m];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				arr[i][j] = matr.arr[i][j];
			}
		}
	}
	void print() // Конструктор печати
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << arr[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void scan() // Конструктор сканирования
	{
		cout << "Enter element matrix:" << endl;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];
	}
	int info_n() // Получение количества строк
	{
		return n;
	};
	int info_m() // Получение количества столбцов
	{
		return m;
	};
	Matrix operator = (const Matrix& matr) // Оператор присваивания
	{
		copy(matr);
		return *this;
	}
	friend Matrix operator + (Matrix& a, Matrix& b) // Оператор сложения
	{
		
		int string = a.info_n();
		int colomn = b.info_m();
		Matrix temp(string, colomn);
		try
		{
			if (string != colomn)
				throw 1;
			else
			{
				for (int i = 0; i < string; i++)
				{
					for (int j = 0; j < colomn; j++)
					{
						temp.arr[i][j] = a.arr[i][j] + b.arr[i][j];
					}
				}
				return temp;
			}
		}
		catch (int i)
		{
			cout << "Error #" << i << " Different size!" << endl;
		}
	}
	friend Matrix operator - (Matrix& a, Matrix& b) // Опратор вычитания
	{
		int string = a.info_n();
		int colomn = b.info_m();
		Matrix temp(string, colomn);
		try
		{
			if (string != colomn)
				throw 1;
			else
			{
				for (int i = 0; i < string; i++)
				{
					for (int j = 0; j < colomn; j++)
					{
						temp.arr[i][j] = a.arr[i][j] - b.arr[i][j];
					}
				}
				return temp;
			}
		}
		catch (int i)
		{
			cout << "Error #" << i << " Different size!" << endl;
		}
	}
	friend ostream& operator << (ostream& s, Matrix& matr) // Оператор вывода
	{
		matr.print();
		return s;
	}
	friend istream& operator >> (istream& s, Matrix& matr) // Оператор ввода
	{
		matr.scan();
		return s;
	}
};