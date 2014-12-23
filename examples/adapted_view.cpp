//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <mizuiro/apply_const_result.hpp>
#include <mizuiro/nonconst_tag.hpp>
#include <mizuiro/raw_pointer.hpp>
#include <mizuiro/raw_value.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/access/raw.hpp>
#include <mizuiro/detail/nonassignable.hpp>
#include <mizuiro/image/dimension.hpp>
#include <mizuiro/image/linear_view.hpp>
#include <mizuiro/image/pitch_type.hpp>
#include <mizuiro/image/access/dereference.hpp>
#include <mizuiro/image/access/stride.hpp>
#include <mizuiro/image/access/dereference_ns/tag.hpp>
#include <mizuiro/image/access/stride_ns/tag.hpp>
#include <mizuiro/image/algorithm/print.hpp>
#include <mizuiro/image/format/store_fwd.hpp>
#include <mizuiro/image/format/tag_of_fwd.hpp>
#include <mizuiro/image/types/pointer.hpp>
#include <mizuiro/image/types/reference.hpp>
#include <mizuiro/image/types/needs_store_ns/tag.hpp>
#include <mizuiro/image/types/pointer_ns/tag.hpp>
#include <mizuiro/image/types/reference_ns/tag.hpp>
#include <mizuiro/image/types/value_type_ns/tag.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <cstring>
#include <iostream>
#include <iterator>
#include <ostream>
#include <type_traits>
#include <vector>
#include <mizuiro/detail/external_end.hpp>


namespace mylib
{

template<
	typename Format
>
struct tag
{
};

template<
	typename Dim,
	typename Type
>
struct native_format
{
	// Typedefs for mizuiro
	typedef Dim dim;

	typedef
	typename
	mizuiro::image::pitch_type<
		dim
	>::type
	pitch;

	// Own typedefs
	typedef Type type;
};

template<
	typename Type
>
class proxy;

}


namespace mizuiro
{
namespace image
{
namespace format
{

template<
	typename Dim,
	typename Type
>
struct tag_of<
	mylib::native_format<
		Dim,
		Type
	>
>
{
	typedef
	mylib::tag<
		mylib::native_format<
			Dim,
			Type
		>
	>
	type;
};

}

namespace types
{
namespace needs_store_ns
{
template<
	typename Dim,
	typename Type
>
std::false_type
needs_store_adl(
	mizuiro::image::types::needs_store_ns::tag,
	mylib::tag<
		mylib::native_format<
			Dim,
			Type
		>
	>
);

}

namespace pointer_ns
{

template<
	typename Dim,
	typename Type,
	typename Constness
>
mizuiro::apply_const_result<
	mizuiro::raw_pointer,
	Constness
>
pointer_adl(
	mizuiro::image::types::pointer_ns::tag,
	mizuiro::access::raw,
	mylib::tag<
		mylib::native_format<
			Dim,
			Type
		>
	>,
	Constness
);

}

namespace reference_ns
{

template<
	typename Dim,
	typename Type
>
mylib::proxy<
	Type
>
reference_adl(
	mizuiro::image::types::reference_ns::tag,
	mizuiro::access::raw,
	mylib::tag<
		mylib::native_format<
			Dim,
			Type
		>
	>,
	mizuiro::nonconst_tag
);

}

namespace value_type_ns
{

template<
	typename Dim,
	typename Type
>
Type
value_type_adl(
	mizuiro::image::types::value_type_ns::tag,
	mylib::tag<
		mylib::native_format<
			Dim,
			Type
		>
	>
);

}
}

namespace access
{
namespace stride_ns
{

template<
	typename Dim,
	typename Type
>
mizuiro::size_type
stride_adl(
	mizuiro::image::access::stride_ns::tag,
	mizuiro::access::raw const &,
	mylib::tag<
		mylib::native_format<
			Dim,
			Type
		>
	>,
	mizuiro::image::format::store<
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

}

namespace dereference_ns
{

template<
	typename Dim,
	typename Type
>
mizuiro::image::types::reference<
	mizuiro::access::raw,
	mylib::native_format<
		Dim,
		Type
	>,
	mizuiro::nonconst_tag
>
dereference_adl(
	mizuiro::image::access::dereference_ns::tag,
	mizuiro::access::raw,
	mylib::tag<
		mylib::native_format<
			Dim,
			Type
		>
	>,
	mizuiro::nonconst_tag,
	mizuiro::image::format::store<
		mylib::native_format<
			Dim,
			Type
		>
	> const &,
	mizuiro::image::types::pointer<
		mizuiro::access::raw,
		mylib::native_format<
			Dim,
			Type
		>,
		mizuiro::nonconst_tag
	> const _data
)
{
	return
		mizuiro::image::types::reference<
			mizuiro::access::raw,
			mylib::native_format<
				Dim,
				Type
			>,
			mizuiro::nonconst_tag
		>(
			_data
		);
}

}
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
	typedef
	mizuiro::raw_pointer
	pointer;

	explicit
	proxy(
		pointer const _data
	)
	:
		data_(
			_data
		)
	{
	}

	typedef
	Type
	value_type;

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
	typedef
	unsigned
	value_type;

	typedef
	mizuiro::image::dimension<
		2
	>
	dim2;

	typedef
	mizuiro::image::linear_view<
		::mizuiro::access::raw,
		mylib::native_format<
			dim2,
			value_type
		>,
		mizuiro::nonconst_tag
	>
	native_view;

	typedef
	std::vector<
		mizuiro::raw_value
	>
	raw_vector;

	dim2 const size(
		100u,
		50u
	);

	raw_vector data(
		sizeof(
			value_type
		)
		*
		size.content()
	);

	native_view const view(
		size,
		data.data()
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

	std::cout
		<< '\n';
}
