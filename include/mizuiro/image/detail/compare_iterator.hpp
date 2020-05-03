//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_COMPARE_ITERATOR_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_COMPARE_ITERATOR_HPP_INCLUDED


namespace mizuiro
{
namespace image
{
namespace detail
{

struct compare_iterator
{
	template<
		typename T1,
		typename T2
	>
	bool
	operator()(
		T1 const &,
		T2 const &
	) const
	{
		return
			false;
	}

	template<
		typename T
	>
	bool
	operator()(
		T const &_a,
		T const &_b
	) const
	{
		return
			_a
			==
			_b;
	}
};

}
}
}

#endif
