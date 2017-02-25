#include "filesystem.h"


#include <iostream>



FileSystem::FileSystem(const std::string path_):path(path_){

       create_filesystem_from(path);

      

}

void FileSystem::create_filesystem_from(const std::string path)
{
     if(boost::filesystem::exists(path)){
            set_files_dirs();

     }
     


     else{

     	    std::cout << path << " does not exits" << "\n";
     }
}

void FileSystem::set_files_dirs()
{
    boost::filesystem::directory_iterator end;
    for(boost::filesystem::directory_iterator itr(path);  itr != end; itr++)
    {
        if(is_directory(itr->status()))
        	directories.push_back(itr->path().string());

        else if(is_file(itr->status()))
        	files.push_back(itr->path().string());


        

    }

}

bool FileSystem::is_directory(const boost::filesystem::file_status fs)
{

	if(boost::filesystem::is_directory(fs))
		return true;
	else
		return false;
}

bool FileSystem::is_file(const boost::filesystem::file_status fs)
{

	if(boost::filesystem::is_regular_file(fs))
		return true;
	else
		return false;
}

void FileSystem::get_directories(std::vector<std::string>& directories)
{
      if(!this->directories.size()){

      	   std::cout << "The path is not set yet,cant get directories!!\n";
      	   return;
      }

      directories = this->directories;
}


void FileSystem::get_files(std::vector<std::string>& files)
{
	 if(!this->files.size()){

      	   std::cout << "The path is not set yet,cant get files!!\n";
      	   return;
      }
      files = this->files;

}