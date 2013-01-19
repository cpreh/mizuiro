//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_IS_INTERLEAVED_HPP_INCLUDED
#define MIZUIRO_IMAGE_IS_INTERLEAVED_HPP_INCLUDED

#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/image/interleaved_fwd.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace image
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Format
>
struct is_interleaved
:
boost::false_type
{
};

template<
	typename DimType,
	typename ColorFormat
>
struct is_interleaved<
	mizuiro::image::interleaved<
		DimType,
		ColorFormat
	>
>
:
boost::true_type
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}

#endif
