//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/color/homogenous_static.hpp>
#include <mizuiro/color/proxy.hpp>
#include <mizuiro/color/channel/luminance.hpp>
#include <mizuiro/color/layout/gray.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/format.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/view.hpp>
#include <mizuiro/image/access/homogenous.hpp>
#include <mizuiro/image/access/homogenous_normal.hpp>
#include <mizuiro/image/algorithm/for_each.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/cstdint.hpp>
#include <mizuiro/detail/external_end.hpp>


typedef mizuiro::image::format<
	mizuiro::image::dimension<
		2
	>,
	mizuiro::image::interleaved<
		mizuiro::color::homogenous_static<
			boost::uint8_t,
			mizuiro::color::layout::gray
		>
	>
> format;

struct set_color
{
	typedef void result_type;

	template<
		typename T
	>
	result_type
	operator()(
		T const &_color
	) const
	{
		_color.set(
			mizuiro::color::channel::luminance(),
			42
		);
	}
};

int main()
{
	typedef mizuiro::image::store<
		format
	> store;

	store img(
		store::dim(
			32,
			64
		)
	);

	typedef store::view_type view_type;

	view_type const view(
		img.view()
	);

	mizuiro::image::algorithm::for_each(
		view,
		set_color()
	);
}
