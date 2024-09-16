#include <gtest/gtest.h>
#include <gmock/gmock.h>

// Sample class to be mocked
class MyClass {
public:
    virtual ~MyClass() = default;
    virtual int add(int a, int b) = 0;
};

// Mock class
class MockMyClass : public MyClass {
public:
    MOCK_METHOD(int, add, (int a, int b), (override));
};

// Test case using GoogleMock
TEST(AdditionTest, HandlesPositiveInput) {
    MockMyClass mock;
    EXPECT_CALL(mock, add(1, 2)).WillOnce(testing::Return(3));
    EXPECT_EQ(mock.add(1, 2), 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
