#include <iostream>
using namespace std;
class Vector
{
private:
	int x;
	int y;
	int z;
public:
	Vector() // Конструктор по умолчанию 
	{
		x = 0;
		y = 0;
		z = 0;
	}
	Vector(int _x, int _y, int _z) // Конструктор с параметрами
	{
		x = _x;
		y = _y;
		z = _z;
	}
	Vector operator + (const Vector& vec) // Оператор сложения
	{
		return Vector(this->x + vec.x, this->y + vec.y, this->z + vec.z);
	}
	Vector operator = (const Vector& vec) // Оператор присваивания
	{
		if (&vec == this)
			return *this;
		return Vector(this->x = vec.x, this->y = vec.y, this->z = vec.z);
	}
	friend ostream& operator << (ostream& s, const Vector& vec) // Оператор вывода 
	{
		return cout << "Coordinates: X = " << vec.x << ", Y = " << vec.y << ", Z = " << vec.z << endl;
	}
	friend istream& operator >> (istream& s, Vector& vec) // Оператор ввода
	{
		cout << "Enter coordinates vector:\nX = ";
		cin >> vec.x;
		cout << "\nY = ";
		cin >> vec.y;
		cout << "\nZ = ";
		cin >> vec.z;
		return s;
	}
};