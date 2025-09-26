#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    cout << "Enter elements row-wise:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "2D Array:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int* arr1D = new int[rows * cols];

    int index = 0;
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            arr1D[index++] = arr[i][j];
        }
    }

    cout << "1D array in column-major order:" << endl;
    for (int i = 0; i < rows * cols; i++) {
        cout << arr1D[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] arr1D;
    return 0;
}

/*Exercise 1:
Write a C++ code to copy data of a 2D array in a 1D array using Column Major Order.*/
