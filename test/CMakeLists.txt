add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTest.cpp DateFixture.cpp TodoListFixture.cpp ActivityFixture.cpp)
add_executable(runUnitTest ${TEST_SOURCE_FILES})
target_link_libraries(runUnitTest gtest gtest_main core)