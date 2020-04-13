#include <iostream>
#include "vector.h"
#include "matrix.h"
using namespace std;

int main()
{
	Vector v1(17, 2, 8);
	Vector v2(1, 7, 8);
	Vector v3;
	cout << v1 << endl;
	cout << v2 << endl;
	cout << v1 + v2 << endl;
	cin >> v3;
	cout << v3 << endl;
	Matrix m1(3, 3);
	Matrix m2(3, 3);
	Matrix m3(4, 4);
	cout << m1 << endl;
	cout << m2 << endl;
	cout << m1+m2 << endl;
	cin >> m3;
	cout << m3 << endl;
	return 0;
}