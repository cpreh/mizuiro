#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_FILL_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_FILL_HPP_INCLUDED

namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

template<
	typename Color
>
struct fill {
	typedef void result_type;

	explicit fill(
		Color const &color
	)
	:
		color(color)
	{}

	template<
		typename Dest
	>
	result_type
	operator()(
		Dest const &dest
	) const
	{
		dest = color;
	}
private:
	Color const &color;
};

}
}
}
}

#endif
