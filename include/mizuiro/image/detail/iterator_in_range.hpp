//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_ITERATOR_IN_RANGE_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_ITERATOR_IN_RANGE_HPP_INCLUDED

#include <mizuiro/image/underlying_data_pointer.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/add_pointer.hpp>
#include <boost/type_traits/remove_pointer.hpp>
#include <functional>

namespace mizuiro
{
namespace image
{
namespace detail
{

// TODO: this should work with ranges!
template<
	typename Iterator1,
	typename Iterator2
>
bool
iterator_in_range(
	Iterator1 const _begin,
	Iterator1 const _end,
	Iterator2 const &_iterator
)
{
	// TODO: is this right?
	typedef std::less_equal<
		typename boost::add_pointer<
			typename boost::add_const<
				typename boost::remove_pointer<
					typename mizuiro::color::types::pointer<
						typename Iterator1::access,
						typename Iterator1::color_format,
						typename Iterator1::constness
					>::type
				>::type
			>::type
		>::type
	> comp_type;

	comp_type comp;

	return
		comp(
			image::underlying_data_pointer(
				_begin
			),
			image::underlying_data_pointer(
				_iterator
			)
		)
		&&
		comp(
			image::underlying_data_pointer(
				_iterator
			),
			image::underlying_data_pointer(
				_end
			)
		);
}

}
}
}

#endif
