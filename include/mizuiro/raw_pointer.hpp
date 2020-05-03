//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef MIZUIRO_RAW_POINTER_HPP_INCLUDED
#define MIZUIRO_RAW_POINTER_HPP_INCLUDED

#include <mizuiro/raw_value.hpp>


namespace mizuiro
{

/**
\brief A pointer to nonconst raw memory
*/
using
raw_pointer
=
mizuiro::raw_value *;

}

#endif
