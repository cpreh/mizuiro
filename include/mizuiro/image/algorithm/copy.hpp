#ifndef MIZUIRO_IMAGE_ALGORITM_COPY_HPP_INCLUDED
#define MIZUIRO_IMAGE_ALGORITM_COPY_HPP_INCLUDED

namespace mizuiro
{
namespace image
{
namespace algorithm
{

template<
	typename ViewD,
	typename ViewS
>
void
copy(
	ViewD const &dest,
	ViewS const &src
)
{
	sge::variant::apply_binary(
		detail::apply_iteration<
			detail::copy
		>(),
		view.begin().
}

}
}
}

#endif
