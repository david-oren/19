TEST(SetTest, Constructors)
{
  LIBRARY::set<int> first; // empty set of ints

  int myints[] = {10, 20, 30, 40, 50};
  LIBRARY::set<int> second(myints, myints + 5); // range

  LIBRARY::set<int> third(second); // a copy of second

  LIBRARY::set<int> fourth(second.begin(), second.end()); // iterator ctor.

  LIBRARY::set<int, classcomp> fifth; // class as Compare

  bool (*fn_pt)(int, int) = fncomp;
  LIBRARY::set<int, bool (*)(int, int)> sixth(fn_pt); // function pointer as Compare
  EXPECT_EQ(first.size(), size_t(0));
  EXPECT_EQ(second.size(), size_t(5));
  EXPECT_EQ(third.size(), size_t(5));
  EXPECT_EQ(fourth.size(), size_t(5));
}

TEST(SetTest, Assignment)
{
  int myints[] = {12, 82, 37, 64, 15};
  LIBRARY::set<int> first(myints, myints + 5); // set with 5 ints
  LIBRARY::set<int> second;                    // empty set

  second = first;              // now second contains the 5 ints
  first = LIBRARY::set<int>(); // and first is empty

  EXPECT_EQ(first.size(), size_t(0));
  EXPECT_EQ(second.size(), size_t(5));
}

TEST(SetTest, Begin)
{
  int myints[] = {75, 23, 65, 42, 13};
  LIBRARY::set<int> myset(myints, myints + 5);

  int result[] = {13, 23, 42, 65, 75};
  int i = 0;
  for (LIBRARY::set<int>::iterator it = myset.begin(); it != myset.end(); ++it)
    EXPECT_EQ(*it, result[i++]);
}

TEST(SetTest, RBegin)
{
  int myints[] = {21, 64, 17, 78, 49};
  LIBRARY::set<int> myset(myints, myints + 5);

  LIBRARY::set<int>::reverse_iterator rit;

  int result[] = {17, 21, 49, 64, 78};
  int i = 5;
  for (rit = myset.rbegin(); rit != myset.rend(); ++rit)
    EXPECT_EQ(*rit, result[--i]);
}

TEST(SetTest, Empty)
{
  LIBRARY::set<int> myset;

  myset.insert(20);
  myset.insert(30);
  myset.insert(10);

  int i = 10;
  while (!myset.empty())
  {
    EXPECT_EQ(*myset.begin(), i);
    i += 10;
    myset.erase(myset.begin());
  }
  EXPECT_EQ(myset.size(), size_t(0));
}

TEST(SetTest, Size)
{
  LIBRARY::set<int> myints;
  EXPECT_EQ(myints.size(), size_t(0));
  for (int i = 0; i < 10; ++i)
    myints.insert(i);
  EXPECT_EQ(myints.size(), size_t(10));
  myints.insert(100);
  EXPECT_EQ(myints.size(), size_t(11));
  myints.erase(5);
  EXPECT_EQ(myints.size(), size_t(10));
}

TEST(SetTest, MaxSize)
{
  LIBRARY::set<int> myset;
  std::set<int> stdset;
  EXPECT_EQ(myset.max_size(), stdset.max_size()) << "T = int = " << sizeof(int); 
  LIBRARY::set<double> myset2;
  std::set<double> stdset2;
  EXPECT_EQ(myset2.max_size(), stdset2.max_size())  << "T = double = " << sizeof(double); 
  LIBRARY::set<char> myset3;
  std::set<char> stdset3;
  EXPECT_EQ(myset3.max_size(), stdset3.max_size())  << "T = char = " << sizeof(char); 
}

TEST(SetTest, Insert)
{
  LIBRARY::set<int> myset;
  LIBRARY::set<int>::iterator it;
  LIBRARY::pair<LIBRARY::set<int>::iterator, bool> ret;

  // set some initial values:
  for (int i = 1; i <= 5; ++i)
    myset.insert(i * 10); // set: 10 20 30 40 50

  ret = myset.insert(20); // no new element inserted

  if (ret.second == false)
    it = ret.first; // "it" now points to element 20

  myset.insert(it, 25); // max efficiency inserting
  myset.insert(it, 24); // max efficiency inserting
  myset.insert(it, 26); // no max efficiency inserting

  int myints[] = {5, 10, 15}; // 10 already in set, not inserted
  myset.insert(myints, myints + 3);

  int i = 0;
  int result[] = {5, 10, 15, 20, 24, 25, 26, 30, 40, 50};
  for (it = myset.begin(); it != myset.end(); ++it)
    EXPECT_EQ(*it, result[i++]);
}
TEST(SetTest, Erase)
{
  LIBRARY::set<int> myset;
  LIBRARY::set<int>::iterator it;

  // insert some values:
  for (int i = 1; i < 10; i++)
    myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90

  it = myset.begin();
  ++it; // "it" points now to 20

  myset.erase(it);

  myset.erase(40);

  it = myset.find(60);
  myset.erase(it, myset.end());

  int i = 0;
  int result[] = {10, 30, 50};
  ASSERT_EQ(myset.size(), size_t(3));
  for (it = myset.begin(); it != myset.end(); ++it)
    EXPECT_EQ(*it, result[i++]);
}
TEST(SetTest, Swap)
{
  int myints[] = {12, 75, 10, 32, 20, 25};
  LIBRARY::set<int> first(myints, myints + 3);      // 10,12,75
  LIBRARY::set<int> second(myints + 3, myints + 6); // 20,25,32
  LIBRARY::set<int>::iterator it;
  first.swap(second);

  int i = 0;
  int result1[] = {20, 25, 32};
  ASSERT_EQ(first.size(), size_t(3));
  for (it = first.begin(); it != first.end(); ++it)
    EXPECT_EQ(*it, result1[i++]);

  i = 0;
  int result2[] = {10, 12, 75};
  ASSERT_EQ(second.size(), size_t(3));
  for (it = second.begin(); it != second.end(); ++it)
    EXPECT_EQ(*it, result2[i++]);
}

TEST(SetTest, Clear)
{
  LIBRARY::set<int> myset;

  myset.insert(100);
  myset.insert(200);
  myset.insert(300);

  ASSERT_EQ(myset.size(), size_t(3));
  myset.clear();
  ASSERT_EQ(myset.size(), size_t(0));
  myset.insert(1101);
  myset.insert(2202);
  ASSERT_EQ(myset.size(), size_t(2));
}

TEST(SetTest, KeyComp)
{
  LIBRARY::set<int> myset;
  int highest;

  LIBRARY::set<int>::key_compare mycomp = myset.key_comp();

  for (int i = 0; i <= 5; i++)
    myset.insert(i);

  highest = *myset.rbegin();
  LIBRARY::set<int>::iterator it = myset.begin();
  while (mycomp(*(it++), highest))
    ;
  EXPECT_EQ(it, myset.end());
}

TEST(SetTest, ValComp)
{
  LIBRARY::set<int> myset;

  LIBRARY::set<int>::value_compare mycomp = myset.value_comp();

  for (int i = 0; i <= 5; i++)
    myset.insert(i);

  int highest = *myset.rbegin();
  LIBRARY::set<int>::iterator it = myset.begin();
  while (mycomp(*(it++), highest))
    ;
  EXPECT_EQ(it, myset.end());
}
TEST(SetTest, Find)
{
  LIBRARY::set<int> myset;
  LIBRARY::set<int>::iterator it;

  // set some initial values:
  for (int i = 1; i <= 5; i++)
    myset.insert(i * 10); // set: 10 20 30 40 50

  it = myset.find(20);
  myset.erase(it);
  myset.erase(myset.find(40));
  int i = 0;
  int result[] = {10, 30, 50};
  ASSERT_EQ(myset.size(), size_t(3));
  for (it = myset.begin(); it != myset.end(); ++it)
    EXPECT_EQ(*it, result[i++]);
}
TEST(SetTest, Count)
{
  LIBRARY::set<int> myset;

  // set some initial values:
  for (int i = 1; i < 5; ++i)
    myset.insert(i * 3); // set: 3 6 9 12

  EXPECT_TRUE(myset.count(3));
  EXPECT_FALSE(myset.count(4));
  EXPECT_TRUE(myset.count(9));
  EXPECT_TRUE(myset.count(12));
}

TEST(SetTest, Bound)
{
  LIBRARY::set<int> myset;
  LIBRARY::set<int>::iterator itlow, itup;

  for (int i = 1; i < 10; i++)
    myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90

  itlow = myset.lower_bound(30); //       ^
  itup = myset.upper_bound(60);  //                   ^

  myset.erase(itlow, itup); // 10 20 70 80 90
  EXPECT_EQ(myset.size(), size_t(5));
  EXPECT_FALSE(myset.count(50));
  EXPECT_TRUE(myset.count(90));
}

TEST(SetTest, EqualRange)
{
  LIBRARY::set<int> myset;

  for (int i = 1; i <= 5; i++)
    myset.insert(i * 10); // myset: 10 20 30 40 50

  LIBRARY::pair<LIBRARY::set<int>::iterator, LIBRARY::set<int>::iterator> ret;
  ret = myset.equal_range(30);
  EXPECT_EQ(*ret.first, 30);
  EXPECT_EQ(*ret.second, 40);
  ret = myset.equal_range(50);
  EXPECT_EQ(*ret.first, 50);
  EXPECT_EQ(ret.second, myset.end());
}

TEST(SetTest, RelOps)
{
  int myints[] = {10, 2, 2, 7, 3, 20, 6, 15};
  LIBRARY::set<int> foo(myints, myints + 5);
  LIBRARY::set<int> bar(myints + 4, myints + 8);

  EXPECT_FALSE(foo == bar);
  EXPECT_TRUE(foo != bar);
  EXPECT_FALSE(foo > bar);
  EXPECT_TRUE(foo < bar);
  EXPECT_FALSE(foo >= bar);
  EXPECT_TRUE(foo <= bar);
}

TEST(SetTest, ConstIterator)
{
  LIBRARY::set<int> set; // three ints with a value of 100
  std::set<int> sset; // three ints with a value of 100
  for (int i = 0; i < 10000; ++i) {
    set.insert(i);
    sset.insert(i);
    set.insert(i);
    sset.insert(i);
  }

  std::set<int>::const_iterator sit;
  LIBRARY::set<int>::const_iterator it;
  LIBRARY::set<int>::const_iterator it3(it);
  LIBRARY::set<int>::iterator it2;

  sit =  sset.begin();
  it = set.begin();
  while (it != set.end())
  {
    EXPECT_EQ(*sit++, *it++);
    // *it += 5;
  }
  it2 = --set.end();
  it = it2;
  it3 = it2;
  // it2 = it;
}

TEST(SetTest, ReverseConstIterator)
{
  LIBRARY::set<int> set; // three ints with a value of 100
  std::set<int> sset; // three ints with a value of 100
  for (int i = 0; i < 10000; ++i) {
    set.insert(i);
    sset.insert(i);
    set.insert(i);
    sset.insert(i);
  }
  LIBRARY::set<int>::const_reverse_iterator rit;
  LIBRARY::set<int>::const_reverse_iterator rit2(rit);
  std::set<int>::const_reverse_iterator srit;

  srit = sset.rbegin();
  rit = set.rbegin();
  while (rit != set.rend()) {
    // *rit += 5;
    EXPECT_EQ(*srit++, *rit++);
  }
  rit2 = set.rbegin();
  rit = rit2;
  // rit2 = rit;
}
