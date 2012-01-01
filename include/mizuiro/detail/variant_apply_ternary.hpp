//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_VARIANT_APPLY_TERNARY_HPP_INCLUDED
#define MIZUIRO_DETAIL_VARIANT_APPLY_TERNARY_HPP_INCLUDED

#include <mizuiro/config.hpp>
#ifdef MIZUIRO_HAVE_FCPPT
#include <fcppt/variant/apply_ternary.hpp>
#else
#error \
	"Sorry, ternary visitation isn't implemented for boost." \
	"Consider using fcppt instead." \
	"Also, we might implement this for boost in the future, too."
#endif

namespace mizuiro
{
namespace detail
{

template<
	typename Operation,
	typename Variant1,
	typename Variant2,
	typename Variant3
>
typename Operation::result_type
variant_apply_ternary(
	Operation const &op,
	Variant1 const &obj1,
	Variant2 const &obj2,
	Variant3 const &obj3
)
{
#ifdef MIZUIRO_HAVE_FCPPT
	return
		fcppt::variant::apply_ternary(
			op,
			obj1,
			obj2,
			obj3
		);
#endif
}

}
}

#endif
