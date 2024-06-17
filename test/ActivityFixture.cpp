#include "gtest/gtest.h"
#include "../Activity.h"

TEST(ActivityFixture,Constructor){
    Activity act1("prova", "descrizione",Date(1,1,2024), Priority::low);
    ASSERT_THROW(Activity act("", "",Date(1,1,2024), Priority::low), std::invalid_argument);
    ASSERT_THROW(Activity act(" ", "",Date(1,1,2024), Priority::low), std::invalid_argument);
    ASSERT_THROW(Activity act("prova", "",Date(1,1,2024), Priority::low), std::invalid_argument);
    ASSERT_NO_THROW(Activity act("prova", "descrizione",Date(1,1,2024), Priority::low));
    cout<<act1.toString();
};
