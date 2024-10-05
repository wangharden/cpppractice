#include "FileManager.h"
#include <iostream>
#include <sstream>

void print_help() {
    std::cout << "可用命令:\n"
              << "list - 列出当前目录内容\n"
              << "create_file <文件名> - 创建新文件\n"
              << "create_dir <目录名> - 创建新目录\n"
              << "delete_file <文件名> - 删除文件\n"
              << "delete_dir <目录名> - 删除目录\n"
              << "copy <源文件> <目标文件> - 复制文件\n"
              << "move <源文件> <目标文件> - 移动文件\n"
              << "search <模式> - 搜索文件\n"
              << "details <文件名> - 显示文件详细信息\n"
              << "exit - 退出程序\n";
}

int main() {
    FileManager fm;
    std::string command;
    std::vector<std::string> args;

    while (true) {
        std::cout << "请输入命令 (输入 'help' 查看帮助): ";
        std::getline(std::cin, command);

        std::istringstream iss(command);
        args.clear();
        std::string arg;
        while (iss >> arg) {
            args.push_back(arg);
        }

        if (args.empty()) continue;

        std::string action = args[0];

        if (action == "exit") {
            break;
        } else if (action == "help") {
            print_help();
        } else if (action == "list") {
            for (const auto& file : fm.list_directory()) {
                std::cout << file << "\n";
            }
        } else if (action == "create_file" && args.size() == 2) {
            fm.create_file(args[1]);
        } else if (action == "create_dir" && args.size() == 2) {
            fm.create_directory(args[1]);
        } else if (action == "delete_file" && args.size() == 2) {
            fm.delete_file(args[1]);
        } else if (action == "delete_dir" && args.size() == 2) {
            fm.delete_directory(args[1]);
        } else if (action == "copy" && args.size() == 3) {
            fm.copy_file(args[1], args[2]);
        } else if (action == "move" && args.size() == 3) {
            fm.move_file(args[1], args[2]);
        } else if (action == "search" && args.size() == 2) {
            for (const auto& file : fm.search_file(args[1])) {
                std::cout << file << "\n";
            }
        } else if (action == "details" && args.size() == 2) {
            std::cout << fm.file_details(args[1]);
        } else {
            std::cout << "无效的命令，请输入 'help' 查看可用命令。\n";
        }
    }

    return 0;
}
