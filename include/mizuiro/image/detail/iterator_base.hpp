#ifndef MIZUIRO_IMAGE_DETAIL_ITERATOR_BASE_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_ITERATOR_BASE_HPP_INCLUDED

#include <boost/iterator/iterator_facade.hpp>

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Iterator,
	typename Reference 
>
struct iterator_base {
	typedef boost::iterator_facade<
		Iterator,
		raw_data,
		boost::random_access_traversal_tag,
		Reference,
		difference_type
	>;
};

}
}
}

#endif
