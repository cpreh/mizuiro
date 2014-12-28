//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_AT_HPP_INCLUDED
#define MIZUIRO_MPL_AT_HPP_INCLUDED

#include <mizuiro/size_type.hpp>


namespace mizuiro
{
namespace mpl
{

template<
	typename List,
	mizuiro::size_type Index
>
struct at;

template<
	typename List
>
struct at<
	List,
	0u
>
{
	typedef
	typename
	List::head
	type;
};

template<
	typename List,
	mizuiro::size_type Index
>
struct at
{
	typedef
	typename
	mizuiro::mpl::at<
		typename List::tail,
		Index - 1u
	>::type
	type;
};

}
}

#endif
