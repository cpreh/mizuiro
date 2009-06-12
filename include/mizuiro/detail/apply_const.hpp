#ifndef MIZUIRO_DETAIL_APPLY_CONST_HPP_INCLUDED
#define MIZUIRO_DETAIL_APPLY_CONST_HPP_INCLUDED

#include <mizuiro/detail/const_tag.hpp>
#include <mizuiro/detail/nonconst_tag.hpp>
#include <boost/type_traits/add_const.hpp>

namespace mizuiro
{
namespace detail
{

template<
	typename BaseType,
	typename Constness
>
struct apply_const;

template<
	typename BaseType
>
struct apply_const<
	BaseType,
	const_tag
>
:
boost::add_const<
	BaseType
>
{};

template<
	typename BaseType
>
struct apply_const<
	BaseType,
	nonconst_tag
>
{
	typedef BaseType type;
};

}
}

#endif
