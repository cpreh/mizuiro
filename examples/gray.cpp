//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/access/normal.hpp>
#include <mizuiro/color/homogenous_static.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/proxy.hpp>
#include <mizuiro/color/access/homogenous_normal.hpp>
#include <mizuiro/color/access/static.hpp>
#include <mizuiro/color/channel/luminance.hpp>
#include <mizuiro/color/layout/gray.hpp>
#include <mizuiro/color/types/homogenous.hpp>
#include <mizuiro/color/types/homogenous_normal.hpp>
#include <mizuiro/color/types/static.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/view.hpp>
#include <mizuiro/image/access/interleaved.hpp>
#include <mizuiro/image/algorithm/for_each.hpp>
#include <mizuiro/image/types/interleaved.hpp>
#include <mizuiro/image/types/interleaved_normal.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/cstdint.hpp>
#include <mizuiro/detail/external_end.hpp>


typedef mizuiro::image::interleaved<
	mizuiro::image::dimension<
		2
	>,
	mizuiro::color::homogenous_static<
		boost::uint8_t,
		mizuiro::color::layout::gray
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
		format,
		mizuiro::access::normal
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
