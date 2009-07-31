#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/format.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/raw_pointer.hpp>
#include <mizuiro/image/raw_view.hpp>
#include <mizuiro/image/make_raw_view.hpp>
#include <mizuiro/image/sub_view.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/color/homogenous.hpp>
#include <mizuiro/color/proxy_impl.hpp>
#include <mizuiro/color/init.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/size_type.hpp>
#include <boost/tr1/array.hpp>
#include <iostream>
#include <ostream>

int main()
{
	//typedef boost::uint8_t channel_type;
	typedef float channel_type;

	typedef mizuiro::image::dimension<
		3	
	> dim_type;

	typedef mizuiro::image::format<
		dim_type,
		mizuiro::image::interleaved<
			mizuiro::color::homogenous<
				channel_type,
				mizuiro::color::layout::rgba
			>
		>
	> format;

	mizuiro::size_type const
		width(
			4
		),
		height(
			4
		),
		depth(
			4	
		);

	std::tr1::array<
		unsigned char,
		width * height * depth * sizeof(float) * format::color_format::element_count
	> raw_data;

	typedef mizuiro::image::raw_view<
		format,
		mizuiro::image::raw_pointer
	>::type view_type;

	typedef view_type::bound_type bound_type;

	view_type const view(
		mizuiro::image::make_raw_view<
			format
		>(
			raw_data.data(),
			dim_type(
				width,
				height,
				depth
			),
			view_type::pitch_type::null()
		)
	);

	{
		typedef view_type::dim_type dim_type;

		typedef dim_type::size_type size_type;

		dim_type const dim(
			view.dim()
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
						mizuiro::color::init::red = static_cast<channel_type>(x),
						mizuiro::color::init::green = static_cast<channel_type>(y),
						mizuiro::color::init::blue = static_cast<channel_type>(z),
						mizuiro::color::init::alpha = static_cast<channel_type>(255)
					);
	}

	view_type const sub_view(
		mizuiro::image::sub_view(
			view,
			bound_type(
				bound_type::dim_type(
					0,
					0,
					0
				),
				bound_type::dim_type(
					2,
					3,
					2	
				)
			)
		)
	);

	mizuiro::image::algorithm::print(
		std::cout,
		sub_view
	);
}
