#ifndef MIZUIRO_IMAGE_DETAIL_ITERATOR_BASE_HPP_INCLUDED
#define MIZUIRO_IMAGE_DETAIL_ITERATOR_BASE_HPP_INCLUDED

#include <mizuiro/image/types/reference.hpp>
#include <mizuiro/difference_type.hpp>
#include <boost/iterator/iterator_facade.hpp>

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename Iterator,
	typename Access,
	typename Format,
	typename Constness,
	typename Category = boost::random_access_traversal_tag
>
struct iterator_base
{
	typedef boost::iterator_facade<
		Iterator,
		typename Format::color_format::channel_type,
		Category,
		typename image::types::reference<
			Access,
			Format,
			Constness
		>::type,
		difference_type
	> type;
};

}
}
}

#endif
