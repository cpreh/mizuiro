#ifndef MIZUIRO_COLOR_IS_SCALAR_HPP_INCLUDED
#define MIZUIRO_COLOR_IS_SCALAR_HPP_INCLUDED

#include <boost/type_traits/is_same.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/int.hpp>

namespace mizuiro
{
namespace color
{

template
<
	typename Format
>
struct is_scalar
:
boost::is_same<
	typename boost::mpl::size<
		typename Format::layout::order
	>::type,
	boost::mpl::int_<
		1
	>
>
{};

}
}

#endif
