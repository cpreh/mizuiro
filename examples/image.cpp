#include <mizuiro/image/store_impl.hpp>
#include <mizuiro/image/format.hpp>
#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/homogenous.hpp>
#include <mizuiro/color/proxy_impl.hpp>
#include <mizuiro/color/output.hpp>
#include <boost/cstdint.hpp>
#include <iostream>
#include <ostream>

int main()
{
	typedef mizuiro::image::format<
		mizuiro::image::dimension<
			3
		>,
		mizuiro::image::interleaved<
			mizuiro::color::homogenous<
				boost::uint8_t,
				mizuiro::color::layout::rgba
			>
		>
	> format;

	typedef mizuiro::image::store<
		format
	> store;

	store img(
		store::dim_type(
			3,
			2,
			1	
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
			mizuiro::color::channel::red
		>(
			static_cast<unsigned char>(10)
		);
	}

	for(
		iterator it(
			view.begin()
		);
		it != view.end();
		++it
	)
		std::cout << *it << ' ';
	
	std::cout << '\n';
}
