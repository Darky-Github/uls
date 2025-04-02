#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define RESET "\033[0m"
#define BLUE "\033[34m" // Directories
#define GREEN "\033[32m" // Executables

void print_permissions(mode_t mode) {
    printf((mode & S_IRUSR) ? "r" : "-");
    printf((mode & S_IWUSR) ? "w" : "-");
    printf((mode & S_IXUSR) ? "x" : "-");
    printf((mode & S_IRGRP) ? "r" : "-");
    printf((mode & S_IWGRP) ? "w" : "-");
    printf((mode & S_IXGRP) ? "x" : "-");
    printf((mode & S_IROTH) ? "r" : "-");
    printf((mode & S_IWOTH) ? "w" : "-");
    printf((mode & S_IXOTH) ? "x" : "-");
}

void list_directory(const char *path, int show_hidden, int show_permissions) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *dir = opendir(path);
    if (!dir) {
        perror("uls");
        return;
    }
    
    while ((entry = readdir(dir)) != NULL) {
        if (!show_hidden && entry->d_name[0] == '.') continue;
        
        char fullpath[1024];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
        stat(fullpath, &file_stat);
        
        if (S_ISDIR(file_stat.st_mode)) printf(BLUE);
        else if (file_stat.st_mode & S_IXUSR) printf(GREEN);
        
        if (show_permissions) {
            print_permissions(file_stat.st_mode);
            printf(" ");
        }
        
        printf("%s%s\n", entry->d_name, RESET);
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    int show_hidden = 0, show_permissions = 0;
    const char *path = ".";
    
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-a") == 0) show_hidden = 1;
        else if (strcmp(argv[i], "-perm") == 0) show_permissions = 1;
        else path = argv[i];
    }
    
    list_directory(path, show_hidden, show_permissions);
    return 0;
}
