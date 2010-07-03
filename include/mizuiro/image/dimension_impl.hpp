//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_DIMENSION_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DIMENSION_IMPL_HPP_INCLUDED

#include <mizuiro/image/dimension_decl.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/static_assert.hpp>
#include <numeric>
#include <functional>
#include <algorithm>
#include <ostream>

#define MIZUIRO_IMAGE_DIMENSION_CONSTRUCTOR_ASSIGN(\
	z,\
	n,\
	text\
)\
data_[n] = text##n;

#define MIZUIRO_IMAGE_DIMENSION_CONSTRUCTOR_IMPL(\
	z,\
	n,\
	text\
)\
template< \
	mizuiro::size_type Dim,\
	typename ValueType\
>\
mizuiro::image::dimension<Dim, ValueType>::dimension(\
	BOOST_PP_ENUM_PARAMS(\
		BOOST_PP_INC(n),\
		const_reference param\
	)\
)\
:\
	data_()\
{\
	BOOST_STATIC_ASSERT(( \
		Dim == BOOST_PP_INC(n) \
	)); \
\
	BOOST_PP_REPEAT(\
		BOOST_PP_INC(n),\
		MIZUIRO_IMAGE_DIMENSION_CONSTRUCTOR_ASSIGN,\
		param\
	)\
}

BOOST_PP_REPEAT(
	MIZUIRO_IMAGE_DIMENSION_CONSTRUCTOR_MAX_SIZE,
	MIZUIRO_IMAGE_DIMENSION_CONSTRUCTOR_IMPL,
	void
)

#undef MIZUIRO_IMAGE_DIMENSION_CONSTRUCTOR_IMPL
#undef MIZUIRO_IMAGE_DIMENSION_CONSTRUCTOR_ASSIGN

template<
	mizuiro::size_type Dim,
	typename ValueType
>
mizuiro::image::dimension<Dim, ValueType>::dimension()
:
	data_()
{}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
typename mizuiro::image::dimension<Dim, ValueType>::iterator
mizuiro::image::dimension<Dim, ValueType>::begin()
{
	return data_.begin();
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
typename mizuiro::image::dimension<Dim, ValueType>::iterator
mizuiro::image::dimension<Dim, ValueType>::end()
{
	return data_.end();
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
typename mizuiro::image::dimension<Dim, ValueType>::const_iterator
mizuiro::image::dimension<Dim, ValueType>::begin() const
{
	return data_.begin();
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
typename mizuiro::image::dimension<Dim, ValueType>::const_iterator
mizuiro::image::dimension<Dim, ValueType>::end() const
{
	return data_.end();
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
typename mizuiro::image::dimension<Dim, ValueType>::size_type
mizuiro::image::dimension<Dim, ValueType>::size() const
{
	return data_.size();
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
typename mizuiro::image::dimension<Dim, ValueType>::size_type
mizuiro::image::dimension<Dim, ValueType>::content() const
{
	return
		std::accumulate(
			begin(),
			end(),
			1,
			std::multiplies<
				value_type
			>()
		);
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
typename mizuiro::image::dimension<Dim, ValueType>::reference
mizuiro::image::dimension<Dim, ValueType>::operator[](
	size_type const index
)
{
	return data_[index];
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
typename mizuiro::image::dimension<Dim, ValueType>::const_reference
mizuiro::image::dimension<Dim, ValueType>::operator[](
	size_type const index
) const
{
	return data_[index];
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
mizuiro::image::dimension<Dim, ValueType> const
mizuiro::image::dimension<Dim, ValueType>::null()
{
	dimension ret;

	for(
		size_type i = 0;
		i < static_size;
		++i
	)
		ret[i] = 0;

	return ret;
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
mizuiro::image::dimension<Dim, ValueType> const
mizuiro::image::operator+(
	dimension<Dim, ValueType> const &a,
	dimension<Dim, ValueType> const &b
)
{
	typedef dimension<Dim, ValueType> dim;

	dim ret;

	for(
		typename dim::size_type i = 0;
		i < dim::static_size;
		++i
	)
		ret[i] = a[i] + b[i];
	
	return ret;
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
bool
mizuiro::image::operator==(
	dimension<Dim, ValueType> const &a,
	dimension<Dim, ValueType> const &b
)
{
	return std::equal(
		a.begin(),
		a.end(),
		b.begin()
	);
}

template<
	mizuiro::size_type Dim,
	typename ValueType
>
bool
mizuiro::image::operator!=(
	dimension<Dim, ValueType> const &a,
	dimension<Dim, ValueType> const &b
)
{
	return !(a == b);
}

template<
	mizuiro::size_type Dim,
	typename ValueType,
	typename Ch,
	typename Traits
>
std::basic_ostream<Ch, Traits> &
mizuiro::image::operator<<(
	std::basic_ostream<Ch, Traits> &s,
	dimension<Dim, ValueType> const &d
)
{
	typedef dimension<
		Dim,
		ValueType
	> dim_type;

	s << s.widen('(');

	for(
		typename dim_type::size_type i = 0;
		i < dim_type::static_size;
		++i
	)
	{
		s << d[i];

		if(
			i != dim_type::static_size - 1
		)
			s << s.widen(',');
	}

	s << s.widen(')');

	return s;
}

#endif
