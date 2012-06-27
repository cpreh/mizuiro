//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ACCESS_INTERLEAVED_HPP_INCLUDED
#define MIZUIRO_IMAGE_ACCESS_INTERLEAVED_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/image/format_store_fwd.hpp>
#include <mizuiro/image/is_interleaved.hpp>
#include <mizuiro/image/to_color_format_store.hpp>
#include <mizuiro/image/access/data_store_size.hpp>
#include <mizuiro/image/access/dereference.hpp>
#include <mizuiro/image/access/stride.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/reference.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace image
{
namespace access
{


template<
	typename Access,
	typename ImageFormat,
	typename Constness
>
struct dereference<
	Access,
	ImageFormat,
	Constness,
	typename boost::enable_if<
		mizuiro::image::is_interleaved<
			ImageFormat
		>
	>::type
>
{
	typedef typename mizuiro::image::types::reference<
		Access,
		ImageFormat,
		Constness
	>::type result_type;

	typedef typename mizuiro::image::types::pointer<
		Access,
		ImageFormat,
		Constness
	>::type pointer;

	static
	result_type
	execute(
		Access const &,
		pointer const _data,
		mizuiro::image::format_store<
			ImageFormat
		> const &_format
	)
	{
		return
			result_type(
				_data,
				mizuiro::image::to_color_format_store(
					_format
				)
			);
	}
};

template<
	typename Access,
	typename ImageFormat
>
struct data_store_size<
	Access,
	ImageFormat,
	typename boost::enable_if<
		mizuiro::image::is_interleaved<
			ImageFormat
		>
	>::type
>
{
	template<
		typename Dim
	>
	static
	mizuiro::size_type
	execute(
		Access const &_access,
		mizuiro::image::format_store<
			ImageFormat
		> const &_format,
		Dim const &_dim
	)
	{
		return
			_dim.content()
			*
			mizuiro::image::access::stride<
				Access,
				ImageFormat
			>::execute(
				_access,
				_format
			);
	}
};

template<
	typename Access,
	typename ImageFormat
>
struct stride<
	Access,
	ImageFormat,
	typename boost::enable_if<
		mizuiro::image::is_interleaved<
			ImageFormat
		>
	>::type
>
{
	static
	mizuiro::size_type
	execute(
		Access const &_access,
		mizuiro::image::format_store<
			ImageFormat
		> const &_format
	)
	{
		return
			mizuiro::color::access::stride<
				Access,
				typename ImageFormat::color_format
			>::execute(
				_access,
				mizuiro::image::to_color_format_store(
					_format
				)
			);
	}
};

}
}
}

#endif
