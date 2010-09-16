//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_OUTPUT_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_OUTPUT_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/detail/promote_channel.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/detail/index_of.hpp>
#include <mizuiro/detail/nonassignable.hpp>
#include <boost/mpl/size.hpp>
#include <boost/utility/enable_if.hpp>
#include <ostream>

namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Ch,
	typename Traits,
	typename Color
>
class output_channel
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		output_channel
	);

	typedef std::basic_ostream<
		Ch,
		Traits
	> stream_type;
public:
	output_channel(
		stream_type &_stream,
		Color const &_color
	)
	:
		stream_(_stream),
		color_(_color)
	{}

	typedef void result_type;

	template<
		typename Channel
	>
	typename boost::enable_if_c<
		mizuiro::detail::index_of<
			typename Color::format::layout::order,
			Channel
		>::value + 1
		==
		boost::mpl::size<
			typename Color::format::layout::order
		>::value,
		result_type
	>::type
	operator()(
		Channel &
	) const
	{
		print_impl<
			Channel
		>();
	}

	template<
		typename Channel
	>
	typename boost::disable_if_c<
		mizuiro::detail::index_of<
			typename Color::format::layout::order,
			Channel
		>::value + 1
		==
		boost::mpl::size<
			typename Color::format::layout::order
		>::value,
		result_type
	>::type
	operator()(
		Channel &
	) const
	{
		print_impl<
			Channel
		>();
		
		stream_ << stream_.widen(',');
	}
private:
	template<
		typename Channel
	>
	result_type
	print_impl() const
	{
		stream_ <<
			static_cast<
				typename detail::promote_channel<
					typename color::types::channel_value<
						typename Color::format,
						Channel
					>::type
				>::type
			>(
				color_. template get<
					Channel
				>()
			);
	}

	stream_type &stream_;

	Color const &color_;
};

}
}
}

#endif
