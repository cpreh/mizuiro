//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_REBIND_TAG_HPP_INCLUDED
#define MIZUIRO_DETAIL_REBIND_TAG_HPP_INCLUDED


namespace mizuiro::detail
{

template<
	typename Tag,
	typename NewInner
>
struct rebind_tag;

template<
	template<
		typename
	> class Tag,
	typename Inner,
	typename NewInner
>
struct rebind_tag<
	Tag<
		Inner
	>,
	NewInner
>
{
	using
	type
	=
	Tag<
		NewInner
	>;
};

}

#endif
