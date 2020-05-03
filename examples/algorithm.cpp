//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/decltype.hpp>
#include <mizuiro/color/for_each_channel.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/proxy.hpp>
#include <mizuiro/color/convert_static/converter.hpp>
#include <mizuiro/color/format/get.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/init/alpha.hpp>
#include <mizuiro/color/init/blue.hpp>
#include <mizuiro/color/init/green.hpp>
#include <mizuiro/color/init/red.hpp>
#include <mizuiro/color/layout/argb.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/operators/equal.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/make_const_view.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/algorithm/copy_and_convert.hpp>
#include <mizuiro/image/algorithm/equal.hpp>
#include <mizuiro/image/algorithm/make_iterator_identity.hpp>
#include <mizuiro/image/algorithm/may_overlap.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/image/algorithm/transform.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved_homogenous.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace
{

template<
	typename ColorFormat
>
using
d2_format
=
mizuiro::image::format::interleaved<
	mizuiro::image::dimension<
		2
	>,
	ColorFormat
>;

}

int
main()
{
	using
	channel_type
	=
	std::uint8_t;

	using
	format1
	=
	d2_format<
		mizuiro::color::format::homogenous_static<
			channel_type,
			mizuiro::color::layout::rgba
		>
	>;

	using
	format2
	=
	d2_format<
		mizuiro::color::format::homogenous_static<
			float,
			mizuiro::color::layout::argb
		>
	>;

	using
	store1
	=
	mizuiro::image::store<
		format1
	>;

	using
	store2
	=
	mizuiro::image::store<
		format2
	>;

	store1::dim const dim(
		4U,
		2U
	);

	store1 img1{
		dim,
		mizuiro::color::object<
			format1::color_format
		>(
			(mizuiro::color::init::red() = channel_type{42}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			(mizuiro::color::init::blue() = channel_type{150}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			(mizuiro::color::init::green() = channel_type{80}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
			(mizuiro::color::init::alpha() = channel_type{255}) // NOLINT(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
		)
	};

	std::cout << "before\n";

	mizuiro::image::algorithm::print(
		std::cout,
		img1.view()
	);

	std::cout << "\n\n";

	store2 img2{
		dim,
		[
			&img1
		](
			store2::view_type const &_dest
		)
		{
			mizuiro::image::algorithm::copy_and_convert<
				mizuiro::color::convert_static::converter
			>(
				mizuiro::image::make_const_view(
					img1.view()
				),
				_dest,
				mizuiro::image::algorithm::may_overlap::no,
				mizuiro::image::algorithm::uninitialized::yes
			);
		}
	};

	std::cout << "after\n";

	mizuiro::image::algorithm::print(
		std::cout,
		img2.view()
	);

	std::cout
		<< "\n\nequal: "
		<< std::boolalpha
		<< mizuiro::image::algorithm::equal(
			img1.view(),
			img1.view()
		)
		<< '\n';

	std::cout << '\n';

	mizuiro::image::algorithm::transform(
		img2.view(),
		img1.view(),
		[](
			auto const &_src,
			auto const &_dest
		)
		{
			mizuiro::color::for_each_channel(
				_src,
				[
					&_src,
					&_dest
				](
					auto const &_channel
				)
				{
					_dest.set(
						_channel,
						static_cast<
							mizuiro::color::types::channel_value<
								mizuiro::color::format::get<
									MIZUIRO_DECLTYPE(
										_dest
									)
								>,
								MIZUIRO_DECLTYPE(
									_channel
								)
							>
						>(
							_src.get(
								_channel
							)
						)
					);
				}
			);
		},
		mizuiro::image::algorithm::make_iterator_identity{},
		mizuiro::image::algorithm::uninitialized::no
	);

	std::cout << "after transform\n";

	mizuiro::image::algorithm::print(
		std::cout,
		img1.view()
	);

	std::cout << '\n';
}
