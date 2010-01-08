#ifndef MIZUIRO_DETAIL_APPLY_CONST_HPP_INCLUDED
#define MIZUIRO_DETAIL_APPLY_CONST_HPP_INCLUDED

#include <mizuiro/const_tag.hpp>
#include <mizuiro/nonconst_tag.hpp>

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
>;

template<
	typename BaseType
>
struct apply_const<
	BaseType &,
	const_tag
>
{
	typedef BaseType const &type;
};

template<
	typename BaseType
>
struct apply_const<
	BaseType *,
	const_tag
>
{
	typedef BaseType const *type;
};

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
