//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_STORE_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_STORE_IMPL_HPP_INCLUDED

#include <mizuiro/image/format/store_decl.hpp>


template<
	typename Format
>
mizuiro::image::format::store<
	Format
>::store(
	Format const *const _format
)
:
	format_(
		_format
		?
			optional_format(
				*_format
			)
		:
			optional_format()
	)
{
}

template<
	typename Format
>
mizuiro::image::format::store<
	Format
>::store(
	Format const &_format
)
:
	format_(
		optional_format(
			_format
		)
	)
{
}

template<
	typename Format
>
typename
mizuiro::image::format::store<
	Format
>::optional_format const
mizuiro::image::format::store<
	Format
>::get() const
{
	return
		format_;
}

#endif
