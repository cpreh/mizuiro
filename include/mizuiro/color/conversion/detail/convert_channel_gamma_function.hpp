//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_CONVERT_CHANNEL_GAMMA_FUNCTION_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_CONVERT_CHANNEL_GAMMA_FUNCTION_HPP_INCLUDED

#include <mizuiro/color/denormalize.hpp>
#include <mizuiro/color/normalize.hpp>
#include <mizuiro/detail/nonassignable.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <cmath>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{
namespace conversion
{
namespace detail
{

template<
	typename Gamma
>
class convert_channel_gamma_function
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		convert_channel_gamma_function
	);
public:
	explicit
	convert_channel_gamma_function(
		Gamma const _gamma
	)
	:
		gamma_(
			_gamma
		)
	{
	}

	typedef
	void
	result_type;

	template<
		typename Channel,
		typename Src,
		typename Dest
	>
	result_type
	operator()(
		Channel const &_channel,
		Src const &_src,
		Dest &_dest
	) const
	{
		_dest.set(
			_channel,
			mizuiro::color::denormalize<
				typename Dest::format
			>(
				_dest.format_store(),
				_channel,
				std::pow(
					mizuiro::color::normalize<
						// TODO!
						float
					>(
						_src,
						_channel
					),
					gamma_
				)
			)
		);
	}
private:
	Gamma const gamma_;
};

}
}
}
}

#endif
