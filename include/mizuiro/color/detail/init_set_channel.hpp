#ifndef MIZUIRO_COLOR_DETAIL_INIT_SET_CHANNEL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_INIT_SET_CHANNEL_HPP_INCLUDED

#include <mizuiro/color/detail/init_channel.hpp>
#include <mizuiro/color/detail/init_channel_percentage.hpp>
#include <mizuiro/color/denormalize.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/static_assert.hpp>

namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename Color,
	typename Value,
	typename Channel
>
void
init_set_channel(
	Color &color,
	init_channel<
		Value,
		Channel
	> const &init
)
{
	BOOST_STATIC_ASSERT((
		boost::is_same<
			typename Color::layout:: template channel_value_type<
				Channel
			>::type,
			Value
		>::value
	));

	color. template set<
		Channel
	>(
		init.value()
	);
}

template<
	typename Color,
	typename Value,
	typename Channel
>
void
init_set_channel(
	Color &color,
	init_channel_percentage<
		Value,
		Channel
	> const &init
)
{
	color. template set<
		Channel
	>(
		denormalize<
			typename Color::layout,
			Channel
		>(
			init.value()
		)
	);
}

}
}
}

#endif
