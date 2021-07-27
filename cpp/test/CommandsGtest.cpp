////////////////////////////////////////////////////////////////////////////
/**
 *  @file   CommandsGtest.cpp
 *  @date   Fri April 21 2021
 *  @brief  Commands Unit Test Class
 */
////////////////////////////////////////////////////////////////////////////

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "MockCommand.h"
#include "Commands.h"

using namespace testing;
using ::testing::AtLeast;

class WhenTestingCommands: public ::testing::Test{};

TEST_F(WhenTestingCommands, WhenTestingCommands_FactoryReturnsBaseCommand)
{
    MockCommand command("Hello");
    EXPECT_CALL(command, execute())
        .Times(AtLeast(1));
    EXPECT_CALL(command, commandOutput())
        .Times(AtLeast(1));

    Commands commands("Hello");
    std::string output;
    ASSERT_FALSE(commands.run(output)); 
}

TEST_F(WhenTestingCommands, WhenTestingCommands_FactoryReturnsDirectory)
{
    MockCommand command("mkdir");
    ON_CALL(command, execute()) 
        .WillByDefault(Return(true));
    ON_CALL(command, commandOutput())
        .WillByDefault(Return("Created"));

    Commands commands("mkdir");
    std::string output;

    ASSERT_TRUE(command.commandOutput() == "Created");

}

TEST_F(WhenTestingCommands, WhenTestingCommands_FactoryReturnsNothing)
{
    Commands commands("mkdir");
    ASSERT_EQ("mkdir", "mkdir");
}