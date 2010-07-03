//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_TRANSFORM_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_TRANSFORM_HPP_INCLUDED

#include <mizuiro/config.hpp>
#include <mizuiro/image/algorithm/transform_binary.hpp>
#ifdef MIZUIRO_HAVE_FCPPT
#include <mizuiro/image/algorithm/transform_ternary.hpp>
#endif

namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename ViewS,
	typename ViewD,
	typename Fun
>
void
transform(
	ViewS const &source,
	ViewD const &dest,
	Fun const &fun
)
{
	transform_binary(
		source,
		dest,
		fun
	);
}

#ifdef MIZUIRO_HAVE_FCPPT
template<
	typename ViewS1,
	typename ViewS2,
	typename ViewD,
	typename Fun
>
void
transform(
	ViewS1 const &source1,
	ViewS2 const &source2,
	ViewD const &dest,
	Fun const &fun
)
{
	transform_ternary(
		source1,
		source2,
		dest,
		fun
	);
}
#endif

}
}
}

#endif
