#include <vector>
#include <deque>
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

TEST(Equal, WhenElementsNotEqual_Throws)
{
    ASSERT_THROW(Ensure::Equal(3, 2), Ensure::EnsureException);
}

TEST(Equal, WhenElementsEqual_DoesNotThrow)
{
    Ensure::Equal(1, 1);
}

TEST(SequenceEquals, WhenContainersDifferentSize_Throws)
{
    std::vector<int> vector{ 1, 2 };
    std::deque<int> deque{ 1, 2, 3, 4 };

    ASSERT_THROW(Ensure::SequenceEquals(vector, deque), Ensure::EnsureException);
}

TEST(SequenceEquals, WhenElementsNotEqualThrows)
{
    std::vector<int> vector{ 1, 2, 3 };
    std::deque<int> deque{ 1, 3, 3 };

    ASSERT_THROW(Ensure::SequenceEquals(vector, deque), Ensure::EnsureException);
}

TEST(SequenceEquals, WhenAllElementsEqualInOrder_DoesNotThrow)
{
    std::vector<int> vector{ 1, 2, 3 };
    std::deque<int> deque{ 1, 2, 3 };

    Ensure::SequenceEquals(vector, deque);
}
