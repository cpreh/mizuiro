#ifndef MIZUIRO_IMAGE_FLIPPED_VIEW_HPP_INCLUDED
#define MIZUIRO_IMAGE_FLIPPED_VIEW_HPP_INCLUDED

#include <mizuiro/image/view_impl.hpp>
#include <mizuiro/image/dimension_impl.hpp>
#include <mizuiro/image/move_iterator.hpp>
#include <boost/utility/enable_if.hpp>
#include <iterator>

#include <iostream>

namespace mizuiro
{
namespace image
{

template<
	typename View
>
typename boost::enable_if_c<
	View::dim_type::static_size == 2,
	View const
>::type
flipped_view(
	View const &view
)
{
	typedef typename View::dim_type dim_type;

	typename dim_type::value_type const height(
		view.dim()[1]
	);

		typename View::pitch_type const pitch_(
					std::distance(
						move_iterator(
							view,
							dim_type(
								view.dim()[0],
								1
							)
						).data(),
						view.begin().data()
					)
					+ view.pitch()[0]
				);

	std::cerr << pitch_ << '\n';

	return
		height > 1
		?
			View(
				view.dim(),
				move_iterator(
					view,
					dim_type(
						0,
						height - 1
					)
				).data(),
				pitch_
				/*typename View::pitch_type(
					std::distance(
						move_iterator(
							view,
							dim_type(
								view.dim()[0],
								1
							)
						).data(),
						view.begin().data()
					)
					+ view.pitch()[0]
				)*/
			)
		:
			view;
}

}
}

#endif
