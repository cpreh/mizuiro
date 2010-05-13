#ifndef MIZUIRO_COLOR_CHANNEL_PROXY_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_CHANNEL_PROXY_DECL_HPP_INCLUDED

#include <mizuiro/color/channel_proxy_fwd.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename Pointer,
	typename ValueType
>
class channel_proxy
{
public:
	typedef ValueType value_type;

	typedef Pointer pointer;

	channel_proxy(
		pointer data
	);

	channel_proxy &
	operator=(
		value_type
	);

	value_type
	get() const;

	operator value_type() const;
private:
	pointer data_;	
};

}
}

#endif
