#include <gtest/gtest.h>
#include "EnsurePlusPlus.hpp"

// These tests use the exception error configuration (which is the default).

TEST(IsNotNullptr, WhenPointerIsNull_Throws)
{
    ASSERT_THROW(Ensure::IsNotNullptr(nullptr, "This should throw."), Ensure::EnsureException);
}

TEST(IsNotNullptr, WhenPointerIsNotNull_DoesNotThrow)
{
    auto value = 0;

    Ensure::IsNotNullptr(&value, "Test value");
}

TEST(Condition, WhenConditionFalse_Throws)
{
    ASSERT_THROW(Ensure::Condition(false, "message"), Ensure::EnsureException);
}

TEST(Condition, WhenConditionTrue_DoesNotThrow)
{
    Ensure::Condition(true, "message");
}

TEST(IsNotEmpty, WhenCollectionEmpty_Throws)
{
    std::vector<int> empty{};

    ASSERT_THROW(Ensure::IsNotEmpty(empty), Ensure::EnsureException);
}

TEST(IsNotEmpty, WhenCollectionNotEmpty_DoesNotThrow)
{
    std::vector<int> nonempty{ 1 };

    Ensure::IsNotEmpty(nonempty);
}
