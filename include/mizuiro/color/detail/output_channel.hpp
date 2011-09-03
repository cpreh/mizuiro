//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_OUTPUT_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_OUTPUT_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/access/is_last_channel.hpp>
#include <mizuiro/color/detail/promote_channel.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/detail/nonassignable.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <ostream>
#include <mizuiro/detail/external_end.hpp>

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
	result_type
	operator()(
		Channel const &_channel
	) const
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
				color_.get(
					_channel
				)
			);

		if(
			!color::access::is_last_channel<
				typename Color::format,
				Channel
			>::execute(
				color_.format_store(),
				_channel
			)
		)
			stream_ << stream_.widen(',');
	}
private:
	stream_type &stream_;

	Color const &color_;
};

}
}
}

#endif
