#include <gtest/gtest.h>

#include <cctype>
#include <cmath>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

// #include "gtest/gtest.h"

bool fncomp(char lhs, char rhs) { return lhs < rhs; }
bool fncomp(int lhs, int rhs) { return lhs < rhs; }

struct classcomp
{
	bool operator()(const char &lhs, const char &rhs) const
	{
		return lhs < rhs;
	}
};

#ifndef LIBRARY
#define LIBRARY ft
#endif

#include <ft.hpp>

#ifndef FLAGS
#define FLAGS 31
#endif

#if (FLAGS & 1)
#include "VectorTest.cpp"
#endif
#if (FLAGS & 2)
#include "ListTest.cpp"
#endif
#if (FLAGS & 4)
#include "StackTest.cpp"
#endif
#if (FLAGS & 8)
#include "QueueTest.cpp"
#endif
#if (FLAGS & 16)
#include "MapTest.cpp"
#endif
// BONUS:
#if (FLAGS & 32)
#include "DequeTest.cpp"
#endif
#if (FLAGS & 64)
#include "SetTest.cpp"
#endif
#if (FLAGS & 128)
#include "MultisetTest.cpp"
#endif
#if (FLAGS & 256)
#include "MultimapTest.cpp"
#endif

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	int ret = RUN_ALL_TESTS();
	return ret;
}
