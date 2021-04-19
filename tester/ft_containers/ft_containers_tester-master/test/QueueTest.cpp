TEST(QueueTest, Constructor)
{
	std::deque<int> mydeck(3, 100);				// deque with 3 elements
	LIBRARY::list<int> mylist(size_t(2), 200);	// list with 2 elements

	LIBRARY::queue<int> first;							   // empty queue
	LIBRARY::queue<int, std::deque<int> > second(mydeck);  // queue initialized to copy of deque

	LIBRARY::queue<int, LIBRARY::list<int> > third;	 // empty queue with list as underlying container
	LIBRARY::queue<int, LIBRARY::list<int> > fourth(mylist);
	EXPECT_EQ(first.size(), size_t(0));
	EXPECT_EQ(second.size(), size_t(3));
	EXPECT_EQ(third.size(), size_t(0));
	EXPECT_EQ(fourth.size(), size_t(2));
}

TEST(QueueTest, Empty)
{
	LIBRARY::queue<int> myqueue;
	int sum(0);

	for (int i = 1; i <= 10; i++)
		myqueue.push(i);

	while (!myqueue.empty())
	{
		sum += myqueue.front();
		myqueue.pop();
	}
	EXPECT_EQ(sum, 55);
}

TEST(QueueTest, PushPop)
{
	LIBRARY::queue<int> myqueue;
	for (int i = 0; i < 5; ++i)
		myqueue.push(i);

	int i = 0;
	while (!myqueue.empty())
	{
		EXPECT_EQ(myqueue.front(), i++);
		myqueue.pop();
	}
}

TEST(QueueTest, Size)
{
	LIBRARY::queue<int> myints;
	EXPECT_EQ(myints.size(), size_t(0));
	for (int i = 0; i < 5; i++)
		myints.push(i);
	EXPECT_EQ(myints.size(), size_t(5));
	myints.pop();
	EXPECT_EQ(myints.size(), size_t(4));
}

TEST(QueueTest, FrontBack)
{
	std::queue<int> myqueue;

	myqueue.push(77);
	myqueue.push(16);

	EXPECT_EQ(myqueue.front(), 77);
	myqueue.front() -= myqueue.back();	// 77-16=61

	EXPECT_EQ(myqueue.front(), 61);
	EXPECT_EQ(myqueue.back(), 16);
}

TEST(QueueTest, RelOp)
{
	LIBRARY::list<int> a;
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);

	LIBRARY::queue<int, LIBRARY::list<int> > foo(a);
	LIBRARY::queue<int, LIBRARY::list<int> > bar(a);
	LIBRARY::queue<int, LIBRARY::list<int> > bob;
	bob.push(30);
	bob.push(20);
	bob.push(10);

	bar.push(0);

	EXPECT_FALSE(bob == bar);
	EXPECT_TRUE(bar != foo);
	EXPECT_TRUE(bar != bob);
	EXPECT_FALSE(foo > bar);
	EXPECT_TRUE(foo < bar);
	EXPECT_FALSE(foo >= bar);
	EXPECT_TRUE(foo <= bar);
}
