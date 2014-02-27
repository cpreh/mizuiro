//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_IMAGE_ALGORITHM_DETAIL_FILL_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITHM_DETAIL_FILL_HPP_INCLUDED

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
class fill
{
	MIZUIRO_DETAIL_NONASSIGNABLE(
		fill
	);
public:
	typedef
	void
	result_type;

	explicit
	fill(
		Fun const &_fun
	)
	:
		fun_(
			_fun
		)
	{
	}

	template<
		typename Dest
	>
	result_type
	operator()(
		Dest const &_dest
	) const
	{
		_dest = fun_();
	}
private:
	Fun const &fun_;
};

}
}
}
}

#endif
