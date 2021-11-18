#include "pch.h"
#include "CppUnitTest.h"
#include "../7.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ut72
{
	TEST_CLASS(ut72)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int** a = new int* [2];

			for (int i = 0; i < 2; i++) {

				a[i] = new int[2];

			}



			a[0][0] = 0;

			a[0][1] = 0;

			a[1][1] = 0;

			a[1][0] = 1;



			second(a, 2);



			Assert::AreEqual(1, a[1][1]);
		}
	};
}
