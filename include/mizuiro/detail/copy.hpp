#ifndef MIZUIRO_COLOR_DETAIL_COPY_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_COPY_HPP_INCLUDED

#include <mizuiro/detail/copy_n.hpp>
#include <iterator>

namespace mizuiro
{
namespace detail
{

template<
	typename Source,
	typename Dest
>
void
copy(
	Source const *const begin,
	Source const *const end,
	Dest *const dest
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
