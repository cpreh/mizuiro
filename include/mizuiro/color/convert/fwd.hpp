#ifndef MIZUIRO_COLOR_CONVERT_FWD_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_FWD_HPP_INCLUDED

#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>

namespace mizuiro
{
namespace color
{

// TODO: can we omit this function?

template<
	typename Dest,
	typename Src
>
Dest const
convert(
	Src const &
)
{
	BOOST_STATIC_ASSERT((
		boost::is_same<
			Dest,
			Src
		>::value && false
	));
}

}
}

#endif
