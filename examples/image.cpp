#include <mizuiro/color/homogenous.hpp>
#include <mizuiro/color/proxy.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/format.hpp>
#include <mizuiro/image/view.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/const_view.hpp>
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

	typedef mizuiro::image::const_view<
		view_type
	>::type const_view_type;

	const_view_type const_view(
		view
	);

	typedef const_view_type::iterator const_iterator;

	for(
		const_iterator it(
			const_view.begin()
		);
		it != const_view.end();
		++it
	)
		std::cout << *it << ' ';
	
	std::cout << '\n';
}
