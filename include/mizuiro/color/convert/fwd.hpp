#ifndef MIZUIRO_COLOR_CONVERT_FWD_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_FWD_HPP_INCLUDED

#include <boost/static_assert.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename Dest,
	typename Src
>
Dest const
convert(
	Src const &
)
{
	BOOST_STATIC_ASSERT(false);
}

}
}

#endif
