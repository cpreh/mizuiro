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
		dest = src;
	}
};

}
}
}
}

#endif
