//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_TRANSFORM_TERNARY_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_TRANSFORM_TERNARY_HPP_INCLUDED

#include <mizuiro/detail/nonassignable.hpp>


namespace mizuiro
{
namespace image
{
namespace algorithm
{
namespace detail
{

template<
	typename Fun
>
struct transform_ternary
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		transform_ternary
	);
public:
	typedef
	void
	result_type;

	explicit
	transform_ternary(
		Fun const &_fun
	)
	:
		fun_(
			_fun
		)
	{
	}

	template<
		typename Source1,
		typename Source2,
		typename Dest
	>
	result_type
	operator()(
		Source1 const &_source1,
		Source2 const &_source2,
		Dest const &_dest
	) const
	{
		this->fun_(
			_source1,
			_source2,
			_dest
		);
	}
private:
	Fun const &fun_;
};

}
}
}
}

#endif
