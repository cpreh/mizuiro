#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_COPY_RAW_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_COPY_RAW_HPP_INCLUDED

#include <mizuiro/image/algorithm/detail/apply_binary_iteration.hpp>
#include <mizuiro/image/algorithm/detail/copy_element.hpp>
#include <mizuiro/image/is_linear_range.hpp>
#include <mizuiro/image/iterator_color_data.hpp>
#include <mizuiro/detail/copy.hpp>
#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>

namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

struct copy_raw
{
	typedef void result_type;

	template<
		typename RangeS,
		typename RangeD
	>
	typename boost::disable_if<
		boost::mpl::and_<
			is_linear_range<
				RangeS
			>,
			is_linear_range<
				RangeD
			>
		>,
		result_type
	>::type
	operator()(
		RangeS const &source,
		RangeD const &dest
	) const
	{
		// TODO: optimize this as well!
		apply_binary_iteration(
			detail::copy_element()
		)(
			source,
			dest
		);
	}

	template<
		typename RangeS,
		typename RangeD
	>
	typename boost::enable_if<
		boost::mpl::and_<
			is_linear_range<
				RangeS
			>,
			is_linear_range<
				RangeD
			>
		>,
		result_type
	>::type
	operator()(
		RangeS const &src,
		RangeD const &dest
	) const
	{
		mizuiro::detail::copy(
			iterator_color_data(
				src.begin()
			),
			iterator_color_data(
				src.end()
			),
			iterator_color_data(
				dest.begin()
			)
		);
	}
};

}
}
}
}

#endif
