//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DETAIL_ITERATOR_BASE_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_ITERATOR_BASE_HPP_INCLUDED

#include <mizuiro/difference_type.hpp>
#include <mizuiro/image/types/reference.hpp>
#include <mizuiro/image/types/value_type.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/iterator/iterator_facade.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Iterator,
	typename Access,
	typename Format,
	typename Constness,
	typename Category = boost::random_access_traversal_tag
>
struct iterator_base
{
	typedef boost::iterator_facade<
		Iterator,
		typename image::types::value_type<
			Format
		>::type,
		Category,
		typename image::types::reference<
			Access,
			Format,
			Constness
		>::type,
		difference_type
	> type;
};

}
}
}

#endif
