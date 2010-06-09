#ifndef MIZUIRO_COLOR_OPERATORS_ADD_HPP_INCLUDED
#define MIZUIRO_COLOR_OPERATORS_ADD_HPP_INCLUDED

#include <mizuiro/color/operators/detail/add.hpp>
#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/for_each_channel.hpp>
#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_same.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename Color1,
	typename Color2
>
typename boost::enable_if<
	boost::mpl::and_<
		boost::is_same<
			typename Color1::format,
			typename Color2::format
		>
		color::is_color<
			Color1
		>,
		color::is_color<
			Color2
		>
	>,
	color::object<
		typename Color1::format
	>
>::type
operator+(
	Color1 const &color1_,
	Color2 const &color2_
)
{
	typename Color::format format;

	typedef color::object<
		format
	> result_type;

	result_type result(
		color1_
	);

	color::for_each_channel<
		format
	>(
		color::operators::detail::add<
			Color1,
			Color2
		>(
			result,
			color2_
		)
	);

	return result;
}

}
}

#endif
