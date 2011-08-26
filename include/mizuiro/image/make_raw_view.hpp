//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_MAKE_RAW_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_MAKE_RAW_VIEW_HPP_INCLUDED

#include <mizuiro/image/detail/raw_view_from_pointer.hpp>
#include <mizuiro/image/raw_view.hpp>
#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/is_raw_pointer.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Format,
	typename Pointer
>
typename boost::enable_if<
	is_raw_pointer<
		Pointer
	>,
	typename detail::raw_view_from_pointer<
		Format,
		Pointer
	>::type
>::type const
make_raw_view(
	Pointer const _data,
	typename detail::raw_view_from_pointer<
		Format,
		Pointer
	>::type::dim const &_size,
	typename detail::raw_view_from_pointer<
		Format,
		Pointer
	>::type::pitch_type const &_pitch
)
{
	return
		typename detail::raw_view_from_pointer<
			Format,
			Pointer
		>::type(
			_size,
			_data,
			_pitch
		);
}

}
}

#endif
