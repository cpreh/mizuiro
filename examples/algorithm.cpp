//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/image/store.hpp>
#include <mizuiro/image/format.hpp>
#include <mizuiro/image/view.hpp>
#include <mizuiro/image/interleaved.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/make_const_view.hpp>
#include <mizuiro/image/algorithm/copy_and_convert.hpp>
#include <mizuiro/image/algorithm/fill_c.hpp>
#include <mizuiro/image/algorithm/may_overlap.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/image/algorithm/transform.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/color/layout/argb.hpp>
#include <mizuiro/color/init.hpp>
#include <mizuiro/color/homogenous_static.hpp>
#include <mizuiro/color/for_each_channel.hpp>
#include <mizuiro/color/proxy.hpp>
#include <boost/spirit/home/phoenix/core/argument.hpp>
#include <boost/cstdint.hpp>
#include <iostream>
#include <ostream>

namespace
{

template<
	typename ColorFormat
>
struct d2_format {
	typedef mizuiro::image::format<
		mizuiro::image::dimension<
			2
		>,
		mizuiro::image::interleaved<
			ColorFormat
		>
	> type;
};

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

}

int main()
{
	typedef boost::uint8_t channel_type;

	typedef d2_format<
		mizuiro::color::homogenous_static<
			channel_type,
			mizuiro::color::layout::rgba
		>
	>::type format1;

	typedef d2_format<
		mizuiro::color::homogenous_static<
			float,
			mizuiro::color::layout::argb
		>
	>::type format2;

	typedef mizuiro::image::store<
		format1
	> store1;

	typedef mizuiro::image::store<
		format2
	> store2;

	store1::dim const dim(
		4,
		2
	);

	store1 img1(
		dim
	);

	mizuiro::image::algorithm::fill_c(
		img1.view(),
		mizuiro::color::object<
			format1::color_format
		>(
			(mizuiro::color::init::red = static_cast<channel_type>(42))
			(mizuiro::color::init::blue = static_cast<channel_type>(150))
			(mizuiro::color::init::green = static_cast<channel_type>(80))
			(mizuiro::color::init::alpha = static_cast<channel_type>(255))
		)
	);

	std::cout << "before\n";

	mizuiro::image::algorithm::print(
		std::cout,
		img1.view()
	);

	std::cout << "\n\n";

	store2 img2(
		dim
	);

	mizuiro::image::algorithm::copy_and_convert(
		mizuiro::image::make_const_view(
			img1.view()
		),
		img2.view(),
		mizuiro::image::algorithm::may_overlap::no
	);

	std::cout << "after\n";

	mizuiro::image::algorithm::print(
		std::cout,
		img2.view()
	);

#if 0
	mizuiro::image::algorithm::transform(
		img2.view(),
		img1.view(),
		transform_test()
	);
#endif

	std::cout << '\n';
}
