#ifndef MIZUIRO_IMAGE_RANGE_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_RANGE_DECL_HPP_INCLUDED

#include <mizuiro/image/range_fwd.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename Iterator
>
class range {
public:
	typedef Iterator iterator;

	range(
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
