//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_DETAIL_NULL_PTR_T_HPP_INCLUDED
#define MIZUIRO_DETAIL_NULL_PTR_T_HPP_INCLUDED

namespace mizuiro
{
namespace detail
{

struct null_ptr_t
{
	template<
		typename T
	>
	operator T *() const
	{
		return 0;
	}
};

}
}

#endif
