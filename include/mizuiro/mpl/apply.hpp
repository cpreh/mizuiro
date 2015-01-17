//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_MPL_APPLY_HPP_INCLUDED
#define MIZUIRO_MPL_APPLY_HPP_INCLUDED


namespace mizuiro
{
namespace mpl
{

template<
	typename Function,
	typename Arg
>
constexpr
decltype(
	Function :: template apply<
		Arg
	>()
)
apply()
{
	return
		Function :: template apply<
			Arg
		>();
}

}
}

#endif
