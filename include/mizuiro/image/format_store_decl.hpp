//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_STORE_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_STORE_DECL_HPP_INCLUDED

#include <mizuiro/color/format_store_decl.hpp>
#include <mizuiro/detail/make_optional.hpp>
#include <mizuiro/detail/optional_impl.hpp>
#include <mizuiro/image/format_store_fwd.hpp>


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
	typedef typename mizuiro::detail::make_optional<
		Format
	>::type optional_format;

	typedef color::format_store<
		typename Format::color_format
	> color_format_store;

	// compatibility to format_argument
	explicit format_store(
		Format const *
	);

	explicit format_store(
		optional_format const &
	);

	optional_format const
	get() const;

	color_format_store const
	color_format() const;
private:
	optional_format format_;
};

}
}

#endif
