#ifndef MIZUIRO_COLOR_IS_ALPHA_HPP_INCLUDED
#define MIZUIRO_COLOR_IS_ALPHA_HPP_INCLUDED

#include <mizuiro/color/layout/alpha.hpp>
#include <boost/type_traits/is_same.hpp>

namespace mizuiro
{
namespace color
{

template
<
	typename Format
>
struct is_alpha
:
boost::is_same<
	typename Format::layout,
	layout::alpha
>
{
};

}
}

#endif
