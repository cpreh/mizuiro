#ifndef MIZUIRO_COLOR_DETAIL_OUTPUT_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_OUTPUT_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/detail/promote_channel.hpp>
#include <mizuiro/detail/index_of.hpp>
#include <boost/mpl/size.hpp>
#include <ostream>

namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Ch,
	typename Traits,
	typename Color
>
class output_channel {
	typedef std::basic_ostream<
		Ch,
		Traits
	> stream_type;
public:
	output_channel(
		stream_type &s,
		Color const &c
	)
	:
		s(s),
		c(c)
	{}

	template<
		typename Channel
	>
	void
	operator()(
		Channel &
	) const
	{
		typedef typename Color::layout::layout::order order;

		s <<
			static_cast<
				typename detail::promote_channel<
					typename Color::layout:: template channel_value_type<
						Channel
					>::type
				>::type
			>(
				c. template get<
					Channel
				>()
			);

		if(
			mizuiro::detail::index_of<
				order,
				Channel
			>::value + 1
			!=
			boost::mpl::size<
				order
			>::value
		)
			s << s.widen(',');
	}
private:
	stream_type &s;
	Color const &c;
};

}
}
}

#endif
