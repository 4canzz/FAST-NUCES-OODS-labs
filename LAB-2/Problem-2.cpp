#include<iostream>
using namespace std;

class matrix
{
    int **p;
    int r;
    int c;
    int *rowmajor;
    int *multiply1D;
public:
    matrix(int row, int col);
    // Constructor
    void disp2D();
    // displays the elements of **p
    void dispRowMajor();
    // converts 2D into 1D using row major
    //and displays the elements Row Major Order Matrix
    void Multiply_rowMajor(matrix &other);
    // Multiplies Matrices in row major order and save the result in a 1D dynamic array
    void rowMajor_2D();
    // Maps the elements stored in row major order to
    // the 2D array and print the results
    ~matrix();
    // Destructor
};

int main()
{
	matrix a(4,3);
	matrix b(3,4);
	a.disp2D();
	a.dispRowMajor();
	b.disp2D();
	b.dispRowMajor();
	a.Multiply_rowMajor(b);
	a.rowMajor_2D();
	return 0;
}

matrix::matrix(int row,int col) {
	r = row;
	c = col;
	p = new int*[r];
	for(int i=0;i < r;i++) {
		p[i]=new int[c];
		for(int j=0;j < c;j++) {
			p[i][j]=(i + j);
		}
	}

	int index = 0;
	rowmajor = new int[r * c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            rowmajor[index++] = p[i][j];
        }
    }

	multiply1D = new int[r * c];
	for (int i = 0; i < c *r; i++) {
		multiply1D[i] = 0;
	}
}

void matrix::disp2D() {
	cout << "2D Matrix: " << endl;
	for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }
}

void matrix::dispRowMajor() {
    cout << "1D array in row-major order:" << endl;
    for (int i = 0; i < r * c; i++) {
        cout << rowmajor[i] << " ";
    }
    cout << endl;
}

void matrix::Multiply_rowMajor(matrix &other) {
	if (this->c == other.r) {
		int** ansmat;
		ansmat = new int*[r];
		for(int i = 0; i < other.c; i++) {
			ansmat[i] = new int[other.c];
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < other.c; j++) {
				ansmat[i][j] = 0;
				for(int k = 0; k < c; k++)
				{
					ansmat[i][j] += this->p[i][k] * other.p[k][j];
				}
			}
		}

		int index = 0;
		for(int i = 0; i < r; i++) {
			for (int j = 0; j < other.c; j++) {
				multiply1D[index++] = ansmat[i][j];
			}	
		}

		cout << "Resultant Matrix: " << endl;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < other.c; j++) {
				cout << ansmat[i][j] << " ";
			}
			cout << endl;
		}

	}
	else cout << "columns of this matrix is not equal to rows of other, operation cannot be performed." << endl;
}

void matrix::rowMajor_2D() {
	cout << "from row major to 2d: " << endl;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			p[i][j] = rowmajor[i * c + j];
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
}

matrix::~matrix() {
	for (int i = 0; i < r; i++) {
		delete[] p[i];
	}
	delete[] p;
	delete rowmajor;
	delete multiply1D;
}

/* Exercise 2:
Using the abstract data Type of a Matrix given below, write a program that
1. Input a 4*3 matrix from user in 2D array
2. Map this array in 1D array using Row major order
3. Input second matrix of 3*4 in 2D array
4. Map this array in 1D array using Row major order.
5. Now perform matrix multiplication on these 1D arrays
6. Save the result back in a 2D array.
Implement this question for any number of rows and columns using class "matrix"

class matrix
{
    int **p;
    int r;
    int c;
    int *rowmajor;
    int *multiply1D;
public:
    matrix(int row, int col);
    // Constructor
    void disp2D();
    // displays the elements of **p
    void dispRowMajor();
    // converts 2D into 1D using row major
    //and displays the elements Row Major Order Matrix
    void Multiply_rowMajor(matrix &other);
    // Multiplies Matrices in row major order and save the result in a 1D dynamic array
    void rowMajor_2D();
    // Maps the elements stored in row major order to
    // the 2D array and print the results
    ~matrix();
    // Destructor
};

int main()
{
	matrix a(4,3);
	matrix b(3,4);
	a.disp2D();
	a.dispRowMajor();
	b.disp2D();
	b.dispRowMajor();
	a.Multiply_rowMajor(b);
	a.rowMajor_2D();
	return 0;
}*/