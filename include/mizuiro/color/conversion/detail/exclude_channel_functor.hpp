//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_EXCLUDE_CHANNEL_FUNCTOR_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_EXCLUDE_CHANNEL_FUNCTOR_HPP_INCLUDED

#include <mizuiro/color/access/compare_channels.hpp>
#include <mizuiro/color/format/store.hpp>
#include <mizuiro/detail/nonassignable.hpp>


namespace mizuiro
{
namespace color
{
namespace conversion
{
namespace detail
{

template<
	typename Format,
	typename StaticChannel
>
class exclude_channel_functor
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		exclude_channel_functor
	);
public:
	typedef
	mizuiro::color::format::store<
		Format
	>
	format_store;

	explicit
	exclude_channel_functor(
		format_store const &_format
	)
	:
		format_(
			_format
		)
	{
	}

	typedef
	bool
	result_type;

	template<
		typename OtherChannel
	>
	bool
	operator()(
		OtherChannel const &_channel
	) const
	{
		return
			!mizuiro::color::access::compare_channels(
				format_,
				StaticChannel(),
				_channel
			);
	}
private:
	format_store const format_;
};

}
}
}
}

#endif
