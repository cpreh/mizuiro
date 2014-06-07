//          Copyright Carl Philipp Reh 2009 - 2014.
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
using
iterator_base
=
boost::iterator_facade<
	Iterator,
	mizuiro::image::types::value_type<
		Format
	>,
	Category,
	mizuiro::image::types::reference<
		Access,
		Format,
		Constness
	>,
	mizuiro::difference_type
>;

}
}
}

#endif
