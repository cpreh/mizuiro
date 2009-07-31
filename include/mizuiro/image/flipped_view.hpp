#ifndef MIZUIRO_IMAGE_FLIPPED_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_FLIPPED_VIEW_HPP_INCLUDED

#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename View
>
typename boost::enable_if_c<
	View::dim_type::static_size == 2,
	View const
>::type
flipped_view(
	View const &view
)
{
}

}
}

#endif
