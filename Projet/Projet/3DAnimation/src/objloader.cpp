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
                        std::vector<Vec2>& tabTexCoords, std::vector<Vec3>& tabNormals)
{
    printf("Loading OBJ file %s...\n", path);

    std::vector<unsigned int> v_indices, vt_indices, vn_indices;
    std::vector<Vec3> tmp_v;
    std::vector<Vec2> tmp_vt;
    std::vector<Vec3> tmp_vn;

    FILE* file = fopen(path, "r");

    if ( file == NULL )
    {
        printf("Impossible to read the file \n");
        getchar();
        return false;
    }

    while (1)
    {
        char tmp_line[128];
        int test = fscanf(file, "%s", tmp_line);
        if (test == EOF)
        {
            //End Of File
            break;
        }

        if ( strcmp( tmp_line, "v" ) == 0 )
        {
            // Vertices
            Vec3 v;
            fscanf(file, "%f %f %f\n", &v.x, &v.y, &v.z );
            tmp_v.push_back(v);
        }
        else if ( strcmp( tmp_line, "vt" ) == 0 )
        {
            // Texture coordinates
            Vec2 vt;
            fscanf(file, "%f %f\n", &vt.x, &vt.y );
            vt.y = -vt.y;
            tmp_vt.push_back(vt);
        }
        else if ( strcmp( tmp_line, "vn" ) == 0 )
        {
            // Normals
            Vec3 vn;
            fscanf(file, "%f %f %f\n", &vn.x, &vn.y, &vn.z );
            tmp_vn.push_back(vn);
        }
        else if ( strcmp( tmp_line, "f" ) == 0 )
        {
            // Faces
            unsigned int v_id[3], vt_id[3], vn_id[3];
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &v_id[0], &vt_id[0], &vn_id[0], &v_id[1], &vt_id[1], &vn_id[1], &v_id[2], &vt_id[2], &vn_id[2] );
            if (matches != 9)
            {
                printf("No texture in .obj file \n");
                return false;
            }

            v_indices.push_back(v_id[0]);
            v_indices.push_back(v_id[1]);
            v_indices.push_back(v_id[2]);

            vt_indices.push_back(vt_id[0]);
            vt_indices.push_back(vt_id[1]);
            vt_indices.push_back(vt_id[2]);

            vn_indices.push_back(vn_id[0]);
            vn_indices.push_back(vn_id[1]);
            vn_indices.push_back(vn_id[2]);

        }
        else
        {
            // Go to next line
            char tmp_buffer[1000];
            fgets(tmp_buffer, 1000, file);
        }
    }

    // For each vertex of each triangle
    for (unsigned int i=0; i<v_indices.size(); i++)
    {
        // Get the indices of its attributes
        unsigned int vertex_index = v_indices[i];
        unsigned int uv_index = vt_indices[i];
        unsigned int normal_index = vn_indices[i];

        // Get the attributes thanks to the index
        Vec3 vertex = tmp_v[ vertex_index-1 ];
        Vec2 uv = tmp_vt[ uv_index-1 ];
        Vec3 normal = tmp_vn[ normal_index-1 ];

        // Put the attributes in buffers
        tabVertices.push_back(vertex);
        tabTexCoords.push_back(uv);
        tabNormals.push_back(normal);
    }

    return true;
}

