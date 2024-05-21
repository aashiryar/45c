#include <gtest/gtest.h>

#include <string>

#include "array.hpp"

using namespace std;

TEST(ArrayTests, Length) {
    Array<int> arr{3};
    EXPECT_EQ(arr.lenght(), 3);

    Array<string> arr2{10};
    EXPECT_EQ(arr2.lenght(), 10);

    EXPECT_EQ(Array<double>{}.lenght(), 0);
}
