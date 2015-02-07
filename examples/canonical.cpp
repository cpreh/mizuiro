//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/const_tag.hpp>
#include <mizuiro/access/normal.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/image/format/canonical.hpp>
#include <mizuiro/image/format/include/canonical.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <iostream>
#include <string>
#include <mizuiro/detail/external_end.hpp>


int
main()
{
	typedef
	mizuiro::image::format::canonical<
		mizuiro::image::dimension<
			2
		>,
		std::string
	>
	format;

	std::array<
		std::string,
		4
	> const string_matrix{{
		std::string("test1"),
		std::string("test2"),
		std::string("test3"),
		std::string("test4")
	}};

	mizuiro::image::linear_view<
		mizuiro::access::normal,
		format,
		mizuiro::const_tag
	> const view(
		format::dim{
			2u,
			2u
		},
		string_matrix.data()
	);

	// TODO: Print this as a 2d matrix
	mizuiro::image::algorithm::print(
		std::cout,
		view
	);

	std::cout << '\n';
}
