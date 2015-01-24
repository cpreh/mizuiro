//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/color/object.hpp>
#include <mizuiro/color/proxy.hpp>
#include <mizuiro/color/channel/luminance.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/layout/l.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/algorithm/for_each.hpp>
#include <mizuiro/image/algorithm/make_iterator_identity.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <cstdint>
#include <mizuiro/detail/external_end.hpp>


namespace
{

typedef
mizuiro::image::format::interleaved<
	mizuiro::image::dimension<
		2
	>,
	mizuiro::color::format::homogenous_static<
		std::uint8_t,
		mizuiro::color::layout::l
	>
>
format;

struct set_color
{
	typedef
	void
	result_type;

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

}

int
main()
{
	typedef
	mizuiro::image::store<
		format
	>
	store;

	typedef
	store::view_type
	view_type;

	store const img{
		store::dim(
			32u,
			64u
		),
		[](
			view_type const &_view
		)
		{
			mizuiro::image::algorithm::for_each(
				_view,
				set_color(),
				mizuiro::image::algorithm::make_iterator_identity{},
				mizuiro::image::algorithm::uninitialized::yes
			);
		}
	};
}
