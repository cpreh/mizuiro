#ifndef MIZUIRO_COLOR_DETAIL_COPY_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_COPY_CHANNEL_HPP_INCLUDED

namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Color
>
struct copy_channel {
	typedef void result_type;

	copy_channel(
		Color const &dest,
		Color const &src
	)
	:
		dest(dest),
		src(src)
	{}

	template<
		typename Channel
	>
	result_type
	operator()(
		Channel &
	) const
	{
		dest. template set<
			Channel
		>(
			src. template get<
				Channel
			>()
		);
	}
private:
	Color const
		&dest,
		&src;
};

}
}
}

#endif
