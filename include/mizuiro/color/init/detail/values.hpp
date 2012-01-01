//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_INIT_DETAIL_VALUES_HPP_INCLUDED
#define MIZUIRO_COLOR_INIT_DETAIL_VALUES_HPP_INCLUDED

#include <mizuiro/color/init/detail/values_fwd.hpp>
#include <mizuiro/detail/external_begin.hpp>
#include <boost/fusion/algorithm/transformation/push_back.hpp>
#include <boost/fusion/container/vector/convert.hpp>
#include <boost/fusion/sequence/intrinsic/front.hpp>
#include <mizuiro/detail/external_end.hpp>

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
class values
{
public:
	typedef Vector vector_type;

	values()
	:
		elements_()
	{}

	values(
		vector_type const &_elements
	)
	:
		elements_(_elements)
	{}

	template<
		typename NewInit
	>
	values<
		typename boost::fusion::result_of::as_vector<
			typename boost::fusion::result_of::push_back<
				vector_type,
				NewInit
			>::type
		>::type
	> const
	operator()(
		values<
			boost::fusion::vector1<
				NewInit
			>
		> const &_newinit
	) const
	{
		return
			boost::fusion::as_vector(
				boost::fusion::push_back(
					elements_,
					boost::fusion::front(
						_newinit.get()
					)
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
