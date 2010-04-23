#ifndef MIZUIRO_IMAGE_FORMAT_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_HPP_INCLUDED

#include <mizuiro/image/detail/pitch_type.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename DimType,
	typename ImageFormat 
>
struct format
{
	typedef DimType dim_type;

	typedef ImageFormat image_format;

	typedef typename detail::pitch_type<
		dim_type
	>::type pitch_type;

	typedef typename image_format::color_format color_format;
};

}
}

#endif
