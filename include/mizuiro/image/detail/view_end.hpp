//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_VIEW_END_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_VIEW_END_HPP_INCLUDED


namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Iterator
>
struct view_end
{
	typedef
	Iterator
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
			Iterator(
				typename
				Iterator::impl{
					typename
					Iterator::impl::internal_type{
						_view.end()
					}
				}
			);
	}
};

}
}
}

#endif
