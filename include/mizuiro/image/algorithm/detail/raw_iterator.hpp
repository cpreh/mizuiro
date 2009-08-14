#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_RAW_ITERATOR_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_RAW_ITERATOR_HPP_INCLUDED

#include <boost/type_traits/is_pointer.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

template<
	typename T
>
typename boost::enable_if<
	boost::is_pointer<
		T
	>,
	T
>::type
raw_iterator(
	T const &t
)
{
	return t;
}

template<
	typename T
>
typename boost::disable_if<
	boost::is_pointer<
		T
	>,
	typename T::pointer
>::type
raw_iterator(
	T const &t
)
{
	return t.get();
}

}
}
}
}

#endif
