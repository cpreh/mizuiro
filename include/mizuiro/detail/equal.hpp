//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_EQUAL_HPP_INCLUDED
#define MIZUIRO_DETAIL_EQUAL_HPP_INCLUDED


namespace mizuiro
{
namespace detail
{

struct equal
{
	typedef
	bool
	result_type;

	template<
		typename Element1,
		typename Element2
	>
	result_type
	operator()(
		Element1 const &_element1,
		Element2 const &_element2
	) const
	{
		return
			_element1
			==
			_element2;
	}
};

}
}

#endif
