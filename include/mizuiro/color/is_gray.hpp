#ifndef MIZUIRO_COLOR_IS_GRAY_HPP_INCLUDED
#define MIZUIRO_COLOR_IS_GRAY_HPP_INCLUDED

#include <mizuiro/color/layout/gray.hpp>
#include <boost/type_traits/is_same.hpp>

namespace mizuiro
{
namespace color
{

template
<
	typename Color
>
struct is_gray
:
boost::is_same<
	typename Color::layout::layout,
	layout::gray
>
{
};

}
}

#endif
