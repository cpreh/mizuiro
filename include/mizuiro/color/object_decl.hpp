//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_OBJECT_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_OBJECT_DECL_HPP_INCLUDED

#include <mizuiro/const_tag.hpp>
#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/access/normal.hpp>
#include <mizuiro/color/format_argument.hpp>
#include <mizuiro/color/format_base_decl.hpp>
#include <mizuiro/color/format_store_decl.hpp>
#include <mizuiro/color/is_color.hpp>
#include <mizuiro/color/object_fwd.hpp>
#include <mizuiro/color/proxy_fwd.hpp>
#include <mizuiro/color/init/detail/values_fwd.hpp>
#include <mizuiro/color/types/channel_reference.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/color/types/pointer.hpp>
#include <mizuiro/color/types/store.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/null_ptr.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
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
	private mizuiro::color::format_base<
		Format
	>::type
{
	typedef typename mizuiro::color::format_base<
		Format
	>::type base;
public:
	typedef Format format;

	typedef typename base::format_store_type format_store_type;

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

	/// constructs an uninitialized color
	explicit object(
		format_store_type const & =
			mizuiro::color::format_argument<Format>::get()
	);

	object(
		object const &
	);

	/// Constructs a color from another color (possibly a view)
	template<
		typename Other
	>
	object(
		Other const &,
		typename boost::enable_if<
			mizuiro::color::is_color<
				Other
			>
		>::type * = mizuiro::detail::null_ptr()
	);

	/// Constructs a color from a special init expression
	template<
		typename Vector
	>
	object(
		mizuiro::color::init::detail::values<
			Vector
		> const &,
		format_store_type const & =
			mizuiro::color::format_argument<Format>::get()
	);

	template<
		typename Channel
	>
	void
	set(
		Channel const &,
		typename mizuiro::color::types::channel_value<
			format,
			Channel
		>::type const &
	);

	template<
		typename Channel
	>
	typename mizuiro::color::types::channel_reference<
		access,
		format,
		Channel,
		mizuiro::const_tag
	>::type
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

	format_store_type const
	format_store() const;
private:
	typedef mizuiro::color::proxy<
		access,
		format,
		mizuiro::nonconst_tag
	> proxy;

	typedef mizuiro::color::proxy<
		access,
		format,
		mizuiro::const_tag
	> const_proxy;

	proxy const
	make_proxy();

	const_proxy const
	make_const_proxy() const;

	typedef typename mizuiro::color::types::store<
		access,
		format
	>::type store;

	store data_;
};

MIZUIRO_DETAIL_POP_WARNING

}
}

#endif
