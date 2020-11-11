#include "../include/main.h"

using namespace std;
using FileLine = OutputFile::FileLine;

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

OutputFile::OutputFile(const string& name, const FileLine& toWrite)
    : name(name), lines(readFile()), toWrite(toWrite) {}

OutputFile::Lines OutputFile::readFile()
{
    Lines lines;
    ifstream file(name);

    for(string line; getline(file, line); )
        lines.push_back(line);

    file.close();
    return lines;
}

void OutputFile::writeLine()
{
    for(; toWrite.lineNum > lines.size(); lines.push_back("\n"));
    lines[toWrite.lineNum - 1] = toWrite.line;

    ofstream file(name);

    for(string line : lines)
    {
        file << line;

        if(line != "\n")
            file << "\n";
    }

    file.close();
}

size_t parseInt(const string& str)
{
    istringstream ss(str);
    size_t num;
    ss >> num;
    return num;
}
