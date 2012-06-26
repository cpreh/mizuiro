//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ACCESS_DEREFERENCE_HPP_INCLUDED
#define MIZUIRO_IMAGE_ACCESS_DEREFERENCE_HPP_INCLUDED


namespace mizuiro
{
namespace image
{
namespace access
{

template<
	typename Access,
	typename ImageFormat,
	typename Constness,
	typename Enable = void
>
struct dereference;

}
}
}

#endif
