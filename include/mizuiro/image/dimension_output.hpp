//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DIMENSION_OUTPUT_HPP_INCLUDED
#define MIZUIRO_IMAGE_DIMENSION_OUTPUT_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace image
{

template<
	mizuiro::size_type Dim,
	typename ValueType,
	typename Ch,
	typename Traits
>
std::basic_ostream<
	Ch,
	Traits
> &
operator<<(
	std::basic_ostream<
		Ch,
		Traits
	> &_stream,
	mizuiro::image::dimension<
		Dim,
		ValueType
	> const &_dim
)
{
	using
	dim
	=
	mizuiro::image::dimension<
		Dim,
		ValueType
	>;

	_stream << _stream.widen('(');

	for(
		typename dim::size_type i = 0;
		i < dim::static_size;
		++i
	)
	{
		_stream << _dim[i];

		if(
			i != dim::static_size - 1
		)
		{
			_stream << _stream.widen(',');
		}
	}

	_stream << _stream.widen(')');

	return _stream;
}

}
}

#endif
