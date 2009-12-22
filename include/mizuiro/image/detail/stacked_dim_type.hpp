#ifndef MIZUIRO_IMAGE_DETAIL_STACKED_DIM_TYPE_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_STACKED_DIM_TYPE_HPP_INCLUDED

#include <mizuiro/image/detail/pitch_type.hpp>
#include <mizuiro/image/dimension_decl.hpp>
#include <fcppt/tr1/array.hpp>

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Dim
>
struct stacked_dim_type {
	typedef std::tr1::array<
		typename Dim::value_type,
		detail::pitch_type<
			Dim
		>::type::static_size
	> type;
};

}
}
}

#endif
