#ifndef MIZUIRO_IMAGE_DIMENSION_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DIMENSION_DECL_HPP_INCLUDED

#include <mizuiro/image/dimension_fwd.hpp>
#include <mizuiro/size_type.hpp>
#include <boost/tr1/array.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>

#ifndef MIZUIRO_IMAGE_DIMENSION_CONSTRUCTOR_MAX_SIZE
#define MIZUIRO_IMAGE_DIMENSION_CONSTRUCTOR_MAX_SIZE 3
#endif

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

	#define MIZUIRO_IMAGE_DIMENSION_MAKE_VARIADIC_CONSTRUCTOR_DECL_IMPL(\
		z,\
		n,\
		text\
	)\
	dimension(\
		BOOST_PP_ENUM_PARAMS_Z(\
			BOOST_PP_INC(n),\
			const_reference param,\
			text\
		)\
	);

	BOOST_PP_REPEAT(
		MIZUIRO_IMAGE_DIMENSION_CONSTRUCTOR_MAX_SIZE,
		MIZUIRO_IMAGE_DIMENSION_MAKE_VARIADIC_CONSTRUCTOR_DECL_IMPL,
		void
	)

	#undef MIZUIRO_IMAGE_DIMENSION_MAKE_VARIADIC_CONSTRUCTOR_DECL_IMPL

	dimension();
	
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
