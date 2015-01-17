//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_VIEW_SIZE_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_VIEW_SIZE_HPP_INCLUDED


namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Dim
>
struct view_size
{
	typedef
	Dim
	result_type;

	template<
		typename View
	>
	result_type const
	operator()(
		View const &_view
	) const
	{
		return
			_view.size();
	}
};

}
}
}

#endif
