#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_COPY_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_COPY_HPP_INCLUDED

namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

struct copy {
	template<
		typename Src,
		typename Dest
	>
	operator()(
		Src const &src,
		Dest const &dest
	)
	{
		dest = src;
	}
};

}
}
}
}

#endif
