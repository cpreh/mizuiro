#ifndef MIZUIRO_IMAGE_RAW_CONTAINER_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_RAW_CONTAINER_DECL_HPP_INCLUDED

#include <mizuiro/image/raw_container_fwd.hpp>

namespace mizuiro
{
namespace image
{

template<
	typename T,
	typename A
>
class raw_container {
public:
	typedef T value_type;
	typedef A allocator_type;

	typedef typename A::pointer pointer;
	typedef typename A::const_pointer const_pointer;
	typedef typename A::size_type size_type;

	raw_container();

	explicit raw_container(
		size_type
	);

	raw_container(
		raw_container const &
	);

	raw_container &
	operator=(
		raw_container const &
	);

	~raw_container();

	void
	resize(
		size_type
	);

	pointer
	data();

	const_pointer
	data() const;

	size_type
	size() const;
private:
	pointer
		data_,
		data_end_;
};

}
}

#endif
