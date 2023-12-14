#include <iostream>
#include <txt2las.hpp>
#include <string.h>


int main(int argc, char *argv[])
{
    // int n = 12;

    // char **params;
    // params =(char **)malloc(sizeof(char *) * 3);

    // for(int i = 0; i < n; i++)
    //     params[i] = (char *)malloc(sizeof(char) * 120);

    // strcpy(params[0],"");
    // strcpy(params[1],"-i");
    // strcpy(params[2],"./pca-modelo.las");
    // strcpy(params[3],"-set_classification");
    // strcpy(params[4],"1");
    // strcpy(params[5],"-set_RGB_of_class");
    // strcpy(params[6],"1");
    // strcpy(params[7],"255");
    // strcpy(params[8],"0");
    // strcpy(params[9],"0");
    // strcpy(params[10],"-o");
    // strcpy(params[11],"./pca-modelo-out.las");
    // // params[1] = "pca_modelo.las";
    // // params[2] = "-repair_bb";

    // int result = txt2las(n, params);

    // for(int i = 0; i < n; i++)
    //     free(params[i]);

    // free(params);
    bool result = lasClassify("./pca-modelo.las", "pca-modelo-out.las",1,0,255,0);
    return result;

}