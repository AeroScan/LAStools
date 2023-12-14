#pragma once
#include <iostream>
int txt2las(int argc, char* argv[]);

int lasClassify(std::string inputFile, std::string outputFile, int class_id, int R, int G, int B);