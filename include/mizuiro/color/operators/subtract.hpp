#ifndef MIZUIRO_COLOR_OPERATORS_SUBTRACT_HPP_INCLUDED
#define MIZUIRO_COLOR_OPERATORS_SUBTRACT_HPP_INCLUDED

#include <mizuiro/color/operators/detail/binary_op.hpp>
#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_same.hpp>
#include <functional>

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
		>,
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
operator-(
	Color1 const &color1_,
	Color2 const &color2_
)
{
	return
		color::operators::detail::binary_op<
			std::minus
		>(
			color1_,
			color2_
		);
}

}
}

#endif
