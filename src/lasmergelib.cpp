#include <lasmerge.hpp>
#include <string.h>

bool mergeClouds(std::vector<std::string> inputFiles, std::string outputFile)
{
    int n = 4 + inputFiles.size();
    int i = 0;
    char **params;
    params = (char **)malloc(sizeof(char *)* n);

    for(int j = 0; j < n; j++)
        {std::cout << "aqui " << j << " " << std::endl;
        params[j] = (char *)malloc(sizeof(char) * 240);
        std::cout << "aqui " << j << " " << std::endl;}
    
    strcpy(params[i++],"");
    strcpy(params[i++],"-i");
    for(std::string file : inputFiles)
        strcpy(params[i++],file.c_str());
    std::cout << i << " " << n << std::endl;
    strcpy(params[i++],"-o");
    std::cout << i << " " << n << std::endl;
    strcpy(params[i],outputFile.c_str());

    int result = lasmerge(n,params);

    for(int i = 0; i < n; i++)
        free(params[i]);
    
    free(params);
    return result;
    
}