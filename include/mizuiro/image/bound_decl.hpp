#ifndef MIZUIRO_IMAGE_BOUND_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_BOUND_DECL_HPP_INCLUDED

#include <mizuiro/image/bound_fwd.hpp>
#include <mizuiro/image/dimension_decl.hpp>
#include <mizuiro/size_type.hpp>

namespace mizuiro
{
namespace image
{

template<
	mizuiro::size_type Dim,
	typename ValueType
>
class bound {
public:
	typedef ValueType value_type;
	typedef mizuiro::size_type size_type;

	typedef dimension<
		Dim,
		value_type
	> dim_type;

	bound(
		dim_type const &positions,
		dim_type const &dimensions
	);

	dim_type const &
	positions() const;

	dim_type const &
	dimensions() const;
private:
	dim_type
		positions_,
		dimensions_;
};

}
}

#endif
