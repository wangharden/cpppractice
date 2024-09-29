#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP

#include <string>

// 列出目录内容
void listDirectory(const std::string& path);

// 创建文件
void createFile(const std::string& filename);

// 创建目录
void createDirectory(const std::string& dirname);

// 删除文件或目录
void deleteFile(const std::string& filename);

// 复制文件
void copyFile(const std::string& source, const std::string& destination);

// 移动文件
void moveFile(const std::string& source, const std::string& destination);

// 搜索文件
void searchFile(const std::string& path, const std::string& filename);

// 显示文件信息
void displayFileInfo(const std::string& filename);

#endif
