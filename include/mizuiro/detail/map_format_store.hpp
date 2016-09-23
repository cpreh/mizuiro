//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_MAP_FORMAT_STORE_HPP_INCLUDED
#define MIZUIRO_DETAIL_MAP_FORMAT_STORE_HPP_INCLUDED

#include <mizuiro/detail/empty_format_store_impl.hpp>
#include <mizuiro/detail/normal_format_store_impl.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename ResultFormat,
	typename Format,
	typename Function
>
inline
mizuiro::detail::empty_format_store<
	ResultFormat
>
map_format_store(
	mizuiro::detail::empty_format_store<
		Format
	> const &,
	Function const &
)
{
	return
		mizuiro::detail::empty_format_store<
			ResultFormat
		>{};
}

template<
	typename ResultFormat,
	typename Format,
	typename Copy,
	typename Function
>
inline
auto
map_format_store(
	mizuiro::detail::normal_format_store<
		Format,
		Copy
	> const &_normal_store,
	Function const &_function
)
->
decltype(
	_function(
		_normal_store.get()
	)
)
{
	return
		_function(
			_normal_store.get()
		);
}

}
}

#endif
