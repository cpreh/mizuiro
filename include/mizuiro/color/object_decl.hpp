#ifndef MIZUIRO_COLOR_OBJECT_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_OBJECT_DECL_HPP_INCLUDED

#include <mizuiro/color/object_fwd.hpp>
#include <mizuiro/color/proxy_fwd.hpp>
#include <mizuiro/color/detail/channel_ref.hpp>
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

	template<
		typename Channel
	>
	void
	set(
		typename detail::channel_ref<
			layout,
			Channel,
			mizuiro::detail::const_tag
		>::type 
	);

	template<
		typename Channel
	>
	typename detail::channel_ref<
		layout,
		Channel,
		mizuiro::detail::const_tag
	>::type
	get() const;

	typedef mizuiro::color::proxy<
		Layout
	> proxy_type;
private:
	typedef typename Layout::store store;

	store data_;
};

}
}

#endif
