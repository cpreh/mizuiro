//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_TYPES_VALUE_TYPE_HPP_INCLUDED
#define MIZUIRO_IMAGE_TYPES_VALUE_TYPE_HPP_INCLUDED

#include <mizuiro/color/object_impl.hpp>

namespace mizuiro
{
namespace image
{
namespace types
{

template<
	typename Format,
	typename Enable = void
>
struct value_type
{
	typedef ::mizuiro::color::object<
		typename Format::color_format
	> type;
};

}
}
}

#endif
