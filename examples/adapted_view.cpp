//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/apply_const.hpp>
#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/raw_pointer.hpp>
#include <mizuiro/raw_value.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/access/raw.hpp>
#include <mizuiro/detail/ignore_effcpp.hpp>
#include <mizuiro/detail/nonassignable.hpp>
#include <mizuiro/detail/pop_warning.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/format_is_static.hpp>
#include <mizuiro/image/format_store_fwd.hpp>
#include <mizuiro/image/linear_view.hpp>
#include <mizuiro/image/pitch_type.hpp>
#include <mizuiro/image/access/dereference.hpp>
#include <mizuiro/image/access/stride.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/reference.hpp>
#include <mizuiro/image/types/value_type.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <cstring>
#include <iostream>
#include <iterator>
#include <ostream>
#include <vector>
#include <mizuiro/detail/external_end.hpp>


namespace mylib
{

template<
	typename Dim,
	typename Type
>
struct native_format
{
	// Typedefs for mizuiro
	typedef Dim dim;

	typedef typename mizuiro::image::pitch_type<
		dim
	>::type pitch;

	// Own typedefs
	typedef Type type;
};

template<
	typename Type
>
class proxy;

}

MIZUIRO_DETAIL_IGNORE_EFFCPP

namespace mizuiro
{
namespace image
{

template<
	typename Dim,
	typename Type
>
struct format_is_static<
	mylib::native_format<
		Dim,
		Type
	>
>
:
boost::true_type
{
};

namespace types
{

template<
	typename Dim,
	typename Type,
	typename Constness
>
struct pointer<
	mizuiro::access::raw,
	mylib::native_format<
		Dim,
		Type
	>,
	Constness
>
:
mizuiro::apply_const<
	mizuiro::raw_pointer,
	Constness
>
{
};

MIZUIRO_DETAIL_POP_WARNING

template<
	typename Dim,
	typename Type
>
struct reference<
	mizuiro::access::raw,
	mylib::native_format<
		Dim,
		Type
	>,
	mizuiro::nonconst_tag
>
{
	typedef mylib::proxy<
		Type
	> type;
};

template<
	typename Dim,
	typename Type
>
struct value_type<
	mylib::native_format<
		Dim,
		Type
	>
>
{
	typedef Type type;
};

}

namespace access
{

template<
	typename Dim,
	typename Type
>
struct stride<
	mizuiro::access::raw,
	mylib::native_format<
		Dim,
		Type
	>
>
{
	static
	mizuiro::size_type
	execute(
		mizuiro::access::raw const &,
		mizuiro::image::format_store<
			mylib::native_format<
				Dim,
				Type
			>
		> const &
	)
	{
		return
			sizeof(Type);
	}
};

template<
	typename Dim,
	typename Type
>
struct dereference<
	mizuiro::access::raw,
	mylib::native_format<
		Dim,
		Type
	>,
	mizuiro::nonconst_tag
>
{
	typedef mizuiro::access::raw access;

	typedef mylib::native_format<
		Dim,
		Type
	> image_format;

	typedef mizuiro::nonconst_tag constness;

	typedef typename mizuiro::image::types::reference<
		access,
		image_format,
		constness
	>::type result_type;

	typedef typename mizuiro::image::types::pointer<
		access,
		image_format,
		constness
	>::type pointer;


	static
	result_type
	execute(
		mizuiro::access::raw const &,
		pointer const _data,
		mizuiro::image::format_store<
			image_format
		> const &
	)
	{
		return
			result_type(
				_data
			);
	}
};

}

}
}

namespace mylib
{

template<
	typename Type
>
class proxy
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		proxy
	);
public:
	typedef mizuiro::raw_pointer pointer;

	explicit proxy(
		pointer const _data
	)
	:
		data_(
			_data
		)
	{
	}

	typedef Type value_type;

	operator
	value_type() const
	{
		value_type result;

		std::memcpy(
			&result,
			data_,
			sizeof(
				value_type
			)
		);

		return result;
	}

	proxy &
	operator=(
		value_type const &_value
	)
	{
		std::memcpy(
			data_,
			&_value,
			sizeof(
				value_type
			)
		);

		return
			*this;
	}
private:
	pointer const data_;
};


}

int
main()
{
	typedef unsigned value_type;

	typedef mizuiro::image::dimension<
		2
	> dim2;

	typedef mizuiro::image::linear_view<
		::mizuiro::access::raw,
		mylib::native_format<
			dim2,
			value_type
		>,
		mizuiro::nonconst_tag
	> native_view;

	typedef std::vector<
		mizuiro::raw_value
	> raw_vector;

	dim2 const size(
		100,
		50
	);

	raw_vector data(
		sizeof(value_type)
		*
		size.content()
	);

	native_view const view(
		size,
		&data[0]
	);

	for(
		native_view::iterator it(
			view.begin()
		);
		it != view.end();
		++it
	)
		*it =
			static_cast<
				value_type
			>(
				std::distance(
					view.begin(),
					it
				)
			);

	mizuiro::image::algorithm::print(
		std::cout,
		view
	);

	std::cout << '\n';
}
