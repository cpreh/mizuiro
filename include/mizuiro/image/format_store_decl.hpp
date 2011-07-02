//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_STORE_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_STORE_DECL_HPP_INCLUDED

#include <mizuiro/image/format_store_fwd.hpp>
#include <mizuiro/color/format_store_decl.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Format
>
class format_store
{
public:
	typedef color::format_store<
		typename Format::color_format
	> color_format_store;

	explicit format_store(
		Format const *
	);

	Format const *
	get() const;

	color_format_store const
	color_format() const;
private:
	Format const *format_;
};

}
}

#endif
