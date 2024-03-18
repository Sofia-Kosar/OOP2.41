#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP2.41/Matrix.cpp"
#include "../OOP2.41/Matrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest241
{
	TEST_CLASS(UnitTest241)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Matrix matrix(3, 4);

			int rows = matrix.getRows();

			Assert::AreEqual(3, rows);
		}
	};
}
