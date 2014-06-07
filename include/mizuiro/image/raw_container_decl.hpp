//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


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
class raw_container
{
public:
	typedef T value_type;

	typedef A allocator_type;

	typedef typename A::pointer pointer;

	typedef typename A::const_pointer const_pointer;

	typedef typename A::size_type size_type;

	raw_container();

	explicit
	raw_container(
		size_type
	);

	raw_container(
		raw_container const &
	);

	raw_container(
		raw_container &&
	);

	raw_container &
	operator=(
		raw_container const &
	);

	raw_container &
	operator=(
		raw_container &&
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

	pointer
	data_end();

	const_pointer
	data_end() const;

	size_type
	size() const;
private:
	void
	allocate(
		size_type
	);

	void
	copy(
		raw_container const &
	);

	void
	destroy();

	void
	after_move();

	allocator_type allocator;

	pointer
		data_,
		data_end_;
};

}
}

#endif
