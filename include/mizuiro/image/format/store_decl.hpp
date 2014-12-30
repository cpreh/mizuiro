//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_FORMAT_STORE_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_FORMAT_STORE_DECL_HPP_INCLUDED

#include <mizuiro/detail/optional_impl.hpp>
#include <mizuiro/image/format/store_fwd.hpp>


namespace mizuiro
{
namespace image
{
namespace format
{

template<
	typename ImageFormat
>
class store
{
public:
	typedef
	mizuiro::detail::optional<
		ImageFormat
	>
	optional_format;

	// compatibility to format_argument
	explicit
	store(
		ImageFormat const *
	);

	explicit
	store(
		ImageFormat const &
	);

	store(
		store const &
	) noexcept;

	optional_format const
	get() const;
private:
	optional_format format_;
};

}
}
}

#endif
