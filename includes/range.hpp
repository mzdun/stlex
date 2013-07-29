#ifndef __RANGE_HEADER__
#define __RANGE_HEADER__

#include "xrange.hpp"
#include <cstddef>

namespace std_ext
{

	template <typename It>
	impl::range_t<It> inline make_range(It from, It to) { return { from, to }; }

	template <typename It>
	impl::range_t<It> inline range(It from, It to) { return { from, to }; }

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

	template <typename _Container>
	auto inline slice(_Container& container, size_t begin, size_t end)
		-> impl::range_t<decltype(container.begin())>
	{
		return make_range(container.begin() + begin, container.begin() + end);
	}

	template <typename _Container>
	auto inline slice(_Container& container, size_t begin)
		-> impl::range_t<decltype(container.begin())>
	{
		return make_range(container.begin() + begin, container.end());
	}

	template <typename _Container>
	auto inline slice(const _Container& container, size_t begin, size_t end)
		-> impl::range_t<decltype(container.begin())>
	{
		return make_range(container.begin() + begin, container.begin() + end);
	}

	template <typename _Container>
	auto inline slice(const _Container& container, size_t begin)
		-> impl::range_t<decltype(container.begin())>
	{
		return make_range(container.begin() + begin, container.end());
	}

	template <typename T, size_t len>
	impl::range_t<T*> inline slice(T(&arr)[len], size_t begin, size_t end)
	{
		return { arr + begin, arr + end };
	}

	template <typename T, size_t len>
	impl::range_t<T*> inline slice(T(&arr)[len], size_t begin)
	{
		return { arr + begin, arr + len };
	}

} // std_ext

using ::std_ext::make_range;
using ::std_ext::range;
using ::std_ext::reverse;

// no std_ext::slice, to not mix it with std::slice

#endif // __RANGE_HEADER__