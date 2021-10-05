//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_SET_CHROMA_PARTS_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_SET_CHROMA_PARTS_HPP_INCLUDED

#include <mizuiro/color/set_percentage.hpp>
#include <fcppt/declare_strong_typedef.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/reference_impl.hpp>


namespace mizuiro::color::conversion::detail
{

template<
	typename Dest,
	typename Float
>
class set_chroma_parts
{
public:
	FCPPT_DECLARE_STRONG_TYPEDEF(
		Float,
		chroma_diff
	);

	FCPPT_DECLARE_STRONG_TYPEDEF(
		Float,
		largest_diff
	);

	FCPPT_DECLARE_STRONG_TYPEDEF(
		Float,
		diff
	);

	set_chroma_parts(
		Dest &_dest,
		chroma_diff const _chroma_diff,
		largest_diff const _largest_diff,
		diff const _diff
	)
	:
		dest_(
			_dest
		),
		chroma_diff_{
			_chroma_diff.get()
		},
		largest_diff_{
			_largest_diff.get()
		},
		diff_{
			_diff.get()
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
			dest_.get(),
			_channel1,
			chroma_diff_
		);

		mizuiro::color::set_percentage(
			dest_.get(),
			_channel2,
			largest_diff_
		);

		mizuiro::color::set_percentage(
			dest_.get(),
			_channel3,
			diff_
		);
	}
private:
	fcppt::reference<
		Dest
	> dest_;

	Float chroma_diff_;

	Float largest_diff_;

	Float diff_;
};

}

#endif
