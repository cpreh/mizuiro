//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_FORMAT_ARGUMENT_HPP_INCLUDED
#define MIZUIRO_DETAIL_FORMAT_ARGUMENT_HPP_INCLUDED

#include <mizuiro/detail/external_begin.hpp>
#include <boost/static_assert.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename Format,
	typename FormatIsStatic,
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
	typename FormatIsStatic,
	typename FormatStore
>
struct format_argument<
	Format,
	FormatIsStatic,
	FormatStore,
	typename boost::disable_if<
		FormatIsStatic
	>::type
>
{
	static
	FormatStore const
	get()
	{
		BOOST_STATIC_ASSERT(
			sizeof(Format) == 0
		);
	}
};

template<
	typename Format,
	typename FormatIsStatic,
	typename FormatStore
>
struct format_argument<
	Format,
	FormatIsStatic,
	FormatStore,
	typename boost::enable_if<
		FormatIsStatic
	>::type
>
{
	static
	FormatStore const
	get()
	{
		return
			FormatStore(
				0
			);
	}
};

}
}

#endif
