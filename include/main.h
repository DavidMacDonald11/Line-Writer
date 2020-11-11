#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

// Basic storage for file information.
class OutputFile
{
public:
    struct FileLine
    {
        std::string line;
        size_t lineNum;
    };
private:
    using Lines = std::vector<std::string>;

    std::string name;
    Lines lines;
    FileLine toWrite;

public:
    OutputFile(const std::string& name, const FileLine& toWrite);

    // Writes the line to the file.
    void writeLine();

private:
    Lines readFile();
};

// Parses an integer from a string.
size_t parseInt(const std::string& str);
