//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_COLOR_CONVERSION_DETAIL_MAKE_LOGICAL_AND_HPP_INCLUDED
#define MIZUIRO_COLOR_CONVERSION_DETAIL_MAKE_LOGICAL_AND_HPP_INCLUDED



namespace mizuiro
{
namespace color
{
namespace conversion
{
namespace detail
{

template<
	typename Fun1,
	typename Fun2
>
inline
auto
make_logical_and(
	Fun1 const &_fun1,
	Fun2 const &_fun2
)
{
	return
		[
			_fun1,
			_fun2
		](
			auto const &_value
		)
		->
		bool
		{
			return
				_fun1(
					_value
				)
				&&
				_fun2(
					_value
				);
		};
}

}
}
}
}

#endif
