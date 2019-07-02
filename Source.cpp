#include <iostream>
#include <fstream>

using namespace std;

class Matrix
{
private:
	int n, m;
	int** arr;

public:
	Matrix()
	{
		this->n = 0;
	}
	Matrix(int a, int b)
	{
		this->n = a;
		this->m = b;
		this->arr = (int**)malloc(n*sizeof(int));

		for (int i = 0; i < n; i++)
		{
			arr[i] = (int*)malloc(m * sizeof(int));
			for (int j = 0; j < m; j++)
			{
				arr[i][j] = 0;
			}
		}
	}
	Matrix(const Matrix &B)
	{
		this->n = B.n;
		this->m = B.m;
		this->arr = (int**)malloc(this->n * sizeof(int));
		for (int i = 0; i < this->n; i++)
		{
			arr[i] = (int*)malloc(this->m * sizeof(int));
			for (int j = 0; j < this->m; j++)
			{
				this->arr[i][j] = B.arr[i][j];
			}
		}
	}

	int** fill()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				arr[i][j] = rand()%10;
			}
		}
		return arr;
	}

	void file()
	{
		ofstream file;
		file.open("File.txt");
		if (!file.is_open())
		{
			cout << "Error";
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					file << arr[i][j];
					file << " ";
				}
				file << "\n";
			}
		}
		file.close();
	}

	void show()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << arr[i][j];
				cout << " ";
			}
			cout << endl;
		}
	}

	Matrix operator*(const Matrix &B)
	{
		try 
		{  
			if (this->m == B.n)
			{
				Matrix C;
				C.n = this->n;
				C.m = B.m;
				C.arr = (int**)calloc(C.n, sizeof(int));

				for (int i = 0; i < C.n; i++)
				{
					C.arr[i] = (int*)calloc(C.m, sizeof(int));
					for (int j = 0; j < C.m; j++)
					{
						for (int k = 0; k < B.n; k++)
						{
							C.arr[i][j] += this->arr[i][k] * B.arr[k][j];
						}
					}
				}
				return C;
			}
			else 
			{
				throw exception("Invalid size");
			}
		}
		catch (const exception &th)
		{
			cout << th.what() << endl;
		}
	}
	Matrix operator+(const Matrix &B)
	{
		try
		{
			if (this->n == B.n && this->m == B.m)
			{
				Matrix C;
				C.n = this->n;
				C.m = this->m;
				C.arr = (int**)malloc(C.n * sizeof(int));

				for (int i = 0; i < C.n; i++)
				{
					C.arr[i] = (int*)malloc(C.m * sizeof(int));
					for (int j = 0; j < C.m; j++)
					{
						C.arr[i][j] = this->arr[i][j] + B.arr[i][j];
					}
				}
				return C;
			}
			else 
			{
				throw exception("Invalid size");
			}
		}
		catch (const exception &th)
		{
			cout << th.what()<<endl;
		}
	}
	Matrix& operator=(const Matrix &C)
	{
		if (this->n != 0)
		{
			for (int i = 0; i < n; i++)
			{
				free (this->arr[i]);
			}
			free (this->arr);
		}

		this->n = C.n;
		this->m = C.m;
		this->arr = (int**)malloc(this->n * sizeof(int));

		for (int i = 0; i < C.n; i++)
		{
			this->arr[i] = (int*)malloc(this->m * sizeof(int));
			for (int j = 0; j < C.m; j++)
			{
				this->arr[i][j] = C.arr[i][j];
			}
		}
		return *this;
	}

	int minor(int** arr,int n)
	{
		int** tmp = new int*[n];
		int i = 0; 
		int result=0;
		if (n == 2) 
		{
			result = arr[0][0] * arr[1][1] - (arr[1][0] * arr[0][1]);
			return result;
		}
		int a = 0;
		while (i < n)
		{
			int m = n - 1;
			for (int j = 0; j < m; j++)
			{
				int c = 0;
				tmp[j] = new int[m];
				for (int k = 0; k < m; k++)
				{
					if (c != i)
					{
						tmp[j][k] = arr[j+1][c];
						c++;
					}
					else
					{
						c++;
						k--;
					}
				}
			}
			a++;
			result = result + arr[0][i] * (a % 2==0 ? -1 : 1)*minor(tmp, m);
			i++;
		}
		return result;
	}
	int det()
	{
		return minor(arr, m);
	}

	~Matrix()
	{
		for (int i = 0; i < n; i++)
		{
			free(arr[i]);
		}
		free(arr);
	}
};

int main()
{
	cout << "A: " << endl;
	Matrix A(3,3);
	A.fill();
	A.show();
	cout << A.det() << endl;
	cout << endl;
	
	cout << "B: " << endl;
	Matrix B(3,2);
	B.fill();
	B.show();
	cout << endl;

	cout << "C: " << endl;
	Matrix C;
	C = A * B;
	C.show();
	C.file();
	cout << endl;

	cout << "D: " << endl;
	Matrix D;
	D = A + B;
	cout << endl;

	cout << "E: " << endl;
	Matrix E(2, 2);
	E.fill();
	E.show();
	cout << endl;
	E = C + B;
	E.show();
	cout << endl;

	cout << "F: " << endl;
	Matrix F(6,6);
	F.fill();
	F.show();
	cout<<F.det()<<endl;
	cout << endl;

	cout << "G: " << endl;
	Matrix G(3, 2);
	G.fill();
	G = G * B;
	cout << endl;

	system("pause");
}