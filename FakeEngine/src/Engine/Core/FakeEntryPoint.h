#pragma once

#include "FakeApplication.h"

extern FakeApplication *CreateApp();

int main(int argc, char *argv[])
	{
	auto app = CreateApp();
	app->Run();
	delete app;

	return 0;
	}