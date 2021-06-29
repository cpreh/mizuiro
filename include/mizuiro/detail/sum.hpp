//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_SUM_HPP_INCLUDED
#define MIZUIRO_DETAIL_SUM_HPP_INCLUDED

#include <mizuiro/integral_size.hpp>
#include <fcppt/mpl/add.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/fold.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename List
>
using
sum
=
fcppt::mpl::list::fold<
	List,
	fcppt::mpl::lambda<
		fcppt::mpl::add
	>,
	mizuiro::integral_size<
		0U
	>
>;

}
}

#endif
