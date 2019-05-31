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
  printf("List for directory: %s\n", input);

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

    // if file is a directory, print <DIR> instead of the filesize

    if ((buf.st_mode & S_IFDIR) != 0) {
      printf("    <DIR>  %s\n", ent->d_name);
      // now we're inside of a directory
      // let's repeat process from above to print one level down for each directory
      struct dirent *subent;
      DIR *subdir = opendir(ent->d_name);
      while (1) {
        subent = readdir(subdir);
        if (subent == NULL) {
          break;
        }
        struct stat subbuf;
        stat(subent->d_name, &subbuf);

        if ((subbuf.st_mode & S_IFDIR) != 0) {
          printf("            <DIR>  %s\n", subent->d_name);
        } else if ((subbuf.st_mode & S_IFREG) != 0) {
          printf("      %10lld  %s\n", subbuf.st_size, subent->d_name);

        }
      }
    } else if ((buf.st_mode & S_IFREG) != 0) {
      printf("%10lld  %s\n", buf.st_size, ent->d_name);
    }
  }


  // Close directory
  closedir(dir);

  return 0;
}