#include "Settings.h"
#include <string>

Settings::Settings(int argc, char** argv)
    : m_screenWidth(100)
    , m_screenHeight(20)
    , m_meshResolution(32)
{
    _ParseArguments(argc, argv);
}

void Settings::_ParseArguments(int argc, char** argv)
{
    // Elegant solution from @T.Rosselet
    for (int i = 1; i < argc; i++) //i starts at 1 because command line arguments start with argv[1] (argv[0] is the name of the exe)
    {
        std::string arg = argv[i];
        if (arg == "-w" && i + 1 < argc)
        {
            m_screenWidth = std::atoi(argv[i + 1]);
            i++;
        }
        else if (arg == "-h" && i + 1 < argc)
        {
            m_screenHeight = std::atoi(argv[i + 1]);
            i++;
        }
        else if (arg == "-r" && i + 1 < argc)
        {
            m_meshResolution = std::atoi(argv[i + 1]);
            i++;
        }
    }
}