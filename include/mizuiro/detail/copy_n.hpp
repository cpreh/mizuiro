#ifndef MIZUIRO_COLOR_DETAIL_COPY_N_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_COPY_N_HPP_INCLUDED

#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_fundamental.hpp>
#include <cstring>

namespace mizuiro
{
namespace detail
{

template<
	typename Source,
	typename Size,
	typename Dest
>
typename boost::enable_if<
	boost::mpl::and_<
		boost::is_fundamental<
			Source
		>,
		boost::is_fundamental<
			Dest
		>
	>,
	void
>::type
copy_n(
	Source const *const src,
	Size const size,
	Dest *const dest
)
{
	std::memcpy(
		dest,
		src,
		size * sizeof(Source)
	);
}

}
}

#endif
