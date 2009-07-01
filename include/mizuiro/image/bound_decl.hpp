#ifndef MIZUIRO_IMAGE_BOUND_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_BOUND_DECL_HPP_INCLUDED

#include <mizuiro/image/bound_fwd.hpp>
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
	typedef value_type &reference;
	typedef value_type const &const_reference;

	typedef std::tr1::array<
		value_type,
		Dim
	> array_type;

	reference
	operator[](
		size_type
	);

	const_reference
	operator[](
		size_type
	) const;
private:
	
};

}
}

#endif
