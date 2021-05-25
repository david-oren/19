#include <gtest/gtest.h>

TEST(DequeTest, Constructors)
{
	// constructors used in the same order as described above:
	LIBRARY::deque<int> first;								  // empty deque of ints
	LIBRARY::deque<int> second(4, 100);						  // four ints with value 100
	LIBRARY::deque<int> third(second.begin(), second.end());  // iterating through second
	LIBRARY::deque<int> fourth(4000, 1);					  // a copy of third
	LIBRARY::deque<int> sixth(fourth);
	// the iterator constructor can be used to copy arrays:
	int myints[] = {16, 2, 77, 29, 20};
	LIBRARY::deque<int> fifth(myints, myints + sizeof(myints) / sizeof(int));

	EXPECT_EQ(first.size(), size_t(0));
	EXPECT_EQ(second.size(), size_t(4));
	EXPECT_EQ(third.size(), size_t(4));
	EXPECT_EQ(fourth.size(), size_t(4000));
	EXPECT_EQ(fifth.size(), size_t(5));
	EXPECT_EQ(sixth.size(), size_t(4000));

	for (LIBRARY::deque<int>::iterator it = second.begin(); it != second.end(); ++it)
		EXPECT_EQ(*it, 100);
	for (size_t i = 0; i < fifth.size(); ++i)
		EXPECT_EQ(myints[i], fifth[i]);
}

TEST(DequeTest, Assignment)
{
	LIBRARY::deque<int> first(3);	// deque with 3 zero-initialized ints
	LIBRARY::deque<int> second(5);	// deque with 5 zero-initialized ints

	second = first;
	first = LIBRARY::deque<int>();

	EXPECT_EQ(first.size(), size_t(0));
	EXPECT_EQ(second.size(), size_t(3));
}

TEST(DequeTest, Begin)
{
	LIBRARY::deque<int> mydeque(2000);
	std::deque<int> stddeque(2000);

	for (int i = 1; i <= 5; i++)
	{
		mydeque.push_back(i);
		stddeque.push_back(i);
	}
	LIBRARY::deque<int>::iterator it;
	std::deque<int>::iterator stdit = stddeque.begin();
	int a = 0;
	int b = 0;
	for (it = mydeque.begin(); it != mydeque.end(); ++it)
	{
		++a;
	}
	for (stdit = stddeque.begin(); stdit != stddeque.end(); ++stdit)
		++b;
	EXPECT_EQ(a, b);
}

TEST(DequeTest, RBegin)
{
	LIBRARY::deque<int> mydeque(5);	 // 5 default-constructed ints
	std::deque<int> stddeque(5);
	LIBRARY::deque<int>::reverse_iterator rit = mydeque.rbegin();
	std::deque<int>::reverse_iterator stdrit = stddeque.rbegin();

	int i = 0;
	for (rit = mydeque.rbegin(); rit != mydeque.rend(); ++rit)
	{
		*stdrit++ = ++i;
		*rit = i;
	}

	std::deque<int>::iterator stdit = stddeque.begin();
	for (LIBRARY::deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); ++it)
		EXPECT_EQ(*it, *stdit++);
}

TEST(DequeTest, Empty)
{
	LIBRARY::deque<int> mydeque;
	int sum(0);

	for (int i = 1; i <= 10; i++)
		mydeque.push_back(i);

	while (!mydeque.empty())
	{
		sum += mydeque.front();
		mydeque.pop_front();
	}
	EXPECT_EQ(sum, 55);
}

TEST(DequeTest, Size)
{
	LIBRARY::deque<int> myints;
	EXPECT_EQ(myints.size(), size_t(0));
	for (int i = 0; i < 5; i++)
		myints.push_back(i);
	EXPECT_EQ(myints.size(), size_t(5));
	myints.insert(myints.begin(), 5, 100);
	EXPECT_EQ(myints.size(), size_t(10));
	myints.pop_back();
	EXPECT_EQ(myints.size(), size_t(9));
}

TEST(DequeTest, MaxSize)
{
	LIBRARY::deque<int> mydeque;
	std::deque<int> stddeque;
	EXPECT_EQ(mydeque.max_size(), stddeque.max_size());
	LIBRARY::deque<double> mydeque2;
	std::deque<double> stddeque2;
	EXPECT_EQ(mydeque2.max_size(), stddeque2.max_size());
}

TEST(DequeTest, Resize)
{
	LIBRARY::deque<int> mydeque;
	int myints[] = {1, 2, 3, 4, 5, 100, 100, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	// set some initial content:
	for (int i = 1; i < 10; ++i)
		mydeque.push_back(i);
	mydeque.resize(5);
	EXPECT_EQ(mydeque.size(), size_t(5));
	mydeque.resize(8, 100);
	EXPECT_EQ(mydeque.size(), size_t(8));
	mydeque.resize(1300);
	for (int i = 0; i < 17; ++i)
		EXPECT_EQ(mydeque[i], myints[i]);
	EXPECT_EQ(mydeque.size(), size_t(1300));
	for (int i = 0; i < 17; ++i)
		EXPECT_EQ(mydeque[i], myints[i]);
	mydeque.resize(12);

	int i = 0;
	for (LIBRARY::deque<int>::iterator it = mydeque.begin(); i < 12; ++it)
	{
		EXPECT_EQ(*it, myints[i++]);
	}
}

TEST(DequeTest, Bracket)
{
	LIBRARY::deque<int> mydeque(10);		  // 10 zero-initialized elements
	LIBRARY::deque<int> mydeque2(1300, 100);  // 10 zero-initialized elements
	LIBRARY::deque<int>::size_type sz = mydeque.size();

	// assign some values:
	for (unsigned i = 0; i < sz; i++)
		mydeque[i] = i;

	// reverse order of elements using operator[]:
	for (unsigned i = 0; i < sz / 2; i++)
	{
		int temp;
		temp = mydeque[sz - 1 - i];
		mydeque[sz - 1 - i] = mydeque[i];
		mydeque[i] = temp;
	}

	// print content:
	int j = 9;
	for (unsigned i = 0; i < sz; i++)
		EXPECT_EQ(mydeque[i], j--);
	EXPECT_EQ(mydeque2[1260], 100);
}

TEST(DequeTest, At)
{
	LIBRARY::deque<unsigned> mydeque(10);  // 10 zero-initialized unsigneds

	// assign some values:
	for (unsigned i = 0; i < mydeque.size(); i++)
		mydeque.at(i) = i;

	for (unsigned i = 0; i < mydeque.size(); i++)
		EXPECT_EQ(mydeque.at(i), i);
	EXPECT_THROW(mydeque.at(20), std::out_of_range);
	EXPECT_THROW(mydeque.at(-1), std::out_of_range);
}

TEST(DequeTest, Front)
{
	LIBRARY::deque<int> mydeque;

	mydeque.push_front(77);
	EXPECT_EQ(mydeque.front(), 77);
	mydeque.push_back(20);
	mydeque.front() -= mydeque.back();
	EXPECT_EQ(mydeque.front(), 57);
}

TEST(DequeTest, Back)
{
	LIBRARY::deque<int> mydeque;

	mydeque.push_back(10);

	while (mydeque.back() != 0)
		mydeque.push_back(mydeque.back() - 1);
	int i = 10;
	for (LIBRARY::deque<int>::iterator it = mydeque.begin(); it != mydeque.end(); ++it)
		EXPECT_EQ(*it, i--);
}

TEST(DequeTest, Assign)
{
	LIBRARY::deque<int> first;
	LIBRARY::deque<int> second;
	LIBRARY::deque<int> third;

	first.assign(7, 100);  // 7 ints with a value of 100

	LIBRARY::deque<int>::iterator it = first.begin() + 1;

	second.assign(it, first.end() - 1);	 // the 5 central values of first

	int myints[] = {1776, 7, 4};
	third.assign(myints, myints + 3);  // assigning from array.
	EXPECT_EQ(first.size(), size_t(7));
	EXPECT_EQ(second.size(), size_t(5));
	EXPECT_EQ(third.size(), size_t(3));
}

TEST(DequeTest, PushBack)
{
	LIBRARY::deque<int> mydeque;
	LIBRARY::deque<int> mydeque2(1023);

	for (int i = 0; i < 1300; ++i)
		mydeque.push_back(i);
	mydeque2.push_back(20);
	mydeque2.push_back(30);
	EXPECT_EQ(mydeque.size(), size_t(1300));
	EXPECT_EQ(mydeque2.size(), size_t(1025));
	EXPECT_EQ(mydeque2.back(), 30);
}

TEST(DequeTest, PushFront)
{
	LIBRARY::deque<int> mydeque;
	LIBRARY::deque<int> mydeque2(1023);

	for (int i = 0; i < 1300; ++i)
		mydeque.push_front(i);
	mydeque2.push_front(20);
	mydeque2.push_front(30);
	EXPECT_EQ(mydeque.size(), size_t(1300));
	EXPECT_EQ(mydeque2.size(), size_t(1025));
	EXPECT_EQ(mydeque2.front(), 30);
}

TEST(DequeTest, PopBack)
{
	LIBRARY::deque<int> mydeque(1023, 0);
	int sum(0);
	mydeque.push_back(10);
	mydeque.push_back(20);
	mydeque.push_back(30);

	for (int i = 0; i < 10; i++)
	{
		sum += mydeque.back();
		mydeque.pop_back();
	}
	EXPECT_EQ(mydeque.size(), size_t(1016));
	while (!mydeque.empty())
	{
		sum += mydeque.back();
		mydeque.pop_back();
	}
	EXPECT_EQ(sum, 60);
}
TEST(DequeTest, PopFront)
{
	LIBRARY::deque<int> mydeque(1023);

	mydeque.push_back(100);
	mydeque.push_back(200);
	mydeque.push_back(300);

	while (!mydeque.empty())
	{
		mydeque.pop_front();
	}
	EXPECT_EQ(mydeque.size(), size_t(0));
}

TEST(DequeTest, InsertIterator2)
{
	LIBRARY::deque<int> mydeque;

	// set some initial values:
	for (int i = 1; i < 6; i++)
		mydeque.push_back(i);  // 1 2 3 4 5

	LIBRARY::deque<int>::iterator it;
	it = mydeque.begin();
	++it;

	it = mydeque.insert(it, 10);  // 1 10 2 3 4 5
	// "it" now points to the newly inserted 10

	mydeque.insert(it, 2, 20);	// 1 20 20 10 2 3 4 5
	// "it" no longer valid!

	it = mydeque.begin() + 2;

	std::vector<int> myvector(2, 30);
	mydeque.insert(it, myvector.begin(), myvector.end());
	// 1 20 30 30 20 10 2 3 4 5

	int result[] = {1, 20, 30, 30, 20, 10, 2, 3, 4, 5};
	int i = 0;
	for (it = mydeque.begin(); it != mydeque.end(); ++it)
		EXPECT_EQ(*it, result[i++]);

	it = mydeque.begin() + 5;
	mydeque.insert(it, 1030, 100);
	EXPECT_EQ(mydeque.size(), size_t(1040));
	EXPECT_EQ(mydeque.front(), 1);
	EXPECT_EQ(mydeque.back(), 5);
	EXPECT_EQ(*(mydeque.begin() + 6), 100);
}

TEST(DequeTest, InsertIterator)
{
	LIBRARY::deque<int> mydeque;
	LIBRARY::deque<int>::iterator it;

	it = mydeque.end();
	mydeque.insert(mydeque.end(), 0);
	// set some initial values:
	for (int i = 1; i < 6; i++)
		mydeque.push_back(i);  // 1 2 3 4 5

	mydeque.insert(mydeque.end(), 6);
	mydeque.insert(mydeque.begin(), -1);
	it = mydeque.begin();
	++it;

	it = mydeque.insert(it, 10);  // 1 10 2 3 4 5
	EXPECT_EQ(*it, 10);
}

TEST(DequeTest, InsertN)
{
	LIBRARY::deque<int> mydeque;
	LIBRARY::deque<int>::iterator it;
	it = mydeque.begin();
	std::deque<int> stddeque;
	std::deque<int>::iterator stdit;
	stdit = stddeque.begin();

	mydeque.insert(it, 1000, 10);	   // 1 10 2 3 4 5
	stddeque.insert(stdit, 1000, 10);  // 1 10 2 3 4 5
	stdit = stddeque.begin();
	for (it = mydeque.begin(); it != mydeque.end(); ++it)
		EXPECT_EQ(*it, *stdit);
	EXPECT_EQ(mydeque.size(), stddeque.size());

	it = mydeque.end();
	stdit = stddeque.end();
	mydeque.insert(it, 2, 20);		// 1 20 20 10 2 3 4 5
	stddeque.insert(stdit, 2, 20);	// 1 10 2 3 4 5
	EXPECT_EQ(mydeque.size(), stddeque.size());

	// std::cout << "SIZE = " << mydeque.size() << std::endl;
	it = mydeque.begin() + 20;
	stdit = stddeque.begin() + 20;
	mydeque.insert(it, 1000, 50);	   // 1 10 2 3 4 5
	stddeque.insert(stdit, 1000, 50);  // 1 10 2 3 4 5
	EXPECT_EQ(mydeque.front(), stddeque.front());
	EXPECT_EQ(mydeque.back(), stddeque.back());
	EXPECT_EQ(mydeque.size(), stddeque.size()) << "AFTER INSERT 1000";
	for (size_t i = 0; i < mydeque.size(); ++i)
	{
		EXPECT_EQ(mydeque[i], stddeque[i]) << i;
		// std::cout << mydeque[i] << " == " << stddeque[i] << " ";
	}
	int d = 0;
	int c = 0;
	for (stdit = stddeque.begin(); stdit != stddeque.end(); ++stdit)
		c++;
	for (it = mydeque.begin(); it != mydeque.end(); ++it)
		d++;
	EXPECT_EQ(c, d);
	EXPECT_EQ(mydeque.front(), stddeque.front());
	EXPECT_EQ(mydeque.back(), stddeque.back());
	EXPECT_EQ(*(mydeque.begin() + 6), 10);
	it = mydeque.begin() + 2000;
	stdit = stddeque.begin() + 2000;
	EXPECT_EQ(*it, *stdit);
	mydeque.insert(it, 300, 50);	  // 1 10 2 3 4 5
	stddeque.insert(stdit, 300, 50);  // 1 10 2 3 4 5
	for (size_t i = 0; i < mydeque.size(); ++i)
	{
		EXPECT_EQ(mydeque[i], stddeque[i]) << i;
		// std::cout << mydeque[i] << " == " << stddeque[i] << " ";
	}
	EXPECT_EQ(mydeque.front(), stddeque.front());
	EXPECT_EQ(mydeque.back(), stddeque.back());
	EXPECT_EQ(mydeque.size(), stddeque.size()) << "LAST INSERT";
}

TEST(DequeTest, InsertRange)
{
	LIBRARY::deque<int> mydeque;
	LIBRARY::deque<int>::iterator it;
	std::deque<int> stddeque;
	std::deque<int>::iterator stdit;

	int first[] = {1, 2, 3, 4, 5};
	mydeque.insert(mydeque.end(), first, first + 5);
	stddeque.insert(stddeque.end(), first, first + 5);
	EXPECT_EQ(mydeque.front(), stddeque.front());
	EXPECT_EQ(mydeque.back(), stddeque.back());
	EXPECT_EQ(mydeque.size(), stddeque.size());

	int myints[2000];
	for (int i = 0; i < 2000; ++i)
		myints[i] = i;
	mydeque.insert(mydeque.end(), myints, myints + 2000);
	stddeque.insert(stddeque.end(), myints, myints + 2000);
	EXPECT_EQ(mydeque.front(), stddeque.front());
	EXPECT_EQ(mydeque.back(), stddeque.back());
	EXPECT_EQ(mydeque.size(), stddeque.size());
	for (int i = 0; i < 2000; ++i)
		EXPECT_EQ(mydeque[i], stddeque[i]);
	mydeque.insert(mydeque.begin() + 1200, mydeque.begin() + 10, mydeque.begin() + 20);
	stddeque.insert(stddeque.begin() + 1200, stddeque.begin() + 10, stddeque.begin() + 20);
	EXPECT_EQ(mydeque.front(), stddeque.front());
	EXPECT_EQ(mydeque.back(), stddeque.back());
	EXPECT_EQ(mydeque.size(), stddeque.size());
	for (int i = 0; i < 2000; ++i)
		EXPECT_EQ(mydeque[i], stddeque[i]);
}

TEST(DequeTest, EraseElement)
{
	LIBRARY::deque<int> mydeque;
	LIBRARY::deque<int>::iterator it;
	std::deque<int> stddeque;
	std::deque<int>::iterator stdit;

	for (int i = 1; i <= 2000; i++)
	{
		mydeque.push_back(i);
		stddeque.push_back(i);
	}

	it = mydeque.erase(mydeque.begin());
	stdit = stddeque.erase(stddeque.begin());
	EXPECT_EQ(*it, *stdit);
	EXPECT_EQ(mydeque.front(), stddeque.front());
	EXPECT_EQ(mydeque.back(), stddeque.back());
	EXPECT_EQ(mydeque.size(), stddeque.size());

	mydeque.erase(mydeque.end() - 1);
	stddeque.erase(stddeque.end() - 1);
	EXPECT_EQ(mydeque.front(), stddeque.front());
	EXPECT_EQ(mydeque.back(), stddeque.back());
	EXPECT_EQ(mydeque.size(), stddeque.size());

	it = mydeque.erase(mydeque.begin() + 100);
	stdit = stddeque.erase(stddeque.begin() + 100);
	EXPECT_EQ(*it, *stdit);
	it = mydeque.erase(mydeque.begin() + 1);
	stdit = stddeque.erase(stddeque.begin() + 1);
	EXPECT_EQ(*it, *stdit);
	it = mydeque.erase(mydeque.begin() + 1900);
	stdit = stddeque.erase(stddeque.begin() + 1900);
	EXPECT_EQ(*it, *stdit);
	EXPECT_EQ(mydeque.front(), stddeque.front());
	EXPECT_EQ(mydeque.back(), stddeque.back());
	EXPECT_EQ(mydeque.size(), stddeque.size());
	for (size_t i = 0; i < mydeque.size(); ++i)
		EXPECT_EQ(mydeque[i], stddeque[i]);
}

TEST(DequeTest, EraseRange)
{
	LIBRARY::deque<int> mydeque;
	LIBRARY::deque<int>::iterator it;
	std::deque<int> stddeque;
	std::deque<int>::iterator stdit;

	int first[] = {1, 2, 3, 4, 5};
	mydeque.insert(mydeque.end(), first, first + 5);
	stddeque.insert(stddeque.end(), first, first + 5);
	it = mydeque.end();
	stdit = stddeque.end();
	it = mydeque.erase(it - 3, it);
	stdit = stddeque.erase(stdit - 3, stdit);
	EXPECT_EQ(*it, *stdit);
	EXPECT_EQ(mydeque.front(), stddeque.front());
	EXPECT_EQ(mydeque.back(), stddeque.back());
	EXPECT_EQ(mydeque.size(), stddeque.size());
	for (size_t i = 0; i < mydeque.size(); ++i)
		EXPECT_EQ(mydeque[i], stddeque[i]);

	for (int i = 1; i <= 30; i++)
	{
		mydeque.push_back(i);
		stddeque.push_back(i);
	}
	it = mydeque.begin();
	stdit = stddeque.begin();
	it = mydeque.erase(it, it + 10);
	stdit = stddeque.erase(stdit, stdit + 10);
	EXPECT_EQ(*it, *stdit);
	EXPECT_EQ(mydeque.front(), stddeque.front());
	EXPECT_EQ(mydeque.back(), stddeque.back());
	EXPECT_EQ(mydeque.size(), stddeque.size());
	for (size_t i = 0; i < mydeque.size(); ++i)
		EXPECT_EQ(mydeque[i], stddeque[i]);

	for (int i = 1; i <= 3000; i++)
	{
		mydeque.push_back(i);
		stddeque.push_back(i);
	}

	it = mydeque.end();
	stdit = stddeque.end();
	it = mydeque.erase(it - 1000, it - 500);
	stdit = stddeque.erase(stdit - 1000, stdit - 500);
	for (size_t i = 0; i < mydeque.size(); ++i)
		EXPECT_EQ(mydeque[i], stddeque[i]);
	EXPECT_EQ(*it, *stdit);
	EXPECT_EQ(mydeque.front(), stddeque.front());
	EXPECT_EQ(mydeque.back(), stddeque.back());
	EXPECT_EQ(mydeque.size(), stddeque.size());

	it = mydeque.begin();
	stdit = stddeque.begin();
	it = mydeque.erase(it + 10, it + 20);
	stdit = stddeque.erase(stdit + 10, stdit + 20);
	for (size_t i = 0; i < mydeque.size(); ++i)
		EXPECT_EQ(mydeque[i], stddeque[i]);
	EXPECT_EQ(*it, *stdit);
	EXPECT_EQ(mydeque.front(), stddeque.front());
	EXPECT_EQ(mydeque.back(), stddeque.back());
	EXPECT_EQ(mydeque.size(), stddeque.size());
}

TEST(DequeTest, Swap)
{
	LIBRARY::deque<int> foo(3, 100);  // three ints with a value of 100
	LIBRARY::deque<int> bar(5, 200);  // five ints with a value of 200

	EXPECT_EQ(foo.size(), size_t(3));
	EXPECT_EQ(bar.size(), size_t(5));
	foo.swap(bar);
	EXPECT_EQ(foo.size(), size_t(5));
	EXPECT_EQ(bar.size(), size_t(3));
}

TEST(DequeTest, Clear)
{
	LIBRARY::deque<int> mydeque;
	mydeque.push_back(100);
	mydeque.push_back(200);
	mydeque.push_back(300);
	mydeque.clear();
	EXPECT_EQ(mydeque.size(), size_t(0));
	mydeque.push_back(1101);
	mydeque.push_back(2202);
	EXPECT_EQ(mydeque.size(), size_t(2));
}

TEST(DequeTest, RelOps)
{
	LIBRARY::deque<int> foo(3, 100);  // three ints with a value of 100
	LIBRARY::deque<int> bar(2, 200);  // two ints with a value of 200

	EXPECT_FALSE(foo == bar);
	EXPECT_TRUE(foo != bar);
	EXPECT_FALSE(foo > bar);
	EXPECT_TRUE(foo < bar);
	EXPECT_FALSE(foo >= bar);
	EXPECT_TRUE(foo <= bar);
}

TEST(DequeTest, IteratorOP1)
{
	LIBRARY::deque<int> mydeque;
	LIBRARY::deque<int>::iterator it;
	std::deque<int> stddeque;
	std::deque<int>::iterator stdit;

	for (int i = 0; i < 20; ++i)
	{
		mydeque.push_front(i);
		stddeque.push_front(i);
	}
	EXPECT_EQ(mydeque.front(), stddeque.front());
	EXPECT_EQ(mydeque.back(), stddeque.back());
	EXPECT_EQ(mydeque.size(), stddeque.size());

	it = mydeque.begin();
	stdit = stddeque.begin();
	EXPECT_EQ(*it, *stdit);
	it += 10;
	stdit += 10;
	EXPECT_EQ(*it, *stdit);
	it -= 5;
	stdit -= 5;
	EXPECT_EQ(*it, *stdit);
	it -= 5;
	stdit -= 5;
	EXPECT_EQ(*it, *stdit);
	EXPECT_EQ(*(it + 10), *(stdit + 10));
	EXPECT_EQ(it[10], stdit[10]);
}
TEST(DequeTest, IteratorOP2)
{
	LIBRARY::deque<std::pair<int, int> > mydeque2;
	LIBRARY::deque<std::pair<int, int> >::iterator it2;
	std::deque<std::pair<int, int> > stddeque2;
	std::deque<std::pair<int, int> >::iterator stdit2;

	std::pair<int, int> p(1, 2);
	mydeque2.push_back(p);
	stddeque2.push_back(p);
	it2 = mydeque2.begin();
	stdit2 = stddeque2.begin();
	EXPECT_EQ(it2->first, stdit2->first);
	EXPECT_EQ(it2->second, stdit2->second);
}
TEST(DequeTest, IteratorOP3)
{
	LIBRARY::deque<int> mydeque;
	LIBRARY::deque<int>::iterator it;
	std::deque<int> stddeque;
	std::deque<int>::iterator stdit;

	for (int i = 0; i < 3000; ++i)
	{
		mydeque.push_front(i);
		stddeque.push_front(i);
	}
	it = mydeque.begin();
	stdit = stddeque.begin();
	EXPECT_EQ(*(5 + it), *(5 + stdit));
	EXPECT_EQ(*(2000 + it), *(2000 + stdit));
	EXPECT_EQ(*(it += 10), *(stdit += 10));
	EXPECT_EQ(it - mydeque.begin(), stdit - stddeque.begin());
	EXPECT_EQ(it - mydeque.end(), stdit - stddeque.end());
	EXPECT_EQ(mydeque.end() - it, stddeque.end() - stdit);
	EXPECT_EQ(*(it - 5), *(stdit - 5));
	int i = 3000;
	LIBRARY::deque<int>::iterator it2 = mydeque.end() - 1;
	for (it = mydeque.begin(); it < mydeque.end(); ++it)
		EXPECT_EQ(--i, *it);
	EXPECT_EQ(i, 0);
	i = 3000;
	for (it = mydeque.begin(); it <= it2; ++it)
		EXPECT_EQ(--i, *it);
	EXPECT_EQ(i, 0);
	for (; it2 > mydeque.begin(); --it2)
		EXPECT_EQ(i++, *it2);
}

TEST(DequeTest, ConstIterator)
{
	LIBRARY::deque<int> deque(3, 100);	// three ints with a value of 100
	LIBRARY::deque<int>::const_iterator it;
	LIBRARY::deque<int>::const_iterator it3(it);
	LIBRARY::deque<int>::iterator it2;

	for (it = deque.begin(); it != deque.end(); ++it)
	{
		// *it += 5;
	}
	it2 = --deque.end();
	it = it2;
	it3 = it2;
	// it2 = it;
}

TEST(DequeTest, ReverseConstIterator)
{
	LIBRARY::deque<int> deque(3, 100);	// three ints with a value of 100
	std::deque<int> sdeque(3, 100);		// three ints with a value of 100

	LIBRARY::deque<int>::const_reverse_iterator rit;
	std::deque<int>::const_reverse_iterator srit;
	LIBRARY::deque<int>::reverse_iterator rit2;

	srit = sdeque.rbegin();
	rit = deque.rbegin();
	while (rit != deque.rend())
	{
		// *rit += 5;
		EXPECT_EQ(*srit++, *rit++);
	}
	rit2 = deque.rbegin();
	rit = rit2;
	// rit2 = rit;
}
