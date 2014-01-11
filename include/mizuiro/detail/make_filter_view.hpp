//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_MAKE_FILTER_VIEW_HPP_INCLUDED
#define MIZUIRO_DETAIL_MAKE_FILTER_VIEW_HPP_INCLUDED

#include <mizuiro/detail/external_begin.hpp>
#include <boost/fusion/view/filter_view/filter_view.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename Pred,
	typename Seq
>
boost::fusion::filter_view<
	Seq const,
	Pred
> const
make_filter_view(
	Seq const &_seq
)
{
	return
		boost::fusion::filter_view<
			Seq const,
			Pred
		>(
			_seq
		);
}

}
}

#endif
