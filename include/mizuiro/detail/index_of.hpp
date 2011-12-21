//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_INDEX_OF_HPP_INCLUDED
#define MIZUIRO_DETAIL_INDEX_OF_HPP_INCLUDED

#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/begin.hpp>
#include <boost/mpl/contains.hpp>
#include <boost/mpl/distance.hpp>
#include <boost/mpl/find.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/static_assert.hpp>
#include <mizuiro/detail/external_end.hpp>

namespace mizuiro
{
namespace detail
{

template<
	typename Elements,
	typename Element
>
struct index_of
:
boost::mpl::distance<
	typename boost::mpl::begin<
		Elements
	>::type,
	typename boost::mpl::find<
		Elements,
		Element
	>::type
>
{
	BOOST_STATIC_ASSERT((
		boost::mpl::contains<
			Elements,
			Element
		>::value
	));
};

}
}

#endif
