#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

class Matrix {
private:
    int K; 
    int N; 
    int** data; 

public:
    // Конструктори
    Matrix();
    Matrix(int k, int n);
    Matrix(const Matrix& other);

    ~Matrix();

    int getRows() const;
    int getColumns() const;
    int getValue(int i, int j) const;
    void setRows(int rows);
    void setColumns(int columns);
    void setValue(int i, int j, int value);

    // Операції
    Matrix operator-(const Matrix& other) const;
    bool operator==(const Matrix& other) const;
    operator double() const;

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
    friend std::istream& operator>>(std::istream& is, Matrix& matrix);
    operator string() const;
    int* operator[](int index);
    const int* operator[](int index) const;
};

#endif 