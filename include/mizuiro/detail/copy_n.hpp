#ifndef MIZUIRO_COLOR_DETAIL_COPY_N_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_COPY_N_HPP_INCLUDED

#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_fundamental.hpp>
#include <cstring>

namespace mizuiro
{
namespace detail
{

template<
	typename T,
	typename Size
>
typename boost::enable_if<
	boost::is_fundamental<
		T
	>,
	void
>::type
copy_n(
	T const *const src,
	Size const size,
	T *const dest
)
{
	std::memcpy(
		dest,
		src,
		size * sizeof(T)
	);
}

}
}

#endif
