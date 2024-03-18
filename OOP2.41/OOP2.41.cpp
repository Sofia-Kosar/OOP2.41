#include "Matrix.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Matrix matrix1(2, 3);
    Matrix matrix2(matrix1);
    Matrix matrix3;
    cout << "������ �������� ������� 1:" << endl;
    cin >> matrix1;
    cout << "������� 1:" << endl;
    cout << matrix1;
    cout << "������ �������� ������� 2:" << endl;
    cin >> matrix2;
    cout << "������� 2:" << endl;
    cout << matrix2;
    try {
        Matrix matrix4 = matrix1 - matrix2;
        cout << "г����� ������� 1 � 2:" << endl;
        cout << matrix4;
    }
    catch (const std::invalid_argument& e) {
        cout << "�������: " << e.what() << endl;
    }

    if (matrix1 == matrix2) {
        cout << "������� ���" << endl;
    }
    else {
        cout << "������� �� ���" << endl;
    }
    cout << "����� ������� 1: " << static_cast<double>(matrix1) << endl;
   
    matrix1[0][0] = 10;
    cout << "���� �������� ������� �������� ������� 1: " << matrix1[0][0] << endl;

    return 0;
}
