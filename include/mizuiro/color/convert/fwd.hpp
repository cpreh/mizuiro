#ifndef MIZUIRO_COLOR_CONVERT_FWD_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_FWD_HPP_INCLUDED

namespace mizuiro
{
namespace color
{

template<
	typename Dest,
	typename Src
>
Dest const
convert(
	Src const &
);

}
}

#endif
