//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_OUTPUT_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_OUTPUT_CHANNEL_HPP_INCLUDED

#include <mizuiro/detail/promote_type.hpp>
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
		stream_(
			_stream
		),
		color_(
			_color
		)
	{
	}

	typedef
	void
	result_type;

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
				mizuiro::detail::promote_type<
					mizuiro::color::types::channel_value<
						typename
						Color::format,
						Channel
					>
				>
			>(
				color_.get(
					_channel
				)
			);

		// TODO: Don't output a comma after the last component.
		// Use a different algorithm than for_each_channel to do this!
		stream_ <<
			stream_.widen(',');
	}
private:
	stream_type &stream_;

	Color const &color_;
};

}
}
}

#endif
