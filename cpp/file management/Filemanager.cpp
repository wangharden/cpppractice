#include "FileManager.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

FileManager::FileManager() : current_path(fs::current_path()) {}

std::string FileManager::get_file_size(uintmax_t size) {
    const char* units[] = {"B", "KB", "MB", "GB", "TB"};
    int i = 0;
    double dsize = static_cast<double>(size);
    while (dsize >= 1024 && i < 4) {
        dsize /= 1024;
        i++;
    }
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << dsize << " " << units[i];
    return ss.str();
}

std::string FileManager::get_time_string(const fs::file_time_type& ftime) {
    auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(ftime - fs::file_time_type::clock::now() + std::chrono::system_clock::now());
    std::time_t cftime = std::chrono::system_clock::to_time_t(sctp);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&cftime), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

std::vector<std::string> FileManager::list_directory() {
    std::vector<std::string> files;
    for (const auto& entry : fs::directory_iterator(current_path)) {
        files.push_back(entry.path().filename().string());
    }
    return files;
}

void FileManager::create_file(const std::string& filename) {
    std::ofstream(current_path / filename).close();
}

void FileManager::create_directory(const std::string& dirname) {
    fs::create_directory(current_path / dirname);
}

void FileManager::delete_file(const std::string& filename) {
    fs::remove(current_path / filename);
}

void FileManager::delete_directory(const std::string& dirname) {
    fs::remove_all(current_path / dirname);
}

void FileManager::copy_file(const std::string& source, const std::string& destination) {
    fs::copy_file(current_path / source, current_path / destination, fs::copy_options::overwrite_existing);
}

void FileManager::move_file(const std::string& source, const std::string& destination) {
    fs::rename(current_path / source, current_path / destination);
}

std::vector<std::string> FileManager::search_file(const std::string& pattern) {
    std::vector<std::string> matches;
    for (const auto& entry : fs::directory_iterator(current_path)) {
        if (entry.path().filename().string().find(pattern) != std::string::npos) {
            matches.push_back(entry.path().filename().string());
        }
    }
    return matches;
}

std::string FileManager::file_details(const std::string& filename) {
    fs::path filepath = current_path / filename;
    std::stringstream ss;
    ss << "File: " << filename << "\n";
    ss << "Size: " << get_file_size(fs::file_size(filepath)) << "\n";
    ss << "Created: " << get_time_string(fs::last_write_time(filepath)) << "\n";
    ss << "Last modified: " << get_time_string(fs::last_write_time(filepath)) << "\n";
    return ss.str();
}
