//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/color/object.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/format/heterogenous_static.hpp>
#include <mizuiro/color/format/include/heterogenous_static.hpp>
#include <mizuiro/color/init/alpha.hpp>
#include <mizuiro/color/init/luminance.hpp>
#include <mizuiro/color/layout/la.hpp>
#include <mizuiro/mpl/size_list.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <mizuiro/detail/external_end.hpp>


int
main()
{
	typedef
	mizuiro::color::format::heterogenous_static<
		mizuiro::mpl::size_list<
			24u,
			8u
		>,
		mizuiro::color::layout::la
	>
	l24_a8_format;

	typedef
	mizuiro::color::object<
		l24_a8_format
	>
	l24_a8_color;

	l24_a8_color const test1(
		(mizuiro::color::init::luminance() = static_cast<std::uint32_t>(0x1FF))
		(mizuiro::color::init::alpha() = static_cast<std::uint8_t>(0xF))
	);

	std::cout
		<< std::hex
		<< test1
		<< '\n';
}
