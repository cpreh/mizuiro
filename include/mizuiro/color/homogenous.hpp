#ifndef MIZUIRO_COLOR_HOMOGENOUS_HPP_INCLUDED
#define MIZUIRO_COLOR_HOMOGENOUS_HPP_INCLUDED

#include <mizuiro/color/homogenous_fwd.hpp>
#include <mizuiro/color/types/homogenous_normal.hpp>
#include <mizuiro/color/types/homogenous.hpp>
#include <mizuiro/access/homogenous_normal.hpp>
#include <mizuiro/size_type.hpp>
#include <boost/mpl/size.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename ChannelType,
	typename Layout
>
struct homogenous
{
	typedef ChannelType channel_type;

	typedef Layout layout;

	static size_type const element_count
		= boost::mpl::size<
			typename layout::order
		>::value;
};

}
}

#endif
