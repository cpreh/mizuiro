//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_TYPES_REFERENCE_HPP_INCLUDED
#define MIZUIRO_IMAGE_TYPES_REFERENCE_HPP_INCLUDED

#include <mizuiro/color/proxy_impl.hpp>

namespace mizuiro
{
namespace image
{
namespace types
{

template<
	typename Access,
	typename Format,
	typename Constness,
	typename Enable = void
>
struct reference
{
	typedef ::mizuiro::color::proxy<
		Access,
		typename Format::color_format,
		Constness
	> type;
};

}
}
}

#endif
