#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_COPY_AND_CONVERT_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_COPY_AND_CONVERT_HPP_INCLUDED

#include <mizurio/color/convert.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

struct copy_and_convert {
	template<
		typename Src,
		typename Dest
	>
	operator()(
		Src const &src,
		Dest const &dest
	)
	{
		dest = 
			color::convert(
				src
			);
	}
};

}
}
}
}

#endif
