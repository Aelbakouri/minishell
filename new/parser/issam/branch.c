#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 128

char* get_current_branch_name() {
	FILE* pipe = popen("git rev-parse --abbrev-ref HEAD", "r");
	if (!pipe)
		return NULL;

	char buffer[BUFFER_SIZE];
	fgets(buffer, BUFFER_SIZE, pipe);
	pclose(pipe);

    // Remove the trailing newline character
	size_t len = strlen(buffer);
	if (len > 0 && buffer[len - 1] == '\n')
		buffer[len - 1] = '\0';

    return strdup(buffer);
}

int main() {
	char* branchName = get_current_branch_name();
	if (branchName) {
		printf("Current branch: %s\n", branchName);
		free(branchName);
	}

	return 0;
}


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <fcntl.h>
// #include <unistd.h>

// #define BUFFER_SIZE 128

// char* get_current_branch_name() {
//     int fileDescriptor = open(".git/HEAD", O_RDONLY);
//     if (fileDescriptor == -1) {
//         printf("Error opening .git/HEAD file.\n");
//         return NULL;
//     }

//     char buffer[BUFFER_SIZE];
//     ssize_t bytesRead = read(fileDescriptor, buffer, BUFFER_SIZE);
//     close(fileDescriptor);

//     if (bytesRead == -1) {
//         printf("Error reading .git/HEAD file.\n");
//         return NULL;
//     }

//     // Parse the branch name from the file contents
//     char* branchStart = strstr(buffer, "ref: refs/heads/");
//     if (!branchStart) {
//         printf("Invalid .git/HEAD file format.\n");
//         return NULL;
//     }

//     char* branchName = strdup(branchStart + strlen("ref: refs/heads/"));
//     size_t len = strlen(branchName);

//     // Remove the trailing newline character
//     if (len > 0 && branchName[len - 1] == '\n')
//         branchName[len - 1] = '\0';

//     return branchName;
// }

// int main() {
//     char* branchName = get_current_branch_name();
//     if (branchName) {
//         printf("Current branch: %s\n", branchName);
//         free(branchName);
//     }

//     return 0;
// }
