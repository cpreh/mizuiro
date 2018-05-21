//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_PROXY_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_PROXY_DECL_HPP_INCLUDED

#include <mizuiro/const_tag.hpp>
#include <mizuiro/color/proxy_fwd.hpp>
#include <mizuiro/color/format/argument.hpp>
#include <mizuiro/color/format/base_decl.hpp>
#include <mizuiro/color/types/channel_reference.hpp>
#include <mizuiro/color/types/channel_value.hpp>
#include <mizuiro/color/types/pointer.hpp>


namespace mizuiro
{
namespace color
{

template<
	typename Access,
	typename Format,
	typename Constness
>
class proxy final
:
	private
		mizuiro::color::format::base<
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
	Access
	access;

	typedef
	Format
	format;

	typedef
	typename
	base::format_store_type
	format_store_type;

	typedef
	mizuiro::color::types::pointer<
		Access,
		Format,
		Constness
	>
	pointer;

	explicit
	proxy(
		pointer data,
		format_store_type const & =
			mizuiro::color::format::argument<
				Format
			>::get()
	);

	template<
		typename OtherConstness
	>
	explicit
	proxy(
		mizuiro::color::proxy<
			Access,
			Format,
			OtherConstness
		> const &
	);

	proxy(
		proxy const &
	);

	template<
		typename Other
	>
	proxy const &
	operator=(
		Other const &
	) const;

	proxy &
	operator=(
		proxy const &
	) = delete;

	proxy &
	operator=(
		proxy &&
	) = delete;

	template<
		typename Channel
	>
	void
	set(
		Channel const &,
		mizuiro::color::types::channel_value<
			Format,
			Channel
		> const &
	) const;

	template<
		typename Channel
	>
	mizuiro::color::types::channel_reference<
		Access,
		Format,
		Channel,
		mizuiro::const_tag
	>
	get(
		Channel const &
	) const;

	pointer
	data() const;

	format_store_type
	format_store() const;
private:
	pointer data_;
};

}
}

#endif
