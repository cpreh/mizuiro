//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_OBJECT_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_OBJECT_DECL_HPP_INCLUDED

#include <mizuiro/const_tag_fwd.hpp>
#include <mizuiro/default_init_fwd.hpp>
#include <mizuiro/no_init_fwd.hpp>
#include <mizuiro/nonconst_tag_fwd.hpp>
#include <mizuiro/access/normal.hpp>
#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/object_fwd.hpp>
#include <mizuiro/color/proxy_fwd.hpp>
#include <mizuiro/color/format/argument.hpp>
#include <mizuiro/color/format/base_decl.hpp>
#include <mizuiro/color/format/store_decl.hpp>
#include <mizuiro/color/init/detail/values_fwd.hpp>
#include <mizuiro/color/types/channel_reference.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/color/types/store.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace mizuiro
{
namespace color
{

/**
\brief A color object stores a color by value

mizuiro::color::object is a class that can be used to store a color by value.

\tparam Format specifies the color format
*/
template<
	typename Format
>
class object final
:
	private
		mizuiro::color::format::base<
			Format
		>
{
	using
	base
	=
	mizuiro::color::format::base<
		Format
	>;
public:
	using
	format
	=
	Format;

	using
	format_store_type
	=
	typename
	base::format_store_type;

	using
	access
	=
	mizuiro::access::normal;

	using
	pointer
	=
	mizuiro::color::types::pointer<
		access,
		format,
		mizuiro::nonconst_tag
	>;

	using
	const_pointer
	=
	mizuiro::color::types::pointer<
		access,
		format,
		mizuiro::const_tag
	>;

	FCPPT_PP_PUSH_WARNING
	FCPPT_PP_DISABLE_VC_WARNING(4686)

	/// constructs an uninitialized color
	explicit
	object(
		mizuiro::no_init const &,
		format_store_type const & =
			mizuiro::color::format::argument<
				Format
			>::get()
	);

	explicit
	object(
		mizuiro::default_init const &,
		format_store_type const & =
			mizuiro::color::format::argument<
				Format
			>::get()
	);

	FCPPT_PP_POP_WARNING

	/// Constructs a color from another color (possibly a view)
	template<
		typename Other,
		typename =
			std::enable_if_t<
				mizuiro::color::is_color<
					Other
				>::value
			>
	>
	explicit
	object(
		Other const &
	);

	FCPPT_PP_PUSH_WARNING
	FCPPT_PP_DISABLE_VC_WARNING(4686)

	/// Constructs a color from a special init expression
	template<
		typename Vector
	>
	explicit
	object(
		mizuiro::color::init::detail::values<
			Vector
		> const &,
		format_store_type const & =
			mizuiro::color::format::argument<
				Format
			>::get()
	);

	FCPPT_PP_POP_WARNING

	template<
		typename Channel
	>
	void
	set(
		Channel const &,
		mizuiro::color::types::channel_value<
			format,
			Channel
		> const &
	);

	template<
		typename Channel
	>
	[[nodiscard]]
	mizuiro::color::types::channel_reference<
		access,
		format,
		Channel,
		mizuiro::const_tag
	>
	get(
		Channel const &
	) const;

	/// ponter to the internal data
	[[nodiscard]]
	pointer
	data();

	/// const pointer to the internal data
	[[nodiscard]]
	const_pointer
	data() const;

	[[nodiscard]]
	constexpr
	format_store_type
	format_store() const;
private:
	template<
		typename Other
	>
	explicit
	object(
		Other const &,
		std::false_type
	);

	template<
		typename Other
	>
	explicit
	object(
		Other const &,
		std::true_type
	);

	template<
		typename Vector
	>
	explicit
	object(
		mizuiro::color::init::detail::values<
			Vector
		> const &,
		std::false_type,
		format_store_type const &
	);

	template<
		typename Vector
	>
	explicit
	object(
		mizuiro::color::init::detail::values<
			Vector
		> const &,
		std::true_type,
		format_store_type const &
	);

	using
	proxy
	=
	mizuiro::color::proxy<
		access,
		format,
		mizuiro::nonconst_tag
	>;

	using
	const_proxy
	=
	mizuiro::color::proxy<
		access,
		format,
		mizuiro::const_tag
	>;

	proxy
	make_proxy();

	const_proxy
	make_const_proxy() const;

	using
	store
	=
	mizuiro::color::types::store<
		format
	>;

	store data_;
};

}
}

#endif
