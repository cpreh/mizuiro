//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_ITERATOR_DIFFERENCE_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_ITERATOR_DIFFERENCE_HPP_INCLUDED


namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename DifferenceType
>
struct iterator_difference
{
	typedef
	DifferenceType
	result_type;

	template<
		typename T
	>
	result_type
	operator()(
		T const &_a,
		T const &_b
	) const
	{
		return
			_b - _a;
	}
};

}
}
}

#endif
