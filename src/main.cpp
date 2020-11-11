#include "../include/main.h"

using namespace std;
using FileLine = OutputFile::FileLine;

int main(int argc, char** argv)
{
    if(argc != 4)
    {
        cerr << "Usage: exeName writeFileName Line# \"String\"\n";
        return 1;
    }

    FileLine fileLine({argv[3], parseInt(argv[2])});
    OutputFile file(argv[1], fileLine);

    return 0;
}

OutputFile::OutputFile(const string& name, const FileLine& toWrite)
    : name(name), fileList(readFile()), toWrite(toWrite) {}

OutputFile::FileList OutputFile::readFile()
{
    FileList fileList;
    ifstream file(name);

    string line;
    for(size_t i = 1; getline(file, line); ++i)
    {
        fileList.push_back({line, i});
    }

    file.close();
    return fileList;
}

void OutputFile::writeLine() const 
{
    
}

size_t parseInt(const string& str)
{
    istringstream ss(str);
    size_t num;
    ss >> num;
    return num;
}
