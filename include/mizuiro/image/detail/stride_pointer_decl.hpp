#ifndef MIZUIRO_IMAGE_STRIDE_POINTER_DECL_HPP_INCLUDED
#define MIZUIRO_IMAGE_STRIDE_POINTER_DECL_HPP_INCLUDED

#include <mizuiro/image/detail/stride_pointer_fwd.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/difference_type.hpp>
#include <boost/type_traits/remove_pointer.hpp>

namespace mizuiro
{
namespace image
{
namespace detail
{

template<
	typename T,
	mizuiro::size_type Stride
>
class stride_pointer {
public:
	typedef typename boost::remove_pointer<
		T
	>::type value_type;

	typedef value_type &reference;

	typedef mizuiro::size_type size_type;
	typedef mizuiro::difference_type difference_type;

	stride_pointer(
		T
	);

	stride_pointer &
	operator+=(
		difference_type
	);

	stride_pointer &
	operator-=(
		difference_type
	);

	stride_pointer &
	operator++();

	stride_pointer &
	operator--();

	reference
	operator*() const;

	reference
	operator[](
		size_type
	) const;

	difference_type
	operator-(
		stride_pointer const &
	) const;

	bool
	operator==(
		stride_pointer const &
	) const;
private:
	static difference_type const sstride =
		static_cast<
			difference_type
		>(
			Stride
		);

	T base_;
};

template<
	typename T,
	mizuiro::size_type Stride
>
stride_pointer<T, Stride> const
operator +(
	stride_pointer<T, Stride>,
	typename stride_pointer<T, Stride>::difference_type
);

template<
	typename T,
	mizuiro::size_type Stride
>
stride_pointer<T, Stride> const
operator -(
	stride_pointer<T, Stride>,
	typename stride_pointer<T, Stride>::difference_type
);

template<
	typename T,
	mizuiro::size_type Stride
>
bool
operator!=(
	stride_pointer<T, Stride> const &,
	stride_pointer<T, Stride> const &
);

}
}
}

#endif
