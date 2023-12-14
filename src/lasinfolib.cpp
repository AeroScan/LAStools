#include <lasinfo.hpp>

bool repairBB(std::string inputFile)
{
    int n = 3;
    int i = 0;
    char **params;
    params = (char **)malloc(sizeof(char *) * n);
    for(int j = 0; j < n;j++)
        params[j] = (char *)malloc(sizeof(char) * 240);
    strcpy(params[i++],"");
    std::cout << "AQUI " << i << std::endl;
    strcpy(params[i++],inputFile.c_str());
    strcpy(params[i],"-repair_bb");

    int result = lasinfo(n, params);

    for(int i = 0; i < 3; i++)
        free(params[i]);
    
    free(params);
    return result;
}