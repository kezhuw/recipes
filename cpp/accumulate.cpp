#include <numeric>
#include <type_traits>

namespace std {

template <typename InputIt>
auto accumulate(InputIt begin, InputIt end) -> typename std::remove_reference<decltype(*begin)>::type {
	typedef typename std::remove_reference<decltype(*begin)>::type ValueType;
	return accumulate(begin, end, ValueType());
}

}

#include <vector>
#include <utility>
#include <iostream>
#include <iterator>
#include <initializer_list>

template <typename ValueType>
void test(std::vector<ValueType> const& v) {
	std::cout << "=========================\n";
	std::copy(std::begin(v), std::end(v), std::ostream_iterator<ValueType>(std::cout, ", "));
	std::cout << "\n";

	auto sum = std::accumulate(std::begin(v), std::end(v));
	std::cout << "sum = " << sum << "\n";
	std::cout << "=========================\n\n";
}

template <typename ValueType>
void test(std::initializer_list<ValueType>&& values) {
	std::vector<ValueType> v(std::forward<std::initializer_list<ValueType>>(values));
	test(v);
}
 
int
main() {
	test<int>({1, 2, 3, 4});
	test<int>(std::vector<int>{2,2,3});
	test<double>({1.1, 1.2, 1.3});
	test<std::string>({"aa", "bb", "cc", "dd"});
	std::cout << "cpp : " << __cplusplus << std::endl;
}
