#!/bin/bash

SourceDir="./src"
SpvDir="./spv"


for srcFile in ${SourceDir}/*; do 
        noDirFile=${srcFile:${#SourceDir}+1}
        ExtFile=${noDirFile//[.]/_}
        OutFile="${SpvDir}/${ExtFile}.spv"
        glslc $srcFile -o $OutFile 
done
