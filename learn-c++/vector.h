#pragma once
#include <cmath>
#include <algorithm>
using std::pow;
using std::sqrt;
template <int T> 
class Vector {
private:
	double _vector[T];
public:
	Vector(double (&vector)[T]) {
		std::copy(vector, vector+T, _vector);
	};
	double get_elem(int i) const {
		return _vector[i];
	}
	double operator*(Vector const& v) const {
		double out = 0;
		for (int i = 0; i < T; i++) {
			out+=_vector[i]*v._vector[i];
		}
		return out;
	};
	friend double distance(Vector const& v1, Vector const& v2) {
		double out = 0;
		for (int i = 0; i < T; i++) {
			out += pow((v1.get_elem(i) - v2.get_elem(i)),2);
		}
		out = sqrt(out);
		return out;
	}
};