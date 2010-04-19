#ifndef MIZUIRO_COLOR_OBJECT_FWD_HPP_INCLUDED
#define MIZUIRO_COLOR_OBJECT_FWD_HPP_INCLUDED

namespace mizuiro
{
namespace color
{

template<
	typename Format,
	typename Access
		= detail::normal_access<
			Format
		>
>
class object;

}
}

#endif
