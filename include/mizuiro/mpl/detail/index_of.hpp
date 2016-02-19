//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_DETAIL_INDEX_OF_HPP_INCLUDED
#define MIZUIRO_MPL_DETAIL_INDEX_OF_HPP_INCLUDED

#include <mizuiro/mpl/head.hpp>
#include <mizuiro/mpl/integral_size.hpp>
#include <mizuiro/mpl/tail.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace mpl
{
namespace detail
{

template<
	typename List,
	typename Element,
	typename Enable = void
>
struct index_of;

template<
	typename List,
	typename Element
>
struct index_of<
	List,
	Element,
	typename
	std::enable_if<
		std::is_same<
			mizuiro::mpl::head<
				List
			>,
			Element
		>::value
	>::type
>
{
	typedef
	mizuiro::mpl::integral_size<
		0u
	>
	type;
};

template<
	typename List,
	typename Element
>
struct index_of<
	List,
	Element,
	typename
	std::enable_if<
		!std::is_same<
			mizuiro::mpl::head<
				List
			>,
			Element
		>::value
	>::type
>
{
	typedef
	mizuiro::mpl::integral_size<
		mizuiro::mpl::detail::index_of<
			mizuiro::mpl::tail<
				List
			>,
			Element
		>::type::value
		+
		1u
	>
	type;
};

}
}
}

#endif
