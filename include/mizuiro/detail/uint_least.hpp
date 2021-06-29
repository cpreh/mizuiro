//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_UINT_LEAST_HPP_INCLUDED
#define MIZUIRO_DETAIL_UINT_LEAST_HPP_INCLUDED

#include <mizuiro/detail/bit_count_at_least.hpp>
#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/front.hpp>
#include <fcppt/mpl/list/keep_if.hpp>
#include <fcppt/mpl/list/object.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename Bits
>
using uint_least
=
fcppt::mpl::list::front<
	fcppt::mpl::list::keep_if<
		fcppt::mpl::list::object<
			unsigned char,
			unsigned short, // NOLINT(google-runtime-int)
			unsigned int,
			unsigned long, // NOLINT(google-runtime-int)
			unsigned long long // NOLINT(google-runtime-int)
		>,
		fcppt::mpl::bind<
			fcppt::mpl::lambda<
				mizuiro::detail::bit_count_at_least
			>,
			fcppt::mpl::constant<
				Bits
			>,
			fcppt::mpl::arg<1>
		>
	>
>;

}
}

#endif
