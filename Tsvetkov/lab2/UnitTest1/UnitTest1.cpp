#include "pch.h"
#include "CppUnitTest.h"
#include "../ltr/Itr.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string c = "da";
		
			Node* root = new Node(c);
			Itr i(root);
			bool a = i.HasNext();
			Assert::AreEqual(a, false);
		}
	};
}
