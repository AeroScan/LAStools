#include <txt2las.hpp>

#include <iostream>
#include <string.h>

int lasClassify(std::string inputFile, std::string outputFile, int class_id, int R, int G, int B)
{
    int n = 12;

    char **params;
    params =(char **)malloc(sizeof(char *) * 3);

    for(int i = 0; i < n; i++)
        params[i] = (char *)malloc(sizeof(char) * 120);
    
    strcpy(params[0],"");
    strcpy(params[1],"-i");
    strcpy(params[2],inputFile.c_str());
    strcpy(params[3],"-set_classification");
    strcpy(params[4],std::to_string(class_id).c_str());
    strcpy(params[5],"-set_RGB_of_class");
    strcpy(params[6],std::to_string(class_id).c_str());
    strcpy(params[7],std::to_string(R).c_str());
    strcpy(params[8],std::to_string(G).c_str());
    strcpy(params[9],std::to_string(B).c_str());
    strcpy(params[10],"-o");
    strcpy(params[11],outputFile.c_str());

    int result = txt2las(n, params);

    for(int i = 0; i < n; i++)
        free(params[i]);

    free(params);
    return result;
}