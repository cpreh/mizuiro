//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_VISITOR_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_VISITOR_HPP_INCLUDED

#include <mizuiro/color/init/detail/set_channel.hpp>
#include <mizuiro/color/object_fwd.hpp>

namespace mizuiro
{
namespace color
{
namespace init
{
namespace detail
{

template<
	typename Format
>
class visitor
{
public:
	typedef void result_type;

	typedef color::object<
		Format
	> color_type;

	explicit visitor(
		color_type &_object
	)
	:
		object_(_object)
	{}

	template<
		typename T
	>
	result_type
	operator()(
		T const &_value
	) const
	{
		detail::set_channel(
			object_,
			_value
		);
	}
private:
	color_type &object_;
};

}
}
}
}

#endif
