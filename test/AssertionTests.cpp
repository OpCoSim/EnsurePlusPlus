#include <gtest/gtest.h>
#include "EnsurePlusPlus.hpp"

TEST(IsNotNullptr, WhenPointerIsNull_Throws)
{
    ASSERT_THROW(Ensure::IsNotNullptr(nullptr, "This should throw."), Ensure::EnsureException);
}

TEST(IsNotNullptr, WhenPointerIsNotNull_DoesNotThrow)
{
    auto value = 0;

    Ensure::IsNotNullptr(&value, "Test value");
}
