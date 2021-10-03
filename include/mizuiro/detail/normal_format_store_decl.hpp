//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_NORMAL_FORMAT_STORE_DECL_HPP_INCLUDED
#define MIZUIRO_DETAIL_NORMAL_FORMAT_STORE_DECL_HPP_INCLUDED

#include <mizuiro/detail/copy_store.hpp>
#include <mizuiro/detail/normal_format_store_fwd.hpp>
#include <mizuiro/detail/ref_store.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace mizuiro::detail
{

template<
	typename Format
>
class normal_format_store<
	Format,
	mizuiro::detail::ref_store
>
{
public:
	using
	ref
	=
	std::reference_wrapper<
		Format const
	>;

	constexpr
	explicit
	normal_format_store(
		ref
	);

	Format const &
	get() const;
private:
	ref format_;
};

template<
	typename Format
>
class normal_format_store<
	Format,
	mizuiro::detail::copy_store
>
{
public:
	constexpr
	explicit
	normal_format_store(
		Format const &
	);

	Format const &
	get() const;
private:
	Format format_;
};

}

#endif
