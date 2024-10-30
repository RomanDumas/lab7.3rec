#include "pch.h"
#include "CppUnitTest.h"
#include "../LR7.3rec/LR7.3rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rows = 3;
			const int cols = 3;
			int** a = new int* [rows];
			for (int i = 0; i < rows; i++) {
				a[i] = new int[cols];
			}

			a[1][0] = -3; a[1][1] = -5; a[1][2] = 4;
			a[2][0] = -7; a[2][1] = 6; a[2][2] = -9;

			int sum = SumAbs(a, cols, rows, 1, 0, 0);
			Assert::AreEqual(10, sum);

			for (int i = 0; i < rows; i++) {
				delete[] a[i];
			}
			delete[] a;
		}
		TEST_METHOD(TestMethod2) 
		{
			const int rows = 3;
			const int cols = 3;
			int** a = new int* [rows];
			for (int i = 0; i < rows; i++) {
				a[i] = new int[cols];
			}

			a[1][0] = 1; a[1][1] = 0; a[1][2] = 4;
			a[2][0] = 5; a[2][1] = 6; a[2][2] = -3;

			int result = CheckForNull(a, cols, rows, 0, 1);
			Assert::AreEqual(1, result);

			for (int i = 0; i < rows; i++) {
				delete[] a[i];
			}
			delete[] a;
		}
	};
}
