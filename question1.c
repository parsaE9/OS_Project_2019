#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
int main(int argc, char *argv[]) {

	int fd[2];
    long int even = 0, num = 0, input, digit;
    char str3[1000];
	// create pipe descriptors
	pipe(fd);
	int id = fork();
	if (id > 0) {
		// parent: writing only, so close read-descriptor.
		//close(fd[0]);
        printf("Enter an integer number: ");
    	scanf("%ld", &num);
		// send the childID on the write-descriptor.
		write(fd[1], &num, sizeof(num));
		//printf("Parent send input = %ld to the child.\n", num);
		sleep(1);
		//printf("hi\n");
		read(fd[0], &str3, sizeof(str3));
		printf("%s\n",str3);
		// close the write descriptor
		//close(fd[1]);
	}
	else if (id == 0) {
		// child: reading only, so close the write-descriptor
		//close(fd[1]);
        // now read the data (will block until it succeeds)
		read(fd[0], &num, sizeof(num));
		//printf("Child received argument = %ld\n",num);
        input = num;
    	while (num > 0) {
    		digit = num % 10;
    		num = num / 10;
    		if (digit % 2 == 0)
    			even = even + digit;
    	}

        // Get the two Strings to be concatenated
        char str1[100] = "the sum of even digits in the input number :";
        int str2 = even;
        char res[60];
        int len = 0;
        for(; str2 > 0; ++len)
        {
            res[len] = str2%10+'0';
            str2/=10;
        }
        res[len] = 0; //null-terminating
        //now we need to reverse res
        for(int i = 0; i < len/2; ++i)
        {
        char c = res[i];
        res[i] = res[len-i-1];
        res[len-i-1] = c;
        }
        //printf("%s\n",res);
        // Declare a new Strings
        // to store the concatenated String
        //char str3[100];
        int i = 0, j = 0;
        //printf("\nFirst string: %s", str1);
        //printf("\nSecond string: %s", res);

        // Insert the first string in the new string
        while (str1[i] != '\0') {
            str3[j] = str1[i];
            i++;
            j++;
        }

        // Insert the second string in the new string
        i = 0;
        while (res[i] != '\0') {
            str3[j] = res[i];
            i++;
            j++;
        }
        str3[j] = '\0';

        // Print the concatenated string
        //printf("\nConcatenated string: %s", str3);



    	write(fd[1], &str3, sizeof(str3));
    	//printf("child sent the sum of even digits to parent\n");
    	sleep(1);
    	//printf("child : hi\n");
		// close the read-descriptor
		//close(fd[0]);
	}
	else if (id < 0)
	    perror("error. child was not created!\n");
	return 0;
}
