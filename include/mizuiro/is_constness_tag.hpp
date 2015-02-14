//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IS_CONSTNESS_TAG_HPP_INCLUDED
#define MIZUIRO_IS_CONSTNESS_TAG_HPP_INCLUDED

#include <mizuiro/const_tag_fwd.hpp>
#include <mizuiro/nonconst_tag_fwd.hpp>
#include <mizuiro/mpl/false.hpp>
#include <mizuiro/mpl/true.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>


namespace mizuiro
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

template<
	typename T
>
struct is_constness_tag
:
mizuiro::mpl::false_
{
};

template<>
struct is_constness_tag<
	mizuiro::const_tag
>
:
mizuiro::mpl::true_
{
};

template<>
struct is_constness_tag<
	mizuiro::nonconst_tag
>
:
mizuiro::mpl::true_
{
};

MIZUIRO_DETAIL_POP_WARNING

}

#endif
