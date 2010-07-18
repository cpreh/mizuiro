//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_MAKE_IMPL_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_MAKE_IMPL_HPP_INCLUDED

#include <boost/fusion/algorithm/transformation/push_back.hpp>
#include <boost/fusion/container/vector/convert.hpp>

namespace mizuiro
{
namespace color
{
namespace init
{
namespace detail
{

template<
	typename Vector
>
class make_impl
{
public:
	typedef Vector vector_type;

	make_impl()
	:
		elements_()
	{}

	make_impl(
		vector_type const &_elements
	)
	:
		elements_(_elements)
	{}

	template<
		typename NewInit
	>
	make_impl<
		typename boost::fusion::result_of::as_vector<
			typename boost::fusion::result_of::push_back<
				vector_type,
				NewInit
			>::type
		>::type
	> const
	operator()(
		NewInit const &_newinit
	) const
	{
		return
			boost::fusion::as_vector(
				boost::fusion::push_back(
					elements_,
					_newinit
				)
			);
	}

	vector_type const &
	get() const
	{
		return elements_;
	}
private:
	vector_type elements_;
};

}
}
}
}

#endif
