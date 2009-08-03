#ifndef MIZUIRO_COLOR_OBJECT_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_OBJECT_IMPL_HPP_INCLUDED

#include <mizuiro/color/object_decl.hpp>
#include <mizuiro/color/proxy_impl.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/static_assert.hpp>

template<
	typename Layout
>
mizuiro::color::object<Layout>::object()
:
	data_()
{}

template<
	typename Layout
>
mizuiro::color::object<Layout>::object(
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
	BOOST_STATIC_ASSERT((\
		boost::is_same<\
			typename layout:: template channel_value_type<\
				typename T##n::channel\
			>::type,\
			typename T##n::value_type\
		>::value\
	));\
	set<\
		typename T##n::channel\
	>(\
		t##n.value()\
	);\
}

#define MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_IMPL(\
	z,\
	n,\
	text\
)\
template<\
	typename Layout\
>\
template<\
	BOOST_PP_ENUM_PARAMS(\
		BOOST_PP_INC(n),\
		typename T\
	)\
>\
mizuiro::color::object<Layout>::object(\
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
	MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_MAX_SIZE,
	MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_IMPL,
	void
)

#undef MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_IMPL
#undef MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_ASSIGN

template<
	typename Layout
>
template<
	typename Channel
>
void
mizuiro::color::object<Layout>::set(
	typename Layout::template channel_value_type<
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
	typename Layout
>
template<
	typename Channel
>
typename Layout:: template channel_reference<
	Channel,
	mizuiro::detail::const_tag
>::type
mizuiro::color::object<Layout>::get() const
{
	return const_proxy(
		data_.data()
	).get<
		Channel
	>();
}

#endif
