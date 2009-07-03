#include <mizuiro/image/store_impl.hpp>
#include <mizuiro/image/format.hpp>
#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/algorithm/for_each.hpp>
#include <mizuiro/color/layout/gray.hpp>
#include <mizuiro/color/homogenous.hpp>
#include <mizuiro/color/proxy_impl.hpp>
//#include <boost/spirit/home/phoenix/bind/bind_function.hpp>
//#include <boost/spirit/home/phoenix/core/argument.hpp>
#include <boost/bind.hpp>
#include <boost/cstdint.hpp>

namespace
{

typedef mizuiro::image::format<
	mizuiro::image::dimension<
		2
	>,
	mizuiro::image::interleaved<
		mizuiro::color::homogenous<
			boost::uint8_t,
			mizuiro::color::layout::gray
		>
	>
> format;

void
set_color(
	format::reference t
)
{
	t.set<
		mizuiro::color::channel::gray
	>(
		static_cast<unsigned char>(20)
	);
}

}

int main()
{
	typedef mizuiro::image::store<
		format
	> store;

	store img(
		store::dim_type(
			32,
			64
		)
	);

	typedef store::view_type view_type;

	view_type const view(
		img.view()
	);

	typedef view_type::iterator iterator;

	mizuiro::image::algorithm::for_each(
		view,
		boost::bind(
			set_color,
			_1
		)
	);
}
