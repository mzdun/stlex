#ifndef __XRANGE_HEADER__
#define __XRANGE_HEADER__

namespace std { namespace ext { namespace impl {
	template <typename It>
	class range_t
	{
		It from;
		It to;

	public:
		range_t(It from, It to)
			: from(from)
			, to(to)
		{
		}
		It begin() { return from; }
		It end() { return to; }
	};
}}}

#endif // __XRANGE_HEADER__