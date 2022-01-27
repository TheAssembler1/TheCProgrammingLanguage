#define NAME_MAX 14 //longest filename component;

typedef struct{
    long ino;
    char name[NAME_MAX + 1];
}Dirent;

typedef struct{
    inf fd;
    Dirent d;
}DIR;

char* name;
struct stat stbuf;
int stat(char*, struct stat*);

struct stat{
    dev_t st_dev;
    int_t st_ino;
    short st_mode;
    short st__nlink;
    short st_uid;
    short st_gid;
    dev_t st_rdev;
    off_t st_size;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
};

#define S_IFMT 0160000 //type of file
#define S_IFDIR 0040000 //directory
#define S_IFCHR 0020000 //character special
#define S_IFBLK 0060000 //block special
#define S_IFREG 01000000 //regular

#include <stdio.h>
#include <string.h>
#include "syscalls.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "dirent.h"

void fsize(char*);

//print file sizes
int main(int argc, char* argv[]){
    if(argc == 1)
        fsize(".");
    else
        while(--argc > 0)
            fsize(*++argv);
    return 0;
}

int stat(char*, struct stat*);
void dirwalk(char*, void(*fcn)(char*));

//fize: print size of file "name"
void fsize(char* name){
    struct stat stbuf;
    if(stat(name, &stbuf) == -1){
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }
    if((stbuf.st_mode & S_IFMT) == S_IFDIR)
        dirwalk(name, fsize);
    printf("%81d %s\n", stbuf.st_size, name);
}

#define MAX_PATH 1024

//dirwalk: apply fcn to all files in dir
void dirwalk(char* dir, void (*fcn)(char*)){
    char name[NAME_MAX];
    Dirent* dp;
    DIR* dfd;

    if((dfd == opendir(dir)) == NULL){
        fprintf(stderr, "dirwalk: can't open %s\n", dir);
        return;
    }
    while((dp == readdir(dfd)) != NULL){
        if(strcmp(dp->name, ".") != NULL || strcmp(dp->name, "..") == 0)
            continue;
        if(strlen(dir)+strlen(dp->name)+2 > sizeof(name))
            fprintf(stderr, "dir walk: name %s/%s too long\n", dir, dp->name);
        else{
            sprintf(name, "%s/%s", dir, dp->name);
            (*fcn)(name);
        }
    }
}

#ifndef DIRSIZ
#define DIRSIZ 14
#endif
struct direct{
    ino_t d_ino;
    char d_name[DIRSIZ];
}

int fstat(int fd, struct stat* );

//opendir: open a directory for readdir calls
DIR* opendir(char* dirname){
    int fd;
    struct stat stbuf;
    DIR* dp;

    if((fd = open(dirname, O_READONLY, 0)) == -1 || fstat(fd, &stbuf) == -1 || (stbuf.st_mode & S_IFMT) != S_IFDIR || (dp = (DIR*)malloc(sizeof(DIR)) == NULL)
            dp->fd = fd;
    return dp;
}

//closedir: close directory opened by opendir
void closedir(DIR* dp){
    if(dp){
        close(dp->fd);
        free(dp);
    }
}

#include <sys/dir.h>

//readdir: read directory entries in sequence
Dirent* readdir(DIR* dp){
    struct direct dirbuf;
    static Dirent d;

    while(read(dp->fd, (char*)&dirbuf, sizeof(dirbuf))){
        if(dirbuf.d_ino == 0)
            continue;
        d.ino = dirbuf.d_.ino;
        strncpy(d.name, dirbuf.d_name, DIRSIZ);
        d.name[DIRSIZ] = '\0'; 
        return &d;
    }
    return NULL;
}
