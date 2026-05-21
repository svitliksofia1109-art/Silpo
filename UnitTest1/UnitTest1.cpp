#include "pch.h"
#include "CppUnitTest.h"
#include "../Сільпо/Order.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestAddProduct)
		{
			Order order;

			order.AddProduct("Milk", 2);

			Assert::AreEqual(1, order.GetProductsCount());
			Assert::AreEqual(2, order.GetQuantity("Milk"));
		}

		TEST_METHOD(TestRemoveProduct)
		{
			Order order;

			order.AddProduct("Milk", 2);
			order.RemoveProduct("Milk");

			Assert::AreEqual(0, order.GetProductsCount());
		}

		TEST_METHOD(TestChangeQuantity)
		{
			Order order;

			order.AddProduct("Bread", 1);
			order.ChangeQuantity("Bread", 5);

			Assert::AreEqual(5, order.GetQuantity("Bread"));
		}

		TEST_METHOD(TestSetStatus)
		{
			Order order;

			order.SetStatus("Paid");

			Assert::AreEqual("Paid", order.GetStatus().c_str());
		}

		TEST_METHOD(TestSetDate)
		{
			Order order;

			order.SetData("2026-05-15");

			Assert::AreEqual("2026-05-15", order.GetDate().c_str());
		}
	};
}