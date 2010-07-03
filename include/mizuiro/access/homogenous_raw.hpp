//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_ACCESS_HOMOGENOUS_RAW_HPP_INCLUDED
#define MIZUIRO_ACCESS_HOMOGENOUS_RAW_HPP_INCLUDED

#include <mizuiro/color/types/channel_reference.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/color/is_homogenous.hpp>
#include <mizuiro/access/is_raw.hpp>
#include <mizuiro/detail/index_of.hpp>
#include <mizuiro/size_type.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/mpl/and.hpp>

namespace mizuiro
{
namespace access
{

template<
	typename Access,
	typename Format,
	typename Channel,
	typename Constness
>
typename boost::enable_if<
	boost::mpl::and_<
		mizuiro::access::is_raw<
			Access
		>,
		mizuiro::color::is_homogenous<
			Format
		>
	>,
	typename mizuiro::color::types::channel_reference<
		Access,
		Format,
		Channel,
		Constness
	>::type
>::type
extract_channel(
	Access const &,
	Format const &,
	Channel const &,
	Constness const &,
	typename mizuiro::color::types::pointer<
		Access,
		Format,
		Constness
	>::type const ptr
)
{
	return ptr + 
		mizuiro::detail::index_of<
			typename Format::layout::order,
			Channel
		>::value
		* sizeof(typename Format::channel_type) // TODO!
	;
}

template<
	typename Access,
	typename Format,
	typename Dim
>
typename boost::enable_if<
	boost::mpl::and_<
		mizuiro::access::is_raw<
			Access
		>,
		mizuiro::color::is_homogenous<
			typename Format::color_format
		>
	>,
	mizuiro::size_type
>::type
data_store_size(
	Access const &,
	Format const &,
	Dim const &dim
)
{
	return
		dim.content()
		* Format::color_format::element_count
		* sizeof(typename Format::color_format::channel_type);
}

}
}

#endif
