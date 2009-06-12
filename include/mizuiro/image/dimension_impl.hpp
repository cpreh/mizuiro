#ifndef MIZUIRO_IMAGE_DIMENSION_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_DIMENSION_IMPL_HPP_INCLUDED

#include <mizuiro/image/dimension_decl.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/foreach.hpp>
#include <numeric>
#include <functional>

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
	mizuiro::size_type Dim\
>\
mizuiro::image::dimension<Dim>::dimension(\
	BOOST_PP_ENUM_PARAMS(\
		BOOST_PP_INC(n),\
		const_reference param\
	)\
)\
:\
	data_()\
{\
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
	mizuiro::size_type Dim
>
mizuiro::image::dimension<Dim>::dimension()
:
	data_()
{}

template<
	mizuiro::size_type Dim
>
typename mizuiro::image::dimension<Dim>::iterator
mizuiro::image::dimension<Dim>::begin()
{
	return data_.begin();
}

template<
	mizuiro::size_type Dim
>
typename mizuiro::image::dimension<Dim>::iterator
mizuiro::image::dimension<Dim>::end()
{
	return data_.end();
}

template<
	mizuiro::size_type Dim
>
typename mizuiro::image::dimension<Dim>::const_iterator
mizuiro::image::dimension<Dim>::begin() const
{
	return data_.begin();
}

template<
	mizuiro::size_type Dim
>
typename mizuiro::image::dimension<Dim>::const_iterator
mizuiro::image::dimension<Dim>::end() const
{
	return data_.end();
}

template<
	mizuiro::size_type Dim
>
typename mizuiro::image::dimension<Dim>::size_type
mizuiro::image::dimension<Dim>::size() const
{
	return data_.size();
}

template<
	mizuiro::size_type Dim
>
typename mizuiro::image::dimension<Dim>::size_type
mizuiro::image::dimension<Dim>::content() const
{
	return std::accumulate(
		begin(),
		end(),
		1,
		std::multiplies<
			value_type
		>()
	);
}

template<
	mizuiro::size_type Dim
>
typename mizuiro::image::dimension<Dim>::reference
mizuiro::image::dimension<Dim>::operator[](
	size_type const index
)
{
	return data_[index];
}

template<
	mizuiro::size_type Dim
>
typename mizuiro::image::dimension<Dim>::const_reference
mizuiro::image::dimension<Dim>::operator[](
	size_type const index
) const
{
	return data_[index];
}

template<
	mizuiro::size_type Dim
>
mizuiro::image::dimension<Dim> const
mizuiro::image::dimension<Dim>::null()
{
	dimension ret;

	BOOST_FOREACH(
		reference r,
		ret.data_
	)
		r = 0;
	
	return ret;
}

#endif
