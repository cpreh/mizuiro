#ifndef MIZUIRO_ACCESS_NORMAL_HPP_INCLUDED
#define MIZUIRO_ACCESS_NORMAL_HPP_INCLUDED

#include <mizuiro/detail/apply_const.hpp>
#include <mizuiro/detail/index_of.hpp>
#include <fcppt/tr1/array.hpp>
#include <boost/mpl/size.hpp>

namespace mizuiro
{
namespace access
{

template<
	typename Format
>
struct normal
{
	typedef typename Format::channel_type;

	typedef typename Format::layout layout;

	typedef std::tr1::array<
		channel_type,
		boost::mpl::size<
			typename layout::order
		>::value
	> store;

	template<
		typename Channel,
		typename Constness
	>
	struct channel_reference
	:
	mizuiro::detail::apply_const<
		channel_type &,
		Constness
	>
	{};

	template<
		typename Channel
	>
	struct channel_value_type
	{
		typedef ChannelType type;
	};

	template<
		typename Constness
	>
	struct pointer
	{
		typedef typename mizuiro::detail::apply_const<
			channel_type *,
			Constness
		>::type type;
	};

	template<
		typename Channel,
		typename Constness
	>
	struct extract_channel
	{
		static
		typename channel_reference<
			Channel,
			Constness
		>::type
		execute(
			typename pointer<
				Constness
			>::type const ptr
		)
		{
			return ptr[
				mizuiro::detail::index_of<
					typename layout::order,
					Channel
				>::value
			];
		}
	};
};

}
}

#endif
