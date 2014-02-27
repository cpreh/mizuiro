//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_COPY_AND_CONVERT_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_COPY_AND_CONVERT_HPP_INCLUDED

#include <mizuiro/color/convert.hpp>


namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

template<
	typename Converter
>
struct copy_and_convert
{
	typedef void result_type;

	template<
		typename Src,
		typename Dest
	>
	result_type
	operator()(
		Src const &_src,
		Dest const &_dest
	) const
	{
		_dest =
			mizuiro::color::convert<
				Converter,
				typename Dest::format
			>(
				_src,
				_dest.format_store()
			);
	}
};

}
}
}
}

#endif
