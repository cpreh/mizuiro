//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_OPERATORS_DETAIL_EQUAL_HPP_INCLUDED
#define MIZUIRO_COLOR_OPERATORS_DETAIL_EQUAL_HPP_INCLUDED

#include <mizuiro/color/operators/detail/compare_channel.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/next.hpp>
#include <boost/type_traits/is_same.hpp>
#include <mizuiro/detail/external_end.hpp>

namespace mizuiro
{
namespace color
{
namespace operators
{
namespace detail
{

template<
	bool Done
>
struct equal;

template<>
struct equal<
	true
>
{
	template<
		typename Iterator,
		typename LastIterator,
		typename Color1,
		typename Color2
	>
	static bool
	execute(
		Color1 const &,
		Color2 const &
	)
	{
		return true;
	}
};

template<>
struct equal<
	false
>
{
	template<
		typename Iterator,
		typename LastIterator,
		typename Color1,
		typename Color2
	>
	static bool
	execute(
		Color1 const &_color1,
		Color2 const &_color2
	)
	{
		typedef typename boost::mpl::deref<Iterator>::type item;

		typedef typename boost::mpl::next<Iterator>::type iter;

		return
			operators::detail::compare_channel(
				_color1.get(
					item()
				),
				_color2.get(
					item()
				)
			)
			?
				detail::equal<
					boost::is_same<
						iter,
						LastIterator
					>::value
				>:: template execute<
					iter,
					LastIterator
				>(
					_color1,
					_color2
				)
			:
				false;
	}
};

}
}
}
}

#endif
