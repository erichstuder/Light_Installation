#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <filesystem>

using ::testing::StrEq;

#include <simulator.h>

class LedPattern_Stub: public LedPattern_Interface {
    public:
        uint16_t getIterations() override {
            return 1;
        }

        Color_t getColor(Pixel_t pixel, uint16_t iteration) override {
            return Color_t{0, 0, 0};
        }
};

class LedPattern_Mock: public LedPattern_Interface {
    public:
        // LedPattern_Mock() {
        //     ON_CALL(*this, getIterations()).WillByDefault(::testing::Return(1));
        //     ON_CALL(*this, getColor(::testing::_, ::testing::_)).WillByDefault(::testing::Return(Color_t{0, 0, 0}));
        // }

        MOCK_METHOD(uint16_t, getIterations, (), (override));
        MOCK_METHOD(Color_t, getColor, (Pixel_t pixel, uint16_t iteration), (override));
};

class Animator_Stub: public Animator_Interface {
    public:
        void animate(const char* file_name) override {}
};

class Animator_Mock: public Animator_Interface {
    public:
        MOCK_METHOD(void, animate, (const char* file_name), (override));
};


TEST(Simulator_Test, Start_Simulator__Animate) {
    RecordProperty("links", "F_001");

    Animator_Mock animator_mock;
    LedPattern_Stub pattern_stub;

    EXPECT_CALL(animator_mock, animate(StrEq("build/pattern.dat")))
        .Times(1);

    simulator(&pattern_stub, &animator_mock);
}

TEST(Simulator_Test, Start_Simulator__Create_Pattern_File) {
    RecordProperty("links", "F_001");

    const char* file_name = "build/pattern.dat";
    // remove file if it exists
    std::filesystem::path filePath = file_name;
    if(std::filesystem::exists(filePath)) {
        std::filesystem::remove(filePath);
    }

    Animator_Stub animator_stub;
    LedPattern_Stub pattern_stub;
    simulator(&pattern_stub, &animator_stub);

    ASSERT_TRUE(std::filesystem::exists(filePath)) << "File " << file_name << " does not  exist";
}
