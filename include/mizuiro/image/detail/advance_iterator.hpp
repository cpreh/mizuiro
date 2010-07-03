//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_ADVANCE_ITERATOR_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_ADVANCE_ITERATOR_HPP_INCLUDED

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Variant,
	typename DifferenceType
>
struct advance_iterator {
	typedef Variant result_type;

	explicit advance_iterator(
		DifferenceType diff
	)
	:
		diff(diff)
	{}

	template<
		typename T
	>
	result_type
	operator()(
		T t
	) const
	{
		return t += diff;	
	}
private:
	DifferenceType const diff;
};

}
}
}

#endif
