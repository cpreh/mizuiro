#ifndef MIZURIO_IMAGE_DETAIL_SUB_VIEW_OFFSET_HPP_INCLUDED
#define MIZURIO_IMAGE_DETAIL_SUB_VIEW_OFFSET_HPP_INCLUDED

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename View
>
typename View::dim_type::value_type
subview_offset(
	View const &view,
	typename View::bound_type const &bound
)
{
	typedef typename View::dim_type dim_type;

	typename dim_type::value_type ret(0);

	dim_type const &dim(
		bound.offsets()
	);

	for(
		typename dim_type::size_type i = 0;
		i < dim_type::static_dim;
		++i
	)
		ret +=
			std::accumulate(
				dim.begin(),
				dim.begin() + i,
				1,
				std::multiplies<
					typename dim_type::size_type
				>()
			);
	return ret;
}

}
}
}

#endif
