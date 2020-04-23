#include <iostream>
using namespace std;

class Matrix
{
private:
	int** arr; // Äâóìåðíûé ìàññèâ
	int n; // Ñòðîêè
	int m; // Ñòîëáöû
public:
	Matrix() // Êîíñòðóêòîð ïî óìîë÷àíèþ
	{
		n = 0;
		m = 0;
		arr = nullptr;
	}
	Matrix(int _n, int _m) // Êîíñòðóêòîð ñ ïàðàìåòðàìè
	{
		n = _n;
		m = _m;
		arr = (int**) new int* [n]; // Âûäåëåíèå ïàìÿòè ïîä ìàññèâ èç óêàçàòåëåé
		for (int i = 0; i < n; i++)
			arr[i] = (int*) new int[m];
		for (int i = 0; i < n; i++) // Çàïîëíÿåì ìàññèâ íóëÿìè
		{
			for (int j = 0; j < m; j++)
			{
				arr[i][j] = 0;
			}
		}
	}
	void copy(const Matrix& matr) // Êîíñòðóêòîð êîïèðîâàíèÿ
	{
		for (int i = 0; i < n; i++) // Îñâîáîæäàåì ïàìÿòü
			delete[] arr[i];
		delete[] arr;
		arr = new int* [n]; // Ñîçäàåì íîâûé ìàññèâ
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
	void print() // Êîíñòðóêòîð ïå÷àòè
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
	void scan() // Êîíñòðóêòîð ââîäà
	{
		cout << "Enter element matrix:" << endl;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];
	}
	int info_n() // Ïîëó÷åíèå êîëè÷åñòâà ñòðîê
	{
		return n;
	};
	int info_m() // Ïîëó÷åíèå êîëè÷åñòâà ñòîëáöîâ
	{
		return m;
	};
	Matrix operator = (const Matrix& matr) // Îïåðàòîð ïðèñâàèâàíèÿ
	{
		copy(matr);
		return *this;
	}
	friend Matrix operator + (Matrix& a, Matrix& b) // Îïåðàòîð ñëîæåíèÿ
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
	friend Matrix operator - (Matrix& a, Matrix& b) // Îïðàòîð âû÷èòàíèÿ
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
	friend ostream& operator << (ostream& s, Matrix& matr) // Îïåðàòîð âûâîäà
	{
		matr.print();
		return s;
	}
	friend istream& operator >> (istream& s, Matrix& matr) // Îïåðàòîð ââîäà
	{
		matr.scan();
		return s;
	}
};

Matrix Matrix::operator *(Matrix& m2)
{
	Matrix temp;
	temp.n = this->n;
	temp.m = this->m;
	int i, j, k;
	temp.arr = new int* [temp.n];
	for (i = 0; i < temp.n; ++i)
	{
		temp.arr[i] = new int[temp.m];
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
