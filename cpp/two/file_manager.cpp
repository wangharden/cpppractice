#include "file_manager.hpp"
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <cstring>
#include <ctime>  // 添加这个头文件

// 列出目录内容
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

// 创建文件
void createFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file) {
        std::cout << "File created: " << filename << std::endl;
    } else {
        std::cerr << "Error creating file." << std::endl;
    }
}

// 创建目录
void createDirectory(const std::string& dirname) {
    // Windows 平台 mkdir 只能接受一个参数
    if (mkdir(dirname.c_str()) == 0) {
        std::cout << "Directory created: " << dirname << std::endl;
    } else {
        std::cerr << "Error creating directory." << std::endl;
    }
}

// 删除文件或目录
void deleteFile(const std::string& filename) {
    if (remove(filename.c_str()) == 0) {
        std::cout << "File/Directory deleted: " << filename << std::endl;
    } else {
        std::cerr << "Error deleting file/directory." << std::endl;
    }
}

// 复制文件
void copyFile(const std::string& source, const std::string& destination) {
    std::ifstream src(source, std::ios::binary);
    std::ofstream dst(destination, std::ios::binary);

    if (src && dst) {
        dst << src.rdbuf();
        std::cout << "File copied to: " << destination << std::endl;
    } else {
        std::cerr << "Error copying file." << std::endl;
    }
}

// 移动文件
void moveFile(const std::string& source, const std::string& destination) {
    if (rename(source.c_str(), destination.c_str()) == 0) {
        std::cout << "File moved to: " << destination << std::endl;
    } else {
        std::cerr << "Error moving file." << std::endl;
    }
}

// 搜索文件
void searchFile(const std::string& path, const std::string& filename) {
    DIR* dir;
    struct dirent* entry;

    if ((dir = opendir(path.c_str())) != nullptr) {
        while ((entry = readdir(dir)) != nullptr) {
            if (std::strcmp(entry->d_name, filename.c_str()) == 0) {
                std::cout << "File found: " << path << "/" << entry->d_name << std::endl;
                closedir(dir);
                return;
            }
        }
        closedir(dir);
        std::cerr << "File not found." << std::endl;
    } else {
        std::cerr << "Could not open directory: " << path << std::endl;
    }
}

// 显示文件信息
void displayFileInfo(const std::string& filename) {
    struct stat file_stat;
    if (stat(filename.c_str(), &file_stat) == 0) {
        std::cout << "File: " << filename << std::endl;
        std::cout << "Size: " << file_stat.st_size << " bytes" << std::endl;
        // 解决 ctime 的问题
        std::cout << "Last modified: " << std::ctime(&file_stat.st_mtime); // 使用 std::ctime
    } else {
        std::cerr << "File does not exist." << std::endl;
    }
}

