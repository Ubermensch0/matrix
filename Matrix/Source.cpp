#include "Matrix.h"

int main()
{
	cout << "A: " << endl;
	Matrix A(3, 3);
	A.randomFill();
	A.show();
	cout << A.det() << endl;
	cout << endl;

	cout << "B: " << endl;
	Matrix B(3, 2);
	B.randomFill();
	B.show();
	cout << endl;

	cout << "C: " << endl;
	Matrix C;
	try 
	{
		C = A * B;
	}
	catch (const exception& th)
	{
		cout << th.what() << endl;
	}
	C.show();
	C.uploadToFile();
	cout << endl;

	cout << "D: " << endl;
	Matrix D;
	try
	{
		D = A + B;
	}
	catch (const exception& th)
	{
		cout << th.what() << endl;
	}
	cout << endl;

	cout << "E: " << endl;
	Matrix E(2, 2);
	E.randomFill();
	E.show();
	cout << endl;
	try
	{
		E = C + B;
	}
	catch (const exception& th)
	{
		cout << th.what() << endl;
	}
	E.show();
	cout << endl;

	cout << "F: " << endl;
	Matrix F(6, 6);
	F.randomFill();
	F.show();
	cout << F.det() << endl;
	cout << endl;

	cout << "G: " << endl;
	Matrix G(3, 2);
	G.randomFill();
	try
	{
		G = G * B;
	}
	catch (const exception& th)
	{
		cout << th.what() << endl;
	}
	cout << endl;

	system("pause");
}