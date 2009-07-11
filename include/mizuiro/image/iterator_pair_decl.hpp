#ifndef MIZUIRO_IMAGE_ITERATOR_PAIR_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_ITERATOR_PAIR_DECL_HPP_INCLUDED

#include <mizuiro/image/iterator_pair_fwd.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Iterator
>
class iterator_pair {
public:
	typedef Iterator iterator;

	iterator_pair(
		iterator begin,
		iterator end
	);

	iterator const
	begin() const;

	iterator const
	end() const;
private:
	iterator
		begin_,
		end_;
};

}
}

#endif
