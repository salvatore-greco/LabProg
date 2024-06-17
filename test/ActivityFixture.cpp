#include "gtest/gtest.h"
#include "../Activity.h"

TEST(ActivityFixture,Constructor){
    ASSERT_THROW(Activity act("", "",Date(1,1,2024), Priority::low), std::invalid_argument);
    ASSERT_THROW(Activity act(" ", "",Date(1,1,2024), Priority::low), std::invalid_argument);
    ASSERT_THROW(Activity act("prova", "",Date(1,1,2024), Priority::low), std::invalid_argument);
    ASSERT_NO_THROW(Activity act("prova", "descrizione",Date(1,1,2024), Priority::low));
};
