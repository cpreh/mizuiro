#ifndef MIZUIRO_IMAGE_DIMENSION_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DIMENSION_DECL_HPP_INCLUDED

#include <mizuiro/image/dimension_fwd.hpp>
#include <mizuiro/size_type.hpp>
#include <tr1/array>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <iosfwd>

#ifndef MIZUIRO_IMAGE_DIMENSION_CONSTRUCTOR_MAX_SIZE
#define MIZUIRO_IMAGE_DIMENSION_CONSTRUCTOR_MAX_SIZE 3
#endif

namespace mizuiro
{
namespace image
{

template<
	mizuiro::size_type Dim,
	typename ValueType
>
class dimension {
public:
	typedef ValueType value_type;
	typedef mizuiro::size_type size_type;
	typedef value_type &reference;
	typedef value_type const &const_reference;

	typedef std::tr1::array<
		value_type,
		Dim
	> array_type;

	static size_type const static_size = Dim;

	typedef typename array_type::iterator iterator;
	typedef typename array_type::const_iterator const_iterator;

	#define MIZUIRO_IMAGE_DIMENSION_MAKE_VARIADIC_CONSTRUCTOR_DECL_IMPL(\
		z,\
		n,\
		text\
	)\
	dimension(\
		BOOST_PP_ENUM_PARAMS(\
			BOOST_PP_INC(n),\
			const_reference param\
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

template<
	mizuiro::size_type Dim,
	typename ValueType
>
dimension<Dim, ValueType> const
operator+(
	dimension<Dim, ValueType> const &,
	dimension<Dim, ValueType> const &
);

template<
	mizuiro::size_type Dim,
	typename ValueType
>
bool
operator==(
	dimension<Dim, ValueType> const &,
	dimension<Dim, ValueType> const &
);

template<
	mizuiro::size_type Dim,
	typename ValueType
>
bool
operator!=(
	dimension<Dim, ValueType> const &,
	dimension<Dim, ValueType> const &
);

template<
	mizuiro::size_type Dim,
	typename ValueType,
	typename Ch,
	typename Traits
>
std::basic_ostream<Ch, Traits> &
operator<<(
	std::basic_ostream<Ch, Traits> &,
	dimension<Dim, ValueType> const &
);

}
}

#endif
