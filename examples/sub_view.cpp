//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/color/object.hpp>
#include <mizuiro/color/output.hpp>
#include <mizuiro/color/format/homogenous_static.hpp>
#include <mizuiro/color/format/include/homogenous_static.hpp>
#include <mizuiro/color/init/alpha.hpp>
#include <mizuiro/color/init/blue.hpp>
#include <mizuiro/color/init/green.hpp>
#include <mizuiro/color/init/red.hpp>
#include <mizuiro/color/layout/rgba.hpp>
#include <mizuiro/image/bound.hpp>
#include <mizuiro/image/const_view.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/pitch_view_impl.hpp>
#include <mizuiro/image/store.hpp>
#include <mizuiro/image/sub_view.hpp>
#include <mizuiro/image/to_pitch_view.hpp>
#include <mizuiro/image/algorithm/copy.hpp>
#include <mizuiro/image/algorithm/fill_indexed.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/image/algorithm/uninitialized.hpp>
#include <mizuiro/image/format/interleaved.hpp>
#include <mizuiro/image/format/include/interleaved_homogenous.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <iostream>
#include <iterator>
#include <ostream>
#include <mizuiro/detail/external_end.hpp>


int main()
{
	typedef float channel_type;

	typedef mizuiro::image::format::interleaved<
		mizuiro::image::dimension<
			3
		>,
		mizuiro::color::format::homogenous_static<
			channel_type,
			mizuiro::color::layout::rgba
		>
	> format;

	typedef mizuiro::image::store<
		format
	> store;

	typedef store::view_type view_type;

	typedef view_type::bound_type bound_type;

	store const img{
		store::dim(
			100u,
			100u,
			100u
		),
		[](
			view_type const &_view
		)
		{
			mizuiro::image::algorithm::fill_indexed(
				_view,
				[](
					view_type::dim const _index
				)
				{
					return
						mizuiro::color::object<
							format::color_format
						>(
							(mizuiro::color::init::red() = static_cast<channel_type>(_index.at_c<0>()))
							(mizuiro::color::init::green() = static_cast<channel_type>(_index.at_c<1>()))
							(mizuiro::color::init::blue() = static_cast<channel_type>(_index.at_c<2>()))
							(mizuiro::color::init::alpha() = channel_type{255})
						);
				},
				mizuiro::image::algorithm::uninitialized::yes
			);
		}
	};

	std::cout << '\n';

	typedef
	mizuiro::image::to_pitch_view<
		typename
		mizuiro::image::const_view<
			view_type
		>
	>
	pitch_view;

	pitch_view const sub_view(
		mizuiro::image::sub_view(
			img.view(),
			bound_type(
				bound_type::dim(
					1u,
					1u,
					1u
				),
				bound_type::dim(
					3u,
					4u,
					3u
				)
			)
		)
	);

	std::cout
		<< "sub image (with pitch "
		<< sub_view.pitch()
		<< ")\n";


	pitch_view const sub_sub_view(
		mizuiro::image::sub_view(
			sub_view,
			bound_type(
				bound_type::dim(
					1u,
					1u,
					1u
				),
				bound_type::dim(
					2u,
					3u,
					2u
				)
			)
		)
	);

	std::cout
		<< "sub sub image (with pitch "
		<< sub_sub_view.pitch()
		<< ")\n";

	mizuiro::image::algorithm::print(
		std::cout,
		sub_sub_view
	);

	std::cout << '\n';

	{
		typedef std::reverse_iterator<
			pitch_view::iterator
		> reverse_iterator;

		for(
			reverse_iterator it(
				sub_sub_view.end()
			);
			it != reverse_iterator(
				sub_sub_view.begin()
			);
			++it
		)
			std::cout << *it << ' ';
	}

	std::cout << '\n';
}
