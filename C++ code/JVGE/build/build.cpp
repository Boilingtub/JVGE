#include <iostream>
#include <stdlib.h>
#include <string>

int main() {
    char mainfile[] = "../src/main.cpp";
    char includeflags[] = "";
    printf("Compiling..%s\n",mainfile);
    system("set CPLUS_INCLUDE_PATH = \"C:/VulkanSDK/1.3.250.1/Include\"");
    system("set LD_PATH = \"\"");
    system("clang++ -Wall ../src/main.cpp -o jvge.exe -IC:/VulkanSDK/1.3.250.1/Include -IC:/Users//jhbri/Coding/C++/JVGE/src/glfw-3.3.8/include");
    return 0;
} 
