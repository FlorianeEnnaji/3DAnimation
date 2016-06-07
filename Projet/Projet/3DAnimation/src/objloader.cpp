#include "ObjLoader.h"

#include <vector>
#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>


bool ObjLoader::loadObj(
    const char * path,
        std::vector<vec3> &tabVertices,
        std::vector<vec2> &tabNormals,
        std::vector<vec3> &tabTexCoords
){
    printf("Loading OBJ file %s...\n", path);

    std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
    std::vector<vec3>  temp_vertices;
    std::vector<vec2>  temp_uvs;
    std::vector<vec3>  temp_normals;


    FILE * file = fopen(path, "r");

    if( file == NULL ){
        //printf("%s", strerror(errno));
        printf("Impossible d'ouvrir le fichier \n");
        getchar();
        return false;
    }

 while( 1 ){

        char lineHeader[128];
        // permet de lire le premier mot de la ligne
        int res = fscanf(file, "%s", lineHeader);
        if (res == EOF)
            break; // EOF = End Of File. Quit the loop.

        // parse des vertex en fonction de l'entete

       if ( strcmp( lineHeader, "v" ) == 0 ){

            vec3 vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
            temp_vertices.push_back(vertex);
           // std::cout << vertex.x << std::endl;

        }else if ( strcmp( lineHeader, "vt" ) == 0 ){

            vec2 uv;
            fscanf(file, "%f %f\n", &uv.x, &uv.y );
            uv.y = -uv.y;
            temp_uvs.push_back(uv);

        }else if ( strcmp( lineHeader, "vn" ) == 0 ){

            vec3 normal;
            fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
            temp_normals.push_back(normal);

        }else if ( strcmp( lineHeader, "f" ) == 0 ){

            std::vector< std::vector<unsigned int> > face;

            std::string vertex1, vertex2, vertex3;
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
            if (matches != 9){
                printf("L'objet ne cotient pas de texture, le parse ne peux pas etre applique.\n");
                return false;
            }

            vertexIndices.push_back(vertexIndex[0]);
            vertexIndices.push_back(vertexIndex[1]);
            vertexIndices.push_back(vertexIndex[2]);

            uvIndices    .push_back(uvIndex[0]);
            uvIndices    .push_back(uvIndex[1]);
            uvIndices    .push_back(uvIndex[2]);

            normalIndices.push_back(normalIndex[0]);
            normalIndices.push_back(normalIndex[1]);
            normalIndices.push_back(normalIndex[2]);

        }else{
            // Probably a comment, eat up the rest of the line
            char stupidBuffer[1000];
            fgets(stupidBuffer, 1000, file);
        }

    }

// For each vertex of each triangle
        for( unsigned int i=0; i<vertexIndices.size(); i++ ){
      //    std::cout << vertexIndex.size() << std::endl;
        // Get the indices of its attributes
        unsigned int vertexIndex = vertexIndices[i];
        unsigned int uvIndex = uvIndices[i];
        unsigned int normalIndex = normalIndices[i];

        // Get the attributes thanks to the index
        vec3 vertex = temp_vertices[ vertexIndex-1 ];
        vec2 uv = temp_uvs[ uvIndex-1 ];
        vec3 normal = temp_normals[ normalIndex-1 ];

        // Put the attributes in buffers
        tabVertices.push_back(vertex);
        tabNormals.push_back(uv);
        tabTexCoords.push_back(normal);


    }

    return true;
}

