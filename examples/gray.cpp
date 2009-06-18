#include <mizuiro/image/store_impl.hpp>
#include <mizuiro/image/format.hpp>
#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/linear_iterator_impl.hpp>
#include <mizuiro/color/layout/gray.hpp>
#include <mizuiro/color/homogenous.hpp>
#include <mizuiro/color/proxy_impl.hpp>
#include <boost/cstdint.hpp>

int main()
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

	for(
		iterator it(
			view.begin()
		);
		it != view.end();
		++it
	)
	{
		(*it).set<
			mizuiro::color::channel::gray
		>(
			static_cast<unsigned char>(20)
		);
	}
}
