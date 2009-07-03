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
	struct replace_pointer {
		typedef interleaved<
			typename color_format::template replace_pointer<
				T
			>::type
		> type;

	};
};

}
}

#endif
