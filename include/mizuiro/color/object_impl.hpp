#ifndef MIZUIRO_COLOR_OBJECT_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_OBJECT_IMPL_HPP_INCLUDED

#include <mizuiro/color/object_decl.hpp>
#include <mizuiro/color/proxy_impl.hpp>

#define MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_ASSIGN(\
	z,\
	n,\
	text\
)\
data_[n] = text##n;

#define MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_IMPL(\
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
		MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_ASSIGN,\
		param\
	)\
}

BOOST_PP_REPEAT(
	MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_MAX_SIZE,
	MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_IMPL,
	void
)

#undef MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_IMPL
#undef MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_ASSIGN


template< typename Layout
>
template<
	typename Channel
>
void
mizuiro::color::object<Layout>::set(
	typename detail::channel_ref<
		layout,
		Channel,
		mizuiro::detail::const_tag
	>::type const ref
)
{
	proxy_type(
		data_
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
typename mizuiro::color::detail::channel_ref<
	Layout,
	Channel,
	mizuiro::detail::const_tag
>::type
mizuiro::color::object<Layout>::get() const
{
	return proxy_type(
		data_
	).get<
		Channel
	>();
}

#endif
