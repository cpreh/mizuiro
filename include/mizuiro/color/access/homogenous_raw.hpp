#ifndef MIZUIRO_COLOR_ACCESS_HOMOGENOUS_RAW_HPP_INCLUDED
#define MIZUIRO_COLOR_ACCESS_HOMOGENOUS_RAW_HPP_INCLUDED

#include <mizuiro/color/types/channel_reference.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/color/is_homogenous.hpp>
#include <mizuiro/access/is_raw.hpp>
#include <mizuiro/detail/index_of.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/mpl/and.hpp>

namespace mizuiro
{
namespace color
{
namespace access
{

template<
	typename Access,
	typename Format,
	typename Channel,
	typename Constness
>
typename boost::enable_if<
	boost::mpl::and_<
		mizuiro::access::is_raw<
			Access
		>,
		color::is_homogenous<
			Format
		>
	>,
	typename types::channel_reference<
		Access,
		Format,
		Channel,
		Constness
	>::type
>::type
extract_channel(
	typename types::pointer<
		Access,
		Format,
		Constness
	>::type const ptr
)
{
	return ptr + 
		mizuiro::detail::index_of<
			typename Format::layout::order,
			Channel
		>::value
		* sizeof(typename Format::channel_type) // TODO!
	;
}

}
}
}

#endif
