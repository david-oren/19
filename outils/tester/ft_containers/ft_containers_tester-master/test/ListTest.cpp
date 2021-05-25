#include <gtest/gtest.h>

TEST(ListTest, Constructor)
{
	// constructors used in the same order as described above:
	LIBRARY::list<int> first;								 // empty list of ints
	LIBRARY::list<int> second(4, 100);						 // four ints with value 100
	LIBRARY::list<int> third(second.begin(), second.end());	 // iterating through second
	LIBRARY::list<int> fourth(third);						 // a copy of third

	// the iterator constructor can also be used to construct from arrays:
	int myints[] = {16, 2, 77, 29, 22};
	LIBRARY::list<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

	EXPECT_EQ(first.size(), size_t(0));
	EXPECT_EQ(second.size(), size_t(4));
	EXPECT_EQ(third.size(), size_t(4));
	EXPECT_EQ(fourth.size(), size_t(4));
	EXPECT_EQ(fifth.size(), size_t(5));
	for (LIBRARY::list<int>::iterator it = second.begin(); it != second.end(); ++it)
		EXPECT_EQ(*it, 100);
	int i = 0;
	for (LIBRARY::list<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		EXPECT_EQ(*it, myints[i++]);
}

TEST(ListTest, AssignmentOp)
{
	LIBRARY::list<int> first(3);   // list of 3 zero-initialized ints
	LIBRARY::list<int> second(5);  // list of 5 zero-initialized ints

	second = first;
	first = LIBRARY::list<int>();

	EXPECT_EQ(first.size(), size_t(0));
	EXPECT_EQ(second.size(), size_t(3));
}

TEST(ListTest, Begin)
{
	int myints[] = {75, 23, 65, 42, 13};
	LIBRARY::list<int> mylist(myints, myints + 5);
	std::list<int> stdlist(myints, myints + 5);

	LIBRARY::list<int>::iterator it = mylist.begin();
	std::list<int>::iterator stdit = stdlist.begin();

	while (it != mylist.end())
	{
		EXPECT_EQ(*it, *stdit);
		stdit++;
		it++;
	}
}

TEST(ListTest, ReverseBegin)
{
	LIBRARY::list<int> mylist;
	for (int i = 1; i <= 5; ++i)
		mylist.push_back(i);

	int i = 5;
	for (LIBRARY::list<int>::reverse_iterator rit = mylist.rbegin(); rit != mylist.rend(); ++rit)
		EXPECT_EQ(*rit, i--);
}

TEST(ListTest, Empty)
{
	LIBRARY::list<int> mylist;
	int sum(0);

	for (int i = 1; i <= 10; ++i)
		mylist.push_back(i);

	while (!mylist.empty())
	{
		sum += mylist.front();
		mylist.pop_front();
	}
	EXPECT_EQ(sum, 55);
}

TEST(ListTest, Size)
{
	LIBRARY::list<int> myints;
	EXPECT_EQ(myints.size(), size_t(0));

	for (int i = 0; i < 10; i++)
		myints.push_back(i);
	EXPECT_EQ(myints.size(), size_t(10));

	myints.insert(myints.begin(), 10, 100);
	EXPECT_EQ(myints.size(), size_t(20));

	myints.pop_back();
	EXPECT_EQ(myints.size(), size_t(19));
}

TEST(ListTest, MaxSize)
{
	LIBRARY::list<int> mylist;
	std::list<int> stdlist;
	EXPECT_EQ(mylist.max_size(), stdlist.max_size());
	LIBRARY::list<char> mylist1;
	std::list<char> stdlist1;
	EXPECT_EQ(mylist1.max_size(), stdlist1.max_size());
	LIBRARY::list<double> mylist2;
	std::list<double> stdlist2;
	EXPECT_EQ(mylist2.max_size(), stdlist2.max_size());
}

TEST(ListTest, Front)
{
	LIBRARY::list<int> mylist;

	mylist.push_back(77);
	mylist.push_back(22);

	EXPECT_EQ(mylist.front(), 77);
	mylist.front() -= mylist.back();
	EXPECT_EQ(mylist.front(), 55);
}

TEST(ListTest, Back)
{
	LIBRARY::list<int> mylist;

	mylist.push_back(10);

	while (mylist.back() != 0)
	{
		mylist.push_back(mylist.back() - 1);
	}
	int i = 10;
	for (LIBRARY::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		EXPECT_EQ(*it, i--);
}

TEST(ListTest, Assign)
{
	LIBRARY::list<int> first;
	LIBRARY::list<int> second;

	first.assign(7, 100);  // 7 ints with value 100
	EXPECT_EQ(first.size(), size_t(7));
	second.assign(first.begin(), first.end());	// a copy of first

	int myints[] = {1776, 7, 4};
	first.assign(myints, myints + 3);  // assigning from array
	EXPECT_EQ(second.size(), size_t(7));
	EXPECT_EQ(first.size(), size_t(3));
}

TEST(ListTest, PushFront)
{
	LIBRARY::list<int> mylist(2, 100);	// two ints with a value of 100

	for (int i = 0; i < 1300; ++i)
		mylist.push_front(i);

	EXPECT_EQ(mylist.size(), size_t(1302));
}

TEST(ListTest, PopFront)
{
	LIBRARY::list<int> mylist;
	mylist.push_back(100);
	mylist.push_back(200);
	mylist.push_back(300);

	while (!mylist.empty())
	{
		mylist.pop_front();
	}
	EXPECT_EQ(mylist.size(), size_t(0));
}

TEST(ListTest, PushBack)
{
	LIBRARY::list<int> mylist;
	for (int i = 0; i < 1300; ++i)
		mylist.push_back(i);

	EXPECT_EQ(mylist.size(), size_t(1300));
}

TEST(ListTest, PopBack)
{
	LIBRARY::list<int> mylist;
	int sum(0);
	mylist.push_back(100);
	mylist.push_back(200);
	mylist.push_back(300);

	while (!mylist.empty())
	{
		sum += mylist.back();
		mylist.pop_back();
	}
	EXPECT_EQ(sum, 600);
}

TEST(ListTest, Insert)
{
	LIBRARY::list<int> mylist;
	LIBRARY::list<int>::iterator it;

	// set some initial values:
	for (int i = 1; i <= 5; ++i)
		mylist.push_back(i);  // 1 2 3 4 5

	it = mylist.begin();
	++it;  // it points now to number 2           ^

	mylist.insert(it, 10);	// 1 10 2 3 4 5

	// "it" still points to number 2                      ^
	mylist.insert(it, 2, 20);  // 1 10 20 20 2 3 4 5

	--it;  // it points now to the second 20            ^

	std::vector<int> myvector(2, 30);
	mylist.insert(it, myvector.begin(), myvector.end());
	// 1 10 20 30 30 20 2 3 4 5
	//               ^
	int result[] = {1, 10, 20, 30, 30, 20, 2, 3, 4, 5};
	int i = 0;
	for (it = mylist.begin(); it != mylist.end(); ++it)
		EXPECT_EQ(*it, result[i++]);
}

TEST(ListTest, InsertPosition)
{
	LIBRARY::list<int> mylist;
	LIBRARY::list<int>::iterator it;
	std::list<int> stdlist;
	std::list<int>::iterator stdit;

	it = mylist.insert(mylist.end(), 1);
	stdit = stdlist.insert(stdlist.end(), 1);
	EXPECT_EQ(*it, *stdit);
	EXPECT_EQ(mylist.size(), stdlist.size());
	mylist.insert(it, 0);
	stdlist.insert(stdit, 0);
	EXPECT_EQ(*it, *stdit);
	it = mylist.insert(mylist.begin(), -1);
	stdit = stdlist.insert(stdlist.begin(), -1);
	EXPECT_EQ(*it, *stdit);
	EXPECT_EQ(mylist.size(), stdlist.size());
	it = mylist.begin();
	stdit = stdlist.begin();
	while (it != mylist.end())
	{
		EXPECT_EQ(*it++, *stdit++);
	}
}

TEST(ListTest, InsertN)
{
	LIBRARY::list<int> mylist;
	LIBRARY::list<int>::iterator it;
	std::list<int> stdlist;
	std::list<int>::iterator stdit;

	mylist.insert(mylist.end(), 100, 1);
	stdit = stdlist.insert(stdlist.end(), 100, 1);
	mylist.insert(mylist.begin(), 50, 0);
	stdlist.insert(stdlist.begin(), 50, 0);
	mylist.insert(mylist.end(), 2, -1);
	stdlist.insert(stdlist.end(), 2, -1);
	EXPECT_EQ(mylist.size(), stdlist.size());
	it = mylist.begin();
	stdit = stdlist.begin();
	while (it != mylist.end())
	{
		EXPECT_EQ(*it++, *stdit++);
	}
}

TEST(ListTest, InsertRange)
{
	LIBRARY::list<int> mylist;
	LIBRARY::list<int> mylist2;
	LIBRARY::list<int>::iterator it;
	std::list<int> stdlist;
	std::list<int> stdlist2;
	std::list<int>::iterator stdit;

	for (int i = 0; i < 100; ++i)
	{
		mylist.insert(mylist.end(), i);
		stdlist.insert(stdlist.end(), i);
	}
	it = mylist.begin();
	stdit = stdlist.begin();
	while (it != mylist.end())
	{
		// std::cout << "[" << *it++ << "," << *stdit++ << "] ";
		EXPECT_EQ(*it++, *stdit++);
	}
	it = mylist.begin();
	stdit = stdlist.begin();
	++it;
	++stdit;
	mylist2.insert(mylist2.begin(), it, mylist.end());
	stdlist2.insert(stdlist2.begin(), stdit, stdlist.end());
	mylist2.insert(mylist2.end(), mylist.begin(), ++it);
	stdlist2.insert(stdlist2.end(), stdlist.begin(), ++stdit);
	EXPECT_EQ(mylist2.size(), stdlist2.size());
	it = mylist2.begin();
	stdit = stdlist2.begin();
	while (it != mylist2.end())
	{
		// std::cout << "[" << *it++ << "," << *stdit++ << "] ";
		EXPECT_EQ(*it++, *stdit++);
	}
}

TEST(ListTest, Erase)
{
	LIBRARY::list<int> mylist;
	LIBRARY::list<int>::iterator it1, it2;

	// set some values:
	for (int i = 1; i < 10; ++i)
		mylist.push_back(i * 10);

	// 10 20 30 40 50 60 70 80 90
	it1 = it2 = mylist.begin();	 // ^^
	LIBRARY::advance(it2, 6);	 // ^                 ^
	++it1;						 //    ^              ^

	it1 = mylist.erase(it1);  // 10 30 40 50 60 70 80 90
							  //    ^           ^

	it2 = mylist.erase(it2);  // 10 30 40 50 60 80 90
							  //    ^           ^

	++it1;	//       ^        ^
	--it2;	//       ^     ^

	mylist.erase(it1, it2);	 // 10 30 60 80 90
							 //        ^

	int result[] = {10, 30, 60, 80, 90};
	int i = 0;
	for (LIBRARY::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		EXPECT_EQ(*it, result[i++]);
}

TEST(ListTest, ErasePosition)
{
	LIBRARY::list<int> mylist;
	LIBRARY::list<int>::iterator it;
	std::list<int> stdlist;
	std::list<int>::iterator stdit;

	mylist.push_back(1);
	mylist.push_back(2);
	stdlist.push_back(1);
	stdlist.push_back(2);

	it = mylist.erase(mylist.begin());
	stdit = stdlist.erase(stdlist.begin());
	EXPECT_EQ(*it, *stdit);
	it = mylist.erase(mylist.begin());
	stdit = stdlist.erase(stdlist.begin());
	EXPECT_EQ(it, mylist.end());

	for (int i = 0; i < 10; ++i)
	{
		mylist.push_front(i);
		stdlist.push_front(i);
	}
	it = mylist.begin();
	stdit = stdlist.begin();
	advance(it, 5);
	advance(stdit, 5);
	while (it != mylist.end())
	{
		EXPECT_EQ(*it, *stdit);
		it = mylist.erase(it);
		stdit = stdlist.erase(stdit);
	}
	EXPECT_EQ(mylist.size(), stdlist.size());
}

TEST(ListTest, EraseRange)
{
	LIBRARY::list<int> mylist;
	LIBRARY::list<int>::iterator it;
	std::list<int> stdlist;
	std::list<int>::iterator stdit;

	for (int i = 0; i < 20; ++i)
	{
		mylist.push_front(i);
		stdlist.push_front(i);
	}
	it = mylist.begin();
	stdit = stdlist.begin();
	advance(it, 5);
	advance(stdit, 5);
	mylist.erase(mylist.begin(), it);
	stdlist.erase(stdlist.begin(), stdit);
	EXPECT_EQ(mylist.size(), stdlist.size());
	it = mylist.begin();
	stdit = stdlist.begin();
	while (it != mylist.end())
	{
		EXPECT_EQ(*it++, *stdit++);
	}
	it = mylist.end();
	stdit = stdlist.end();
	advance(it, -5);
	advance(stdit, -5);
	mylist.erase(it, mylist.end());
	stdlist.erase(stdit, stdlist.end());
	EXPECT_EQ(mylist.size(), stdlist.size());
	it = mylist.begin();
	stdit = stdlist.begin();
	while (it != mylist.end())
	{
		EXPECT_EQ(*it++, *stdit++);
	}
	mylist.erase(mylist.begin(), mylist.begin());
	stdlist.erase(stdlist.begin(), stdlist.begin());
	EXPECT_EQ(mylist.size(), stdlist.size());
	mylist.erase(mylist.begin(), mylist.end());
	stdlist.erase(stdlist.begin(), stdlist.end());
	EXPECT_EQ(mylist.size(), stdlist.size());
}

TEST(ListTest, Swap)
{
	LIBRARY::list<int> foo(3, 100);	 // three ints with a value of 100
	LIBRARY::list<int> bar(5, 200);	 // five ints with a value of 200

	EXPECT_EQ(foo.size(), size_t(3));
	EXPECT_EQ(bar.size(), size_t(5));
	foo.swap(bar);
	EXPECT_EQ(foo.size(), size_t(5));
	EXPECT_EQ(bar.size(), size_t(3));

	EXPECT_EQ(foo.size(), size_t(5));
	foo.swap(foo);
	EXPECT_EQ(foo.size(), size_t(5));
	EXPECT_EQ(foo.front(), 200);
}

TEST(ListTest, Resize)
{
	LIBRARY::list<int> mylist;
	LIBRARY::list<int>::iterator it;
	std::list<int> stdlist;
	std::list<int>::iterator stdit;
	// set some initial content:
	for (int i = 1; i < 10; ++i)
		mylist.push_back(i);

	mylist.resize(5);
	mylist.resize(8, 100);
	mylist.resize(12);

	int myints[] = {1, 2, 3, 4, 5, 100, 100, 100, 0, 0, 0, 0};
	int i = 0;
	for (it = mylist.begin(); it != mylist.end(); ++it)
		EXPECT_EQ(*it, myints[i++]);
	mylist.resize(0);

	mylist.resize(10, 1);
	stdlist.resize(10, 1);
	EXPECT_EQ(mylist.size(), stdlist.size());
	it = mylist.begin();
	stdit = stdlist.begin();
	while (it != mylist.end())
	{
		EXPECT_EQ(*it++, *stdit++);
	}

	mylist.resize(100, 10);
	stdlist.resize(100, 10);
	EXPECT_EQ(mylist.size(), stdlist.size());
	it = mylist.begin();
	stdit = stdlist.begin();
	while (it != mylist.end())
	{
		EXPECT_EQ(*it++, *stdit++);
	}

	mylist.resize(12);
	stdlist.resize(12);
	EXPECT_EQ(mylist.size(), stdlist.size());
	it = mylist.begin();
	stdit = stdlist.begin();
	while (it != mylist.end())
	{
		EXPECT_EQ(*it++, *stdit++);
	}
}

TEST(ListTest, Clear)
{
	LIBRARY::list<int> mylist;
	LIBRARY::list<int>::iterator it;

	mylist.push_back(100);
	mylist.push_back(200);
	mylist.push_back(300);

	mylist.clear();
	EXPECT_EQ(mylist.size(), size_t(0));
	mylist.push_back(1101);
	mylist.push_back(2202);
	EXPECT_EQ(mylist.size(), size_t(2));
}

TEST(ListTest, Splice)
{
	LIBRARY::list<int> mylist1, mylist2;
	LIBRARY::list<int>::iterator it;

	// set some initial values:
	for (int i = 1; i <= 4; ++i)
		mylist1.push_back(i);  // mylist1: 1 2 3 4

	for (int i = 1; i <= 3; ++i)
		mylist2.push_back(i * 10);	// mylist2: 10 20 30

	it = mylist1.begin();
	++it;  // points to 2

	mylist1.splice(it, mylist2);  // mylist1: 1 10 20 30 2 3 4
								  // mylist2 (empty)
								  // "it" still points to 2 (the 5th element)
	int myints1[] = {1, 10, 20, 30, 2, 3, 4};
	int i = 0;
	for (LIBRARY::list<int>::iterator it = mylist1.begin(); it != mylist1.end(); ++it)
		EXPECT_EQ(*it, myints1[i++]);
	mylist2.splice(mylist2.begin(), mylist1, it);
	// mylist1: 1 10 20 30 3 4
	// mylist2: 2
	// "it" is now invalid.
	EXPECT_EQ(mylist2.front(), 2);
	it = mylist1.begin();
	LIBRARY::advance(it, 3);  // "it" points now to 30

	mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end());
	// mylist1: 30 3 4 1 10 20
	int myints2[] = {30, 3, 4, 1, 10, 20};
	i = 0;
	for (LIBRARY::list<int>::iterator it = mylist1.begin(); it != mylist1.end(); ++it)
		EXPECT_EQ(*it, myints2[i++]);
}

TEST(ListTest, SpliceItList)
{
	LIBRARY::list<int> mylist1, mylist2;
	LIBRARY::list<int>::iterator it;
	std::list<int> stdlist1, stdlist2;
	std::list<int>::iterator stdit;

	for (int i = 0; i < 10; ++i)
	{
		mylist1.push_back(i);
		stdlist1.push_back(i);
		mylist2.push_back(100 - i);
		stdlist2.push_back(100 - i);
	}
	it = mylist1.end();
	stdit = stdlist1.end();
	mylist1.splice(it, mylist2);
	stdlist1.splice(stdit, stdlist2);
	EXPECT_EQ(mylist1.size(), stdlist1.size());
	EXPECT_EQ(mylist2.size(), stdlist2.size());
	it = mylist1.begin();
	stdit = stdlist1.begin();
	while (it != mylist1.end())
		EXPECT_EQ(*it++, *stdit++);

	it = mylist2.begin();
	stdit = stdlist2.begin();
	mylist2.splice(it, mylist1);
	stdlist2.splice(stdit, stdlist1);
	EXPECT_EQ(mylist1.size(), stdlist1.size());
	EXPECT_EQ(mylist2.size(), stdlist2.size());
	it = mylist2.begin();
	stdit = stdlist2.begin();
	while (it != mylist2.end())
		EXPECT_EQ(*it++, *stdit++);

	for (int i = 50; i < 60; ++i)
	{
		mylist1.push_back(i);
		stdlist1.push_back(i);
	}
	it = mylist2.begin();
	stdit = stdlist2.begin();
	advance(it, 10);
	advance(stdit, 10);
	mylist2.splice(it, mylist1);
	stdlist2.splice(stdit, stdlist1);
	EXPECT_EQ(mylist1.size(), stdlist1.size());
	EXPECT_EQ(mylist2.size(), stdlist2.size());
	it = mylist2.begin();
	stdit = stdlist2.begin();
	while (it != mylist2.end())
		EXPECT_EQ(*it++, *stdit++);
}

TEST(ListTest, SpliceItIt)
{
	LIBRARY::list<int> mylist1, mylist2;
	LIBRARY::list<int>::iterator it;
	std::list<int> stdlist1, stdlist2;
	std::list<int>::iterator stdit;

	for (int i = 0; i < 10; ++i)
	{
		mylist1.push_back(i);
		stdlist1.push_back(i);
		mylist2.push_back(100 - i);
		stdlist2.push_back(100 - i);
	}
	it = mylist1.end();
	stdit = stdlist1.end();
	mylist1.splice(it, mylist2, mylist2.begin());
	stdlist1.splice(stdit, stdlist2, stdlist2.begin());
	EXPECT_EQ(mylist1.size(), stdlist1.size());
	EXPECT_EQ(mylist2.size(), stdlist2.size());
	it = mylist1.begin();
	stdit = stdlist1.begin();
	while (it != mylist1.end())
		EXPECT_EQ(*it++, *stdit++);

	it = mylist1.begin();
	stdit = stdlist1.begin();
	mylist1.splice(it, mylist2, --mylist2.end());
	stdlist1.splice(stdit, stdlist2, --stdlist2.end());
	EXPECT_EQ(mylist1.size(), stdlist1.size());
	EXPECT_EQ(mylist2.size(), stdlist2.size());
	it = mylist1.begin();
	stdit = stdlist1.begin();
	while (it != mylist1.end())
		EXPECT_EQ(*it++, *stdit++);

	it = mylist1.begin();
	stdit = stdlist1.begin();
	advance(it, 7);
	advance(stdit, 7);
	mylist1.splice(it, mylist2, --mylist2.end());
	stdlist1.splice(stdit, stdlist2, --stdlist2.end());
	EXPECT_EQ(mylist1.size(), stdlist1.size());
	EXPECT_EQ(mylist2.size(), stdlist2.size());
	it = mylist1.begin();
	stdit = stdlist1.begin();
	while (it != mylist1.end())
		EXPECT_EQ(*it++, *stdit++);
}

TEST(ListTest, SpliceItRange)
{
	LIBRARY::list<int> mylist1, mylist2;
	LIBRARY::list<int>::iterator it;
	std::list<int> stdlist1, stdlist2;
	std::list<int>::iterator stdit;

	for (int i = 0; i < 10; ++i)
	{
		mylist1.push_back(i);
		stdlist1.push_back(i);
		mylist2.push_back(100 - i);
		stdlist2.push_back(100 - i);
	}
	it = mylist2.end();
	stdit = stdlist2.end();
	advance(it, -6);
	advance(stdit, -6);
	mylist1.splice(mylist1.end(), mylist2, it, mylist2.end());
	stdlist1.splice(stdlist1.end(), stdlist2, stdit, stdlist2.end());
	EXPECT_EQ(mylist1.size(), stdlist1.size());
	EXPECT_EQ(mylist2.size(), stdlist2.size());
	it = mylist1.begin();
	stdit = stdlist1.begin();
	while (it != mylist1.end())
		EXPECT_EQ(*it++, *stdit++);

	it = mylist2.begin();
	stdit = stdlist2.begin();
	advance(it, 2);
	advance(stdit, 2);
	mylist1.splice(mylist1.begin(), mylist2, mylist2.begin(), it);
	stdlist1.splice(stdlist1.begin(), stdlist2, stdlist2.begin(), stdit);
	EXPECT_EQ(mylist1.size(), stdlist1.size());
	EXPECT_EQ(mylist2.size(), stdlist2.size());
	it = mylist1.begin();
	stdit = stdlist1.begin();
	while (it != mylist1.end())
		EXPECT_EQ(*it++, *stdit++);

	it = mylist1.begin();
	stdit = stdlist1.begin();
	advance(it, 7);
	advance(stdit, 7);
	mylist1.splice(it, mylist2, mylist2.begin(), mylist2.end());
	stdlist1.splice(stdit, stdlist2, stdlist2.begin(), stdlist2.end());
	EXPECT_EQ(mylist1.size(), stdlist1.size());
	EXPECT_EQ(mylist2.size(), stdlist2.size());
	it = mylist1.begin();
	stdit = stdlist1.begin();
	while (it != mylist1.end())
		EXPECT_EQ(*it++, *stdit++);
	while (it != mylist1.begin())
		EXPECT_EQ(*--it, *--stdit);
}

TEST(ListTest, Remove)
{
	int myints[] = {17, 89, 7, 14};
	LIBRARY::list<int> mylist(myints, myints + 4);

	mylist.remove(89);
	int myints2[] = {17, 7, 14};
	int i = 0;
	for (LIBRARY::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		EXPECT_EQ(*it, myints2[i++]);
}

// a predicate implemented as a function:
bool single_digit(const int &value) { return (value < 10); }

// a predicate implemented as a class:
struct is_odd
{
	bool operator()(const int &value) { return (value % 2) == 1; }
};

TEST(ListTest, RemoveIf)
{
	int myints[] = {15, 36, 7, 17, 20, 39, 4, 1};
	LIBRARY::list<int> mylist(myints, myints + 8);	// 15 36 7 17 20 39 4 1

	mylist.remove_if(single_digit);	 // 15 36 17 20 39
	int myints2[] = {15, 36, 17, 20, 39};
	int i = 0;
	for (LIBRARY::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		EXPECT_EQ(*it, myints2[i++]);
	mylist.remove_if(is_odd());	 // 36 20
	int myints3[] = {36, 20};
	i = 0;
	for (LIBRARY::list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		EXPECT_EQ(*it, myints3[i++]);
}

// a binary predicate implemented as a function:
bool same_integral_part(double first, double second)
{
	return (int(first) == int(second));
}

// a binary predicate implemented as a class:
struct is_near
{
	bool operator()(double first, double second)
	{
		return (fabs(first - second) < 5.0);
	}
};

TEST(ListTest, Unique)
{
	double mydoubles[] = {12.15, 2.72, 73.0, 12.77, 3.14,
						  12.77, 73.35, 72.25, 15.3, 72.25};
	LIBRARY::list<double> mylist(mydoubles, mydoubles + 10);

	mylist.sort();	//  2.72,  3.14, 12.15, 12.77, 12.77,
					// 15.3,  72.25, 72.25, 73.0,  73.35

	double mysorted[] = {2.72, 3.14, 12.15, 12.77, 12.77,
						 15.3, 72.25, 72.25, 73.0, 73.35};
	int i = 0;
	for (LIBRARY::list<double>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		EXPECT_EQ(*it, mysorted[i++]);

	mylist.unique();  //  2.72,  3.14, 12.15, 12.77
					  // 15.3,  72.25, 73.0,  73.35

	double myunique[] = {2.72, 3.14, 12.15, 12.77,
						 15.3, 72.25, 73.0, 73.35};
	i = 0;
	for (LIBRARY::list<double>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		EXPECT_EQ(*it, myunique[i++]);

	mylist.unique(same_integral_part);	//  2.72,  3.14, 12.15
										// 15.3,  72.25, 73.0

	double myunique2[] = {2.72, 3.14, 12.15,
						  15.3, 72.25, 73.0};
	i = 0;
	for (LIBRARY::list<double>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		EXPECT_EQ(*it, myunique2[i++]);

	mylist.unique(is_near());  //  2.72, 12.15, 72.25

	double final[] = {2.72, 12.15, 72.25};
	i = 0;
	for (LIBRARY::list<double>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		EXPECT_EQ(*it, final[i++]);
}

// compare only integral part:
bool mycomparison(double first, double second)
{
	return (int(first) < int(second));
}

TEST(ListTest, Merge)
{
	LIBRARY::list<double> first, second;

	first.push_back(3.1);
	first.push_back(2.2);
	first.push_back(2.9);

	second.push_back(3.7);
	second.push_back(7.1);
	second.push_back(1.4);

	first.sort();
	second.sort();

	first.merge(second);
	double test1[] = {1.4, 2.2, 2.9, 3.1, 3.7, 7.1};
	int i = 0;
	for (LIBRARY::list<double>::iterator it = first.begin(); it != first.end(); ++it)
		EXPECT_EQ(*it, test1[i++]);

	// (second is now empty)
	EXPECT_EQ(second.size(), size_t(0));
	second.push_back(2.1);

	first.merge(second, mycomparison);
	double final[] = {1.4, 2.2, 2.9, 2.1, 3.1, 3.7, 7.1};
	i = 0;
	for (LIBRARY::list<double>::iterator it = first.begin(); it != first.end(); ++it)
		EXPECT_EQ(*it, final[i++]);
}

TEST(ListTest, Merge2)
{
	LIBRARY::list<double> first, second;
	LIBRARY::list<double>::iterator it, it2;
	std::list<double> sfirst, ssecond;
	std::list<double>::iterator sit, sit2;

	for (int i = 0; i < 10; ++i)
	{
		first.push_back(i);
		sfirst.push_back(i);
		second.push_back(i + 5);
		ssecond.push_back(i + 5);
	}
	first.merge(first);
	sfirst.merge(sfirst);
	EXPECT_EQ(first.size(), sfirst.size());
	it = first.begin();
	sit = sfirst.begin();
	while (it != first.end())
		EXPECT_EQ(*it++, *sit++);

	first.merge(second);
	sfirst.merge(ssecond);
	EXPECT_EQ(first.size(), sfirst.size());
	EXPECT_EQ(second.size(), ssecond.size());
	it = first.begin();
	sit = sfirst.begin();
	while (it != first.end())
		EXPECT_EQ(*it++, *sit++);
	while (sit != sfirst.begin())
		EXPECT_EQ(*--it, *--sit);

	for (int i = -10; i < 0; ++i)
	{
		second.push_back(i + 5);
		ssecond.push_back(i + 5);
	}
	first.merge(second);
	sfirst.merge(ssecond);
	EXPECT_EQ(first.size(), sfirst.size());
	EXPECT_EQ(second.size(), ssecond.size());
	it = first.begin();
	sit = sfirst.begin();
	while (sit != sfirst.end())
		EXPECT_EQ(*it++, *sit++);
	while (sit != sfirst.begin())
		EXPECT_EQ(*--it, *--sit);
}

// comparison, not case sensitive.
bool compare_nocase(const std::string &first, const std::string &second)
{
	unsigned int i = 0;
	while ((i < first.length()) && (i < second.length()))
	{
		if (tolower(first[i]) < tolower(second[i]))
			return true;
		else if (tolower(first[i]) > tolower(second[i]))
			return false;
		++i;
	}
	return (first.length() < second.length());
}

TEST(ListTest, Sort)
{
	LIBRARY::list<std::string> mylist;
	std::list<std::string> stdlist;
	mylist.push_back("one");
	mylist.push_back("two");
	mylist.push_back("Three");
	stdlist.push_back("one");
	stdlist.push_back("two");
	stdlist.push_back("Three");

	mylist.sort();
	stdlist.sort();
	EXPECT_EQ(mylist.front(), stdlist.front());

	mylist.sort(compare_nocase);
	stdlist.sort(compare_nocase);
	EXPECT_EQ(mylist.front(), stdlist.front());
}

TEST(ListTest, Sort2)
{
	LIBRARY::list<int> mylist;
	std::list<int> stdlist;
	LIBRARY::list<int>::iterator it;
	std::list<int>::iterator sit;
	int random;
	for (int i = 0; i < 10000; ++i)
	{
		random = rand();
		mylist.push_back(random);
		stdlist.push_back(random);
	}
	mylist.sort();
	stdlist.sort();
	it = mylist.begin();
	sit = stdlist.begin();
	while (sit != stdlist.end())
		EXPECT_EQ(*it++, *sit++);
}

TEST(ListTest, Reverse)
{
	LIBRARY::list<int> mylist;

	for (int i = 1; i < 10; ++i)
		mylist.push_back(i);

	mylist.reverse();

	int i = 9;
	for (LIBRARY::list<int>::const_iterator it = mylist.begin(); it != mylist.end(); ++it)
		EXPECT_EQ(*it, i--);
}

TEST(ListTest, RelationalOp)
{
	LIBRARY::list<int> foo(3, 100);	 // three ints with a value of 100
	LIBRARY::list<int> bar(2, 200);	 // two ints with a value of 200

	EXPECT_FALSE(foo == bar);
	EXPECT_TRUE(foo != bar);
	EXPECT_FALSE(foo > bar);
	EXPECT_TRUE(foo < bar);
	EXPECT_FALSE(foo >= bar);
	EXPECT_TRUE(foo <= bar);
}

TEST(ListTest, ConstIterator)
{
	LIBRARY::list<int> list(3, 100);  // three ints with a value of 100
	LIBRARY::list<int>::const_iterator it;
	LIBRARY::list<int>::const_iterator it3(it);
	LIBRARY::list<int>::iterator it2;

	for (it = list.begin(); it != list.end(); ++it)
	{
		// *it += 5;
	}
	it2 = --list.end();
	it = it2;
	it3 = it2;
	// it2 = it;
}

TEST(ListTest, ReverseConstIterator)
{
	LIBRARY::list<int> list(3, 100);  // three ints with a value of 100
	std::list<int> slist(3, 100);	  // three ints with a value of 100

	LIBRARY::list<int>::const_reverse_iterator rit;
	std::list<int>::const_reverse_iterator srit;
	LIBRARY::list<int>::reverse_iterator rit2;

	srit = slist.rbegin();
	rit = list.rbegin();
	while (rit != list.rend())
	{
		// *rit += 5;
		EXPECT_EQ(*srit++, *rit++);
	}
	rit2 = list.rbegin();
	rit = rit2;
	// rit2 = rit;
}
