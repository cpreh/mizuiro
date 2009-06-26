#ifndef MIZUIRO_DETAIL_INDEX_OF_HPP_INCLUDED
#define MIZUIRO_DETAIL_INDEX_OF_HPP_INCLUDED

#include <boost/mpl/begin.hpp>
#include <boost/mpl/distance.hpp>
#include <boost/mpl/find.hpp>

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
> {};

}
}

#endif
