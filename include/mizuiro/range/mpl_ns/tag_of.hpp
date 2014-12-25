//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_RANGE_MPL_NS_TAG_OF_HPP_INCLUDED
#define MIZUIRO_RANGE_MPL_NS_TAG_OF_HPP_INCLUDED

#include <mizuiro/range/tag_of_fwd.hpp>
#include <mizuiro/range/mpl_ns/tag.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/is_sequence.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace range
{

template<
	typename Sequence
>
struct
tag_of<
	Sequence,
	typename
	std::enable_if<
		boost::mpl::is_sequence<
			Sequence
		>::value
	>::type
>
{
	typedef
	mizuiro::range::mpl_ns::tag<
		Sequence
	>
	type;
};

}
}

#endif
