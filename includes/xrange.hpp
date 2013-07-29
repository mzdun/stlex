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

	template <typename T>
	class array_reverse_adaptor_t
	{
		T* current;
	public:
		typedef array_reverse_adaptor_t<T> my_t;
		typedef T* pointer;
		typedef T& reference;
		array_reverse_adaptor_t(T* ptr) : current(ptr) {}

		my_t& operator ++ ()
		{
			--current;
			return *this;
		}
		my_t& operator ++ (int)
		{
			my_t copy(*this);
			--current;
			return copy;
		}

		reference operator*()
		{
			return *(current - 1);
		}
		
		friend bool operator == (const my_t& lhs, const my_t& rhs)
		{
			return lhs.current == rhs.current;
		}

		friend bool operator < (const my_t& lhs, const my_t& rhs)
		{
			return lhs.current < rhs.current;
		}
	};

	template <typename T>
	bool operator != (const array_reverse_adaptor_t<T>& lhs, const array_reverse_adaptor_t<T>& rhs)
	{
		return !(lhs == rhs);
	}

	template <typename T>
	bool operator >= (const array_reverse_adaptor_t<T>& lhs, const array_reverse_adaptor_t<T>& rhs)
	{
		return !(lhs < rhs);
	}

	template <typename T>
	bool operator > (const array_reverse_adaptor_t<T>& lhs, const array_reverse_adaptor_t<T>& rhs)
	{
		return rhs < lhs;
	}

	template <typename T>
	bool operator <= (const array_reverse_adaptor_t<T>& lhs, const array_reverse_adaptor_t<T>& rhs)
	{
		return !(rhs < lhs);
	}

}}}

#endif // __XRANGE_HEADER__