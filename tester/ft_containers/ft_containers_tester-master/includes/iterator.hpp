#ifndef ITERATOR_HPP
#define ITERATOR_HPP

namespace ft
{
template <bool flag, class IsTrue, class IsFalse>
struct choose;

template <class IsTrue, class IsFalse>
struct choose<true, IsTrue, IsFalse>
{
	typedef IsTrue type;
};

template <class IsTrue, class IsFalse>
struct choose<false, IsTrue, IsFalse>
{
	typedef IsFalse type;
};
// ITERATOR TAGS ###############################################################
struct input_iterator_tag
{
};
///  Marking output iterators.
struct output_iterator_tag
{
};
/// Forward iterators support a superset of input iterator operations.
struct forward_iterator_tag : public input_iterator_tag
{
};
/// Bidirectional iterators support a superset of forward iterator
/// operations.
struct bidirectional_iterator_tag : public forward_iterator_tag
{
};
/// Random-access iterators support a superset of bidirectional iterator
/// operations.
struct random_access_iterator_tag : public bidirectional_iterator_tag
{
};

// ITERATOR TRAITS #############################################################
template <class Iterator>
struct iterator_traits
{
	typedef typename Iterator::value_type value_type;
	typedef typename Iterator::difference_type difference_type;
	typedef typename Iterator::pointer pointer;
	typedef typename Iterator::reference reference;
	typedef typename Iterator::iterator_category iterator_category;
};
template <class T>
struct iterator_traits<T*>
{
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef T* pointer;
	typedef T& reference;
	typedef random_access_iterator_tag iterator_category;  // STD OR FT?
};
template <class T>
struct iterator_traits<const T*>
{
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef const T* pointer;
	typedef const T& reference;
	typedef random_access_iterator_tag iterator_category;
};

// ADVANCE #####################################################################
template <class InputIterator, class Distance>
void advance(InputIterator& i, Distance n, ft::input_iterator_tag)
{
	for (; n > 0; --n) ++i;
}

template <class BidirectionalIterator, class Distance>
void advance(BidirectionalIterator& i, Distance n, ft::bidirectional_iterator_tag)
{
	if (n >= 0)
		for (; n > 0; --n) ++i;
	else
		for (; n < 0; ++n) --i;
}

template <class RandomAccessIterator, class Distance>
void advance(RandomAccessIterator& i, Distance n, ft::random_access_iterator_tag)
{
	i += n;
}

template <class InputIterator, class Distance>
void advance(InputIterator& i, Distance n)
{
	advance(i, n, typename iterator_traits<InputIterator>::iterator_category());
}

// DISTANCE ####################################################################
template <class InputIterator>
typename ft::iterator_traits<InputIterator>::difference_type
distance(InputIterator first, InputIterator last, ft::input_iterator_tag)
{
	typename ft::iterator_traits<InputIterator>::difference_type n = 0;
	for (; first != last; first++) n++;
	return n;
}

template <class RandomAccessIterator>
typename ft::iterator_traits<RandomAccessIterator>::difference_type
distance(RandomAccessIterator first, RandomAccessIterator last, ft::random_access_iterator_tag)
{
	return last - first;
}

template <class InputIterator>
typename ft::iterator_traits<InputIterator>::difference_type
distance(InputIterator first, InputIterator last)
{
	return distance(first, last, typename iterator_traits<InputIterator>::iterator_category());
}

// REVERSE_ITERATOR ############################################################
template <class Iterator>
class reverse_iterator
{
	Iterator base_;

	template <class It2>
	friend class reverse_iterator;

public:
	typedef Iterator iterator_type;
	typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
	typedef typename iterator_traits<Iterator>::value_type value_type;
	typedef typename iterator_traits<Iterator>::difference_type difference_type;
	typedef typename iterator_traits<Iterator>::pointer pointer;
	typedef typename iterator_traits<Iterator>::reference reference;

	reverse_iterator() {}
	explicit reverse_iterator(iterator_type it) : base_(--it) {}
	template <class Iter>
	reverse_iterator(const reverse_iterator<Iter>& rev_it) : base_(--rev_it.base())
	{
	}

	template <class Iter>
	reverse_iterator& operator=(const reverse_iterator<Iter>& rev_it)
	{
		base_ = rev_it.base_;
		// base_ = --rev_it.base();
		return *this;
	}

	iterator_type base() const
	{
		Iterator ret(base_);
		++ret;
		return ret;
	}

	reference operator*() const { return *base_; }
	pointer operator->() const { return &(operator*()); }
	reference operator[](difference_type n) const { return base_[-1 - n]; }

	reverse_iterator operator+(difference_type n) const
	{
		reverse_iterator tmp(*this);
		tmp.base_ = tmp.base_ - n;
		return tmp;
	}
	reverse_iterator& operator+=(difference_type n)
	{
		base_ = base_ - n;
		return *this;
	}
	reverse_iterator operator-(difference_type n) const
	{
		reverse_iterator tmp(*this);
		tmp.base_ = tmp.base_ + n;
		return tmp;
	}
	reverse_iterator& operator-=(difference_type n)
	{
		base_ = base_ + n;
		return *this;
	}
	reverse_iterator& operator++()
	{
		--base_;
		return *this;
	}
	reverse_iterator operator++(int)
	{
		reverse_iterator tmp(*this);
		--base_;
		return tmp;
	}
	reverse_iterator& operator--()
	{
		++base_;
		return *this;
	}
	reverse_iterator operator--(int)
	{
		reverse_iterator tmp(*this);
		++base_;
		return tmp;
	}
	template <class it>
	friend bool operator==(const reverse_iterator& lhs, const reverse_iterator<it>& rhs)
	{
		return lhs.base_ == rhs.base_;
	}
	template <class it>
	friend bool operator!=(const reverse_iterator& lhs, const reverse_iterator<it>& rhs)
	{
		return lhs.base_ != rhs.base_;
	}
	template <class it>
	friend bool operator<(const reverse_iterator& lhs, const reverse_iterator<it>& rhs)
	{
		return lhs.base_ > rhs.base_;
	}
	template <class it>
	friend bool operator<=(const reverse_iterator& lhs, const reverse_iterator<it>& rhs)
	{
		return lhs.base_ >= rhs.base_;
	}
	template <class it>
	friend bool operator>(const reverse_iterator& lhs, const reverse_iterator<it>& rhs)
	{
		return lhs.base_ < rhs.base_;
	}
	template <class it>
	friend bool operator>=(const reverse_iterator& lhs, const reverse_iterator<it>& rhs)
	{
		return lhs.base_ <= rhs.base_;
	}
};

template <class Iterator>
ft::reverse_iterator<Iterator> operator+(
	typename ft::reverse_iterator<Iterator>::difference_type n,
	const ft::reverse_iterator<Iterator>& rev_it)
{
	return ft::reverse_iterator<Iterator>(rev_it + n);
}
template <class Iterator>
ft::reverse_iterator<Iterator> operator-(
	typename ft::reverse_iterator<Iterator>::difference_type n,
	const ft::reverse_iterator<Iterator>& rev_it)
{
	return ft::reverse_iterator<Iterator>(rev_it - n);
}
}  // namespace ft

#endif
