#ifndef MIZUIRO_DETAIL_CONSTNESS_FROM_POINTER_HPP_INCLUDED
#define MIZUIRO_DETAIL_CONSTNESS_FROM_POINTER_HPP_INCLUDED

#include <mizuiro/detail/nonconst_tag.hpp>
#include <mizuiro/detail/const_tag.hpp>

namespace mizuiro
{
namespace detail
{

template<
	typename T
>
struct constness_from_pointer;

template<
	typename T
>
struct constness_from_pointer<
	T *
>
{
	typedef nonconst_tag type;
};

template<
	typename T
>
struct constness_from_pointer<
	T const *
>
{
	typedef const_tag type;
};

}
}

#endif
