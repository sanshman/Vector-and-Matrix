#include <iostream>
using namespace std;

template <class T>
class Matrix
{
public:
	T** arr;// Двумерный массив
	int n; // Строки
	int m; // Столбцы
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
		arr = (T**) new T * [n]; // Выделение памяти под массив из указателей
		for (int i = 0; i < n; i++)
			arr[i] = (T*) new T[m];
	}
	void copy(const Matrix& matr) // Конструктор копирования
	{
		for (int i = 0; i < n; i++) // Освобождаем память
			delete[] arr[i];
		delete[] arr;
		arr = new T * [n]; // Создаем новый массив
		for (int i = 0; i < n; i++)
			arr[i] = new T[m];
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
	void scan() // Конструктор ввода
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
	Matrix operator*(Matrix& tmp);
	friend ostream& operator << (ostream& s, Matrix& matr) // Оператор вывода
	{
		cout << "Matrix printing:" << endl;
		matr.print();
		return s;
	}
	friend istream& operator >> (istream& s, Matrix& matr) // Оператор ввода
	{
		matr.scan();
		return s;
	}
};

template <typename T>
Matrix<T> Matrix<T>::operator *(Matrix& m2)
{
	Matrix temp;
	temp.n = this->n;
	temp.m = this->m;
	int i, j, k;
	temp.arr = new T * [temp.n];
	for (i = 0; i < temp.n; ++i)
	{
		temp.arr[i] = new T[temp.m];
		for (j = 0; j < temp.m; ++j)
		{
			temp.arr[i][j] = 0;
			for (k = 0; k < temp.m; ++k)
			{
				temp.arr[i][j] = temp.arr[i][j] + (this->arr[i][k] * m2.arr[k][j]);
			}
		}
	}
	return temp;
}

template <class T>
class Matrix_function : public Matrix<T>
{
public:
	Matrix transpose(Matrix temp) // Транспонирование
	{
		int string = temp.info_n();
		int colomn = temp.info_m();
		Matrix result(string, colomn);
		for (int i = 0; i < string; i++)
		{
			for (int j = 0; j < colomn; j++)
			{
				result.arr[i][j] = temp.arr[j][i];
			}
		}
		return result;
	}
	Matrix step_form(Matrix input) // Ступенчатый вид (метод Гаусса)
	{
		int string = input.info_n();
		int colomn = input.info_m();
		Matrix result(string, colomn);
		result = input;
		for (int i = 0; i < input.n - 1; i++)
		{
			for (int j = i + 1; j < input.n; j++)
			{
				double coeff = -result.arr[j][i] / result.arr[i][i];
				for (int k = i; k < input.n; k++)
				{
					result.arr[j][k] += result.arr[i][k] * coeff;
				}
			}
		}
		return result;
	}
	/*Matrix reverse(Matrix temp) // Обратная матрица
	{
		return result;
	}*/
};
