//          Copyright Carl Philipp Reh 2009 - 2014.
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
#include <mizuiro/color/types/store_needs_init.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <type_traits>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{

MIZUIRO_DETAIL_IGNORE_EFFCPP

/**
\brief A color object stores a color by value

mizuiro::color::object is a class that can be used to store a color by value.

\tparam Format specifies the color format
*/
template<
	typename Format
>
class object
:
	private mizuiro::color::format::base<
		Format
	>
{
	typedef
	mizuiro::color::format::base<
		Format
	>
	base;
public:
	typedef
	Format
	format;

	typedef
	typename
	base::format_store_type
	format_store_type;

	typedef
	mizuiro::access::normal
	access;

	typedef
	mizuiro::color::types::pointer<
		access,
		format,
		mizuiro::nonconst_tag
	>
	pointer;

	typedef
	mizuiro::color::types::pointer<
		access,
		format,
		mizuiro::const_tag
	>
	const_pointer;

	/// constructs an uninitialized color
	template<
		typename FormatArg = Format
	>
	explicit
	object(
		mizuiro::no_init const &,
		format_store_type const & =
			mizuiro::color::format::argument<
				Format
			>::get(),
		typename std::enable_if<
			!mizuiro::color::types::store_needs_init<
				FormatArg
			>::value
		>::type * = nullptr
	);

	explicit
	object(
		mizuiro::default_init const &,
		format_store_type const & =
			mizuiro::color::format::argument<
				Format
			>::get()
	);

	object(
		object const &
	);

	/// Constructs a color from another color (possibly a view)
	template<
		typename Other,
		typename FormatArg = Format
	>
	object(
		Other const &,
		typename std::enable_if<
			mizuiro::color::is_color<
				Other
			>::value
			&&
			!mizuiro::color::types::store_needs_init<
				FormatArg
			>::value
		>::type * = nullptr
	);

	template<
		typename Other,
		typename FormatArg = Format
	>
	object(
		Other const &,
		typename std::enable_if<
			mizuiro::color::is_color<
				Other
			>::value
			&&
			mizuiro::color::types::store_needs_init<
				FormatArg
			>::value
		>::type * = nullptr
	);

	/// Constructs a color from a special init expression
	template<
		typename Vector,
		typename FormatArg = Format
	>
	explicit
	object(
		mizuiro::color::init::detail::values<
			Vector
		> const &,
		format_store_type const & =
			mizuiro::color::format::argument<
				Format
			>::get(),
		typename std::enable_if<
			!mizuiro::color::types::store_needs_init<
				FormatArg
			>::value
		>::type * = nullptr
	);

	template<
		typename Vector,
		typename FormatArg = Format
	>
	explicit
	object(
		mizuiro::color::init::detail::values<
			Vector
		> const &,
		format_store_type const & =
			mizuiro::color::format::argument<
				Format
			>::get(),
		typename std::enable_if<
			mizuiro::color::types::store_needs_init<
				FormatArg
			>::value
		>::type * = nullptr
	);

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
	pointer
	data();

	/// const pointer to the internal data
	const_pointer
	data() const;

	pointer
	data_end();

	const_pointer
	data_end() const;

	constexpr
	format_store_type const
	format_store() const;
private:
	typedef
	mizuiro::color::proxy<
		access,
		format,
		mizuiro::nonconst_tag
	>
	proxy;

	typedef
	mizuiro::color::proxy<
		access,
		format,
		mizuiro::const_tag
	>
	const_proxy;

	proxy const
	make_proxy();

	const_proxy const
	make_const_proxy() const;

	typedef
	mizuiro::color::types::store<
		format
	>
	store;

	store data_;
};

MIZUIRO_DETAIL_POP_WARNING

}
}

#endif
