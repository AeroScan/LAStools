#include <iostream>
#include <lasinfo.hpp>
#include <string.h>


int main(int argc, char *argv[])
{

    // char **params;
    // params =(char **)malloc(sizeof(char *) * 3);

    // for(int i = 0; i < 3; i++)
    //     params[i] = (char *)malloc(sizeof(char) * 120);

    // strcpy(params[0],"");
    // strcpy(params[1],"./pca-modelo.las");
    // strcpy(params[2],"-repair_bb");
    // // params[1] = "pca_modelo.las";
    // // params[2] = "-repair_bb";

    // int result = lasinfo(3, params);

    // for(int i = 0; i < 3; i++)
    //     free(params[i]);

    // free(params);
    bool result = repairBB("./pca-modelo.las");
    return result;

}