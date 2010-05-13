#ifndef MIZUIRO_COLOR_OBJECT_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_OBJECT_IMPL_HPP_INCLUDED

#include <mizuiro/color/object_decl.hpp>
#include <mizuiro/color/proxy_impl.hpp>
#include <mizuiro/color/detail/init_set_channel.hpp>
#include <mizuiro/access/homogenous_normal.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>

template<
	typename Format
>
mizuiro::color::object<Format>::object()
:
	data_()
{}

template<
	typename Format
>
mizuiro::color::object<Format>::object(
	object const &other
)
:
	data_(other.data_)
{}

#define MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_ASSIGN(\
	z,\
	n,\
	text\
)\
{\
	detail::init_set_channel(\
		*this,\
		t##n\
	);\
}

#define MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_IMPL(\
	z,\
	n,\
	text\
)\
template<\
	typename Format\
>\
template<\
	BOOST_PP_ENUM_PARAMS(\
		BOOST_PP_INC(n),\
		typename T\
	)\
>\
mizuiro::color::object<Format>::object(\
	BOOST_PP_ENUM_BINARY_PARAMS(\
		BOOST_PP_INC(n),\
		T,\
		const &t\
	)\
)\
:\
	data_()\
{\
	BOOST_PP_REPEAT(\
		BOOST_PP_INC(n),\
		MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_ASSIGN,\
		t\
	)\
}

BOOST_PP_REPEAT(
	MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_MAX_PARAMS,
	MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_IMPL,
	void
)

#undef MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_IMPL
#undef MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_ASSIGN

template<
	typename Format
>
template<
	typename Channel
>
void
mizuiro::color::object<Format>::set(
	typename types::channel_value<
		format,
		Channel
	>::type const &ref
)
{
	proxy(
		data_.data()
	).set<
		Channel
	>(
		ref
	);
}

template<
	typename Format
>
template<
	typename Channel
>
typename mizuiro::color::types::channel_reference<
	typename mizuiro::color::object<
		Format
	>::access,
	typename mizuiro::color::object<
		Format
	>::format,
	Channel,
	mizuiro::const_tag
>::type
mizuiro::color::object<Format>::get() const
{
	return
		const_proxy(
			data_.data()
		).get<
			Channel
		>();
}

template<
	typename Format
>
typename mizuiro::color::object<
	Format
>::pointer
mizuiro::color::object<Format>::data()
{
	return data_.data();
}

template<
	typename Format
>
typename mizuiro::color::object<
	Format
>::const_pointer
mizuiro::color::object<Format>::data() const
{
	return data_.data();
}

#endif
