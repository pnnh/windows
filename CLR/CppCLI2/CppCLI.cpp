#include "pch.h"

#include "CppCLI.h"
#include <iostream>

#include "Helper.h"
#include "gliese/logger/logger.h"
#include "quark/services/logger/logger.h"


using namespace System;

int CppCLI::Logger::Info(String^ message)
{
	Console::WriteLine(message);
	std::wcout << L"Hello from C++" << std::endl;

	gliese::Logger::LogInfo("helloGliese2");
	quark::Logger::LogInfo("helloQuark2");

	auto result = helper::Helper::Write("Hello from Helper");

	return result * 10;
}
