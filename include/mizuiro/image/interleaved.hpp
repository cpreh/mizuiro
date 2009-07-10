#ifndef MIZUIRO_IMAGE_INTERLEAVED_HPP_INCLUDED
#define MIZUIRO_IMAGE_INTERLEAVED_HPP_INCLUDED

namespace mizuiro
{
namespace image
{

template<
	typename ColorFormat
>
struct interleaved {
	typedef ColorFormat color_format;

	template<
		typename T
	>
	struct replace_access {
		typedef interleaved<
			typename color_format::template replace_access<
				T
			>::type
		> type;

	};
};

}
}

#endif
