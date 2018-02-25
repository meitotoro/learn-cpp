#include "matrix.h"
#include "tools.h"
#include <stdexcept>

using std::endl;
using std::cout;


namespace la {


	Matrix::Matrix(int row, int column) :
		_row(row), _column(column)
	{
		_vector = new int[row*column]();
		//cout << "gouzao";

	}
	Matrix::Matrix(const Matrix& ma)
	{
		_row = ma._row;
		_column = ma._column;
		_vector = new int[_row*_column]();
		for (int i = 0; i < _row*_column; i++) {
			_vector[i] = ma._vector[i];
		}
		//cout << "kaobeigouzao";
	}
	Matrix::~Matrix()
	{
		delete[] _vector;
		//cout << "xigou";
	}

	void Matrix::random() {
		for (int i = 0; i < _row*_column; i++) {
			_vector[i] = randomInt(0, 100);
		}
	}

	Matrix Matrix::transpose() const {
		Matrix v1(_column, _row);
		for (int i = 0; i < _row; i++) {
			for (int j = 0; j < _column; j++) {
				int a = _vector[i*_column + j];
				v1._vector[j*_row + i] = a;
			}
		}
		return v1;
	}

	int Matrix::row() const
	{
		return _row;
	}

	int Matrix::column() const
	{
		return _column;
	}

	vector<int> Matrix::getRowNums(int row) const
	{
		vector<int> v1;
		v1.resize(_column);
		for (int i = 0; i < _column; i++) {
			v1[i] = _vector[row*_column + i];
		}
		return v1;
	}

	vector<int> Matrix::getColumnNums(int column) const
	{
		vector<int> v1;
		v1.resize(_row);
		for (int i = 0; i < _row; i++) {
			v1[i] = _vector[i*_column + column];
		}
		return v1;
	}

	Matrix Matrix::operator+(const Matrix & v1)
	{
		Matrix v(_row, _column);
		if (_row == v1._row&&_column == v1._column) {

			for (int i = 0; i < _row*_column; i++) {

				v._vector[i] = _vector[i] + v1._vector[i];

			}
		}
		return v;
	}



	Matrix Matrix::operator*(const Matrix & v1)
	{
		int col = v1._column;
		Matrix v2(_row, col);
		if (_column != v1._row) {
			throw std::invalid_argument("two matrix cant't be multiplied!");
		}
		for (int i = 0; i < _row; i++) {
			for (int j = 0; j < v1._column; j++) {
				vector<int> row = getRowNums(i);
				vector<int> column = v1.getColumnNums(j);
				int count = 0;
				for (int m = 0; m < _column; m++) {
					count = count + row[m] * column[m];
				}
				v2._vector[i*col + j] = count;
			}
		}
		return v2;
	}

	void Matrix::description()
	{
		cout << _row << " * " << _column << "matrix";
	}

	ostream & operator<<(ostream &output, const Matrix& v)
	{
		for (int i = 0; i < v._row*v._column; i++) {
			output << v._vector[i] << " ";
			if ((i + 1) % v._column == 0) {
				output << endl;
			}
		}
		return output;
	}

	SqareMatrix::SqareMatrix(int row) : Matrix(row, row)
	{

	}

	SqareMatrix SqareMatrix::identity(int row) {
		SqareMatrix v(row);
		for (int i = 0; i < v._row; i++) {
			v._vector[i*v._row + i] = 1;
		}
		return v;
	}

	void SqareMatrix::description()
	{
		cout << _row << " row square";
	}
}