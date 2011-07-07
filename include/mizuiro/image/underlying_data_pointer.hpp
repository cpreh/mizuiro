//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_UNDERLYING_DATA_POINTER_HPP_INCLUDED
#define MIZUIRO_IMAGE_UNDERLYING_DATA_POINTER_HPP_INCLUDED

#include <mizuiro/color/types/pointer.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Iterator
>
typename mizuiro::color::types::pointer<
	typename Iterator::access,
	typename Iterator::color_format,
	typename Iterator::constness
>::type
underlying_data_pointer(
	Iterator const &_iterator
)
{
	return
		color_pointer(
			typename Iterator::access(),
			_iterator.format_store(),
			typename Iterator::constness(),
			_iterator.data()
		);
}

}
}

#endif
