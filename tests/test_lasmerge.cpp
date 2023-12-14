#include <iostream>
#include <lasmerge.hpp>
#include <string.h>

int main()
{
    // int n = 12;

    // char **params;
    // params =(char **)malloc(sizeof(char *) * n);

    // for(int i = 0; i < n; i++)
    //     params[i] = (char *)malloc(sizeof(char) * 120);

    // strcpy(params[0],"");
    // strcpy(params[1],"-i");
    // strcpy(params[2],"./pca-modelo.ply");
    // strcpy(params[3],"./Modelo_3D_PCM_04.ply");
    // strcpy(params[10],"-o");
    // strcpy(params[11],"./cloud_out.las");
    // // params[1] = "pca_modelo.las";
    // // params[2] = "-repair_bb";

    // int result = lasmerge(n, params);

    // for(int i = 0; i < n; i++)
    //     free(params[i]);

    // free(params);
    bool result = mergeClouds(std::vector<std::string>({"./pca-modelo.ply","./Modelo_3D_PCM_04.ply"}),"./cloud_out.las");
    return result;
}