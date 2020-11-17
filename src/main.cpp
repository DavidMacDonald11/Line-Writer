#include "../include/main.h"

using namespace std;
using FileLine = OutputFile::Line;

// Writes a line to a file.
int main(int argc, char** argv)
{
    if(argc != 4)
    {
        cerr << "Usage: exeName writeFileName Line# \"String\"\n";
        return 1;
    }

    FileLine toWrite({argv[3], parseInt(argv[2])});
    OutputFile file(argv[1], toWrite);

    file.writeLine();

    return 0;
}

size_t parseInt(const string& intString)
{
    istringstream ss(intString);
    size_t num;
    ss >> num;
    return num;
}
