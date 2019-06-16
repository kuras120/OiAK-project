ADD_EXECUTABLE( ut
                UnitTests.cpp FloatingPointConstructorTest.cpp FloatingPointAdderTest.cpp FloatingPointPerformanceTest.cpp)

INCLUDE_DIRECTORIES( mocks )

ADD_DEPENDENCIES( ut GTEST )

TARGET_LINK_LIBRARIES( ut
                       FLOATING_POINT
                       gtest
                       gmock
                       gtest_main
                       pthread
 )

ADD_TEST( UT ut )