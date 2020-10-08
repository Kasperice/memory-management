#include <gtest/gtest.h>

#include "SharedPointer.hpp"
#include "WeakPointer.hpp"

#include <functional>
#include <string>

template <typename T>
struct randomStruct {
public:
    randomStruct(T value)
        : value_(value){};
    T getValue()
    {
        return value_;
    }

private:
    T value_{};
};

template <typename T>
struct randomClass {
public:
    randomClass(T value)
        : value_(value){};
    T getValue()
    {
        return value_;
    }

private:
    T value_{};
};

class SharedPointerToStructTest : public ::testing::Test {
};

TEST_F(SharedPointerToStructTest, shouldReturnRandomStructMemberVariableText)
{
    auto text {"lambada"};
    auto s_ptr = new randomStruct{text};
    ASSERT_EQ(s_ptr->getValue(), text);
}

TEST_F(SharedPointerToStructTest, shouldReturnRandomStructMemberVariableIntiger)
{
    auto num {10};
    auto i_ptr = new randomStruct{num};
    ASSERT_EQ(i_ptr->getValue(), num);
}
