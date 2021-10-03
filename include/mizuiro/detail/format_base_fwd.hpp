//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_FORMAT_BASE_FWD_HPP_INCLUDED
#define MIZUIRO_DETAIL_FORMAT_BASE_FWD_HPP_INCLUDED

#include <mizuiro/detail/empty_format_base_fwd.hpp>
#include <mizuiro/detail/normal_format_base_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro::detail
{

template<
	typename Format,
	template<
		typename
	> class FormatNeedsStore,
	typename Copy = void
>
using format_base
=
std::conditional_t<
	FormatNeedsStore<
		Format
	>::value,
	mizuiro::detail::normal_format_base<
		Format,
		Copy
	>,
	mizuiro::detail::empty_format_base<
		Format
	>
>;

}

#endif
