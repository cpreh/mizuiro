#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_PRINT_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_PRINT_HPP_INCLUDED

#include <mizuiro/color/output.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

template<
	typename Sink
>
struct print {
	typedef void result_type;

	explicit print(
		Sink &sink
	)
	:
		sink(sink)
	{}

	template<
		typename Src
	>
	result_type
	operator()(
		Src const &src
	) const
	{
		sink
			<< src
			<< sink.widen(' ');
	}
private:
	Sink &sink;
};

}
}
}
}

#endif
