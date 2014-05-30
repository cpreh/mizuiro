//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_DETAIL_COMPARE_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_COMPARE_HPP_INCLUDED

#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/deref.hpp>
#include <boost/mpl/next.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
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
		typename Color2,
		typename Compare
	>
	static
	bool
	execute(
		Color1 const &,
		Color2 const &,
		Compare const &
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
		typename Color2,
		typename Compare
	>
	static
	bool
	execute(
		Color1 const &_color1,
		Color2 const &_color2,
		Compare const &_compare
	)
	{
		typedef
		typename
		boost::mpl::deref<
			Iterator
		>::type
		item;

		typedef
		typename
		boost::mpl::next<
			Iterator
		>::type
		iter;

		return
			_compare(
				_color1.get(
					item()
				),
				_color2.get(
					item()
				)
			)
			&&
			mizuiro::color::detail::compare<
				std::is_same<
					iter,
					LastIterator
				>::value
			>:: template execute<
				iter,
				LastIterator
			>(
				_color1,
				_color2,
				_compare
			);
	}
};

}
}
}

#endif
