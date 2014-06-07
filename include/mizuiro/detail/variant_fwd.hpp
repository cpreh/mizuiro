//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_VARIANT_FWD_HPP_INCLUDED
#define MIZUIRO_DETAIL_VARIANT_FWD_HPP_INCLUDED

#include <mizuiro/config.hpp>
#ifdef MIZUIRO_HAVE_FCPPT
#include <fcppt/variant/object_fwd.hpp>
#else
#include <mizuiro/detail/external_begin.hpp>
#include <boost/variant/variant.hpp>
#include <mizuiro/detail/external_end.hpp>
#endif


namespace mizuiro
{
namespace detail
{

template<
	typename Sequence
>
using
variant
=
#ifdef MIZUIRO_HAVE_FCPPT
	fcppt::variant::object<
		Sequence
	>
#else
	typename
	boost::make_variant_over<
		Sequence
	>::type
#endif
;

}
}

#endif
