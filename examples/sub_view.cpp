#include <mizuiro/image/store_impl.hpp>
#include <mizuiro/image/format.hpp>
#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/bound_impl.hpp>
#include <mizuiro/image/sub_view.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/init.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/homogenous.hpp>
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

	typedef view_type::bound_type bound_type;

	// TODO: create an algorithm for this!
	
	{
		view_type const view(
			img.view()
		);

		typedef view_type::dim_type dim_type;

		typedef dim_type::size_type size_type;

		dim_type const dim(
			img.view().dim()
		);

		for(size_type x = 0; x < dim[0]; ++x)
			for(size_type y = 0; y < dim[1]; ++y)
				for(size_type z = 0; z < dim[2]; ++z)
					view.at(
						dim_type(
							x,
							y,
							z
						)
					)
					= mizuiro::color::object<
						format::color_format
					>(
						mizuiro::color::init::red = x,
						mizuiro::color::init::green = y,
						mizuiro::color::init::blue = z,
						mizuiro::color::init::alpha = 255
					);
	}

	std::cout << "whole image:\n";

	mizuiro::image::algorithm::print(
		std::cout,
		img.view()
	);

	std::cout << '\n';

	view_type const sub_view(
		mizuiro::image::sub_view(
			img.view(),
			bound_type(
				bound_type::dim_type(
					0,
					0,
					0
				),
				bound_type::dim_type(
					1,
					1,
					1
				)
			)
		)
	);

	std::cout << "sub image:\n";

	mizuiro::image::algorithm::print(
		std::cout,
		sub_view
	);

	std::cout << '\n';
}
