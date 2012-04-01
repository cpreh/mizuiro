//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_IS_COLOR_HPP_INCLUDED
#define MIZUIRO_COLOR_IS_COLOR_HPP_INCLUDED

#include <mizuiro/color/object_fwd.hpp>
#include <mizuiro/color/proxy_fwd.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename T
>
struct is_color
:
boost::false_type
{};

template<
	typename Format
>
struct is_color<
	color::object<
		Format
	>
>
:
boost::true_type
{};

template<
	typename Access,
	typename Format,
	typename Constness
>
struct is_color<
	color::proxy<
		Access,
		Format,
		Constness
	>
>
:
boost::true_type
{};

MIZUIRO_DETAIL_POP_WARNING

}
}

#endif
