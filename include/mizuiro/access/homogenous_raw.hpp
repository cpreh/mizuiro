//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_ACCESS_HOMOGENOUS_RAW_HPP_INCLUDED
#define MIZUIRO_ACCESS_HOMOGENOUS_RAW_HPP_INCLUDED

#include <mizuiro/access/channel_index.hpp>
#include <mizuiro/access/data_store_size.hpp>
#include <mizuiro/access/extract_channel.hpp>
#include <mizuiro/access/raw.hpp>
#include <mizuiro/color/types/channel_reference.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/color/is_homogenous.hpp>
#include <mizuiro/size_type.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace access
{

template<
	typename Format,
	typename Channel,
	typename Constness
>
struct extract_channel<
	access::raw,
	Format,
	Channel,
	Constness,
	typename boost::enable_if<
		mizuiro::color::is_homogenous<
			Format
		>
	>::type
>
{
	static
	typename mizuiro::color::types::channel_reference<
		access::raw,
		Format,
		Channel,
		Constness
	>::type
	execute(
		access::raw const &_access,
		Format const *const _format,
		Channel const &_channel,
		Constness const &,
		typename mizuiro::color::types::pointer<
			access::raw,
			Format,
			Constness
		>::type const _ptr
	)
	{
		return
			_ptr +
			access::channel_index<
				access::raw,
				Format,
				Channel
			>::execute(
				_access,
				_format,
				_channel
			)
			* sizeof(typename Format::channel_type)
		;
	}
};

template<
	typename Format,
	typename Dim
>
struct data_store_size<
	access::raw,
	Format,
	Dim,
	typename boost::enable_if<
		mizuiro::color::is_homogenous<
			typename Format::color_format
		>
	>::type
>
{
	static
	mizuiro::size_type
	execute(
		access::raw const &,
		Format const &,
		Dim const &_dim
	)
	{
		return
			_dim.content()
			* Format::color_format::element_count
			* sizeof(typename Format::color_format::channel_type);
	}
};

}
}

#endif
