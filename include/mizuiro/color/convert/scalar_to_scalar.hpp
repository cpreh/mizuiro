//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERT_SCALAR_TO_SCALAR_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERT_SCALAR_TO_SCALAR_HPP_INCLUDED

#include <mizuiro/color/is_scalar.hpp>
#include <mizuiro/color/object_impl.hpp>
#include <mizuiro/color/normalize.hpp>
#include <mizuiro/color/denormalize.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/front.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace color
{

template
<
	class Dest,
	class Src 
>
typename boost::enable_if
<
	boost::mpl::and_
	<
		is_scalar
		<
			Dest
		>,
		is_scalar
		<
			typename Src::format
		>
	>,
	object<
		Dest
	> const
>::type
convert
(
	Src const &src
)
{
	typedef object<
		Dest
	> dest_type;
	
	dest_type dest;

	typedef typename boost::mpl::front<
		typename Dest::layout::order
	>::type dest_channel;

	dest.template set
	<
		dest_channel
	>
	(
		denormalize
		<
			typename dest_type::format,
			dest_channel,
			float
		>
		(
			normalize
			<
				typename boost::mpl::front<
					typename Src::format::layout::order
				>::type,
				float
			>
			(
				src
			)
		)
	);

	return dest;
}

}
}

#endif
