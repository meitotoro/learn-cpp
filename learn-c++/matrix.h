#pragma once
#include <iostream>
#include <vector>

using std::vector;
using std::ostream;
namespace la {
	class Matrix {
	public:
		Matrix(int row, int column);
		Matrix(const Matrix& ma);
		~Matrix();
		void random();
		Matrix transpose() const;
		int row() const;
		int column() const;
		vector<int> getRowNums(int row) const;
		vector<int> getColumnNums(int column) const;
		Matrix operator+(const Matrix& v1);
		friend ostream& operator<<(ostream &output, const Matrix& v);
		Matrix operator*(const Matrix& v1);
		virtual void description();

	protected:
		int *_vector;
		int _row;
		int _column;
	};

	class SqareMatrix :public Matrix {
	public:
		explicit SqareMatrix(int row);
		static SqareMatrix identity(int row);
		void description() override;
	};
}