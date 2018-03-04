#include "vector.h"

int main() {
	double a[2] = { 0.04,0.5 };
	double b[2] = { 0.06,0.8 };
	Vector<2> v1(a);
	Vector<2> v2(b);
	double c=v1*v2;
	double dis = distance(v1, v2);
	return 0;
}