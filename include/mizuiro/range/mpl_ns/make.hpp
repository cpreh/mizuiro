//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_RANGE_MPL_NS_MAKE_HPP_INCLUDED
#define MIZUIRO_RANGE_MPL_NS_MAKE_HPP_INCLUDED

#include <mizuiro/range/mpl_ns/tag.hpp>
#include <mizuiro/range/detail/mpl.hpp>
#include <mizuiro/range/make_ns/tag.hpp>


namespace mizuiro
{
namespace range
{
namespace mpl_ns
{

template<
	typename Sequence
>
mizuiro::range::detail::mpl<
	Sequence
>
make_adl(
	mizuiro::range::make_ns::tag,
	mizuiro::range::mpl_ns::tag<
		Sequence
	>,
	Sequence const &
)
{
	return
		mizuiro::range::detail::mpl<
			Sequence
		>();
}

}
}
}

#endif
