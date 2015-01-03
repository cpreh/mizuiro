//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/array.hpp>
#include <mizuiro/mpl/list.hpp>
#include <mizuiro/mpl/include/list.hpp>
#include <mizuiro/range/make.hpp>
#include <mizuiro/range/include/array.hpp>
#include <mizuiro/range/include/mpl.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/test/unit_test.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace
{

template<
	typename Range1
>
void
test_length(
	Range1 const &_range1
)
{
	static_assert(
		!Range1::empty::value,
		""
	);

	static_assert(
		!Range1::tail_type::empty::value,
		""
	);

	static_assert(
		Range1::tail_type::tail_type::empty::value,
		""
	);

	typedef
	typename
	Range1::tail_type
	range2_type;

	range2_type const range2(
		_range1.next()
	);

	static_assert(
		!range2_type::empty::value,
		""
	);

	static_assert(
		range2_type::tail_type::empty::value,
		""
	);

	typedef
	typename
	range2_type::tail_type
	range3_type;

	range3_type const range3(
		range2.next()
	);

	static_assert(
		range3_type::empty::value,
		""
	);

	static_cast<
		void
	>(
		range3
	);
}

}

MIZUIRO_DETAIL_IGNORE_EFFCPP

BOOST_AUTO_TEST_CASE(
	range_mpl
)
{
MIZUIRO_DETAIL_POP_WARNING

	auto const range(
		mizuiro::range::make(
			mizuiro::mpl::list<
				int,
				float
			>{}
		)
	);

	test_length(
		range
	);
}

MIZUIRO_DETAIL_IGNORE_EFFCPP

BOOST_AUTO_TEST_CASE(
	range_array
)
{
MIZUIRO_DETAIL_POP_WARNING

	auto const range(
		mizuiro::range::make(
			mizuiro::array<
				int,
				2u
			>{{
				0,
				0
			}}
		)
	);

	test_length(
		range
	);
}
