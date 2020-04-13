#include <iostream>
using namespace std;

class Matrix
{
private:
	int** arr;
	int n; // ������
	int m; // �������
public:
	Matrix() // ����������� �� ���������
	{
		n = 0;
		m = 0;
		arr = nullptr;
	}
	Matrix(int _n, int _m) // ����������� � �����������
	{
		n = _n;
		m = _m;
		arr = (int**) new int* [n]; // ��������� ������ ��� ������ �� ����������
		for (int i = 0; i < n; i++)
			arr[i] = (int*) new int[m];
		for (int i = 0; i < n; i++) // ��������� ������ ���������� ������� � �������� 40
		{
			for (int j = 0; j < m; j++)
			{
				arr[i][j] = rand() % 40;
			}
		}
	}
	void copy(const Matrix& matr) // ����������� �����������
	{
		for (int i = 0; i < n; i++) // ����������� ������
			delete[] arr[i];
		delete[] arr;
		arr = new int* [n]; // ������� ����� ������
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
	void print() // ����������� ������
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
	void scan() // ����������� ������������
	{
		cout << "Enter element matrix:" << endl;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];
	}
	int info_n() // ��������� ���������� �����
	{
		return n;
	};
	int info_m() // ��������� ���������� ��������
	{
		return m;
	};
	Matrix operator = (const Matrix& matr) // �������� ������������
	{
		copy(matr);
		return *this;
	}
	friend Matrix operator + (Matrix& a, Matrix& b) // �������� ��������
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
	friend Matrix operator - (Matrix& a, Matrix& b) // ������� ���������
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
	friend ostream& operator << (ostream& s, Matrix& matr) // �������� ������
	{
		matr.print();
		return s;
	}
	friend istream& operator >> (istream& s, Matrix& matr) // �������� �����
	{
		matr.scan();
		return s;
	}
};