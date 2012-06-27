//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_FORMAT_BASE_FWD_HPP_INCLUDED
#define MIZUIRO_DETAIL_FORMAT_BASE_FWD_HPP_INCLUDED

#include <mizuiro/detail/empty_format_base_fwd.hpp>
#include <mizuiro/detail/normal_format_base_fwd.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/if.hpp>
#include <mizuiro/detail/external_end.hpp>

namespace mizuiro
{
namespace detail
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename Format,
	template<
		typename
	> class FormatStore,
	template<
		typename
	> class FormatIsStatic
>
struct format_base
:
boost::mpl::if_<
	FormatIsStatic<
		Format
	>,
	mizuiro::detail::empty_format_base<
		FormatStore<
			Format
		>
	>,
	mizuiro::detail::normal_format_base<
		FormatStore<
			Format
		>
	>
>
{
};

MIZUIRO_DETAIL_POP_WARNING

}
}

#endif
