//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_VARIANT_APPLY_BINARY_HPP_INCLUDED
#define MIZUIRO_DETAIL_VARIANT_APPLY_BINARY_HPP_INCLUDED

#include <mizuiro/config.hpp>
#ifdef MIZUIRO_HAVE_FCPPT
#include <fcppt/variant/apply_binary.hpp>
#else
#include <mizuiro/detail/external_begin.hpp>
#include <boost/variant/apply_visitor.hpp>
#include <mizuiro/detail/external_end.hpp>
#endif

namespace mizuiro
{
namespace detail
{

template<
	typename Operation,
	typename Variant1,
	typename Variant2
>
typename Operation::result_type
variant_apply_binary(
	Operation const &op,
	Variant1 const &obj1,
	Variant2 const &obj2
)
{
	return
#ifdef MIZUIRO_HAVE_FCPPT
		fcppt::variant::apply_binary(
			op,
			obj1,
			obj2
		);
#else
		boost::apply_visitor(
			op,
			obj1,
			obj2
		);
#endif
}

}
}

#endif
