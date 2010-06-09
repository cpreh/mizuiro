#ifndef MIZUIRO_COLOR_OPERATORS_DETAIL_ADD_HPP_INCLUDED
#define MIZUIRO_COLOR_OPERATORS_DETAIL_ADD_HPP_INCLUDED

namespace mizuiro
{
namespace color
{
namespace operators
{
namespace detail
{

template<
	typename Color1,
	typename Color2
>
class add
{
public:
	explicit add(
		Color1 &color1_,
		Color2 const &color2_
	)
	:
		color1_(color1_),
		color2_(color2_)
	{}

	typedef void result_type;

	template<
		typename Channel
	>
	result_type
	operator()() const
	{
		color1_. template set<
		>(
			color1_. template get<
				Channel
			>()
			+
			color2_. template get<
				Channel
			>()
		);
	}
private:
	Color1 &color1_;
	Color2 const &color2_;
};

}
}
}
}

#endif
