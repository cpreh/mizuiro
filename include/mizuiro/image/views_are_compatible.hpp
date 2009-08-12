#ifndef MIZUIRO_IMAGE_VIEWS_ARE_COMPATIBLE_HPP_INCLUDED
#define MIZUIRO_IMAGE_VIEWS_ARE_COMPATIBLE_HPP_INCLUDED

#include <mizuiro/color/channel_value_type.hpp>
#include <boost/mpl/fold.hpp>
#include <boost/mpl/zip_view.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/back.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/bind.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/quote.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/integral_constant.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename View1,
	typename View2
>
struct views_are_compatible
:
boost::mpl::and_<
	boost::is_same<
		typename View1::dim_type,
		typename View2::dim_type
	>,
	boost::mpl::fold<
		boost::mpl::zip_view<
			boost::mpl::vector<
				typename View1::color_format::layout::order,
				typename View2::color_format::layout::order
			>
		>,
		boost::true_type,
		boost::mpl::and_<
			boost::mpl::_1,
			boost::mpl::bind<
				boost::mpl::quote2<
					boost::is_same
				>,
				boost::mpl::bind<
					boost::mpl::quote2<
						color::channel_value_type
					>,
					typename View1::color_format,
					boost::mpl::front<
						boost::mpl::_2
					>
				>,
				boost::mpl::bind<
					boost::mpl::quote2<
						color::channel_value_type
					>,
					typename View2::color_format,
					boost::mpl::back<
						boost::mpl::_2
					>
				>
			>
		>
	>
>
{};

}
}

#endif
