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
    using FileList = std::vector<FileLine>;

    std::string name;
    FileList fileList;
    FileLine toWrite;

public:
    OutputFile(const std::string& name, const FileLine& toWrite);

    // Writes the line to the file.
    void writeLine() const;

private:
    FileList readFile();
};

// Parses an integer from a string.
size_t parseInt(const std::string& str);
