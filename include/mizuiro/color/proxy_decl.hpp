//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_PROXY_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_PROXY_DECL_HPP_INCLUDED

#include <mizuiro/const_tag.hpp>
#include <mizuiro/color/format_argument.hpp>
#include <mizuiro/color/format_base_decl.hpp>
#include <mizuiro/color/proxy_fwd.hpp>
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
class proxy
:
	private color::format_base<
		Format
	>::type
{
	typedef typename color::format_base<
		Format
	>::type base;
public:
	typedef Access access;

	typedef Format format;

	typedef typename base::format_store_type format_store_type;

	typedef typename color::types::pointer<
		Access,
		Format,
		Constness
	>::type pointer;

	proxy(
		pointer data,
		format_store_type const & =
			color::format_argument<Format>::get()
	);

	template<
		typename OtherConstness
	>
	proxy(
		color::proxy<
			Access,
			Format,
			OtherConstness
		> const &
	);

	template<
		typename Other
	>
	proxy const &
	operator=(
		Other const &
	) const;

	template<
		typename Channel
	>
	void
	set(
		Channel const &,
		typename types::channel_value<
			Format,
			Channel
		>::type const &
	) const;

	template<
		typename Channel
	>
	typename types::channel_reference<
		Access,
		Format,
		Channel,
		mizuiro::const_tag
	>::type
	get(
		Channel const &
	) const;

	pointer
	data() const;

	format_store_type const
	format_store() const;
private:
	pointer data_;
};

}
}

#endif
