//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IS_CONSTNESS_TAG_HPP_INCLUDED
#define MIZUIRO_IS_CONSTNESS_TAG_HPP_INCLUDED

#include <mizuiro/const_tag_fwd.hpp>
#include <mizuiro/nonconst_tag_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{

template<
	typename T
>
struct is_constness_tag
:
std::false_type
{
};

template<>
struct is_constness_tag<
	mizuiro::const_tag
>
:
std::true_type
{
};

template<>
struct is_constness_tag<
	mizuiro::nonconst_tag
>
:
std::true_type
{
};

}

#endif
