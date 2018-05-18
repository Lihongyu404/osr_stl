#include <iostream>
#include <stdio.h>
#include "LinkedList.h"
#include <gtest/gtest.h>

using namespace std;
class TestNode
{
public:
	TestNode(){}
	TestNode(int x, int y):m_x(x),m_y(y){}
	bool operator==(const TestNode & testNoded)
	{
		return m_x == testNoded.m_x && m_y == testNoded.m_y;
	}
    int m_x;
	int m_y;
};
class LinkedListTest:public testing::Test
{
protected:
	LinkedList<TestNode> m_LinkedList;
	virtual void SetUp()
	{
		for (int i = 0; i < 6; i++)
		{
			m_LinkedList.PushBack({i,i});
		}
	}

	virtual void TearDown()
	{
		m_LinkedList.Clear();
	}
};

TEST_F(LinkedListTest, Begin)
{
	LinkedList<TestNode>::Iterator iterator = m_LinkedList.Begin();
	EXPECT_EQ(true, TestNode(0,0) == *iterator);
	
}
TEST_F(LinkedListTest, ADD)
{
	LinkedList<TestNode>::Iterator iterator = m_LinkedList.Begin();
	EXPECT_EQ(true, TestNode(0,0) == *iterator++);
	EXPECT_EQ(true, TestNode(1,1) == *iterator++);
	EXPECT_EQ(true, TestNode(3,3) == *(++iterator));
}

TEST_F(LinkedListTest, SUB)
{
	LinkedList<TestNode>::Iterator iterator = m_LinkedList.End();
	EXPECT_EQ(true, TestNode(5,5) == *--iterator);
	EXPECT_EQ(true, TestNode(5,5) == *iterator--);
	EXPECT_EQ(true, TestNode(4,4) == *(iterator--));
}
TEST_F(LinkedListTest, Erase)
{
	LinkedList<TestNode>::Iterator iterator = m_LinkedList.Begin();
	m_LinkedList.Erase(iterator);
	iterator = m_LinkedList.Begin();
	EXPECT_EQ(true, TestNode(1,1) == *iterator);
	EXPECT_EQ(5,    m_LinkedList.Size());

	m_LinkedList.Erase(iterator);
	iterator = m_LinkedList.Begin();
	EXPECT_EQ(true, TestNode(2,2) == *iterator);
	EXPECT_EQ(4,    m_LinkedList.Size());

	m_LinkedList.Erase(iterator);
	iterator = m_LinkedList.Begin();
	EXPECT_EQ(true, TestNode(3,3) == *iterator);
	EXPECT_EQ(3,    m_LinkedList.Size());

	m_LinkedList.Erase(iterator);
	iterator = m_LinkedList.Begin();
	EXPECT_EQ(true, TestNode(4,4) == *iterator);
	EXPECT_EQ(2,    m_LinkedList.Size());

	m_LinkedList.Erase(iterator);
	iterator = m_LinkedList.Begin();
	EXPECT_EQ(true, TestNode(5,5) == *iterator);
	EXPECT_EQ(1,    m_LinkedList.Size());

	m_LinkedList.Erase(iterator);
	iterator = m_LinkedList.Begin();
	EXPECT_EQ(0,    m_LinkedList.Size());
	
	m_LinkedList.Erase(iterator);
	EXPECT_EQ(0, 	m_LinkedList.Size());	
}

TEST_F(LinkedListTest, Clear)
{
	for (int i = 0; i < 6; i++)
	{
		m_LinkedList.PushBack({i,i});
	}
	m_LinkedList.Clear();
	EXPECT_EQ(0, 	m_LinkedList.Size());	
}

TEST_F(LinkedListTest, Scan)
{
	LinkedList<TestNode>::Iterator iterator = m_LinkedList.Begin();
	int index = 0;
	for (; iterator != m_LinkedList.End(); iterator++)
	{
		EXPECT_EQ(true,  TestNode(index, index) == 	TestNode(iterator->m_x, iterator->m_y));
		index++;
	}
}


int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	return 0;
}

