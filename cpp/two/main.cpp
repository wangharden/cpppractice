#include "file_manager.hpp"
#include <iostream>

void displayMenu() {
    std::cout << "File Management System" << std::endl;
    std::cout << "1. List Directory" << std::endl;
    std::cout << "2. Create File" << std::endl;
    std::cout << "3. Create Directory" << std::endl;
    std::cout << "4. Delete File/Directory" << std::endl;
    std::cout << "5. Copy File" << std::endl;
    std::cout << "6. Move File" << std::endl;
    std::cout << "7. Search File" << std::endl;
    std::cout << "8. Display File Info" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

int main() {
    int choice;
    std::string path, filename, destination;

    while (true) {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter directory path: ";
                std::cin >> path;
                listDirectory(path);
                break;
            case 2:
                std::cout << "Enter filename: ";
                std::cin >> filename;
                createFile(filename);
                break;
            case 3:
                std::cout << "Enter directory name: ";
                std::cin >> filename;
                createDirectory(filename);
                break;
            case 4:
                std::cout << "Enter file/directory to delete: ";
                std::cin >> filename;
                deleteFile(filename);
                break;
            case 5:
                std::cout << "Enter source file: ";
                std::cin >> filename;
                std::cout << "Enter destination: ";
                std::cin >> destination;
                copyFile(filename, destination);
                break;
            case 6:
                std::cout << "Enter source file: ";
                std::cin >> filename;
                std::cout << "Enter destination: ";
                std::cin >> destination;
                moveFile(filename, destination);
                break;
            case 7:
                std::cout << "Enter directory path: ";
                std::cin >> path;
                std::cout << "Enter filename to search: ";
                std::cin >> filename;
                searchFile(path, filename);
                break;
            case 8:
                std::cout << "Enter filename: ";
                std::cin >> filename;
                displayFileInfo(filename);
                break;
            case 0:
                return 0;
            default:
                std::cerr << "Invalid choice." << std::endl;
        }
        std::cout << std::endl;
    }
}
