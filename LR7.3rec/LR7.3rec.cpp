#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void CreateRows(int** a, const int cols, const int rows, int i, int j);
void CreateCols(int** a, const int cols, const int rows, int i, int j);
void PrintRows(int** a, const int cols, const int rows, int i, int j);
void PrintCols(int** a, const int cols, const int rows, int i, int j);
void HarCol(int** a, const int cols, const int rows, int sum, int i, int j, int p);
int SumAbs(int** a, const int cols, const int rows, int i, int j, int sum);
void PrintCharacteristic(int** a, const int cols);
void Sort(int** a, const int cols, const int rows, int k, int i, int j);
void SortCols(int** a, const int cols, const int rows, int k, int i, int j);
void SumCols(int** a, const int cols, const int rows, int i, int p, int j, int sum, int t);
void FindingCols(int** a, const int cols, const int rows, int j, int p,int i, int t);
int CheckForNull(int** a, const int cols, const int rows, int i, int j);
void ExchangeCols(int** a, const int cols, const int rows, int i, int j);


int main() {
	srand((unsigned)time(NULL));
	int rows, cols, sum = 0;
	int i = 0, j = 0, p=0;
	cout << "rows = "; cin >> rows;
	cout << "cols = "; cin >> cols;
	int** a = new int* [rows + 1];
	for (int i = 0; i < rows + 1; i++)
		a[i] = new int[cols];

	CreateRows(a, cols, rows + 1, 1, j);
	cout << endl << "the arrey" << endl;
	PrintRows(a, cols, rows + 1, 1 ,j);
	cout << endl << endl;

	HarCol(a, cols, rows + 1, sum, i, j, p);

	cout << "Added characteristic" << endl;
	PrintCharacteristic(a, cols);
	PrintRows(a, cols, rows, 1, j);

	Sort(a, cols, rows + 1, 0, 0, j);
	cout << endl << "Sorted array " << endl;
	PrintCharacteristic(a, cols);
	PrintRows(a, cols, rows + 1, 1, j);
	cout << "there is -1 when column is without 0 \n" << endl;
	FindingCols(a, cols, rows + 1, j, p,i, 0);
	
	for (int i = 0; i < rows; i++)
		delete a[i];
	delete[] a;

	return 0;
}
void CreateRows(int** a, const int cols, const int rows, int i, int j) {
	if (i > rows - 1)
		return;
	j = 0;
	CreateCols(a, cols, rows, i, j);
	return CreateRows(a, cols, rows, i + 1, j);
}
void CreateCols(int** a, const int cols, const int rows, int i, int j) {
	if (j > cols - 1)
		return;
	a[i][j] = -10 + rand() * 21 / RAND_MAX;
	return CreateCols(a, cols, rows, i, j + 1);
}
void PrintRows(int** a, const int cols, const int rows, int i, int j) {
	if (i > (rows - 1)) {
		cout << endl;
		return;
	}
	cout << "                    ";
	cout << setw(4) << a[i][j] << " ";
	PrintCols(a, cols, rows, i, j + 1);
	return PrintRows(a, cols, rows, i + 1, j);
}
void PrintCols(int** a, const int cols, const int rows, int i, int j) {
	if (j > cols - 1) {
		cout << endl;
		return;
	}
	cout << setw(3) << a[i][j] << " ";
	return PrintCols(a, cols, rows, i, j + 1);
}
void HarCol(int** a, const int cols, const int rows, int sum, int i, int j, int p) {
	if (j > cols - 1)
		return;
	sum = 0;
	i = 1;
	sum = SumAbs(a, cols, rows, i, j, sum);
	if (sum == 0) 
		a[0][p++] = -1;
	else
		a[0][p++] = sum;
	
	return HarCol(a, cols, rows, sum, i, j+1, p);
}
int SumAbs(int** a, const int cols, const int rows, int i, int j, int sum) {
	if (i > rows - 1)
		return sum;
	if (a[i][j] < 0 && abs(a[i][j]) % 2 == 1)
		sum += abs(a[i][j]);
	return SumAbs(a, cols, rows, i + 1, j, sum);
}
void PrintCharacteristic(int** a, const int cols) {
	cout << "characteristic cols ";
	for (int j = 0; j < cols; j++)
		cout << setw(4) << a[0][j];
	cout << endl;
	
}
void PrintCharacteristic(int** a, const int cols, int j) {
	if (j > cols - 1)
		return;
	cout << setw(4) << a[0][j];
	cout << endl;
	return PrintCharacteristic(a, cols, j+1);
}

void Sort(int** a, const int cols, const int rows, int k, int i, int j) {
	if (k > cols - 2)
		return;
	SortCols(a, cols, rows,k , i, j);
	return Sort(a, cols, rows, k + 1, i, j);
}
void SortCols(int** a, const int cols, const int rows, int k, int i, int j) {
	if (j > cols - k - 2)
		return;
	if (a[0][j] > a[0][j + 1])
		ExchangeCols(a, cols, rows, i, j);
	return SortCols(a, cols, rows,k, i, j + 1);
}
void ExchangeCols(int** a, const int cols, const int rows, int i, int j) {
	if (i > rows-1)
		return;
	int tmp = a[i][j + 1];
	a[i][j + 1] = a[i][j];
	a[i][j] = tmp;
	return ExchangeCols(a, cols, rows, i + 1, j);
}

void FindingCols(int** a, const int cols, const int rows, int j, int p, int i, int t) {
	if (j > cols - 1)
		return;
	t = CheckForNull(a, cols, rows, i, j);
	SumCols(a, cols, rows, 1, p, j, p, t);
	p++;
	return FindingCols(a, cols, rows, j + 1, p,i, t);
}

void SumCols(int** a, const int cols, const int rows, int i, int p, int j, int sum, int t) { //працюэ
	if (i > rows-1) {
		cout << "sum column No" << p << " = " << sum << endl;
		return;
	}
	
	if (t == 1)
		sum += a[i][j];
	else
		sum = -1;
	return SumCols(a, cols, rows, i+1, p, j, sum, t);
}
int CheckForNull(int** a, const int cols, const int rows, int i, int j) {
	if (i > rows-1)
		return -1;
	if (a[i][j] == 0)
		return 1;
	return CheckForNull(a, cols, rows, i + 1, j);

}