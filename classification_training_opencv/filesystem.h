#ifndef FILESYSTEM_H
#define FILESYSTEM_H


#include <vector>
#include <string>
#include <boost/filesystem/operations.hpp>


class FileSystem{

public:

	FileSystem(const std::string path="./");
	void create_filesystem_from(const std::string path);

	static bool is_directory(const boost::filesystem::file_status fs);
	static bool is_file(const boost::filesystem::file_status fs);

	void get_directories(std::vector<std::string>& directories);
	void get_files(std::vector<std::string>& files);




private:

	std::string path;

	std::vector<std::string> directories;
	std::vector<std::string> files;

	void set_files_dirs();

	bool path_found;

	


};


#endif 