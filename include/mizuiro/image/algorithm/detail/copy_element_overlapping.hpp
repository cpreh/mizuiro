//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_COPY_ELEMENT_OVERLAPPING_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_COPY_ELEMENT_OVERLAPPING_HPP_INCLUDED


namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

template<
	typename ValueType
>
struct copy_element_overlapping
{
	typedef
	void
	result_type;

	template<
		typename Src,
		typename Dest
	>
	result_type
	operator()(
		Src const &_src,
		Dest const &_dest
	) const
	{
		ValueType const temp(
			_src
		);

		_dest = temp;
	}
};

}
}
}
}

#endif
