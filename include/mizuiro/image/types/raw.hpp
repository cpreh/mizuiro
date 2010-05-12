#ifndef MIZUIRO_IMAGE_TYPES_RAW_HPP_INCLUDED
#define MIZUIRO_IMAGE_TYPES_RAW_HPP_INCLUDED

#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/data_store.hpp>
#include <mizuiro/image/detail/stride_pointer_impl.hpp>
#include <mizuiro/image/detail/raw_container_fwd.hpp>
#include <mizuiro/color/types/homogenous_raw.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/color/homogenous.hpp>
#include <mizuiro/access/raw.hpp>
#include <mizuiro/raw_value.hpp>

namespace mizuiro
{
namespace image
{
namespace types
{

template<
	typename Format,
	typename Constness
>
struct pointer<
	::mizuiro::access::raw,
	Format,
	Constness
>
{
	typedef detail::stride_pointer<
		typename color::types::pointer<
			::mizuiro::access::raw,
			typename Format::color_format,
			Constness
		>::type,
		sizeof(typename Format::color_format::channel_type)
	> type;	
};

template<
	typename ChannelType,
	typename Layout
>
struct data_store<
	::mizuiro::access::raw,
	::mizuiro::color::homogenous<
		ChannelType,
		Layout
	>
>
{
	typedef detail::raw_container<
		mizuiro::raw_value
	> type;
};

}
}
}

#endif
