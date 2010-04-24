#ifndef MIZUIRO_ACCESS_IS_NORMAL_HPP_INCLUDED
#define MIZUIRO_ACCESS_IS_NORMAL_HPP_INCLUDED

#include <mizuiro/access/normal.hpp>
#include <boost/type_traits/is_same.hpp>

namespace mizuiro
{
namespace access
{

template<
	typename T
>
struct is_normal
:
boost::is_same<
	T,
	normal
>
{};

}
}

#endif
