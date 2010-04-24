#ifndef MIZUIRO_ACCESS_IS_RAW_HPP_INCLUDED
#define MIZUIRO_ACCESS_IS_RAW_HPP_INCLUDED

#include <mizuiro/access/raw.hpp>
#include <boost/type_traits/is_same.hpp>

namespace mizuiro
{
namespace access
{

template<
	typename T
>
struct is_raw
:
boost::is_same<
	T,
	raw
>
{};

}
}

#endif
