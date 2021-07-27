////////////////////////////////////////////////////////////////////////////
/**
 *  @file   MockCommand.h
 *  @date   Fri April 26 2021
 *  @brief  Command Mock Unit Test Class
 */
////////////////////////////////////////////////////////////////////////////
#ifndef _MOCK_COMMAND_H
#define _MOCK_COMMAND_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>
#include "Command.h"

class MockCommand : public Command 
{
    public:
        MockCommand(const std::string &commands) : Command(commands) {};
        MOCK_METHOD(bool, execute, (), (override));
        MOCK_METHOD(std::string, commandHelp, (), (override));
        MOCK_METHOD(std::string, commandOutput, (), (override));
};


#endif