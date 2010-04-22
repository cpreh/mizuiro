#ifndef MIZUIRO_COLOR_IS_HOMOGENOUS_HPP_INCLUDED
#define MIZUIRO_COLOR_IS_HOMOGENOUS_HPP_INCLUDED

#include <mizuiro/color/homogenous_fwd.hpp>
#include <boost/type_traits/integral_constant.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename T
>
struct is_homogenous
:
boost::false_type
{};

template<
	typename ChannelType,
	typename Layout
>
struct is_homogenous<
	homogenous<
		ChannelType,
		Layout
	>
>
:
boost::true_type
{};

}
}

#endif

