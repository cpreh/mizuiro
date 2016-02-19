//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_FORMAT_ARGUMENT_HPP_INCLUDED
#define MIZUIRO_DETAIL_FORMAT_ARGUMENT_HPP_INCLUDED

#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename Format,
	typename FormatNeedsStore,
	typename FormatStore,
	typename Enable = void
>
struct format_argument;

// This is a hack for VC++
// It instantiates default arguments even if they
// are never used.
// The static assert has to be put into the function
// because VC++ doesn't look that far.
template<
	typename Format,
	typename FormatNeedsStore,
	typename FormatStore
>
struct format_argument<
	Format,
	FormatNeedsStore,
	FormatStore,
	typename
	std::enable_if<
		FormatNeedsStore::value
	>::type
>
{
	static
	FormatStore
	get()
	{
		static_assert(
			sizeof(Format) == 0,
			"This color format requires a store!"
		);
	}
};

template<
	typename Format,
	typename FormatNeedsStore,
	typename FormatStore
>
struct format_argument<
	Format,
	FormatNeedsStore,
	FormatStore,
	typename
	std::enable_if<
		!FormatNeedsStore::value
	>::type
>
{
	static
	FormatStore
	get()
	{
		return
			FormatStore(
				nullptr
			);
	}
};

}
}

#endif
