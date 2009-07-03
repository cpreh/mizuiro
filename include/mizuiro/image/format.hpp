#ifndef MIZUIRO_IMAGE_FORMAT_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_HPP_INCLUDED

#include <mizuiro/image/detail/pitch_type.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Dim,
	typename ImageFormat 
>
struct format {
	typedef Dim dim_type;
	typedef ImageFormat image_format;

	typedef typename detail::pitch_type<
		dim_type
	>::type pitch_type;

	typedef typename image_format::color_format color_format;
	typedef typename color_format::value_type value_type;
	typedef typename color_format::pointer pointer;
	typedef typename color_format::reference reference;
	typedef typename color_format::const_pointer const_pointer;

	template<
		typename T
	>
	struct replace_pointer {
		typedef format<
			Dim,
			typename ImageFormat::template replace_pointer<
				T
			>::type
		> type;
	};
};

}
}

#endif
