//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_BOUND_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_BOUND_DECL_HPP_INCLUDED

#include <mizuiro/size_type.hpp>
#include <mizuiro/image/bound_fwd.hpp>
#include <mizuiro/image/dimension_decl.hpp>


namespace mizuiro
{
namespace image
{

template<
	mizuiro::size_type Dim,
	typename ValueType
>
class bound
{
public:
	typedef ValueType value_type;
	typedef mizuiro::size_type size_type;

	typedef dimension<
		Dim,
		value_type
	> dim;

	bound(
		dim const &pos,
		dim const &size
	);

	dim const &
	pos() const;

	dim const &
	size() const;
private:
	dim
		pos_,
		size_;
};

}
}

#endif
