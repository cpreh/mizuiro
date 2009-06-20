#ifndef MIZUIRO_COLOR_CONVERT_IDENTITY_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_IDENTITY_HPP_INCLUDED

namespace mizuiro
{
namespace color
{

template<
	typename Color
>
Color const &
convert(
	Color const &src
)
{
	return src;
}

}
}

#endif
