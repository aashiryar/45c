#include <gtest/gtest.h>

#include <sstream>

#include "alloc.hpp"
#include "int_array.hpp"

using namespace std;

TEST(IntArrayTests, Length) {
    Array arr{10};
    EXPECT_EQ(arr.lenght(), 10);
    EXPECT_EQ(Array{}.lenght(), 0);
}

TEST(IntArrayTests, Subscript) {
    Array arr{10};
    arr[0] = 3;
    arr[3] = 5;
    EXPECT_EQ(arr[0], 3);
    EXPECT_EQ(arr[3], 5);
}

TEST(IntArrayTests, Print) {
    stringstream out;

    Array arr{3};
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;

    out << arr;

    EXPECT_EQ(out.str(), "       0       1       2");
}

TEST(IntArrayTests, Read) {
    stringstream in{"1 2 3 4"};

    Array arr{3};
    in >> arr;

    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
}

TEST(IntArrayTests, Fill) {
    Array arr{10};
    arr.fill(20);
    EXPECT_EQ(arr[0], 20);
    arr.fill(5);
    EXPECT_EQ(arr[9], 5);
}

TEST(IntArrayTests, OutOfBounds) {
    Array arr{10};
    EXPECT_ANY_THROW(arr[11]);
}

TEST(IntArrayTests, CopyConstructor) {
    Array arr{10};
    arr.fill(20);
    Array arr2{arr};
    EXPECT_EQ(arr2.lenght(), 10);
    EXPECT_EQ(arr2[0], 20);
    EXPECT_EQ(arr2[9], 20);

    Array empty;
    Array arr3{empty};
    EXPECT_EQ(arr3.lenght(), 0);
}

TEST(IntArrayTests, MoveConstructor) {
    AllocationTracker tracker;
}