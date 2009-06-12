#ifndef MIZUIRO_IMAGE_DIMENSION_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DIMENSION_DECL_HPP_INCLUDED

#include <mizuiro/image/dimension_fwd.hpp>
#include <mizuiro/size_type.hpp>
#include <boost/tr1/array.hpp>

namespace mizuiro
{
namespace image
{

template<
	mizuiro::size_type Dim
>
class dimension {
public:
	typedef mizuiro::size_type value_type;
	typedef mizuiro::size_type size_type;
	typedef value_type &reference;
	typedef value_type const &const_reference;

	typedef std::tr1::array<
		size_type,
		Dim
	> array_type;

	typedef typename array_type::iterator iterator;
	typedef typename array_type::const_iterator const_iterator;

	// TODO: ctor!
	dimension(
		int,
		int,
		int
	);
	
	iterator
	begin();

	iterator
	end();

	const_iterator
	begin() const;

	const_iterator
	end() const;

	size_type
	size() const;

	size_type
	content() const;

	reference
	operator[](
		size_type
	);

	const_reference
	operator[](
		size_type
	) const;

	static dimension const
	null();
private:
	array_type data_;
};

}
}

#endif
