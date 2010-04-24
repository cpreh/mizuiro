#ifndef MIZUIRO_DETAIL_CHOOSE_CONST_HPP_INCLUDED
#define MIZUIRO_DETAIL_CHOOSE_CONST_HPP_INCLUDED

#include <mizuiro/const_tag.hpp>
#include <mizuiro/nonconst_tag.hpp>

namespace mizuiro
{
namespace detail
{

template<
	typename T
>
struct choose_const;

template<
	typename T
>
struct choose_const<
	T *
>
{
	typedef nonconst_tag type;
};

template<
	typename T
>
struct choose_const<
	T const *
>
{
	typedef const_tag type;
};

}
}

#endif
