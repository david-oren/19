TEST(MapTest, Constructors)
{
	LIBRARY::map<char, int> first;

	first['a'] = 10;
	first['b'] = 30;
	first['c'] = 50;
	first['d'] = 70;

	LIBRARY::map<char, int> second(first.begin(), first.end());

	LIBRARY::map<char, int> third(second);

	LIBRARY::map<char, int, classcomp> fourth;	// class as Compare

	EXPECT_EQ(first.size(), size_t(4));
	EXPECT_EQ(second.size(), size_t(4));
	EXPECT_EQ(third.size(), size_t(4));
	EXPECT_EQ(fourth.size(), size_t(0));
	bool (*fn_pt)(char, char) = fncomp;
	LIBRARY::map<char, int, bool (*)(char, char)> fifth(fn_pt);	 // function pointer as Compare
}

TEST(MapTest, Assignment)
{
	LIBRARY::map<char, int> first;
	LIBRARY::map<char, int> second;

	first['x'] = 8;
	first['y'] = 16;
	first['z'] = 32;

	second = first;						// second now contains 3 ints
	first = LIBRARY::map<char, int>();	// and first is now empty

	EXPECT_EQ(first.size(), size_t(0));
	EXPECT_EQ(second.size(), size_t(3));
}

TEST(MapTest, Begin)
{
	LIBRARY::map<char, int> mymap;

	mymap['b'] = 100;
	mymap['a'] = 200;
	mymap['c'] = 300;

	char c = 'a';
	for (LIBRARY::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
		EXPECT_EQ(it->first, c++);
}

TEST(MapTest, RBegin)
{
	LIBRARY::map<char, int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	int i = 300;
	LIBRARY::map<char, int>::reverse_iterator rit;
	for (rit = mymap.rbegin(); rit != mymap.rend(); ++rit)
	{
		EXPECT_EQ(rit->second, i);
		i -= 100;
	}
}

TEST(MapTest, Empty)
{
	LIBRARY::map<char, int> mymap;

	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;

	while (!mymap.empty())
	{
		// std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		mymap.erase(mymap.begin());
	}
	EXPECT_EQ(mymap.size(), size_t(0));
}
TEST(MapTest, Size)
{
	LIBRARY::map<char, int> mymap;
	mymap['a'] = 101;
	mymap['b'] = 202;
	mymap['c'] = 302;

	EXPECT_EQ(mymap.size(), size_t(3));
}

TEST(MapTest, MaxSize)
{
	LIBRARY::map<int, int> mymap;
	std::map<int, int> stdmap;
	EXPECT_EQ(mymap.max_size(), stdmap.max_size());
	LIBRARY::map<double, double> mymap2;
	std::map<double, double> stdmap2;
	EXPECT_EQ(mymap2.max_size(), stdmap2.max_size());
	LIBRARY::map<char, int> mymap3;
	std::map<char, int> stdmap3;
	EXPECT_EQ(mymap3.max_size(), stdmap3.max_size());
}

TEST(MapTest, Brackets)
{
	LIBRARY::map<char, std::string> mymap;

	mymap['a'] = "an element";
	mymap['b'] = "another element";
	mymap['c'] = mymap['b'];

	// for (ft::map<char, std::string>::iterator it = mymap.begin(); it != mymap.end(); it++)
	// 	std::cout << it->first << " => " << it->second << '\n';

	EXPECT_EQ(mymap['a'], "an element");
	EXPECT_EQ(mymap['b'], "another element");
	EXPECT_EQ(mymap['c'], "another element");
	EXPECT_EQ(mymap['d'], "");
	EXPECT_EQ(mymap.size(), size_t(4));
}
TEST(MapTest, Insert)
{
	LIBRARY::map<char, int> mymap;

	// first insert function version (single parameter):
	mymap.insert(LIBRARY::pair<char, int>('a', 100));
	mymap.insert(LIBRARY::pair<char, int>('z', 200));

	LIBRARY::pair<LIBRARY::map<char, int>::iterator, bool> ret;
	ret = mymap.insert(LIBRARY::pair<char, int>('z', 500));
	EXPECT_FALSE(ret.second);

	// second insert function version (with hint position):
	LIBRARY::map<char, int>::iterator it = mymap.begin();
	mymap.insert(it, LIBRARY::pair<char, int>('b', 300));  // max efficiency inserting
	mymap.insert(it, LIBRARY::pair<char, int>('c', 400));  // no max efficiency inserting

	// third insert function version (range insertion):
	LIBRARY::map<char, int> anothermap;
	anothermap.insert(mymap.begin(), mymap.find('c'));

	// showing contents:
	int i = 0;
	int res1[] = {100, 300, 400, 200};
	for (it = mymap.begin(); it != mymap.end(); ++it)
		EXPECT_EQ(it->second, res1[i++]);

	char c = 'a';
	for (it = anothermap.begin(); it != anothermap.end(); ++it)
		EXPECT_EQ(it->first, c++);
}

TEST(MapTest, Erase)
{
	LIBRARY::map<char, int> mymap;
	LIBRARY::map<char, int>::iterator it;

	// insert some values:
	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;
	mymap['d'] = 40;
	mymap['e'] = 50;
	mymap['f'] = 60;

	it = mymap.find('b');
	mymap.erase(it);  // erasing by iterator

	mymap.erase('c');  // erasing by key

	it = mymap.find('e');
	mymap.erase(it, mymap.end());  // erasing by range

	EXPECT_EQ(mymap['d'], 40);
	EXPECT_EQ(mymap['a'], 10);
	EXPECT_EQ(mymap.size(), size_t(2));
}

TEST(MapTest, Swap)
{
	LIBRARY::map<char, int> foo, bar;

	foo['x'] = 100;
	foo['y'] = 200;

	bar['a'] = 11;
	bar['b'] = 22;
	bar['c'] = 33;

	EXPECT_EQ(foo.size(), size_t(2));
	EXPECT_EQ(bar.size(), size_t(3));
	foo.swap(bar);
	EXPECT_EQ(foo['a'], 11);
	EXPECT_EQ(foo.size(), size_t(3));
	EXPECT_EQ(bar.size(), size_t(2));

	swap(bar, foo);
	EXPECT_EQ(foo['x'], 100);
	EXPECT_EQ(foo.size(), size_t(2));
	EXPECT_EQ(bar.size(), size_t(3));
}

TEST(MapTest, Clear)
{
	LIBRARY::map<char, int> mymap;

	mymap['x'] = 100;
	mymap['y'] = 200;
	mymap['z'] = 300;

	mymap.clear();
	EXPECT_EQ(mymap.size(), size_t(0));
	mymap['a'] = 1101;
	mymap['b'] = 2202;
	EXPECT_EQ(mymap.size(), size_t(2));
}

TEST(MapTest, KeyComp)
{
	LIBRARY::map<char, int> mymap;

	LIBRARY::map<char, int>::key_compare mycomp = mymap.key_comp();

	mymap['a'] = 100;
	mymap['b'] = 200;
	mymap['c'] = 300;

	char highest = mymap.rbegin()->first;  // key value of last element

	LIBRARY::map<char, int>::iterator it = mymap.begin();
	do
	{
	} while (mycomp((*it++).first, highest));
	EXPECT_EQ(it, mymap.end());
}

TEST(MapTest, ValComp)
{
	LIBRARY::map<char, int> mymap;

	mymap['x'] = 1001;
	mymap['y'] = 2002;
	mymap['z'] = 3003;

	LIBRARY::pair<char, int> highest = *mymap.rbegin();	 // last element

	LIBRARY::map<char, int>::iterator it = mymap.begin();
	do
	{
		// std::cout << it->first << " => " << it->second << '\n';
	} while (mymap.value_comp()(*it++, highest));
	EXPECT_EQ(it, mymap.end());
}
TEST(MapTest, Find)
{
	LIBRARY::map<char, int> mymap;
	LIBRARY::map<char, int>::iterator it;

	mymap['a'] = 50;
	mymap['b'] = 100;
	mymap['c'] = 150;
	mymap['d'] = 200;

	it = mymap.find('b');
	if (it != mymap.end())
		mymap.erase(it);

	EXPECT_EQ(mymap.size(), size_t(3));
	EXPECT_EQ(mymap.find('a')->second, 50);
	EXPECT_EQ(mymap.find('b'), mymap.end());
	EXPECT_EQ(mymap.find('c')->second, 150);
	EXPECT_EQ(mymap.find('d')->second, 200);
	EXPECT_EQ(mymap.size(), size_t(3));
}
TEST(MapTest, Count)
{
	LIBRARY::map<char, int> mymap;

	mymap['a'] = 101;
	mymap['c'] = 202;
	mymap['f'] = 303;
	EXPECT_TRUE(mymap.count('a'));
	EXPECT_FALSE(mymap.count('b'));
	EXPECT_TRUE(mymap.count('c'));
	EXPECT_TRUE(mymap.count('f'));
}

TEST(MapTest, Bound)
{
	LIBRARY::map<char, int> mymap;
	LIBRARY::map<char, int>::iterator itlow, itup;

	mymap['a'] = 20;
	mymap['b'] = 40;
	mymap['c'] = 60;
	mymap['d'] = 80;
	mymap['e'] = 100;

	itlow = mymap.lower_bound('b');	 // itlow points to b
	itup = mymap.upper_bound('c');	 // itup points to d (not c!)
	EXPECT_EQ(itup->second, 80);
	mymap.erase(itlow, itup);  // erases [itlow,itup)

	EXPECT_EQ(mymap.size(), size_t(3));
	EXPECT_FALSE(mymap.count('b'));
	EXPECT_TRUE(mymap.count('d'));
}

TEST(MapTest, EqualRange)
{
	LIBRARY::map<char, int> mymap;

	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;

	LIBRARY::pair<LIBRARY::map<char, int>::iterator, LIBRARY::map<char, int>::iterator> ret;
	ret = mymap.equal_range('b');
	EXPECT_EQ(ret.first->first, 'b');
	EXPECT_EQ(ret.first->second, 20);
	EXPECT_EQ(ret.second->first, 'c');
	EXPECT_EQ(ret.second->second, 30);
	ret = mymap.equal_range('c');
	EXPECT_EQ(ret.first->first, 'c');
	EXPECT_EQ(ret.first->second, 30);
	EXPECT_EQ(ret.second, mymap.end());
}

TEST(MapTest, RelOps)
{
	LIBRARY::map<char, int> foo, bar;
	std::map<char, int> foo2, bar2;
	foo['a'] = 100;
	foo['b'] = 200;
	bar['a'] = 10;
	bar['z'] = 1000;

	foo2['a'] = 100;
	foo2['b'] = 200;
	bar2['a'] = 10;
	bar2['z'] = 1000;
	// for (LIBRARY::map<char,int>::iterator it = bar.begin(); it != bar.end(); ++it)
	//   std::cout << it->first << "=>" << it->second << " , ";
	// std::cout << std::endl;
	// for (std::map<char,int>::iterator it = bar2.begin(); it != bar2.end(); ++it)
	//   std::cout << it->first << "=>" << it->second << " , ";
	// std::cout << std::endl;

	// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
	EXPECT_FALSE(foo == bar);
	EXPECT_TRUE(foo != bar);
	EXPECT_FALSE(foo < bar);
	EXPECT_TRUE(foo > bar);
	EXPECT_FALSE(foo <= bar);
	EXPECT_TRUE(foo >= bar);
}

TEST(MapTest, RelOpsCchudant)
{
	LIBRARY::map<int, int> map;
	map[0] = 50;
	map[90] = 5;

	LIBRARY::map<int, int> map2;
	map2[0] = 50;
	map2[90] = 5;
	map2[2] = 80;

	EXPECT_TRUE(map != map2);
	EXPECT_TRUE(map2 < map);
	EXPECT_TRUE(map2 <= map);
	EXPECT_TRUE(!(map2 > map));
	EXPECT_TRUE(!(map2 >= map));

	map[2] = 80;
	EXPECT_TRUE(map == map2);
	EXPECT_TRUE(!(map2 < map));
	EXPECT_TRUE(map2 <= map);
	EXPECT_TRUE(!(map2 > map));
	EXPECT_TRUE(map2 >= map);

	map[1] = 4;
	EXPECT_TRUE(map != map2);
	EXPECT_TRUE(map2 > map);
	EXPECT_TRUE(map2 >= map);
	EXPECT_TRUE(!(map2 < map));
	EXPECT_TRUE(!(map2 <= map));
}

TEST(MapTest, Glagan)
{
	LIBRARY::map<int, int> mp;
	std::map<int, int> stdmp;
	LIBRARY::map<int, int>::iterator it;
	std::map<int, int>::iterator sit;
	mp[5] = 42;
	mp[7] = 28;
	mp[9] = 44;

	EXPECT_EQ(mp.size(), size_t(3));
	it = mp.begin();
	EXPECT_EQ((*it).first, 5);
	EXPECT_EQ(it->second, 42);
	EXPECT_EQ(mp[5], 42);
	it = --mp.end();
	EXPECT_EQ((*it).first, 9);
	EXPECT_EQ(it->second, 44);
	EXPECT_EQ(mp[9], 44);
}

TEST(MapTest, Glagan2)
{
	LIBRARY::map<std::string, int> mp;
	std::map<std::string, int> stdmp;
	LIBRARY::map<std::string, int>::iterator it;
	std::map<std::string, int>::iterator sit;

	mp[std::string("hej")] = 1;
	mp[std::string("bonjour")] = 2;
	mp[std::string("hello")] = 3;
	mp[std::string("ciao")] = 4;
	EXPECT_EQ(mp.size(), size_t(4));

	it = mp.begin();
	EXPECT_EQ(it->second, 2);
	it++;
	EXPECT_EQ(it->second, 4);
	it++;
	EXPECT_EQ(it->second, 1);
	it++;
	EXPECT_EQ(it->second, 3);
	it = mp.find(std::string("hej"));
}

TEST(MapTest, ConstIterator)
{
	LIBRARY::map<int, int> map;	 // three ints with a value of 100
	map[5] = 42;
	map[7] = 28;
	map[9] = 44;
	LIBRARY::map<int, int>::const_iterator it;
	LIBRARY::map<int, int>::const_iterator it3(it);
	LIBRARY::map<int, int>::iterator it2;

	for (it = map.begin(); it != map.end(); ++it)
	{
		// it->second += 5;
	}
	it2 = --map.end();
	it = it2;
	it3 = it2;
	// it2 = it;
}

TEST(MapTest, ReverseConstIterator)
{
	LIBRARY::map<int, int> map;	 // three ints with a value of 100
	std::map<int, int> smap;	 // three ints with a value of 100
	map[5] = 42;
	map[7] = 28;
	map[9] = 44;
	smap[5] = 42;
	smap[7] = 28;
	smap[9] = 44;
	LIBRARY::map<int, int>::const_reverse_iterator rit;
	LIBRARY::map<int, int>::const_reverse_iterator rit2(rit);
	std::map<int, int>::const_reverse_iterator srit;

	srit = smap.rbegin();
	rit = map.rbegin();
	while (rit != map.rend())
	{
		// *rit += 5;
		EXPECT_EQ(srit->first, rit->first);
		EXPECT_EQ(srit->second, rit->second);
		srit++;
		rit++;
	}
	rit2 = map.rbegin();
	rit = rit2;
	// rit2 = rit;
}
