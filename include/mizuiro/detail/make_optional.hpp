//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_MAKE_OPTIONAL_HPP_INCLUDED
#define MIZUIRO_DETAIL_MAKE_OPTIONAL_HPP_INCLUDED

#include <mizuiro/config.hpp>
#ifdef MIZUIRO_HAVE_FCPPT
#include <fcppt/optional_fwd.hpp>
#else
#include <mizuiro/detail/external_begin.hpp>
#include <boost/optional/optional_fwd.hpp>
#include <mizuiro/detail/external_end.hpp>
#endif

namespace mizuiro
{
namespace detail
{

template<
	typename Type
>
struct make_optional
{
#ifdef MIZUIRO_HAVE_FCPPT
	typedef fcppt::optional<
		Type
	> type;
#else
	typedef boost::optional<
		Type
	> type;
#endif
};

}
}

#endif
