//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_FORMAT_STORE_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_FORMAT_STORE_DECL_HPP_INCLUDED

#include <mizuiro/color/format/store_fwd.hpp>


namespace mizuiro
{
namespace color
{
namespace format
{

template<
	typename Format
>
class store
{
public:
	explicit
	store(
		Format const *
	);

	Format const *
	get() const;
private:
	Format const *format_;
};

}
}
}

#endif
