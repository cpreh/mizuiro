//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_FORMAT_BASE_FWD_HPP_INCLUDED
#define MIZUIRO_DETAIL_FORMAT_BASE_FWD_HPP_INCLUDED

#include <mizuiro/detail/empty_format_base_fwd.hpp>
#include <mizuiro/detail/normal_format_base_fwd.hpp>
#include <boost/mpl/if.hpp>

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
	> class FormatIsStatic
>
struct format_base
:
boost::mpl::if_<
	FormatIsStatic<
		Format
	>,
	detail::empty_format_base<
		Format,
		FormatStore<
			Format
		>
	>,
	detail::normal_format_base<
		Format,
		FormatStore<
			Format
		>
	>
>
{
};

}
}

#endif
