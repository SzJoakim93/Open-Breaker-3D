#include "FileManager.h"
#include <cstdio>

void str_split_list(char_list * splited, char * base, char c, int * sum)
{
    *sum = 0;
    int i=0, k=0;

    char new_string[32];

    for (; base[i] != 0; i++)
    {
        if (base[i] == c)
        {
            splited->insert(new_string);
            new_string[0] = 0;
            k=0;
            (*sum)++;
        }
        else
        {
            new_string[k] = base[i];
            new_string[k+1] = 0;
            k++;
        }
    }

    splited->insert(new_string);
    (*sum)++;
}

void load_files_from_txt(char_list * files, char * path, int * sum)
{
    *sum = 0;
    FILE * file = fopen(path, "r");
    if (file == 0)
    {
        fprintf(stderr, "Cannot open text file: %s", path);
        strcpy(path, "error.bmp");
        return;
    }
    else
    {
        while (!feof(file))
        {
            char new_file[32];
            fscanf(file, "%s", new_file);
            files->insert(new_file);
            (*sum)++;
        }
        fclose(file);
    }
}

void load_files_from_dir(char_list * files, char * path, char * extension, int * sum)
{
    *sum = 0;
    DIR *dir;
    struct dirent *ent;
    dir = opendir(path);
    int i=-2;
    while ((ent = readdir (dir)) != NULL)
    {
        if (i>-1)
        {
            char cextension[8];
            int j=0;
            while (ent->d_name[j] != '.' && j < strlen(ent->d_name))
                j++;

            int k;
            for (k=0; ent->d_name[j+k] != 0; k++)
                cextension[k] = ent->d_name[j+k];
            cextension[k] = 0;

            for (int k=0; cextension[k] != 0; k++)
                if (cextension[k] > 96 && cextension[k] < 123)
                    cextension[k] -= 32;


            if (!strcmp(cextension, extension))
            {
                char temp[32];
                strcpy(temp, path);
                strcat(temp, "/");
                strcat(temp, ent->d_name);

                files->insert(temp);
                (*sum)++;
            }
        }
        i++;
    }
}

bool is_dir(const char* path)
{
    struct stat buf;
    stat(path, &buf);
    return S_ISDIR(buf.st_mode);
}