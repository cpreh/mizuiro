#ifndef MIZUIRO_COLOR_DETAIL_STRIDE_POINTER_DECL_HPP_INCLUDED
#define MIZUIRO_COLOR_DETAIL_STRIDE_POINTER_DECL_HPP_INCLUDED

#include <mizuiro/image/detail/stride_pointer_fwd.hpp>
#include <mizuiro/size_type.hpp>
#include <mizuiro/difference_type.hpp>
#include <boost/type_traits/remove_pointer.hpp>
#include <iterator>

namespace mizuiro
{
namespace color
{
namespace detail
{

template<
	typename T,
	mizuiro::size_type Stride
>
class stride_pointer
{
public:
	typedef typename boost::remove_pointer<
		T
	>::type value_type;

	typedef value_type &reference;

	typedef mizuiro::size_type size_type;
	typedef mizuiro::difference_type difference_type;
	typedef T pointer;

	typedef std::random_access_iterator_tag iterator_category;

	static size_type const stride = Stride;

	stride_pointer(
		T
	);

	template<
		typename OtherT
	>
	stride_pointer(
		stride_pointer<
			OtherT,
			Stride
		> const &
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

	T
	get() const;
private:
	static difference_type const sstride =
		static_cast<
			difference_type
		>(
			stride
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
