#include "pch.h"
#include "CppUnitTest.h"
#include "..\algstr3\Tree.h"
#include "..\algstr3\Tree.cpp"
#include "..\algstr3\Node.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{
	TEST_CLASS(UnitTest3)
	{
	public:
		
		TEST_METHOD(сontains1)
		{
			Tree* T1 = new Tree;
			try
			{
				T1->contains(1);
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "Tree is empty");
			}
		}

		TEST_METHOD(createDepthIterator1)
		{
			Tree* T1 = new Tree;
			try
			{
				T1->CreateDepthIterator();
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "Tree is empty");
			}
		}
		TEST_METHOD(createDepthIterator2)
		{
			Tree* T1 = new Tree;
			T1->insert(1);
			Iterator* iter = T1->CreateDepthIterator();
			Assert::IsTrue(iter->next() == 1);
		}
		TEST_METHOD(remove)
		{
			Tree* T1 = new Tree;
			try
			{
				T1->remove(1);
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "element is absent");
			}
		}
		TEST_METHOD(remove1)
		{
			Tree* T1 = new Tree;
			int arr[10] = { 7,6,9,8,10,2,1,4,3,5 };
			for (int i = 0; i < 10; i++) {
				T1->insert(arr[i]);
			}
			try
			{
				T1->remove(16);
			}
			catch (const char* warning)
			{
				Assert::AreEqual(warning, "element is absent");
			}
		}
		TEST_METHOD(createWidthIterator1)
		{
			Tree* T1 = new Tree;
			int arr[10] = { 7,6,9,2,8,10,1,4,3,5 };
			for (int i = 0; i < 10; i++) {
				T1->insert(arr[i]);
			};
			Iterator* iter = T1->CreateWidthIterator();
			for (int i = 0; i < 10; i++) {
				Assert::IsTrue(arr[i] == iter->next());
			}
		}
		TEST_METHOD(contains2)
		{
			Tree* T1 = new Tree;
			int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
			for (int i = 0; i < 10; i++) {
				T1->insert(arr[i]);
				Assert::IsTrue(T1->contains(arr[i]));
			}
		}
		TEST_METHOD(contains3)
		{
			Tree* T1 = new Tree;
			int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
			for (int i = 0; i < 10; i++) T1->insert(arr[i]);
			Assert::IsFalse(T1->contains(15));
		}
		TEST_METHOD(remove2)
		{
			Tree* T1 = new Tree;
			int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
			for (int i = 0; i < 10; i++) {
				T1->insert(arr[i]);
			}
			T1->remove(1);
			Assert::IsFalse(T1->contains(1));
		}
	};
}
