//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_IS_LINEAR_ITERATOR_HPP_INCLUDED
#define MIZUIRO_IMAGE_IS_LINEAR_ITERATOR_HPP_INCLUDED

#include <mizuiro/image/linear_iterator_fwd.hpp>
#include <boost/type_traits/integral_constant.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Iterator
>
struct is_linear_iterator
:
boost::false_type
{};

template<
	typename Access,
	typename Format,
	typename Constness
>
struct is_linear_iterator<
	linear_iterator<
		Access,
		Format,
		Constness
	>
>
:
boost::true_type
{};

}
}

#endif
