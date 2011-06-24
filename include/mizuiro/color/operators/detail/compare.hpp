//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_OPERATORS_DETAIL_COMPARE_HPP_INCLUDED
#define MIZUIRO_COLOR_OPERATORS_DETAIL_COMPARE_HPP_INCLUDED

#include <mizuiro/compare.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/next.hpp>
#include <boost/type_traits/is_same.hpp>

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
struct compare;

template<>
struct compare<
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
struct compare<
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
			::mizuiro::compare(
				_color1.get(
					item()
				),
				_color2.get(
					item()
				)	
			)
			?
				detail::compare<
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
