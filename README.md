stl::ext
========

API inspired by C++11 standard library

## &lt;range.hpp&gt; ##

This header contains utilities for range-based `for` loops.

### make_range(begin, end) ###

Synopsis:

    template <typename It>
        auto std::ext::make_range(It begin, It end);

Creates an object usable in a range-based `for` loop, iterating between `begin` and `end`.

### reverse(container) ###

Synopsis:

    template <typename Container>
        auto std::ext::reverse(Container& container);
    template <typename Container>
        auto std::ext::reverse(const Container& container);

Creates an object usable in a range-based `for` loop, iterating between `container.rbegin()` and `container.rend()`.

### reverse(array) ###

Synopsis:

    template <typename T, size_t len>
        auto std::ext::reverse(T (&array)[len]);

Iterates over the elements of the table in reverse order.
