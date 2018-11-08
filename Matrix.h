#ifndef MATRIX_H
#define MATRIX_H

#include <bits/stdc++.h>

class Matrix 
{
public:
    int col;
    int row;
    double **mat;
    
    Matrix() {}

    /** 
     * construct matrix with fixed width and height
    */
    Matrix(const int &_row, const int &_col);    

    /** 
     * construct a matrix by passing a 2 dimension - array 
    */
    template <int ROWS, int COLS>
    Matrix(const int &_row, const int &_col, double (&example)[ROWS][COLS])
    {
        this->row = _row;
        this->col = _col;
        mat = new double *[_row];
        for (int i = 0; i < _row; ++i)
            mat[i] = new double[col];
        for (int i = 0; i < _row; ++i)
        {
            for (int j = 0; j < _col; ++j)
                mat[i][j] = example[i][j];
        }
    }
    
    /** 
     * get value at cell[x][y] of matrix
    */
    double& operator()(const int &x, const int &y) const;    

    /**
     * multiply two matrices
    */
    Matrix operator * (const Matrix &oth) const;
    
    void show(void) const;    

    // @Destructor
    ~Matrix() 
    {
        delete[] mat;
    }
};

#endif