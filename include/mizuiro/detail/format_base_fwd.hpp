//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_FORMAT_BASE_FWD_HPP_INCLUDED
#define MIZUIRO_DETAIL_FORMAT_BASE_FWD_HPP_INCLUDED

#include <mizuiro/detail/empty_format_base_fwd.hpp>
#include <mizuiro/detail/normal_format_base_fwd.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename Format,
	template<
		typename
	> class FormatStore,
	template<
		typename
	> class FormatNeedsStore
>
using format_base
=
typename
std::conditional<
	FormatNeedsStore<
		Format
	>::value,
	mizuiro::detail::normal_format_base<
		FormatStore<
			Format
		>
	>,
	mizuiro::detail::empty_format_base<
		FormatStore<
			Format
		>
	>
>::type;

}
}

#endif
