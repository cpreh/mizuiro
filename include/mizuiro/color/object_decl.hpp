#ifndef MIZUIRO_COLOR_OBJECT_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_OBJECT_DECL_HPP_INCLUDED

#include <mizuiro/color/object_fwd.hpp>
#include <mizuiro/color/object_constructor_max_params.hpp>
#include <mizuiro/color/proxy_fwd.hpp>
#include <mizuiro/color/types/store.hpp>
#include <mizuiro/color/types/channel_reference.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/access/normal.hpp>
#include <mizuiro/const_tag.hpp>
#include <mizuiro/nonconst_tag.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>

namespace mizuiro
{
namespace color
{

template<
	typename Format
>
class object
{
public:
	typedef Format format;

	typedef mizuiro::access::normal access;

	typedef typename color::types::pointer<
		access,
		format,
		mizuiro::nonconst_tag
	>::type pointer;

	typedef typename color::types::pointer<
		access,
		format,
		mizuiro::const_tag
	>::type const_pointer;

	object();

	object(
		object const &
	);

	#define MIZUIRO_COLOR_OBJECT_MAKE_VARIADIC_CONSTRUCTOR_DECL_IMPL(\
		z,\
		n,\
		text\
	)\
	template<\
		BOOST_PP_ENUM_PARAMS(\
			BOOST_PP_INC(n),\
			typename T\
		)\
	>\
	explicit object(\
		BOOST_PP_ENUM_BINARY_PARAMS(\
			BOOST_PP_INC(n),\
			T,\
			const &t\
		)\
	);

	BOOST_PP_REPEAT(
		MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_MAX_PARAMS,
		MIZUIRO_COLOR_OBJECT_MAKE_VARIADIC_CONSTRUCTOR_DECL_IMPL,
		void
	)

	#undef MIZUIRO_COLOR_OBJECT_MAKE_VARIADIC_CONSTRUCTOR_DECL_IMPL

	template<
		typename Channel
	>
	void
	set(
		typename types::channel_value<
			format,
			Channel
		>::type const &
	);

	template<
		typename Channel
	>
	typename types::channel_reference<
		access,
		format,
		Channel,
		mizuiro::const_tag
	>::type
	get() const;

	pointer
	data();

	const_pointer
	data() const;
private:
	typedef color::proxy<
		access,
		format,
		mizuiro::nonconst_tag
	> proxy;

	typedef color::proxy<
		access,
		format,
		mizuiro::const_tag
	> const_proxy;

	typedef typename color::types::store<
		access,
		format
	>::type store;

	store data_;
};

}
}

#endif
