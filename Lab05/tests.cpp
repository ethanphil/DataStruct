
#include "WhatToSort.h"
#include <gtest/gtest.h>


/* 	void TestEmpty(ILinkedList* list)
	{
			ASSERT_TRUE(list->isEmpty());

			ASSERT_EQ(std::string(""), list->toString());

			list->clear();
			ASSERT_TRUE(list->isEmpty());

	}
		TEST(PointerBasedLinkedList,TestEmpy)
		{
			ILinkedList *linkedList = new PointerBasedLinkedList();

			TestEmpty(linkedList);

			delete linkedList;

		}
		
        TEST(ArrayBasedLinkedList, TestEmpy) 
		{           
			ILinkedList *linkedList = new ArrayBasedLinkedList();

			TestEmpty(linkedList);

			delete linkedList;
		}

		void Test1Add(ILinkedList* list)
		{
			ASSERT_TRUE(list->isEmpty());
			ASSERT_TRUE(list->add(1));

			ASSERT_FALSE(list->isEmpty());

			ASSERT_EQ(std::string("1"), list->toString());

			list->clear();
			ASSERT_TRUE(list->isEmpty());

		}

		TEST(ArrayBasedLinkedList, Test1Add)
		{
			ILinkedList *linkedList = new ArrayBasedLinkedList();
			Test1Add(linkedList);
			delete linkedList;
		}

		TEST(PointerBasedLinkedList,Test1Add)
		{
			ILinkedList* linkedList = new PointerBasedLinkedList();
			Test1Add(linkedList);
			delete linkedList;
		}

		void Test2Add(ILinkedList * list)
		{
			ASSERT_TRUE(list->isEmpty());
			ASSERT_TRUE(list->add(1));
			ASSERT_TRUE(list->add(2));

			ASSERT_FALSE(list->isEmpty());

			ASSERT_EQ(std::string("1 2"), list->toString());

			list->clear();
			ASSERT_TRUE(list->isEmpty());
		}

		TEST(ArrayBasedLinkedList, Test2Add)
		{
			ILinkedList * linkedList = new ArrayBasedLinkedList();
			Test2Add(linkedList);
			delete linkedList;
		}

		TEST(PointerBasedLinkedList,Test2Add)
		{
			ILinkedList * linkedList = new PointerBasedLinkedList();
			Test2Add(linkedList);
			delete linkedList;
		}

		void Test3Add(ILinkedList* list)
		{
			ASSERT_TRUE(list->isEmpty());
			ASSERT_TRUE(list->add(1));
			ASSERT_TRUE(list->add(2));
			ASSERT_TRUE(list->add(3));

			ASSERT_FALSE(list->isEmpty());

			ASSERT_EQ(std::string("1 2 3"), list->toString());

			list->clear();
			ASSERT_TRUE(list->isEmpty());
		}

		TEST(ArrayBasedLinkedList, Test3Add)
		{
			ILinkedList *linkedList = new ArrayBasedLinkedList();
			Test3Add(linkedList);
			delete linkedList;
		}


		TEST(PointerBasedLinkedList,Test3Add)
		{
			ILinkedList *linkedList = new PointerBasedLinkedList();
			Test3Add(linkedList);
			delete linkedList;
		}

		void Test11Add(ILinkedList* list, bool isPointerBased)
		{
			ASSERT_TRUE(list->isEmpty());
			ASSERT_TRUE(list->add(1));
			ASSERT_TRUE(list->add(2));
			ASSERT_TRUE(list->add(3));
			ASSERT_TRUE(list->add(4));
			ASSERT_TRUE(list->add(5));
			ASSERT_TRUE(list->add(6));
			ASSERT_TRUE(list->add(7));
			ASSERT_TRUE(list->add(8));
			ASSERT_TRUE(list->add(9));
			ASSERT_TRUE(list->add(10));
			if(isPointerBased)
			{
				ASSERT_TRUE(list->add(11));
			}
			else
			{
				ASSERT_FALSE(list->add(11));//Capacity is 11 so won't add
			}

			ASSERT_FALSE(list->isEmpty());

			if(isPointerBased)
			{
				ASSERT_EQ(std::string("1 2 3 4 5 6 7 8 9 10 11"), list->toString());
			}
			else
			{
				ASSERT_EQ(std::string("1 2 3 4 5 6 7 8 9 10"), list->toString());//Capacity is 11 so won't add
			}

			list->clear();
			ASSERT_TRUE(list->isEmpty());
		}

		TEST(ArrayBasedLinkedList, Test11Add)
		{
			ILinkedList * linkedList = new ArrayBasedLinkedList();
			Test11Add(linkedList, false);
			delete linkedList;
		}

		TEST(PointerBasedLinkedList, Test11Add)
		{
			ILinkedList * linkedList = new PointerBasedLinkedList();
			Test11Add(linkedList, true);
			delete linkedList;
		}

		void TestRemoveNonExistant(ILinkedList* list)
		{
			ASSERT_TRUE(list->isEmpty());
			ASSERT_TRUE(list->add(1));
			ASSERT_TRUE(list->add(2));
			ASSERT_TRUE(list->add(3));

			ASSERT_FALSE(list->remove(4));

			ASSERT_FALSE(list->isEmpty());

			ASSERT_EQ(std::string("1 2 3"), list->toString());

			list->clear();
			ASSERT_TRUE(list->isEmpty());
		}

		TEST(ArrayBasedLinkedList, TestRemoveNonExistant)
		{
			ILinkedList* linkedList = new ArrayBasedLinkedList();
			TestRemoveNonExistant(linkedList);
			delete linkedList;
		}

		TEST(PointerBasedLinkedList, TestRemoveNonExistant)
		{
			ILinkedList* linkedList = new PointerBasedLinkedList();
			TestRemoveNonExistant(linkedList);
			delete linkedList;
		}

		void TestBeginingRemove(ILinkedList* list)
		{
			ASSERT_TRUE(list->isEmpty());
			ASSERT_TRUE(list->add(1));
			ASSERT_TRUE(list->add(2));
			ASSERT_TRUE(list->add(3));

			ASSERT_TRUE(list->remove(1));

			ASSERT_FALSE(list->isEmpty());

			ASSERT_EQ(std::string("2 3"), list->toString());

			list->clear();
			ASSERT_TRUE(list->isEmpty());
		}

		TEST(ArrayBasedLinkedList, TestBeginingRemove)
		{
			ILinkedList* linkedList = new ArrayBasedLinkedList();
			TestBeginingRemove(linkedList);
			delete linkedList;
		}

		TEST(PointerBasedLinkedList, TestBeginingRemove)
		{
			ILinkedList* linkedList = new PointerBasedLinkedList();
			TestBeginingRemove(linkedList);
			delete linkedList;
		}

		void TestMiddleRemove(ILinkedList* list)
		{
			ASSERT_TRUE(list->isEmpty());
			ASSERT_TRUE(list->add(1));
			ASSERT_TRUE(list->add(2));
			ASSERT_TRUE(list->add(3));

			ASSERT_TRUE(list->remove(2));

			ASSERT_FALSE(list->isEmpty());

			ASSERT_EQ(std::string("1 3"), list->toString());

			list->clear();
			ASSERT_TRUE(list->isEmpty());
		}

		TEST(PointerBasedLinkedList, TestMiddleRemove)
		{
			ILinkedList* linkedList = new PointerBasedLinkedList();
			TestMiddleRemove(linkedList);
			delete linkedList;
		}

		TEST(ArrayBasedLinkedList, TestMiddleRemove)
		{
			ILinkedList* linkedList = new ArrayBasedLinkedList();
			TestMiddleRemove(linkedList);
			delete linkedList;
		}

		void TestEndRemove(ILinkedList* list)
		{
			ASSERT_TRUE(list->isEmpty());
			ASSERT_TRUE(list->add(1));
			ASSERT_TRUE(list->add(2));
			ASSERT_TRUE(list->add(3));

			ASSERT_TRUE(list->remove(3));

			ASSERT_FALSE(list->isEmpty());

			ASSERT_EQ(std::string("1 2"), list->toString());

			list->clear();
			ASSERT_TRUE(list->isEmpty());
		}

		TEST(ArrayBasedLinkedList, TestEndRemove)
		{
			ILinkedList* linkedList = new ArrayBasedLinkedList();
			TestEndRemove(linkedList);
			delete linkedList;
		}

		TEST(PointerBasedLinkedList, TestEndRemove)
		{
			ILinkedList* linkedList = new PointerBasedLinkedList();
			TestEndRemove(linkedList);
			delete linkedList;
		}

		void TestMultipleRemove(ILinkedList* list)
		{
			ASSERT_TRUE(list->isEmpty());
			ASSERT_TRUE(list->add(1));
			ASSERT_TRUE(list->add(2));
			ASSERT_TRUE(list->add(3));
			ASSERT_TRUE(list->add(4));
			ASSERT_TRUE(list->add(5));
			ASSERT_TRUE(list->add(6));
			ASSERT_TRUE(list->add(7));
			ASSERT_TRUE(list->add(8));
			ASSERT_TRUE(list->add(9));
			ASSERT_TRUE(list->add(10));
			ASSERT_FALSE(list->add(11));

			ASSERT_TRUE(list->remove(2));
			ASSERT_TRUE(list->remove(4));
			ASSERT_TRUE(list->remove(6));
			ASSERT_TRUE(list->remove(8));

			ASSERT_FALSE(list->remove(2));
			ASSERT_FALSE(list->remove(4));
			ASSERT_FALSE(list->remove(6));
			ASSERT_FALSE(list->remove(8));

			ASSERT_FALSE(list->isEmpty());

			ASSERT_EQ(std::string("1 3 5 7 9 10"), list->toString());

			list->clear();
			ASSERT_TRUE(list->isEmpty());
		}

		TEST(ArrayBasedLinkedList, TestMultipleRemove)
		{
			ILinkedList* linkedList = new ArrayBasedLinkedList();
			TestMultipleRemove(linkedList);
			delete linkedList;

		}

		TEST(PointerBasedLinkedList, TestMultipleRemove)
		{
			ILinkedList* linkedList = new PointerBasedLinkedList();
			TestMultipleRemove(linkedList);
			delete linkedList;
		} */


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
