#ifndef __RANGE_HEADER__
#define __RANGE_HEADER__

#include "xrange.hpp"
#include <iterator>

namespace std { namespace ext
{
	using std::begin;
	using std::end;

	template <typename It>
	impl::range_t<It> make_range(It from, It to) { return impl::range_t<It>(from, to); }

	template <typename _Container>
	auto inline reverse(_Container& container)
		-> impl::range_t<decltype(container.rbegin())>
	{
		return make_range(container.rbegin(), container.rend());
	}

	template <typename _Container>
	auto inline reverse(const _Container& container)
		-> impl::range_t<decltype(container.rbegin())>
	{
		return make_range(container.rbegin(), container.rend());
	}
}}

#endif // __RANGE_HEADER__