#ifndef MIZUIRO_COLOR_OBJECT_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_OBJECT_DECL_HPP_INCLUDED

#include <mizuiro/color/object_fwd.hpp>
#include <mizuiro/color/proxy_fwd.hpp>
#include <mizuiro/detail/nonconst_tag.hpp>
#include <mizuiro/detail/const_tag.hpp>
#include <boost/preprocessor/arithmetic/inc.hpp>
#include <boost/preprocessor/repetition/enum_binary_params.hpp>
#include <boost/preprocessor/repetition/enum_params.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>

#ifndef MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_MAX_SIZE
#define MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_MAX_SIZE 4
#endif

namespace mizuiro
{
namespace color
{

template<
	typename Layout
>
class object {
public:
	typedef Layout layout;

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
	object(\
		BOOST_PP_ENUM_BINARY_PARAMS(\
			BOOST_PP_INC(n),\
			T,\
			const &t\
		)\
	);

	BOOST_PP_REPEAT(
		MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_MAX_SIZE,
		MIZUIRO_COLOR_OBJECT_MAKE_VARIADIC_CONSTRUCTOR_DECL_IMPL,
		void
	)

	#undef MIZUIRO_COLOR_OBJECT_MAKE_VARIADIC_CONSTRUCTOR_DECL_IMPL

	typedef typename Layout:: template reference<
		mizuiro::detail::nonconst_tag
	>::type proxy;

	typedef typename Layout:: template reference<
		mizuiro::detail::const_tag
	>::type const_proxy;

	template<
		typename Channel
	>
	void
	set(
		typename layout:: template channel_value_type<
			Channel
		>::type const &
	);

	template<
		typename Channel
	>
	typename layout:: template channel_reference<
		Channel,
		mizuiro::detail::const_tag
	>::type
	get() const;
private:
	typedef typename Layout::store store;

	store data_;
};

}
}

#endif
