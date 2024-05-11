#include <stdexcept>
#include "gtest/gtest.h"
#include "../Date.h"
#include <memory>


class DateFixture : public ::testing::Test{

protected:
    //date buone, quelle non buone non le posso avere dato che il costruttore lancia un eccezione
    Date normalDate = Date(1,12,2019);
    Date leapYearDate = Date (29, 2, 2024);
    Date anotherNormalDate = Date (1, 12, 2021);


};

//test
TEST_F(DateFixture, constructor){
    ASSERT_THROW(Date date = Date (31,4,2017), std::invalid_argument); //giorno non esistente
    ASSERT_THROW(Date date = Date(30,2,2016), std::invalid_argument);
    EXPECT_THROW(Date date = Date(29,2,2023), std::invalid_argument);
    ASSERT_NO_THROW(Date date = Date (1,12,2020));

}
TEST_F(DateFixture, operatorOverloading){
    ASSERT_TRUE(normalDate < anotherNormalDate);
    ASSERT_FALSE(leapYearDate < anotherNormalDate);
}
