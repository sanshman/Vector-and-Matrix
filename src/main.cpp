#include <iostream>
#include "vector.h"
#include "matrix.h"
using namespace std;

int main()
{
	Matrix<double> m1(2, 2);
	cin >> m1;
	cout << m1 << endl;
	Matrix<double> m2(2, 2);
	cin >> m2;
	cout << m2 << endl;
	/*Operation*/
		cout << "====={ Matrix_1 + Matrix_2 }=====\n" << m1+m2 << endl;
		cout << "====={ Matrix_1 - Matrix_2 }=====\n" << m1-m2 << endl;
		cout << "====={ Matrix_1 * Matrix_2 }=====\n" << m1*m2 << endl;
	/*Function*/
	Matrix_function<double> test;
		cout << "===>> Transpose <<===\n" << test.transpose(m1) << endl;
		cout << "===>> Step form <<===\n" << test.step_form(m1) << endl;
		cout << "===>> Determinate <<===\n" << "D = " << test.determinate(m1) << endl;
	return 0;
}