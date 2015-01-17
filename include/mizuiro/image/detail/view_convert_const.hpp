//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_VIEW_CONVERT_CONST_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_VIEW_CONVERT_CONST_HPP_INCLUDED

#include <mizuiro/image/make_const_view.hpp>


namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Variant
>
struct view_convert_const
{
	typedef
	Variant
	result_type;

	template<
		typename View
	>
	result_type const
	operator()(
		View const &_view
	) const
	{
		return
			Variant(
				mizuiro::image::make_const_view(
					_view
				)
			);
	}
};

}
}
}

#endif
