#ifndef MIZUIRO_IMAGE_DETAIL_IS_RAW_ACCESS_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_IS_RAW_ACCESS_HPP_INCLUDED

#include <mizuiro/image/detail/raw_access.hpp>
#include <boost/type_traits/integral_constant.hpp>

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename T
>
struct is_raw_access
:
boost::false_type
{};

template<
	typename Layout
>
struct is_raw_access<
	raw_access<
		Layout
	>
>
:
boost::true_type
{};

}
}
}

#endif
