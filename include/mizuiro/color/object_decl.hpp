//          Copyright Carl Philipp Reh 2009 - 2010.
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
#include <mizuiro/detail/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <mizuiro/detail/external_end.hpp>


namespace mizuiro
{
namespace color
{

/// A color object that stores a color by value
/**
 * color::object is a class that can be used to store a color value.
 * @tparam Format specifies the color format
*/
template<
	typename Format
>
class object
:
	private color::format_base<
		Format
	>::type
{
	typedef typename color::format_base<
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
			color::format_argument<Format>::get()
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
			color::is_color<
				Other
			>
		>::type * = 0
	);

	/// Constructs a color from a special init expression
	template<
		typename Vector
	>
	object(
		init::detail::values<
			Vector
		> const &,
		format_store_type const & =
			color::format_argument<Format>::get()
	);

	/// Sets a color channel denoted by @tparam Channel
	template<
		typename Channel
	>
	void
	set(
		Channel const &,
		typename types::channel_value<
			format,
			Channel
		>::type const &
	);

	/// Gets a color channel denoted by @tparam Channel
	template<
		typename Channel
	>
	typename types::channel_reference<
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

	format_store_type const
	format_store() const;
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
