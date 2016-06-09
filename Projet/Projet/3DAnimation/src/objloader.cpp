#include "ObjLoader.h"

#include <vector>
#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>

/////////////////////////////// PUBLIC ///////////////////////////////////////

//============================= LIFECYCLE ====================================

ObjLoader::ObjLoader()
{

}

//============================= OPERATIONS ===================================

bool ObjLoader::loadObj(const char* path, std::vector<Vec3>& tabVertices,
                        std::vector<Vec2>& tabNormals, std::vector<Vec3>& tabTexCoords)
{
    printf("Loading OBJ file %s...\n", path);

    std::vector<unsigned int> vertex_indices, uv_indices, normal_indices;
    std::vector<Vec3> temp_vertices;
    std::vector<Vec2> temp_uvs;
    std::vector<Vec3> temp_normals;

    FILE* file = fopen(path, "r");

    if ( file == NULL )
    {
        //printf("%s", strerror(errno));
        printf("Impossible d'ouvrir le fichier \n");
        getchar();
        return false;
    }

    while (1)
    {
        char line_header[128];
        // permet de lire le premier mot de la ligne
        int res = fscanf(file, "%s", line_header);
        if (res == EOF)
        {
            //End Of File
            break;
        }

        // parse des vertex en fonction de l'entete

       if ( strcmp( line_header, "v" ) == 0 )
       {
            Vec3 vertex;
            fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
            temp_vertices.push_back(vertex);
           // std::cout << vertex.x << std::endl;
        }
       else if ( strcmp( line_header, "vt" ) == 0 )
       {
            Vec2 uv;
            fscanf(file, "%f %f\n", &uv.x, &uv.y );
            uv.y = -uv.y;
            temp_uvs.push_back(uv);

        }
       else if ( strcmp( line_header, "vn" ) == 0 )
       {
            Vec3 normal;
            fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
            temp_normals.push_back(normal);

        }
       else if ( strcmp( line_header, "f" ) == 0 )
       {
            std::vector< std::vector<unsigned int> > face;

            std::string vertex1, vertex2, vertex3;
            unsigned int vertex_index[3], uv_index[3], normal_index[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertex_index[0], &uv_index[0], &normal_index[0], &vertex_index[1], &uv_index[1], &normal_index[1], &vertex_index[2], &uv_index[2], &normal_index[2] );
            if (matches != 9)
            {
                printf("L'objet ne cotient pas de texture, le parse ne peux pas etre applique.\n");
                return false;
            }

            vertex_indices.push_back(vertex_index[0]);
            vertex_indices.push_back(vertex_index[1]);
            vertex_indices.push_back(vertex_index[2]);

            uv_indices.push_back(uv_index[0]);
            uv_indices.push_back(uv_index[1]);
            uv_indices.push_back(uv_index[2]);

            normal_indices.push_back(normal_index[0]);
            normal_indices.push_back(normal_index[1]);
            normal_indices.push_back(normal_index[2]);

       }
       else
       {
            // Probably a comment, eat up the rest of the line
            char stupid_buffer[1000];
            fgets(stupid_buffer, 1000, file);
        }
    }

    // For each vertex of each triangle
    for (unsigned int i=0; i<vertex_indices.size(); i++)
    {
        //std::cout << vertexIndex.size() << std::endl;
        // Get the indices of its attributes
        unsigned int vertex_index = vertex_indices[i];
        unsigned int uv_index = uv_indices[i];
        unsigned int normal_index = normal_indices[i];

        // Get the attributes thanks to the index
        Vec3 vertex = temp_vertices[ vertex_index-1 ];
        Vec2 uv = temp_uvs[ uv_index-1 ];
        Vec3 normal = temp_normals[ normal_index-1 ];

        // Put the attributes in buffers
        tabVertices.push_back(vertex);
        tabNormals.push_back(uv);
        tabTexCoords.push_back(normal);
    }

    return true;
}

