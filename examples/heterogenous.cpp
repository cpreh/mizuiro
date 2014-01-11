//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/size_type.hpp>
#include <mizuiro/color/object.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/format/heterogenous_static.hpp>
#include <mizuiro/color/format/include/heterogenous_static.hpp>
#include <mizuiro/color/init/depth.hpp>
#include <mizuiro/color/init/stencil.hpp>
#include <mizuiro/color/layout/depth_stencil.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/mpl/vector/vector10_c.hpp>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <mizuiro/detail/external_end.hpp>


int
main()
{
	typedef mizuiro::color::format::heterogenous_static<
		boost::mpl::vector2_c<
			mizuiro::size_type,
			24u,
			8u
		>,
		mizuiro::color::layout::depth_stencil
	> depth24_stencil8_format;

	typedef mizuiro::color::object<
		depth24_stencil8_format
	> depth24_stencil8_color;

	depth24_stencil8_color const test1(
		(mizuiro::color::init::depth() = static_cast<std::uint32_t>(0x1FF))
		(mizuiro::color::init::stencil() = static_cast<std::uint8_t>(0xF))
	);

	std::cout
		<< std::hex
		<< test1
		<< '\n';
}
