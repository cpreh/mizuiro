//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_NORMAL_FORMAT_BASE_DECL_HPP_INCLUDED
#define MIZUIRO_DETAIL_NORMAL_FORMAT_BASE_DECL_HPP_INCLUDED

#include <mizuiro/detail/normal_format_base_fwd.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename Store
>
class normal_format_base
{
protected:
	typedef Store format_store_type;

	explicit
	normal_format_base(
		format_store_type const &
	);

	normal_format_base(
		normal_format_base const &
	) noexcept;

	format_store_type const
	format_store_base() const;
private:
	format_store_type format_;
};

}
}

#endif
