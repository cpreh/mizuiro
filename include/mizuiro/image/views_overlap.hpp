//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_VIEWS_OVERLAP_HPP_INCLUDED
#define MIZUIRO_IMAGE_VIEWS_OVERLAP_HPP_INCLUDED

#include <mizuiro/image/detail/iterator_in_range.hpp>
#include <mizuiro/image/detail/same_pointers.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename View1,
	typename View2
>
typename boost::enable_if<
	detail::same_pointers<
		View1,
		View2
	>,
	bool
>::type
views_overlap(
	View1 const &_view1,
	View2 const &_view2
)
{
	return
		image::detail::iterator_in_range(
			_view1.begin(),
			_view1.end(),
			_view2.begin()
		)
		||
		image::detail::iterator_in_range(
			_view2.begin(),
			_view2.end(),
			_view1.begin()
		);
}

template<
	typename View1,
	typename View2
>
typename boost::disable_if<
	detail::same_pointers<
		View1,
		View2
	>,
	bool
>::type
views_overlap(
	View1 const &,
	View2 const &
)
{
	return false;
}

}
}

#endif
