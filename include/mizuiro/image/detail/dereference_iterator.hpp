//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_DEREFERENCE_ITERATOR_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_DEREFERENCE_ITERATOR_HPP_INCLUDED

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Reference
>
struct dereference_iterator {
	typedef Reference result_type;

	template<
		typename T
	>
	result_type
	operator()(
		T const &it
	) const
	{
		return *it;
	}
};

}
}
}

#endif
