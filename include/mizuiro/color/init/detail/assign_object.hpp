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
#include <mizuiro/detail/is_set.hpp>
#include <mizuiro/detail/tuple_for_each.hpp>
#include <fcppt/config/external_begin.hpp>
#include <brigand/algorithms/all.hpp>
#include <brigand/algorithms/transform.hpp>
#include <brigand/functions/lambda/apply.hpp>
#include <brigand/functions/lambda/bind.hpp>
#include <brigand/types/args.hpp>
#include <fcppt/config/external_end.hpp>


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
	static_assert(
		brigand::all<
			mizuiro::color::types::static_channels<
				Format
			>,
			brigand::bind<
				mizuiro::color::init::detail::contains_channel,
				brigand::pin<
					Vector
				>,
				brigand::_1
			>
		>::value,
		"Forgotten channel in initialization"
	);

	static_assert(
		mizuiro::detail::is_set<
			brigand::transform<
				Vector,
				brigand::bind<
					mizuiro::color::init::detail::to_channel_type,
					brigand::_1
				>
			>
		>::value,
		"Duplicate channel initialization"
	);

	mizuiro::detail::tuple_for_each(
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
		},
		_init.get()
	);
}

}
}
}
}

#endif
