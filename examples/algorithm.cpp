//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/color/for_each_channel.hpp>
#include <mizuiro/color/make_compare_function.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/proxy.hpp>
#include <mizuiro/color/convert_static/converter.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/init/alpha.hpp>
#include <mizuiro/color/init/blue.hpp>
#include <mizuiro/color/init/green.hpp>
#include <mizuiro/color/init/red.hpp>
#include <mizuiro/color/layout/argb.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/make_const_view.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/algorithm/compare.hpp>
#include <mizuiro/image/algorithm/copy_and_convert.hpp>
#include <mizuiro/image/algorithm/may_overlap.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/image/algorithm/transform.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <cstdint>
#include <functional>
#include <iostream>
#include <ostream>
#include <mizuiro/detail/external_end.hpp>


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

// TODO: Use this?
/*
template<
	typename Src,
	typename Dest
>
struct channel_operation
{
	typedef void result_type;

	channel_operation(
		Src const &_src,
		Dest const &_dest
	)
	:
		src_(_src),
		dest_(_dest)
	{}

	template<
		typename Channel
	>
	result_type
	operator()(
		Channel const &_channel
	) const
	{
		dest_.set(
			_channel,
			src_.get(
				_channel
			)
		);
	}
private:
	Src const &src_;
	Dest const &dest_;
};

struct transform_test
{
	typedef void result_type;

	template<
		typename Src,
		typename Dest
	>
	result_type
	operator()(
		Src const &_src,
		Dest const &_dest
	) const
	{
		mizuiro::color::for_each_channel<
			typename Src::format::layout
		>(
			::channel_operation<
				Src,
				Dest
			>(
				_src,
				_dest
			)
		);
	}
};
*/

}

int main()
{
	typedef std::uint8_t channel_type;

	typedef d2_format<
		mizuiro::color::format::homogenous_static<
			channel_type,
			mizuiro::color::layout::rgba
		>
	> format1;

	typedef d2_format<
		mizuiro::color::format::homogenous_static<
			float,
			mizuiro::color::layout::argb
		>
	> format2;

	typedef mizuiro::image::store<
		format1
	> store1;

	typedef mizuiro::image::store<
		format2
	> store2;

	store1::dim const dim(
		4u,
		2u
	);

	store1 img1{
		dim,
		mizuiro::color::object<
			format1::color_format
		>(
			(mizuiro::color::init::red() = static_cast<channel_type>(42))
			(mizuiro::color::init::blue() = static_cast<channel_type>(150))
			(mizuiro::color::init::green() = static_cast<channel_type>(80))
			(mizuiro::color::init::alpha() = static_cast<channel_type>(255))
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
				mizuiro::image::algorithm::may_overlap::no
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
		<< mizuiro::image::algorithm::compare(
			img1.view(),
			img1.view(),
			mizuiro::color::make_compare_function(
				std::equal_to<
					channel_type
				>()
			)
		)
		<< '\n';
#if 0
	mizuiro::image::algorithm::transform(
		img2.view(),
		img1.view(),
		transform_test()
	);
#endif

	std::cout << '\n';
}
