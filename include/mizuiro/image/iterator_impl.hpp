#ifndef MIZUIRO_IMAGE_ITERATOR_IMPL_HPP_INCLUDED
#define MIZUIRO_IMAGE_ITERATOR_IMPL_HPP_INCLUDED

#include <mizuiro/image/iterator_decl.hpp>
#include <sge/variant/apply_unary.hpp>
#include <sge/variant/apply_binary.hpp>
#include <sge/variant/object_impl.hpp>
#include <mizuiro/image/detail/advance_iterator.hpp>
#include <mizuiro/image/detail/increment_iterator.hpp>
#include <mizuiro/image/detail/decrement_iterator.hpp>
#include <mizuiro/image/detail/iterator_difference.hpp>
#include <mizuiro/image/detail/dereference_iterator.hpp>
#include <mizuiro/image/detail/compare_iterator.hpp>
#include <mizuiro/image/detail/iterator_data.hpp>

template<
	typename Format,
	typename Constness
>
mizuiro::image::iterator<Format, Constness>::iterator(
	internal_type const &internal_
)
:
	internal_(internal_)
{}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::iterator<Format, Constness>::internal_type const &
mizuiro::image::iterator<Format, Constness>::internal() const
{
	return internal_;
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::iterator<Format, Constness>::pointer
mizuiro::image::iterator<Format, Constness>::data() const
{
	return sge::variant::apply_unary(
		detail::iterator_data<
			pointer
		>(),
		internal_
	);
}

template<
	typename Format,
	typename Constness
>
void
mizuiro::image::iterator<Format, Constness>::advance(
	difference_type	const diff
)
{
	internal_ =
		sge::variant::apply_unary(
			detail::advance_iterator<
				internal_type,
				difference_type
			>(
				diff
			),
			internal_
		);
}
	
template<
	typename Format,
	typename Constness
>
void
mizuiro::image::iterator<Format, Constness>::increment()
{
	internal_ =
		sge::variant::apply_unary(
			detail::increment_iterator<
				internal_type
			>(),
			internal_
		);
}

template<
	typename Format,
	typename Constness
>
void
mizuiro::image::iterator<Format, Constness>::decrement()
{
	internal_ =
		sge::variant::apply_unary(
			detail::decrement_iterator<
				internal_type
			>(),
			internal_
		);
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::iterator<Format, Constness>::difference_type
mizuiro::image::iterator<Format, Constness>::distance_to(
	iterator const &other
) const
{
	return
		sge::variant::apply_binary(
			detail::iterator_difference<
				difference_type
			>(),
			internal_,
			other.internal_
		);
}

template<
	typename Format,
	typename Constness
>
typename mizuiro::image::iterator<Format, Constness>::reference
mizuiro::image::iterator<Format, Constness>::dereference() const
{
	return
		sge::variant::apply_unary(
			detail::dereference_iterator<
				reference
			>(),
			internal_
		);
}

template<
	typename Format,
	typename Constness
>
bool
mizuiro::image::iterator<Format, Constness>::equal(
	iterator const &other
) const
{
	return
		sge::variant::apply_binary(
			detail::compare_iterator(),
			internal_,
			other.internal_
		);
}

#endif
