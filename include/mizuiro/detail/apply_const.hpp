#ifndef MIZUIRO_DETAIL_APPLY_CONST_HPP_INCLUDED
#define MIZUIRO_DETAIL_APPLY_CONST_HPP_INCLUDED

#include <mizuiro/detail/const_tag.hpp>
#include <mizuiro/detail/nonconst_tag.hpp>
#include <boost/type_traits/add_const.hpp>
#include <boost/type_traits/is_reference.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <boost/type_traits/add_reference.hpp>
#include <boost/mpl/if.hpp>

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
{
	typedef typename boost::mpl::if_<
		boost::is_reference<
			BaseType
		>,
		typename boost::add_reference<
			typename boost::add_const<
				typename boost::remove_reference<
					BaseType
				>::type
			>::type
		>::type,
		typename boost::add_const<
			BaseType
		>::type
	>::type type;
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
