//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_RANGE_DETAIL_MPL_HPP_INCLUDED
#define MIZUIRO_RANGE_DETAIL_MPL_HPP_INCLUDED

#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/pop_front.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace range
{
namespace detail
{

template<
	typename Sequence
>
struct mpl
{
	typedef
	boost::mpl::empty<
		Sequence
	>
	empty;

	typename
	boost::mpl::front<
		Sequence
	>::type
	get() const
	{
		return
			typename
			boost::mpl::front<
				Sequence
			>::type();
	}

	mpl<
		typename
		boost::mpl::pop_front<
			Sequence
		>::type
	>
	next() const
	{
		return
			mpl<
				typename
				boost::mpl::pop_front<
					Sequence
				>::type
			>();
	}
};

}
}
}

#endif
