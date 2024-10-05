#pragma once

#include <string>
#include <vector>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

class FileManager {
private:
    fs::path current_path;
    std::string get_file_size(uintmax_t size);
    std::string get_time_string(const fs::file_time_type& ftime);

public:
    FileManager();
    std::vector<std::string> list_directory();
    void create_file(const std::string& filename);
    void create_directory(const std::string& dirname);
    void delete_file(const std::string& filename);
    void delete_directory(const std::string& dirname);
    void copy_file(const std::string& source, const std::string& destination);
    void move_file(const std::string& source, const std::string& destination);
    std::vector<std::string> search_file(const std::string& pattern);
    std::string file_details(const std::string& filename);
};
