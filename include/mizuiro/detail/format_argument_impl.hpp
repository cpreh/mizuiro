//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_FORMAT_ARGUMENT_IMPL_HPP_INCLUDED
#define MIZUIRO_DETAIL_FORMAT_ARGUMENT_IMPL_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename Result,
	bool NeedsStore
>
typename
std::enable_if<
	NeedsStore,
	Result
>::type
format_argument_impl()
{
	static_assert(
		sizeof(Result) == 0,
		"This color format requires a store!"
	);
}

template<
	typename Result,
	bool NeedsStore
>
typename
std::enable_if<
	!NeedsStore,
	Result
>::type
format_argument_impl()
{
	return
		Result{};
}

}
}

#endif
