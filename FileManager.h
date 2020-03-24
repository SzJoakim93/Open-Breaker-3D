#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <dirent.h>
#include <sys/stat.h>

#include "char_list.h"
#include "list.h"
#include "vector.h"
    
void str_split_list(char_list * splited, char * base, char c, int * sum);
void load_files_from_txt(char_list * files, char * path, int * sum);
void load_files_from_dir(char_list * files, char * path, char * extension, int * sum);
bool is_dir(const char* path);

#endif //File_manager_H