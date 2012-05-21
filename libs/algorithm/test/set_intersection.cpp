#ifndef SPROUT_LIBS_ALGORITHM_TEST_SET_INTERSECTION_CPP
#define SPROUT_LIBS_ALGORITHM_TEST_SET_INTERSECTION_CPP

#include <sprout/algorithm/set_intersection.hpp>
#include <sprout/array.hpp>
#include <sprout/sub_array.hpp>
#include <sprout/container.hpp>
#include <testspr/tools.hpp>

namespace testspr {
	static void algorithm_set_intersection_test() {
		using namespace sprout;
		{
			SPROUT_STATIC_CONSTEXPR auto arr1 = array<int, 5>{{20, 25, 30, 35, 40}};
			SPROUT_STATIC_CONSTEXPR auto arr1_2 = array<int, 5>{{10, 20, 30, 40, 50}};
			SPROUT_STATIC_CONSTEXPR auto arr2 = array<int, 10>{};
			SPROUT_STATIC_CONSTEXPR auto arr3 = array<int, 2>{};

			// 論理積
			{
				SPROUT_STATIC_CONSTEXPR auto merged = sprout::set_intersection(
					sprout::begin(arr1),
					sprout::end(arr1),
					sprout::begin(arr1_2),
					sprout::end(arr1_2),
					arr2
					);
				TESTSPR_DOUBLE_ASSERT(testspr::equal(
					merged,
					array<int, 10>{{20, 30, 40, 0, 0, 0, 0, 0, 0, 0}}
					));
			}
			{
				SPROUT_STATIC_CONSTEXPR auto merged = sprout::fit::set_intersection(
					sprout::begin(arr1),
					sprout::end(arr1),
					sprout::begin(arr1_2),
					sprout::end(arr1_2),
					arr2
					);
				TESTSPR_DOUBLE_ASSERT(testspr::equal(
					merged,
					array<int, 3>{{20, 30, 40}}
					));
			}
			// 論理積
			// 出力範囲をオーバーする場合
			{
				SPROUT_STATIC_CONSTEXPR auto merged = sprout::set_intersection(
					sprout::begin(arr1),
					sprout::end(arr1),
					sprout::begin(arr1_2),
					sprout::end(arr1_2),
					arr3
					);
				TESTSPR_DOUBLE_ASSERT(testspr::equal(
					merged,
					array<int, 2>{{20, 30}}
					));
			}
			{
				SPROUT_STATIC_CONSTEXPR auto merged = sprout::fit::set_intersection(
					sprout::begin(arr1),
					sprout::end(arr1),
					sprout::begin(arr1_2),
					sprout::end(arr1_2),
					arr3
					);
				TESTSPR_DOUBLE_ASSERT(testspr::equal(
					merged,
					array<int, 2>{{20, 30}}
					));
			}
			// 論理積
			// 出力範囲の切り出し
			{
				SPROUT_STATIC_CONSTEXPR auto merged = sprout::set_intersection(
					sprout::begin(arr1),
					sprout::end(arr1),
					sprout::begin(arr1_2),
					sprout::end(arr1_2),
					sprout::sub(arr2, 2, 8)
					);
				TESTSPR_DOUBLE_ASSERT(testspr::equal(
					merged,
					array<int, 6>{{20, 30, 40, 0, 0, 0}}
					));
				TESTSPR_DOUBLE_ASSERT(testspr::equal(
					sprout::get_internal(merged),
					array<int, 10>{{0, 0, 20, 30, 40, 0, 0, 0, 0, 0}}
					));
			}
			{
				SPROUT_STATIC_CONSTEXPR auto merged = sprout::fit::set_intersection(
					sprout::begin(arr1),
					sprout::end(arr1),
					sprout::begin(arr1_2),
					sprout::end(arr1_2),
					sprout::sub(arr2, 2, 8)
					);
				TESTSPR_DOUBLE_ASSERT(testspr::equal(
					merged,
					array<int, 3>{{20, 30, 40}}
					));
				TESTSPR_DOUBLE_ASSERT(testspr::equal(
					sprout::get_internal(merged),
					array<int, 10>{{0, 0, 20, 30, 40, 0, 0, 0, 0, 0}}
					));
			}
		}
		{
			SPROUT_STATIC_CONSTEXPR auto arr1 = array<int, 5>{{20, 25, 30, 35, 40}};
			SPROUT_STATIC_CONSTEXPR auto arr1_2 = array<int, 5>{{10, 20, 30, 40, 50}};
			SPROUT_STATIC_CONSTEXPR auto arr2 = array<int, 10>{};
			SPROUT_STATIC_CONSTEXPR auto arr3 = array<int, 2>{};

			// 論理積
			{
				SPROUT_STATIC_CONSTEXPR auto merged = sprout::set_intersection(
					sprout::begin(arr1),
					sprout::end(arr1),
					sprout::begin(arr1_2),
					sprout::end(arr1_2),
					arr2,
					testspr::less<int>()
					);
				TESTSPR_DOUBLE_ASSERT(testspr::equal(
					merged,
					array<int, 10>{{20, 30, 40, 0, 0, 0, 0, 0, 0, 0}}
					));
			}
			{
				SPROUT_STATIC_CONSTEXPR auto merged = sprout::fit::set_intersection(
					sprout::begin(arr1),
					sprout::end(arr1),
					sprout::begin(arr1_2),
					sprout::end(arr1_2),
					arr2,
					testspr::less<int>()
					);
				TESTSPR_DOUBLE_ASSERT(testspr::equal(
					merged,
					array<int, 3>{{20, 30, 40}}
					));
			}
			// 論理積
			// 出力範囲をオーバーする場合
			{
				SPROUT_STATIC_CONSTEXPR auto merged = sprout::set_intersection(
					sprout::begin(arr1),
					sprout::end(arr1),
					sprout::begin(arr1_2),
					sprout::end(arr1_2),
					arr3,
					testspr::less<int>()
					);
				TESTSPR_DOUBLE_ASSERT(testspr::equal(
					merged,
					array<int, 2>{{20, 30}}
					));
			}
			{
				SPROUT_STATIC_CONSTEXPR auto merged = sprout::fit::set_intersection(
					sprout::begin(arr1),
					sprout::end(arr1),
					sprout::begin(arr1_2),
					sprout::end(arr1_2),
					arr3,
					testspr::less<int>()
					);
				TESTSPR_DOUBLE_ASSERT(testspr::equal(
					merged,
					array<int, 2>{{20, 30}}
					));
			}
			// 論理積
			// 出力範囲の切り出し
			{
				SPROUT_STATIC_CONSTEXPR auto merged = sprout::set_intersection(
					sprout::begin(arr1),
					sprout::end(arr1),
					sprout::begin(arr1_2),
					sprout::end(arr1_2),
					sprout::sub(arr2, 2, 8),
					testspr::less<int>()
					);
				TESTSPR_DOUBLE_ASSERT(testspr::equal(
					merged,
					array<int, 6>{{20, 30, 40, 0, 0, 0}}
					));
				TESTSPR_DOUBLE_ASSERT(testspr::equal(
					sprout::get_internal(merged),
					array<int, 10>{{0, 0, 20, 30, 40, 0, 0, 0, 0, 0}}
					));
			}
			{
				SPROUT_STATIC_CONSTEXPR auto merged = sprout::fit::set_intersection(
					sprout::begin(arr1),
					sprout::end(arr1),
					sprout::begin(arr1_2),
					sprout::end(arr1_2),
					sprout::sub(arr2, 2, 8),
					testspr::less<int>()
					);
				TESTSPR_DOUBLE_ASSERT(testspr::equal(
					merged,
					array<int, 3>{{20, 30, 40}}
					));
				TESTSPR_DOUBLE_ASSERT(testspr::equal(
					sprout::get_internal(merged),
					array<int, 10>{{0, 0, 20, 30, 40, 0, 0, 0, 0, 0}}
					));
			}
		}
	}
}	// namespace testspr

#ifndef TESTSPR_CPP_INCLUDE
#	define TESTSPR_TEST_FUNCTION testspr::algorithm_set_intersection_test
#	include <testspr/include_main.hpp>
#endif

#endif	// #ifndef SPROUT_LIBS_ALGORITHM_TEST_SET_INTERSECTION_CPP
