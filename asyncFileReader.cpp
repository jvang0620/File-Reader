#include <iostream>
#include <fstream>
#include <string>
#include <future>

// Function to read a file asynchronously
std::string readFileAsync(const std::string &filePath)
{
    std::ifstream file(filePath);
    if (file.is_open())
    {
        // Reading file content
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();
        return content;
    }
    else
    {
        // Throwing a runtime exception for error  handling
        throw std::runtime_error("C++ Error: Unable to open file");
    }
}

int main()
{
    std::string filePath = "sample.txt";

    // Using std::async for asynchronous execution
    auto future = std::async(std::launch::async, readFileAsync, filePath);

    try
    {
        // Getting the result of the asynchronous operation
        std::string content = future.get();
        std::cout << "C++ Content: " << content << std::endl;
    }
    catch (const std::exception &e)
    {
        // Handling errors
        std::cerr << "C++ Error: " << e.what() << std::endl;
    }

    return 0;
}