#include <txt2las.hpp>

#include <iostream>
#include <string.h>

int lasClassify(std::string inputFile, std::string outputFile, int class_id, int R, int G, int B)
{
    int n = 12;

    char **params;
    params =(char **)malloc(sizeof(char *) * n);

    int i;
    for(i = 0; i < n; i++)
        params[i] = (char *)malloc(sizeof(char) * 120);
    
    i = 0;
    strcpy(params[i++],"");
    strcpy(params[i++],"-i");
    strcpy(params[i++],inputFile.c_str());
    strcpy(params[i++],"-set_classification");
    strcpy(params[i++],std::to_string(class_id).c_str());
    strcpy(params[i++],"-set_RGB_of_class");
    strcpy(params[i++],std::to_string(class_id).c_str());
    strcpy(params[i++],std::to_string(R).c_str());
    strcpy(params[i++],std::to_string(G).c_str());
    strcpy(params[i++],std::to_string(B).c_str());
    strcpy(params[i++],"-o");
    strcpy(params[i++],outputFile.c_str());

    int result = txt2las(n, params);

    for(i = 0; i < n; i++)
        free(params[i]);

    free(params);
    return result;
}