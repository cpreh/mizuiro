//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_SET_CHROMA_PARTS_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_SET_CHROMA_PARTS_HPP_INCLUDED

#include <mizuiro/color/set_percentage.hpp>
#include <mizuiro/detail/nonassignable.hpp>


namespace mizuiro
{
namespace color
{
namespace conversion
{
namespace detail
{

template<
	typename Dest,
	typename Float
>
class set_chroma_parts
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		set_chroma_parts
	);
public:
	set_chroma_parts(
		Dest &_dest,
		Float const _chroma_diff,
		Float const _largest_diff,
		Float const _diff
	)
	:
		dest_(
			_dest
		),
		chroma_diff_{
			_chroma_diff
		},
		largest_diff_{
			_largest_diff
		},
		diff_{
			_diff
		}
	{
	}

	template<
		typename Channel1,
		typename Channel2,
		typename Channel3
	>
	void
	operator()(
		Channel1 const &_channel1,
		Channel2 const &_channel2,
		Channel3 const &_channel3
	) const
	{
		mizuiro::color::set_percentage(
			dest_,
			_channel1,
			chroma_diff_
		);

		mizuiro::color::set_percentage(
			dest_,
			_channel2,
			largest_diff_
		);

		mizuiro::color::set_percentage(
			dest_,
			_channel3,
			diff_
		);
	}
private:
	Dest &dest_;

	Float const chroma_diff_;

	Float const largest_diff_;

	Float const diff_;
};

}
}
}
}

#endif
