#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_COPY_AND_CONVERT_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_COPY_AND_CONVERT_HPP_INCLUDED

#include <mizuiro/color/convert.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

struct copy_and_convert {
	typedef void result_type;

	template<
		typename Src,
		typename Dest
	>
	result_type
	operator()(
		Src const &src,
		Dest const &dest
	) const
	{
		dest = 
			color::convert<
				typename Dest::format
			>(
				src
			);
	}
};

}
}
}
}

#endif
