#ifndef MIZUIRO_COLOR_DETAIL_COPY_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_COPY_HPP_INCLUDED

#include <mizuiro/detail/copy_n.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_fundamental.hpp>
#include <iterator>

namespace mizuiro
{
namespace detail
{

template<
	typename T
>
inline
typename boost::enable_if<
	boost::is_fundamental<
		T
	>,
	void
>::type
copy(
	T const *const begin,
	T const *const end,
	T *const dest
)
{
	return copy_n(
		begin,
		std::distance(
			begin,
			end
		),
		dest
	);
}

}
}

#endif
