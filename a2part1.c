#include <sys/types.h>

#include <sys/stat.h>

#include <stdlib.h>

#include <unistd.h>

#include <fcntl.h> // for creat

#include <dirent.h> // for read dir

#include <errno.h>

#include <stdio.h>

#include <limits.h>

#include <time.h>

#include <string.h>

#include <pwd.h>

#include <grp.h>

#include <locale.h>

#include <langinfo.h>

#include <stdint.h>

//*************************
DIR * dir;
DIR * dir1;
int c1 = 0;
int c2 = 0;
struct dirent * entry;
struct dirent * entry1;

struct stat fileStat1;
struct stat fileStat;
int info;
char cwd[512];
//************************

void subTraverse(DIR * directory) {
  while ((entry1 = readdir(directory)) != NULL) {

    printf("\nInformation for   %s\n", entry1 -> d_name);

    info = stat(entry1 -> d_name, & fileStat1);

    printf("---------------------------------\n");
    printf("File Size: \t\t%d bytes\n", fileStat1.st_size);
    printf("Number of Links: \t%d\n", fileStat1.st_nlink);
    //printf("File inode: \t\t%d\n", fileStat1.st_ino);
    printf("Owner's User ID: \t%d\n", fileStat1.st_uid);
    //printf("File Mode: \t\t%d\n", fileStat1.st_mode);

    printf("File Permissions: \t");
    printf((S_ISDIR(fileStat1.st_mode)) ? "d" : "-");
    //printf( (S_ISLNK(fileStat1.st_mode)) ? "l" : "-");
    printf((fileStat1.st_mode & S_IRUSR) ? "r" : "-");
    printf((fileStat1.st_mode & S_IWUSR) ? "w" : "-");
    printf((fileStat1.st_mode & S_IXUSR) ? "x" : "-");
    printf((fileStat1.st_mode & S_IRGRP) ? "r" : "-");
    printf((fileStat1.st_mode & S_IWGRP) ? "w" : "-");
    printf((fileStat1.st_mode & S_IXGRP) ? "x" : "-");
    printf((fileStat1.st_mode & S_IROTH) ? "r" : "-");
    printf((fileStat1.st_mode & S_IWOTH) ? "w" : "-");
    printf((fileStat1.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");
  }
}

//***************
void traverse() {
  while ((entry = readdir(dir)) != NULL) {

    printf("\nInformation for   %s\n", entry -> d_name);
    //printf("%s\n", entry->d_name);

    info = stat(entry -> d_name, & fileStat);

    printf("---------------------------------\n");
    printf("File Size: \t\t%d bytes\n", fileStat.st_size);
    printf("Number of Links: \t%d\n", fileStat.st_nlink);
    printf("File inode: \t\t%d\n", fileStat.st_ino);
    printf("Owner's User ID: \t%d\n", fileStat.st_uid);
    printf("File Mode: \t\t%d\n", fileStat.st_mode);


    printf("File Permissions: \t");
    printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    //printf( (S_ISLNK(fileStat.st_mode)) ? "l" : "-");
    printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");

    info = lstat(entry -> d_name, & fileStat);
    if (S_ISLNK(fileStat.st_mode)) printf("Link: \t\t\tYes\n");

    if (strcmp(entry -> d_name, "folder1")&&(c1 == 0 ))
    {
      char home[] = "/home/010/y/yx/yxt170330/cs3377/a2part1d/folder1";
      if ((dir1 = opendir(home)) == NULL)
	 	perror("opendir() error");
      subTraverse(dir1);
      closedir(dir1);
      c1 = 1;
    }

    else if (strcmp(entry -> d_name, "folder2")&&(c2==0) )
    {
      char home[] = "/home/010/y/yx/yxt170330/cs3377/a2part1d/folder2";
       if ((dir1 = opendir(home)) == NULL)
	   perror("opendir() error");
       subTraverse(dir1);
       closedir(dir1);
	c2 =1;
     }
}
}

int main(int argc, char * argv[]) {
  int folder;
  int file;
  int link; // file types return value holder variable
	// make all the directories as given by the question
  folder = mkdir("/home/010/y/yx/yxt170330/cs3377/a2part1d", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

  chdir("a2part1d");

  folder = mkdir("/home/010/y/yx/yxt170330/cs3377/a2part1d/folder1", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

  folder = mkdir("/home/010/y/yx/yxt170330/cs3377/a2part1d/folder2", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

  char * filename = "/home/010/y/yx/yxt170330/cs3377/a2part1d/folder1/file1.txt";
  mode_t mode = S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH;
  file = creat(filename, mode);

  filename = "/home/010/y/yx/yxt170330/cs3377/a2part1d/folder1/file2.txt";
  mode = S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH;
  file = creat(filename, mode);

  filename = "/home/010/y/yx/yxt170330/cs3377/a2part1d/folder2/file3.txt";
  mode = S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH;
  file = creat(filename, mode);

  const char * actualpath = "/home/010/y/yx/yxt170330/cs3377/a2part1d/folder2/file3.txt";
  const char * sympath = "/home/010/y/yx/yxt170330/cs3377/a2part1d/link1";

  link = symlink(actualpath, sympath);

  //********************************************

  getcwd(cwd, sizeof(cwd));
  printf("current working directory is: %s\n", cwd);
  if ((dir = opendir(cwd)) == NULL)
    perror("opendir() error");

  else {
    puts("Information on directory contents:");
    traverse();
    closedir(dir);
  }

  //**************************

  chdir("/home/010/y/yx/yxt170330/cs3377/a2part1d/folder1");

  chmod("/home/010/y/yx/yxt170330/cs3377/a2part1d/folder1/file2.txt", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

  printf("\nTask 3 Complete\n");
  //***************************

  if ((dir = opendir("/home/010/y/yx/yxt170330/cs3377/a2part1d/folder1")) == NULL)
    perror("opendir() error");

  else {
    puts("Folder 1 directory entries:");
    FILE * fp = fopen("file1.txt", "w");
    if (fp == NULL) {
      puts("Couldn't open file");
      exit(0);
    } else {
      while ((entry = readdir(dir)) != NULL) {
       // printf("%s\n", entry -> d_name);
        fputs(entry -> d_name, fp);
        fputs("\n", fp);

      }
      fclose(fp);
      printf("Task 4 Complete\n");
    }

    closedir(dir);
  }

  exit(0);
}
