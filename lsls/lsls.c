#include <stdio.h>
#include <dirent.h>
// stdlib.h to get access to exit()
#include <stdlib.h>
// gives us access to stat()
#include <sys/stat.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line

  // if we don't have 1 argument after ./lsls, exit the program and print error message
  if (argc != 2) {
    fprintf(stderr, "arguments should be ./lsls [directory_name]\n");
    exit(1);
  }

  // input directory is 2nd argument in command line
  char *input = argv[1];

  // Open directory
  DIR *dir = opendir(input);

  // if no directory, exit the program
  if (dir == NULL) {
    fprintf(stderr, "Error opening '%s'\n", argv[1]);
  }

  // Repeatly read and print entries

  // pointer to dirent structure from dirent.h
  struct dirent *ent;
  // loop through enttries and print their names
  while (1) {
    ent = readdir(dir);
    // if no more entries, break out of loop
    if (ent == NULL) {
      break;
    }

    // initialize buffer to hold size of file
    struct stat buf;
    stat(ent->d_name, &buf);

    printf("  %lld  %s\n", buf.st_size, ent->d_name);
  }


  // Close directory
  closedir(dir);

  return 0;
}