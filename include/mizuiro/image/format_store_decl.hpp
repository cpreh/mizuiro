//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_STORE_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_STORE_DECL_HPP_INCLUDED

#include <mizuiro/detail/make_optional.hpp>
#include <mizuiro/detail/optional_impl.hpp>
#include <mizuiro/image/format_store_fwd.hpp>


namespace mizuiro
{
namespace image
{

template<
	typename ImageFormat
>
class format_store
{
public:
	typedef typename mizuiro::detail::make_optional<
		ImageFormat
	>::type optional_format;

	// compatibility to format_argument
	explicit format_store(
		ImageFormat const *
	);

	explicit format_store(
		ImageFormat const &
	);

	optional_format const
	get() const;
private:
	optional_format format_;
};

}
}

#endif
