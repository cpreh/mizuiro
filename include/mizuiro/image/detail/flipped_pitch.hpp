//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_FLIPPED_PITCH_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_FLIPPED_PITCH_HPP_INCLUDED

#include <mizuiro/detail/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Pitch
>
typename boost::enable_if_c<
	Pitch::static_size >= 2,
	Pitch
>::type const
flipped_pitch(
	Pitch const &_old_pitch,
	typename Pitch::value_type _last_value
)
{
	Pitch ret;

	for(
		typename Pitch::size_type index = 0;
		index < Pitch::static_size - 1;
		++index
	)
		ret[index] = _old_pitch[index];

	ret.back() = _last_value;

	return ret;
}

template<
	typename Pitch
>
typename boost::disable_if_c<
	Pitch::static_size >= 2,
	Pitch
>::type const
flipped_pitch(
	Pitch const &,
	typename Pitch::value_type _last_value
)
{
	return
		Pitch(
			_last_value
		);
}

}
}
}

#endif
