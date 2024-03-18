#include "Matrix.h"
#include <stdexcept>
#include <cmath>
#include <sstream>


using namespace std;

Matrix::Matrix() : K(0), N(0), data(nullptr) {}

Matrix::Matrix(int k, int n) : K(k), N(n) {
    data = new int* [K];
    for (int i = 0; i < K; ++i) {
        data[i] = new int[N]();
    }
}

Matrix::Matrix(const Matrix& other) : K(other.K), N(other.N) {
    data = new int* [K];
    for (int i = 0; i < K; ++i) {
        data[i] = new int[N];
        for (int j = 0; j < N; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

Matrix::~Matrix() {
    if (data != nullptr) {
        for (int i = 0; i < K; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
}

int Matrix::getRows() const {
    return K;
}

int Matrix::getColumns() const {
    return N;
}

int Matrix::getValue(int i, int j) const {
    return data[i][j];
}
void Matrix::setRows(int rows) {
    K = rows;
}

void Matrix::setColumns(int columns) {
    N = columns;
}
void Matrix::setValue(int i, int j, int value) {
    data[i][j] = value;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (K != other.K || N != other.N) {
        throw std::invalid_argument("Розміри матриць не співпадають");
    }
    Matrix result(K, N);
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < N; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

bool Matrix::operator==(const Matrix& other) const {
    if (K != other.K || N != other.N) {
        return false;
    }
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < N; ++j) {
            if (data[i][j] != other.data[i][j]) {
                return false;
            }
        }
    }
    return true;
}

Matrix::operator double() const {
    double sumOfSquares = 0.0;
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < N; ++j) {
            sumOfSquares += data[i][j] * data[i][j];
        }
    }
    return std::sqrt(sumOfSquares);
}

ostream& operator<<(ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.K; ++i) {
        for (int j = 0; j < matrix.N; ++j) {
            os << matrix.data[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

istream& operator>>(istream& is, Matrix& matrix) {
    for (int i = 0; i < matrix.K; ++i) {
        for (int j = 0; j < matrix.N; ++j) {
            is >> matrix.data[i][j];
        }
    }
    return is;
}

Matrix::operator string() const {
    std::stringstream ss;
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < N; ++j) {
            ss << data[i][j] << " ";
        }
        ss << "\n";
    }
    return ss.str();
}

int* Matrix::operator[](int index) {
    return data[index];
}

const int* Matrix::operator[](int index) const {
    return data[index];
}
