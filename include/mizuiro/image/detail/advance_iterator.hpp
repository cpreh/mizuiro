//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_ADVANCE_ITERATOR_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_ADVANCE_ITERATOR_HPP_INCLUDED

#include <mizuiro/detail/nonassignable.hpp>


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
class advance_iterator
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		advance_iterator
	);
public:
	typedef
	Variant
	result_type;

	explicit
	advance_iterator(
		DifferenceType const _diff
	)
	:
		diff_(
			_diff
		)
	{
	}

	template<
		typename T
	>
	result_type
	operator()(
		T _value
	) const
	{
		return
			_value += diff_;
	}
private:
	DifferenceType const diff_;
};

}
}
}

#endif
