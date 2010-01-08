#ifndef MIZUIRO_COLOR_OBJECT_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_OBJECT_DECL_HPP_INCLUDED

#include <mizuiro/color/object_fwd.hpp>
#include <mizuiro/color/proxy_fwd.hpp>
#include <mizuiro//const_tag.hpp>
#include <mizuiro//nonconst_tag.hpp>
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
	typename Format
>
class object {
public:
	typedef Format format;

	typedef typename format:: template pointer<
		mizuiro::nonconst_tag
	>::type pointer;

	typedef typename format:: template pointer<
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
		MIZUIRO_COLOR_OBJECT_CONSTRUCTOR_MAX_SIZE,
		MIZUIRO_COLOR_OBJECT_MAKE_VARIADIC_CONSTRUCTOR_DECL_IMPL,
		void
	)

	#undef MIZUIRO_COLOR_OBJECT_MAKE_VARIADIC_CONSTRUCTOR_DECL_IMPL

	typedef typename Format:: template reference<
		mizuiro::nonconst_tag
	>::type proxy;

	typedef typename Format:: template reference<
		mizuiro::const_tag
	>::type const_proxy;

	template<
		typename Channel
	>
	void
	set(
		typename format:: template channel_value_type<
			Channel
		>::type const &
	);

	template<
		typename Channel
	>
	typename format:: template channel_reference<
		Channel,
		mizuiro::const_tag
	>::type
	get() const;

	pointer
	data();

	const_pointer
	data() const;
private:
	typedef typename format::store store;

	store data_;
};

}
}

#endif
