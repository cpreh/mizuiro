#ifndef MIZUIRO_IMAGE_FORMAT_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_HPP_INCLUDED

#include <mizuiro/image/detail/pitch_type.hpp>
#include <mizuiro/detail/nonconst_tag.hpp>
#include <mizuiro/detail/const_tag.hpp>

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

	typedef typename color_format::channel_type channel_type;

	typedef typename color_format:: template pointer<
		mizuiro::detail::nonconst_tag
	>::type pointer;

	typedef typename color_format:: template pointer<
		mizuiro::detail::const_tag
	>::type const_pointer;

	template<
		typename T
	>
	struct replace_access {
		typedef format<
			Dim,
			typename ImageFormat::template replace_access<
				T
			>::type
		> type;
	};
};

}
}

#endif
