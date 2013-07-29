#ifndef __RANGE_HEADER__
#define __RANGE_HEADER__

#include "xrange.hpp"
#include <iterator>

namespace std { namespace ext
{
	using std::begin;
	using std::end;

	template <typename It>
	impl::range_t<It> inline make_range(It from, It to) { return { from, to }; }

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

	template <typename T, size_t len>
	impl::range_t<impl::array_reverse_adaptor_t<T>> inline reverse(T(&arr)[len])
	{
		return { arr + len, arr };
	}
}}

#endif // __RANGE_HEADER__