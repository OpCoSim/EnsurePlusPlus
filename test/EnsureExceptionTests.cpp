#include <gtest/gtest.h>
#include "EnsurePlusPlus.hpp"

using namespace Ensure;

TEST(EnsureException, ConstructorCorrectlySetsErrorMessage)
{
    auto constexpr message = "this is a test error message";

    auto exception = EnsureException(message);

    ASSERT_STREQ(message, exception.what());
}
