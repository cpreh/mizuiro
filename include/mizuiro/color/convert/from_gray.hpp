#ifndef MIZUIRO_COLOR_CONVERT_FROM_GRAY_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_FROM_GRAY_HPP_INCLUDED

#include <mizuiro/color/convert/fwd.hpp>
#include <mizuiro/color/proxy_impl.hpp>
#include <mizuiro/color/homogenous.hpp>
#include <mizuiro/color/layout/gray.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename Dest,
	typename Base,
	template<
		typename
	> class Color
>
Dest const
convert(
	Color<
		homogenous<
			Base,
			layout::gray
		>
	> const &src
)
{
	Base const max(
		homogenous<
			Base,
			layout::gray
		>::channel_max()
	);

	Dest dest;
	
	// TODO!
}

}
}

#endif
