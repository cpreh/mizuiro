//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_VARIANT_APPLY_UNARY_HPP_INCLUDED
#define MIZUIRO_DETAIL_VARIANT_APPLY_UNARY_HPP_INCLUDED

#include <mizuiro/config.hpp>
#ifdef MIZUIRO_HAVE_FCPPT
#include <fcppt/variant/apply_unary.hpp>
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
	typename Variant
>
typename Operation::result_type
variant_apply_unary(
	Operation const &op,
	Variant const &obj
)
{
	return
#ifdef MIZUIRO_HAVE_FCPPT
		fcppt::variant::apply_unary(
			op,
			obj
		);
#else
		boost::apply_visitor(
			op,
			obj
		);
#endif
}

}
}

#endif
