#ifndef MIZUIRO_IMAGE_FORMAT_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_HPP_INCLUDED

namespace mizuiro
{
namespace image
{

template<
	typename Dim,
	typename ImageFormat 
>
struct format {
	typedef Dim dim;
	typedef ImageFormat image_format;
	typedef typename image_format::color_format color_format;
};

}
}

#endif
