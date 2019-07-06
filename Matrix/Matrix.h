#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Matrix
{
private:
	int n, m;
	int** arr;

public:
	Matrix();
	Matrix(int a, int b);
	Matrix(const Matrix& B);

	int** randomFill();

	void uploadToFile();

	void show();

	Matrix operator*(const Matrix& B);
	Matrix operator+(const Matrix& B);
	Matrix& operator=(const Matrix& C);

	int minor(int** arr, int n);
	int det();

	~Matrix();
};