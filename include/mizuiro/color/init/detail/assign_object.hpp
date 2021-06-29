//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_ASSIGN_OBJECT_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_ASSIGN_OBJECT_HPP_INCLUDED

#include <mizuiro/color/object_fwd.hpp>
#include <mizuiro/color/init/detail/contains_channel.hpp>
#include <mizuiro/color/init/detail/set_channel.hpp>
#include <mizuiro/color/init/detail/to_channel_type.hpp>
#include <mizuiro/color/init/detail/values_fwd.hpp>
#include <mizuiro/color/types/static_channels.hpp>
#include <fcppt/algorithm/loop.hpp>
#include <fcppt/algorithm/loop_break_tuple.hpp>
#include <fcppt/mpl/arg.hpp>
#include <fcppt/mpl/bind.hpp>
#include <fcppt/mpl/constant.hpp>
#include <fcppt/mpl/lambda.hpp>
#include <fcppt/mpl/list/all_of.hpp>
#include <fcppt/mpl/list/from.hpp>
#include <fcppt/mpl/list/map.hpp>
#include <fcppt/mpl/list/is_set.hpp>


namespace mizuiro
{
namespace color
{
namespace init
{
namespace detail
{

template<
	typename Format,
	typename Vector
>
inline
void
assign_object(
	mizuiro::color::object<
		Format
	> &_object,
	mizuiro::color::init::detail::values<
		Vector
	> const &_init
)
{
	using
	color_types
	=
	fcppt::mpl::list::from<
		Vector
	>;

	static_assert(
		fcppt::mpl::list::all_of<
			mizuiro::color::types::static_channels<
				Format
			>,
			fcppt::mpl::bind<
				fcppt::mpl::lambda<
					mizuiro::color::init::detail::contains_channel
				>,
				fcppt::mpl::constant<
					color_types
				>,
				fcppt::mpl::arg<1>
			>
		>::value,
		"Forgotten channel in initialization"
	);

	static_assert(
		fcppt::mpl::list::is_set<
			fcppt::mpl::list::map<
				color_types,
				fcppt::mpl::lambda<
					mizuiro::color::init::detail::to_channel_type
				>
			>
		>::value,
		"Duplicate channel initialization"
	);

	fcppt::algorithm::loop(
		_init.get(),
		[
			&_object
		](
			auto const &_value
		)
		{
			mizuiro::color::init::detail::set_channel(
				_object,
				_value
			);
		}
	);
}

}
}
}
}

#endif
