#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

// Basic storage for file information.
class OutputFile
{
public:
    struct Line
    {
        std::string line;
        size_t lineNum;
    };
private:
    using Lines = std::vector<std::string>;

    const std::string name;
    const Line toWrite;
    Lines lines;

public:
    OutputFile(const std::string& name, const Line& toWrite);

    // Writes the line to the file.
    void writeLine();
private:
    Lines readFile() const;
};
