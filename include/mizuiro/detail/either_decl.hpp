//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_EITHER_DECL_HPP_INCLUDED
#define MIZUIRO_DETAIL_EITHER_DECL_HPP_INCLUDED

#include <mizuiro/detail/either_fwd.hpp>


namespace mizuiro
{
namespace detail
{

template<
	typename Left,
	typename Right
>
class either
{
public:
	explicit
	either(
		Left const &
	);

	explicit
	either(
		Right const &
	);

	either(
		either const &
	)
	noexcept;

	either(
		either &&
	)
	noexcept;

	either &
	operator=(
		either const &
	);

	either &
	operator=(
		either &&
	);

	~either();

	bool
	is_left() const;

	Left const &
	left() const;

	Right const &
	right() const;
private:
	void
	copy(
		either const &
	)
	noexcept;

	void
	move(
		either &&
	)
	noexcept;

	void
	destroy();

	union
	{
		Left left_;

		Right right_;
	};

	bool is_left_;
};

}
}

#endif
