#include "Settings.h"

#include <iostream>

Settings::Settings(int argc, char** argv)
{
	ParseArguments(argc, argv);
}

void Settings::ParseArguments(int argc, char** argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string arg = argv[i];

        if (arg == "-w" && i + 1 < argc)
        {
            m_width = std::atoi(argv[++i]);
        }
        else if (arg == "-h" && i + 1 < argc)
        {
            m_height = std::atoi(argv[++i]);
        }
    }
}
