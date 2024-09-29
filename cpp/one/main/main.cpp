#include <iostream>
#include <string>
#include <dirent.h>  // POSIX API for directory operations

void listDirectory(const std::string& path) {
    DIR* dir;
    struct dirent* entry;

    if ((dir = opendir(path.c_str())) != nullptr) {
        while ((entry = readdir(dir)) != nullptr) {
            std::cout << entry->d_name << std::endl;  // 打印文件名
        }
        closedir(dir);
    } else {
        std::cerr << "Could not open directory: " << path << std::endl;
    }
}

int main() {
    std::string path = ".";  // 当前目录
    std::cout << "Contents of current directory:" << std::endl;
    listDirectory(path);
    return 0;
}
