#include "../include/output_file.h"

using namespace std;
using Line = OutputFile::Line;

OutputFile::OutputFile(const string& name, const Line& toWrite)
    : name(name), toWrite(toWrite), lines(readFile()) {}

OutputFile::Lines OutputFile::readFile() const
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
