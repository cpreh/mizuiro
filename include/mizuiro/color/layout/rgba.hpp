#ifndef MIZUIRO_COLOR_LAYOUT_RGBA_HPP_INCLUDED
#define MIZUIRO_COLOR_LAYOUT_RGBA_HPP_INCLUDED

namespace mizuiro
{
namespace color
{
namespace layout
{

typedef basic_additive<
	boost::mpl::vector<
		red,
		green,
		blue,
		alpha
	>
> rgba;

}
}
}

#endif
