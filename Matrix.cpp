#include "Matrix.h"

Matrix::Matrix(const int &_row, const int &_col)
{
    this->row = _row;
    this->col = _col;
    mat = new double *[_row];
    for (int i = 0; i < _row; ++i)
        mat[i] = new double[col];
}

double &Matrix::operator()(const int &x, const int &y) const
{
    return mat[x][y];
}

Matrix Matrix::operator*(const Matrix &oth) const
{
    Matrix result(this->row, oth.col);
    for (int i = 0; i < this->row; ++i)
        for (int j = 0; j < oth.col; ++j)
            for (int k = 0; k < this->col; ++k)
                result.mat[i][j] += (*this).mat[i][k] * oth.mat[k][j];

    return result;
}

void Matrix::show(void) const
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
            std::cerr << std::setw(4) << mat[i][j];
        std::cerr << "\n";
    }
}