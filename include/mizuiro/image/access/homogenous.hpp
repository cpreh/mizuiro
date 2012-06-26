#ifndef MIZUIRO_IMAGE_ACCESS_HOMOGENOUS_HPP_INCLUDED
#define MIZUIRO_IMAGE_ACCESS_HOMOGENOUS_HPP_INCLUDED

#include <mizuiro/color/is_homogenous.hpp>
#include <mizuiro/image/format_store_impl.hpp>
#include <mizuiro/image/access/dereference.hpp>
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
		mizuiro::color::is_homogenous<
			typename ImageFormat::color_format
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
		pointer const _data,
		mizuiro::image::format_store<
			ImageFormat
		> const &_format
	)
	{
		return
			result_type(
				_data,
				_format.color_format()
			);
	}
};

}
}
}

#endif
