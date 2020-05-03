//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_VALUES_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_VALUES_HPP_INCLUDED

#include <mizuiro/color/init/detail/values_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <tuple>
#include <type_traits>
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
	typename Tuple
>
class values
{
public:
	using
	tuple_type
	=
	Tuple;

	values()
	:
		elements_()
	{
	}

	explicit
	values(
		tuple_type _elements
	)
	:
		elements_(
			std::move(
				_elements
			)
		)
	{
	}

	template<
		typename NewInit
	>
	[[nodiscard]]
	values<
		decltype(
			std::tuple_cat(
				std::declval<
					tuple_type
				>(),
				std::declval<
					std::tuple<
						NewInit
					>
				>()
			)
		)
	>
	operator()(
		values<
			std::tuple<
				NewInit
			>
		> const &_newinit
	) const
	{
		return
			values<
				decltype(
					std::tuple_cat(
						std::declval<
							tuple_type
						>(),
						std::declval<
							std::tuple<
								NewInit
							>
						>()
					)
				)
			>(
				std::tuple_cat(
					tuple_type{
						elements_
					},
					std::tuple<
						NewInit
					>{
						_newinit.get()
					}
				)
			);
	}

	[[nodiscard]]
	tuple_type const &
	get() const
	{
		return
			elements_;
	}
private:
	tuple_type elements_;
};

}
}
}
}

#endif
