//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_STORE_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_STORE_IMPL_HPP_INCLUDED

#include <mizuiro/color/format_store_impl.hpp>
#include <mizuiro/image/format_store_decl.hpp>


template<
	typename Format
>
mizuiro::image::format_store<Format>::format_store(
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
mizuiro::image::format_store<Format>::format_store(
	optional_format const &_format
)
:
	format_(_format)
{
}

template<
	typename Format
>
typename mizuiro::image::format_store<Format>::optional_format const
mizuiro::image::format_store<Format>::get() const
{
	return format_;
}

template<
	typename Format
>
typename mizuiro::image::format_store<Format>::color_format_store const
mizuiro::image::format_store<Format>::color_format() const
{
	return
		format_
		?
			format_->color_format_store()
		:
			color_format_store(
				0
			)
		;
}

#endif
