#include <iostream>
#include <random>
#include <vector>
#include "matrix.h"
#include "tools.h"

using std::cout;
using std::endl;
using std::vector;
using std::ostream;
using std::cerr;
using la::Matrix;
using la::SqareMatrix;

void guess() {
	cout << "����һ��0-100����" << endl; // c standard output
	int a = -1;
	int b = randomInt(0, 100);
	while (a != b) {
		std::cin >> a;
		if (a < b) {
			cout << "��̫С�ˣ����������롣��" << endl;
		}
		else if (a > b) {
			cout << "��̫���ˣ����������롣��" << endl;
		}
	}
	cout << "��¶��ˣ�";
}


int main1() {
	//guess();
	Matrix v1(8, 5);
	v1.random();
	cout << v1;
	cout << endl;
	Matrix v2(8, 5);
	v2.random();
	cout << v2;
	cout << endl;
	Matrix v3 = v1 + v2;
	cout << v3;
	cout << endl;
	SqareMatrix::identity(5);
	cout << endl;

	Matrix* m;
	m = &v1;
	m->description();
	cout << endl;
	SqareMatrix v4(4);
	m = &v4;
	m->description();
	
	
	Matrix v5 = v1.transpose();
	cout << v2;
	cout << endl;
	Matrix v6(4, 2);
	v6.random();	
	cout << v6;
	cout << endl;
	try
	{
		Matrix v7 = v1 * v6;
		cout << v7;

	}
	catch (std::invalid_argument& msg)
	{
		cerr << msg.what() << endl;
	}
	
	
	return 0;
}
