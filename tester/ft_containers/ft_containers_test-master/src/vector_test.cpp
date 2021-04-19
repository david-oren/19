/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 20:34:52 by charles           #+#    #+#             */
/*   Updated: 2020/04/26 12:08:35 by charles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers_test.hpp"
#include <vector>

static void testConstructorDefault()
{
    testName = "Vector.Vector empty";

    ft::Vector<int> v1;
    ASSERT(v1.empty());
    ASSERT(v1.size() == 0);
    ASSERT(v1.capacity() >= 0);
    ASSERT(v1.max_size() > 0);

    ft::Vector<char> v2;
    ASSERT(v2.empty());
    ASSERT(v2.size() == 0);
    ASSERT(v2.capacity() >= 0);
    ASSERT(v2.max_size() > 0);

    ft::Vector< ft::Vector<char*> > v3;
    ASSERT(v3.empty());
    ASSERT(v3.size() == 0);
    ASSERT(v3.capacity() >= 0);
    ASSERT(v3.max_size() > 0);
}

static void testConstructorFill()
{
    testName = "Vector.Vector fill";

    ft::Vector<int> v1(0);
    ASSERT(v1.empty());
    ASSERT(v1.size() == 0);
    ASSERT(v1.capacity() >= 0);

    ft::Vector<int> v2(3);
    ASSERT(!v2.empty());
    ASSERT(v2.size() == 3);
    ASSERT(v2.capacity() >= 3);
    for (size_t i = 0; i < v2.size(); i++)
        ASSERT(v2[i] == int());

    ft::Vector<std::string> v3(5);
    ASSERT(!v3.empty());
    ASSERT(v3.size() == 5);
    ASSERT(v3.capacity() >= 5);
    for (size_t i = 0; i < v3.size(); i++)
        ASSERT(v3[i] == std::string());

    ft::Vector<float> v4(6, 42.0f);
    ASSERT(!v4.empty());
    ASSERT(v4.size() == 6);
    ASSERT(v4.capacity() >= 6);
    for (size_t i = 0; i < v4.size(); i++)
        ASSERT(v4[i] == float(42.0));

    ft::Vector<std::string> v5(2, "bonjour");
    ASSERT(!v5.empty());
    ASSERT(v5.size() == 2);
    ASSERT(v5.capacity() >= 2);
    for (size_t i = 0; i < v5.size(); i++)
        ASSERT(v5[i] == std::string("bonjour"));
}

static void testConstructorRange()
{
    testName = "Vector.Vector range";

    int         arr1[5] = {1, 2, 3, 4, 5};
    std::string arr2[3] = {"bonjour", "je", "suis"};
    float       arr3[4] = {42.1, 42.2, 42.3, 42.4};

    ft::Vector<int> v1(arr1, arr1 + 5);
    ASSERT(!v1.empty());
    ASSERT(v1.size() == 5);
    ASSERT(v1.capacity() >= 5);
    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(v1[i] == arr1[i]);

    ft::Vector<std::string> v2(arr2, arr2 + 3);
    ASSERT(!v2.empty());
    ASSERT(v2.size() == 3);
    ASSERT(v2.capacity() >= 3);
    for (size_t i = 0; i < v2.size(); i++)
        ASSERT(v2[i] == arr2[i]);

    ft::Vector<float> v3(arr3, arr3 + 4);
    ASSERT(!v3.empty());
    ASSERT(v3.size() == 4);
    ASSERT(v3.capacity() >= 4);
    for (size_t i = 0; i < v3.size(); i++)
        ASSERT(v3[i] == arr3[i]);
}

static void testConstructorCopy()
{
    testName = "Vector.Vector copy";

    int                             arr1[5] = {1, 2, 3, 4, 5};
    std::string                     arr2[3] = {"bonjour", "je", "suis"};
    ft::Vector<int>                 v1_copied(arr1, arr1 + 5);
    ft::Vector<std::string>         v2_copied(arr2, arr2 + 3);
    ft::Vector<float>               v3_copied(6, 42.0f);
    ft::Vector< ft::Vector<char*> > v4_copied;

    ft::Vector<int> v1(v1_copied);
    ASSERT(v1.empty() == v1_copied.empty());
    ASSERT(v1.size() == v1_copied.size());
    ASSERT(v1.capacity() == v1_copied.capacity());
    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(v1[i] == v1_copied[i]);
    v1[0] = 0;
    ASSERT(v1[0] == 0);
    ASSERT(v1_copied[0] == 1);

    ft::Vector<std::string> v2(v2_copied);
    ASSERT(v2.empty() == v2_copied.empty());
    ASSERT(v2.size() == v2_copied.size());
    ASSERT(v2.capacity() == v2_copied.capacity());
    for (size_t i = 0; i < v2.size(); i++)
        ASSERT(v2[i] == v2_copied[i]);
    v2[0] = "aaa";
    ASSERT(v2[0] == "aaa");
    ASSERT(v2_copied[0] == "bonjour");
    v2[1] = "bbb";
    ASSERT(v2[1] == "bbb");
    ASSERT(v2_copied[1] == "je");
    v2[2] = "ccc";
    ASSERT(v2[2] == "ccc");
    ASSERT(v2_copied[2] == "suis");

    ft::Vector<float> v3(v3_copied);
    ASSERT(v3.empty() == v3_copied.empty());
    ASSERT(v3.size() == v3_copied.size());
    ASSERT(v3.capacity() == v3_copied.capacity());
    for (size_t i = 0; i < v3.size(); i++)
        ASSERT(v3[i] == v3_copied[i]);
    v3[5] = 19.19f;
    ASSERT(v3[5] == 19.19f);
    ASSERT(v3_copied[0] == 42.0);

    ft::Vector< ft::Vector<char*> > v4(v4_copied);
    ASSERT(v4.empty() == v4_copied.empty());
    ASSERT(v4.size() == v4_copied.size());
    ASSERT(v4.capacity() == v4_copied.capacity());
}

static void testOperatorAssign()
{
    testName = "Vector.operator=";

    int                             arr1[5] = {1, 2, 3, 4, 5};
    std::string                     arr2[3] = {"bonjour", "je", "suis"};
    ft::Vector<int>                 v1_duplicated(arr1, arr1 + 5);
    ft::Vector<std::string>         v2_duplicated(arr2, arr2 + 3);
    ft::Vector<float>               v3_duplicated(6, 42.0f);
    ft::Vector< ft::Vector<char*> > v4_duplicated;

    ft::Vector<int> v1;
    v1 = v1_duplicated;
    ASSERT(v1.empty() == v1_duplicated.empty());
    ASSERT(v1.size() == v1_duplicated.size());
    ASSERT(v1.capacity() == v1_duplicated.capacity());
    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(v1[i] == v1_duplicated[i]);
    v1[0] = 0;
    ASSERT(v1[0] == 0);
    ASSERT(v1_duplicated[0] == 1);

    ft::Vector<std::string> v2(10, "zzz");
    v2 = v2_duplicated;
    ASSERT(v2.empty() == v2_duplicated.empty());
    ASSERT(v2.size() == v2_duplicated.size());
    ASSERT(v2.capacity() == v2_duplicated.capacity());
    for (size_t i = 0; i < v2.size(); i++)
        ASSERT(v2[i] == v2_duplicated[i]);
    v2[0] = "aaa";
    ASSERT(v2[0] == "aaa");
    ASSERT(v2_duplicated[0] == "bonjour");
    v2[1] = "bbb";
    ASSERT(v2[1] == "bbb");
    ASSERT(v2_duplicated[1] == "je");
    v2[2] = "ccc";
    ASSERT(v2[2] == "ccc");
    ASSERT(v2_duplicated[2] == "suis");

    ft::Vector<float> v3(v3_duplicated);
    v3 = v3_duplicated;
    ASSERT(v3.empty() == v3_duplicated.empty());
    ASSERT(v3.size() == v3_duplicated.size());
    ASSERT(v3.capacity() == v3_duplicated.capacity());
    for (size_t i = 0; i < v3.size(); i++)
        ASSERT(v3[i] == v3_duplicated[i]);
    v3[5] = 19.19f;
    ASSERT(v3[5] == 19.19f);
    ASSERT(v3_duplicated[0] == 42.0f);

    ft::Vector< ft::Vector<char*> > v4(2, ft::Vector<char*>(2, NULL));
    v4 = v4_duplicated;
    ASSERT(v4.empty() == v4_duplicated.empty());
    ASSERT(v4.size() == v4_duplicated.size());
    ASSERT(v4.capacity() == v4_duplicated.capacity());
}

static void testBegin()
{
    testName = "Vector.begin";

    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::Vector<int> v1(arr1, arr1 + 5);

    ft::Vector<int>::iterator v1_it = v1.begin();
    ASSERT(*v1_it == 1);
    ASSERT(*(int*)(v1_it.operator->()) == 1);
    ASSERT(v1_it[0] == 1);
    ASSERT(v1_it[1] == 2);
    ASSERT(v1_it[2] == 3);
    ASSERT(v1_it[3] == 4);
    ASSERT(v1_it[4] == 5);

    ASSERT(v1_it == v1.begin());
    ASSERT(v1_it != v1.rbegin());
    ASSERT(v1_it != v1.end());
    ASSERT(v1_it != v1.rend());

    ASSERT(v1_it <= v1.begin());
    ASSERT(v1_it >= v1.begin());
    ASSERT(v1_it < v1.end());
    ASSERT(v1.end() > v1_it);

    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(*(v1_it + i) == arr1[i]);

    for (size_t i = 0; v1_it != v1.end(); ++v1_it, i++)
        ASSERT(*v1_it == arr1[i]);
    ASSERT(v1_it == v1.end());

    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(*(v1_it - 1 - i) == arr1[4 - i]);

    --v1_it;
    for (size_t i = 0; v1_it != v1.begin(); --v1_it, i++)
        ASSERT(*v1_it == arr1[4 - i]);
    ASSERT(*v1_it == arr1[0]);

    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(*v1_it++ == arr1[i]);
    ASSERT(v1_it == v1.end());

    v1_it--;
    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(*v1_it-- == arr1[4 - i]);
}

static void testEnd()
{
    testName = "Vector.end";

    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::Vector<int> v1(arr1, arr1 + 5);

    ft::Vector<int>::iterator v1_it = v1.end();
    ASSERT(v1_it[-1] == 5);
    ASSERT(v1_it[-2] == 4);
    ASSERT(v1_it[-3] == 3);
    ASSERT(v1_it[-4] == 2);
    ASSERT(v1_it[-5] == 1);

    ASSERT(v1_it == v1.end());
    ASSERT(v1_it != v1.begin());
    ASSERT(v1_it != v1.rbegin());
    ASSERT(v1_it != v1.rend());

    ASSERT(v1_it >= v1.end());
    ASSERT(v1_it >= v1.end());
    ASSERT(v1_it <= v1.end());
    ASSERT(v1_it <= v1.end());
    ASSERT(v1_it > v1.begin());
    ASSERT(v1.begin() < v1_it);

    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(*(v1_it - i - 1) == arr1[4 - i]);

    --v1_it;
    for (size_t i = 0; v1_it != v1.begin(); --v1_it, i++)
        ASSERT(*v1_it == arr1[4 - i]);
    ASSERT(v1_it == v1.begin());
    ASSERT(*v1_it == arr1[0]);

    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(*(v1_it + i) == arr1[i]);

    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(*v1_it++ == arr1[i]);
    ASSERT(v1_it == v1.end());

    v1_it--;
    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(*v1_it-- == arr1[4 - i]);
}

static void testRbegin()
{
    testName = "Vector.rbegin";

    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::Vector<int> v1(arr1, arr1 + 5);

    ft::Vector<int>::iterator v1_it = v1.rbegin();
    ASSERT(v1_it[0] == 5);
    ASSERT(v1_it[1] == 4);
    ASSERT(v1_it[2] == 3);
    ASSERT(v1_it[3] == 2);
    ASSERT(v1_it[4] == 1);

    ASSERT(v1_it == v1.rbegin());
    ASSERT(v1_it != v1.rend());
    ASSERT(v1_it != v1.begin());
    ASSERT(v1_it != v1.end());

    ASSERT(v1_it >= v1.rbegin());
    ASSERT(v1_it >= v1.rbegin());
    ASSERT(v1_it <= v1.rbegin());
    ASSERT(v1_it <= v1.rbegin());
    ASSERT(v1_it > v1.begin());
    ASSERT(v1_it < v1.end());
    ASSERT(v1_it < v1.rend());


    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(*(v1_it + i) == arr1[4 - i]);

    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(*v1_it++ == arr1[4 - i]);
    ASSERT(v1_it == v1.rend());
}

static void testRend()
{
    testName = "Vector.rend";

    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::Vector<int> v1(arr1, arr1 + 5);

    ft::Vector<int>::iterator v1_it = v1.rend();
    ASSERT(v1_it[-1] == 1);
    ASSERT(v1_it[-2] == 2);
    ASSERT(v1_it[-3] == 3);
    ASSERT(v1_it[-4] == 4);
    ASSERT(v1_it[-5] == 5);

    ASSERT(v1_it == v1.rend());
    ASSERT(v1_it != v1.rbegin());
    ASSERT(v1_it != v1.begin());
    ASSERT(v1_it != v1.end());

    ASSERT(v1_it >= v1.rend());
    ASSERT(v1_it >= v1.rend());
    ASSERT(v1_it <= v1.rend());
    ASSERT(v1_it <= v1.rend());
    ASSERT(v1_it > v1.rbegin());

    v1_it--;
    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(*(v1_it - i) == arr1[i]);
}

static void testResize()
{
    testName = "Vector.resize";

    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::Vector<int> v1(arr1, arr1 + 5);

    v1.resize(7);
    ASSERT(v1.size() == 7);
    ASSERT(v1.capacity() >= 7);
    for (size_t i = 0; i < 5; i++)
        ASSERT(v1[i] == arr1[i]);
    for (size_t i = 5; i < v1.size(); i++)
        ASSERT(v1[i] == int());

    v1.resize(10, 42);
    ASSERT(v1.size() == 10);
    ASSERT(v1.capacity() >= 10);
    for (size_t i = 0; i < 5; i++)
        ASSERT(v1[i] == arr1[i]);
    for (size_t i = 5; i < 7; i++)
        ASSERT(v1[i] == int());
    for (size_t i = 7; i < v1.size(); i++)
        ASSERT(v1[i] == 42);

    size_t prev_capacity = v1.capacity();
    v1.resize(10);
    ASSERT(v1.size() == 10);
    ASSERT(v1.capacity() == prev_capacity);
    for (size_t i = 0; i < 5; i++)
        ASSERT(v1[i] == arr1[i]);
    for (size_t i = 5; i < 7; i++)
        ASSERT(v1[i] == int());
    for (size_t i = 7; i < v1.size(); i++)
        ASSERT(v1[i] == 42);

    v1.resize(6);
    ASSERT(v1.size() == 6);
    ASSERT(v1.capacity() >= 6);
    for (size_t i = 0; i < 5; i++)
        ASSERT(v1[i] == arr1[i]);
    ASSERT(v1[5] == int());

    v1.resize(1);
    ASSERT(v1.size() == 1);
    ASSERT(v1.capacity() >= 1);
    ASSERT(v1[0] == arr1[0]);

    v1.resize(0);
    ASSERT(v1.size() == 0);
    ASSERT(v1.capacity() >= 0);
}

static void testReserve()
{
    testName = "Vector.reserve";

    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::Vector<int> v1(arr1, arr1 + 5);

    v1.reserve(0);
    ASSERT(v1.size() == 5);
    ASSERT(v1.capacity() >= 5);
    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(v1[i] == arr1[i]);

    v1.reserve(5);
    ASSERT(v1.size() == 5);
    ASSERT(v1.capacity() >= 5);
    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(v1[i] == arr1[i]);

    v1.reserve(6);
    ASSERT(v1.size() == 5);
    ASSERT(v1.capacity() >= 6);
    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(v1[i] == arr1[i]);

    v1.reserve(30);
    ASSERT(v1.size() == 5);
    ASSERT(v1.capacity() >= 30);
    for (size_t i = 0; i < v1.size(); i++)
        ASSERT(v1[i] == arr1[i]);
}

static void testOperatorBracket()
{
    testName = "Vector.operator[]";

    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::Vector<int> v1(arr1, arr1 + 5);

    ASSERT(v1[0] == 1);
    ASSERT(v1[1] == 2);
    ASSERT(v1[2] == 3);
    ASSERT(v1[3] == 4);
    ASSERT(v1[4] == 5);

    int&       mut  = v1[0];
    const int& imut = v1[0];
    ASSERT(mut == 1);
    ASSERT(imut == 1);
}

static void testAt()
{
    testName = "Vector.at";

    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::Vector<int> v1(arr1, arr1 + 5);

    try
    {
        ASSERT(v1.at(0) == 1);
        ASSERT(v1.at(1) == 2);
        ASSERT(v1.at(2) == 3);
        ASSERT(v1.at(3) == 4);
        ASSERT(v1.at(4) == 5);

        int&       mut  = v1.at(0);
        const int& imut = v1.at(0);
        ASSERT(mut == 1);
        ASSERT(imut == 1);
    }
    catch (const std::exception& e) { ASSERT(false); }

    try { v1.at(5); }
    catch (const std::out_of_range& e) { ASSERT(true); }
    catch (const std::exception& e)    { ASSERT(false); }

    try { v1.at(-1); }
    catch (const std::out_of_range& e) { ASSERT(true); }
    catch (const std::exception& e)    { ASSERT(false); }
}

static void testFront()
{
    testName = "Vector.front";

    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::Vector<int> v1(arr1, arr1 + 5);
    int&       mut  = v1.front();
    const int& imut = v1.front();
    ASSERT(mut == 1);
    ASSERT(imut == 1);
}

static void testBack()
{
    testName = "Vector.back";

    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::Vector<int> v1(arr1, arr1 + 5);
    int&       mut  = v1.back();
    const int& imut = v1.back();
    ASSERT(mut == 5);
    ASSERT(imut == 5);
}

static void testAssign()
{
    testName = "Vector.assign";

    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::Vector<int> v1(arr1, arr1 + 5);

    v1.assign(arr1 + 1, arr1 + 4);
    ASSERT(v1.size() == 3);
    ASSERT(v1.capacity() >= 3);
    for (size_t i = 0; i < 3; i++)
        ASSERT(v1[i] == arr1[i + 1]);

    v1.assign((size_t)6, (int)42);
    ASSERT(v1.size() == 6);
    ASSERT(v1.capacity() >= 6);
    for (size_t i = 0; i < 6; i++)
        ASSERT(v1[i] == 42);

    // fml
    // std::vector< std::vector<int>::size_type > ve(arr1, arr1 + 5);
    // ve.assign(6, 42);
    // ASSERT(ve.size() == 6);
    // ASSERT(ve.capacity() >= 6);
    // for (size_t i = 0; i < 6; i++)
    //     ASSERT(ve[i] == 42);
}

static void testPushBack()
{
    testName = "Vector.push_back";

    ft::Vector<int> v1;

    v1.push_back(1);
    ASSERT(v1.size() == 1);
    ASSERT(v1.capacity() >= 1);
    ASSERT(v1[0] == 1);

    v1.push_back(2);
    ASSERT(v1.size() == 2);
    ASSERT(v1.capacity() >= 2);
    ASSERT(v1[0] == 1);
    ASSERT(v1[1] == 2);

    v1.push_back(3);
    ASSERT(v1.size() == 3);
    ASSERT(v1.capacity() >= 3);
    ASSERT(v1[0] == 1);
    ASSERT(v1[1] == 2);
    ASSERT(v1[2] == 3);

    v1.push_back(4);
    ASSERT(v1.size() == 4);
    ASSERT(v1.capacity() >= 4);
    ASSERT(v1[0] == 1);
    ASSERT(v1[1] == 2);
    ASSERT(v1[2] == 3);
    ASSERT(v1[3] == 4);

    v1.push_back(5);
    ASSERT(v1.size() == 5);
    ASSERT(v1.capacity() >= 5);
    ASSERT(v1[0] == 1);
    ASSERT(v1[1] == 2);
    ASSERT(v1[2] == 3);
    ASSERT(v1[3] == 4);
    ASSERT(v1[4] == 5);
}

static void testPopBack()
{
    testName = "Vector.pop_back";

    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::Vector<int> v1(arr1, arr1 + 5);

    v1.pop_back();
    ASSERT(v1.size() == 4);
    ASSERT(v1.capacity() >= 4);
    ASSERT(v1[0] == 1);
    ASSERT(v1[1] == 2);
    ASSERT(v1[2] == 3);
    ASSERT(v1[3] == 4);

    v1.pop_back();
    ASSERT(v1.size() == 3);
    ASSERT(v1.capacity() >= 3);
    ASSERT(v1[0] == 1);
    ASSERT(v1[1] == 2);
    ASSERT(v1[2] == 3);

    v1.pop_back();
    ASSERT(v1.size() == 2);
    ASSERT(v1.capacity() >= 2);
    ASSERT(v1[0] == 1);
    ASSERT(v1[1] == 2);

    v1.pop_back();
    ASSERT(v1.size() == 1);
    ASSERT(v1.capacity() >= 1);
    ASSERT(v1[0] == 1);

    v1.pop_back();
    ASSERT(v1.size() == 0);
    ASSERT(v1.capacity() >= 0);
}

static void testInsert()
{
    testName = "Vector.insert";

    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::Vector<int> v1;
    ft::Vector<int>::iterator it;

    it = v1.insert(v1.end(), 1);
    ASSERT(v1.size() == 1);
    ASSERT(v1.capacity() >= 1);
    ASSERT(v1[0] == 1);
    ASSERT(*it == 1);

    it = v1.insert(v1.end(), 2);
    ASSERT(v1.size() == 2);
    ASSERT(v1.capacity() >= 2);
    ASSERT(v1[0] == 1);
    ASSERT(v1[1] == 2);
    ASSERT(*it == 2);

    it = v1.insert(v1.begin(), 0);
    ASSERT(v1.size() == 3);
    ASSERT(v1.capacity() >= 3);
    ASSERT(v1[0] == 0);
    ASSERT(v1[1] == 1);
    ASSERT(v1[2] == 2);
    ASSERT(*it == 0);

    v1.insert(v1.begin() + 1, arr1 + 1, arr1 + 4);
    ASSERT(v1.size() == 6);
    ASSERT(v1.capacity() >= 6);
    ASSERT(v1[0] == 0);
    ASSERT(v1[1] == 2);
    ASSERT(v1[2] == 3);
    ASSERT(v1[3] == 4);
    ASSERT(v1[4] == 1);
    ASSERT(v1[5] == 2);

    v1.insert(v1.begin() + 2, (size_t)3, (int)-1);
    ASSERT(v1.size() == 9);
    ASSERT(v1.capacity() >= 9);
    ASSERT(v1[0] == 0);
    ASSERT(v1[1] == 2);
    ASSERT(v1[2] == -1);
    ASSERT(v1[3] == -1);
    ASSERT(v1[4] == -1);
    ASSERT(v1[5] == 3);
    ASSERT(v1[6] == 4);
    ASSERT(v1[7] == 1);
    ASSERT(v1[8] == 2);
}

static void testErase()
{
    testName = "Vector.erase";

    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::Vector<int> v1(arr1, arr1 + 5);
    ft::Vector<int>::iterator it;

    it = v1.erase(v1.begin());
    ASSERT(v1.size() == 4);
    ASSERT(v1.capacity() >= 4);
    for (size_t i = 0; i < 4; i++)
        ASSERT(v1[i] == arr1[i + 1]);
    ASSERT(*it == 2);

    it = v1.erase(v1.end() - 1);
    ASSERT(v1.size() == 3);
    ASSERT(v1.capacity() >= 3);
    for (size_t i = 0; i < 3; i++)
        ASSERT(v1[i] == arr1[i + 1]);
    ASSERT(it == v1.end());

    it = v1.erase(v1.end() - 2);
    ASSERT(v1.size() == 2);
    ASSERT(v1.capacity() >= 2);
    ASSERT(v1[0] == 2);
    ASSERT(v1[1] == 4);
    ASSERT(*it == 4);

    v1.assign(arr1, arr1 + 5);
    it = v1.erase(v1.begin() + 1, v1.begin() + 3);
    ASSERT(v1.size() == 3);
    ASSERT(v1.capacity() >= 3);
    ASSERT(v1[0] == 1);
    ASSERT(v1[1] == 4);
    ASSERT(v1[2] == 5);
    ASSERT(*it == 4);

    it = v1.erase(v1.begin() + 1, v1.end());
    ASSERT(v1.size() == 1);
    ASSERT(v1.capacity() >= 1);
    ASSERT(v1[0] == 1);
    ASSERT(it == v1.end());

}

static void testSwap()
{
    testName = "Vector.swap";

    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::Vector<int> v1(arr1, arr1 + 5);
    ft::Vector<int> v2(arr1 + 1, arr1 + 4);

    v1.swap(v2);
    ASSERT(v1.size() == 3);
    ASSERT(v1.capacity() >= 3);
    for (size_t i = 0; i < 3; i++)
        ASSERT(v1[i] == arr1[i + 1]);
    ASSERT(v2.size() == 5);
    ASSERT(v2.capacity() >= 3);
    for (size_t i = 0; i < 5; i++)
        ASSERT(v2[i] == arr1[i]);

    v2.swap(v1);
    ASSERT(v2.size() == 3);
    ASSERT(v2.capacity() >= 3);
    for (size_t i = 0; i < 3; i++)
        ASSERT(v2[i] == arr1[i + 1]);
    ASSERT(v1.size() == 5);
    ASSERT(v1.capacity() >= 3);
    for (size_t i = 0; i < 5; i++)
        ASSERT(v1[i] == arr1[i]);
}

static void testClear()
{
    testName = "Vector.clear";

    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::Vector<int> v1(arr1, arr1 + 5);
    v1.clear();
    ASSERT(v1.size() == 0);
}

static void testOperatorEqual()
{
    testName = "Vector.operator[== !=]";

    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::Vector<int> v1(arr1, arr1 + 5);
    ft::Vector<int> v2(arr1 + 1, arr1 + 4);
    ft::Vector<int> v3(v1);

    ASSERT(v1 != v2);
    ASSERT(v1 == v3);
    ASSERT(v2 != v1);
    ASSERT(v2 != v3);
    ASSERT(v3 == v1);
    ASSERT(v3 != v2);

    v3[0] = 0;
    ASSERT(v1 != v3);
    ASSERT(v3 != v1);
}

static void testOperatorCompar()
{
    testName = "Vector.operator[< > <= >=]";

    std::string s1 = "bonjour";
    std::string s2 = "bonjoura";
    std::string s3 = "bonjou";
    ft::Vector<char> v1(s1.begin(), s1.end());
    ft::Vector<char> v2(s2.begin(), s2.end());
    ft::Vector<char> v3(s3.begin(), s3.end());

    ASSERT(v1 < v2);
    ASSERT(v1 > v3);
    ASSERT(v1 <= v2);
    ASSERT(v1 >= v3);
    ASSERT(v1 <= v1);
    ASSERT(v1 >= v1);

    ASSERT(v2 > v1);
    ASSERT(v2 > v3);
    ASSERT(v2 >= v1);
    ASSERT(v2 >= v3);
    ASSERT(v2 <= v2);
    ASSERT(v2 >= v2);

    ASSERT(v3 < v1);
    ASSERT(v3 < v2);
    ASSERT(v3 <= v1);
    ASSERT(v3 <= v2);
    ASSERT(v3 <= v3);
    ASSERT(v3 >= v3);
}

static void testSwapFunc()
{
    testName = "std::swap(Vector, Vector)";

    int             arr1[5] = {1, 2, 3, 4, 5};
    ft::Vector<int> v1(arr1, arr1 + 5);
    ft::Vector<int> v2(arr1 + 1, arr1 + 4);

    std::swap(v1, v2);
    ASSERT(v1.size() == 3);
    ASSERT(v1.capacity() >= 3);
    for (size_t i = 0; i < 3; i++)
        ASSERT(v1[i] == arr1[i + 1]);
    ASSERT(v2.size() == 5);
    ASSERT(v2.capacity() >= 3);
    for (size_t i = 0; i < 5; i++)
        ASSERT(v2[i] == arr1[i]);

    std::swap(v1, v2);
    ASSERT(v2.size() == 3);
    ASSERT(v2.capacity() >= 3);
    for (size_t i = 0; i < 3; i++)
        ASSERT(v2[i] == arr1[i + 1]);
    ASSERT(v1.size() == 5);
    ASSERT(v1.capacity() >= 3);
    for (size_t i = 0; i < 5; i++)
        ASSERT(v1[i] == arr1[i]);
}

void vectorTest()
{
    testContainer = "Vector";

    testConstructorDefault();
    testConstructorFill();
    testConstructorRange();
    testConstructorCopy();
    testOperatorAssign();

    testBegin();
    testEnd();
    testRbegin();
    testRend();

    testResize();
    testReserve();

    testOperatorBracket();
    testAt();
    testFront();
    testBack();

    testAssign();
    testPushBack();
    testPopBack();
    testInsert();
    testErase();
    testSwap();
    testClear();

    testOperatorEqual();
    testOperatorCompar();
    testSwapFunc();
}
