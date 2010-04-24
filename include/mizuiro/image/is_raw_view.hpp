#ifndef MIZUIRO_IMAGE_IS_RAW_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_IS_RAW_VIEW_HPP_INCLUDED

#include <mizuiro/access/raw.hpp>
#include <boost/type_traits/is_same.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename View
>
struct is_raw_view
:
boost::is_same<
	typename View::access,
	::mizuiro::access::raw
>
{};

}
}

#endif
