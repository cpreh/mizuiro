#ifndef MIZUIRO_COLOR_HOMOGENOUS_HPP_INCLUDED
#define MIZUIRO_COLOR_HOMOGENOUS_HPP_INCLUDED

namespace mizuiro
{
namespace color
{

template<
	typename ChannelType,
	typename Layout
>
struct homogenous
{
	typedef ChannelType channel_type;

	typedef Layout layout;

#if 0
	template<
		typename Constness
	>
	struct reference {
		typedef proxy<
			homogenous<
				channel_type,
				layout,
				AccessTypes
			>,
			Constness
		> type;
	};

	static size_type const element_count
		= boost::mpl::size<
			typename layout::order
		>::value;
#endif
};

}
}

#endif
