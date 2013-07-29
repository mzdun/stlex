stl::ext
========

API inspired by C++11 standard library

## &lt;range.hpp&gt; ##

This header contains utilities for range-based `for` loops. For example:

    std::vector<std::string> poem { "Marry", "had", "a", "little", "lamb" };
    for (auto && s : reverse(poem))
        std::cout << s << " "; // lamb little a had Marry
    std::cout << std::endl;
    
    for (auto && s : slice(poem, 2, 5))
        std::cout << s << " "; // a little lamb
    std::cout << std::endl;

### make_range(begin, end) ###

Synopsis:

    template <typename It>
        auto std_ext::make_range(It begin, It end);
    template <typename It>
        auto std_ext::range(It begin, It end);

Creates an object usable in a range-based `for` loop, iterating between `begin` and `end`. `range` and `make_range` are aliases for the same functionality, with the latter name similar to the `std::make_*` family (such as `std::make_pair` or `std::make_shared`).

### reverse(container) ###

Synopsis:

    template <typename Container>
        auto std_ext::reverse(Container& container);
    template <typename Container>
        auto std_ext::reverse(const Container& container);

Creates an object usable in a range-based `for` loop, iterating between `container.rbegin()` and `container.rend()`.

### reverse(array) ###

Synopsis:

    template <typename T, size_t len>
        auto std_ext::reverse(T (&array)[len]);

Iterates over the elements of the table in reverse order.

### slice(container, begin, end) ###

Synopsis:

    template <typename Container>
        auto std_ext::slice(Container& container, size_t begin, size_t end);
    template <typename Container>
        auto std_ext::slice(const Container& container, size_t begin, size_t end);

Alias for `make_range(container.begin() + begin, container.begin() + end)`.

### slice(array, begin, end) ###

Synopsis:

    template <typename T, size_t len>
        auto std_ext::slice(T (&array)[len], size_t begin, size_t end);

Alias for `make_range(array + begin, array + end)`.
