xof 0303txt 0032
template Vector {
 <3d82ab5e-62da-11cf-ab39-0020af71e433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template MeshFace {
 <3d82ab5f-62da-11cf-ab39-0020af71e433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template Mesh {
 <3d82ab44-62da-11cf-ab39-0020af71e433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

template MeshNormals {
 <f6f23f43-7686-11cf-8f52-0040333594a3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template Coords2d {
 <f6f23f44-7686-11cf-8f52-0040333594a3>
 FLOAT u;
 FLOAT v;
}

template MeshTextureCoords {
 <f6f23f40-7686-11cf-8f52-0040333594a3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template ColorRGBA {
 <35ff44e0-6c7c-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <d3e16e81-7835-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template Material {
 <3d82ab4d-62da-11cf-ab39-0020af71e433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshMaterialList {
 <f6f23f42-7686-11cf-8f52-0040333594a3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material <3d82ab4d-62da-11cf-ab39-0020af71e433>]
}

template TextureFilename {
 <a42790e1-7810-11cf-8f52-0040333594a3>
 STRING filename;
}

template VertexDuplicationIndices {
 <b8d65549-d7c9-4995-89cf-53a9a8b031e3>
 DWORD nIndices;
 DWORD nOriginalVertices;
 array DWORD indices[nIndices];
}


Mesh {
 24;
 -17.499998;0.000000;26.999997;,
 -17.499998;0.000000;26.999997;,
 -17.499998;0.000000;26.999997;,
 -17.499998;0.000000;-26.999997;,
 -17.499998;0.000000;-26.999997;,
 -17.499998;0.000000;-26.999997;,
 -17.499998;14.999998;26.999997;,
 -17.499998;14.999998;26.999997;,
 -17.499998;14.999998;26.999997;,
 -17.499998;14.999998;-26.999997;,
 -17.499998;14.999998;-26.999997;,
 -17.499998;14.999998;-26.999997;,
 17.499998;0.000000;26.999997;,
 17.499998;0.000000;26.999997;,
 17.499998;0.000000;26.999997;,
 17.499998;0.000000;-26.999997;,
 17.499998;0.000000;-26.999997;,
 17.499998;0.000000;-26.999997;,
 17.499998;14.999998;26.999997;,
 17.499998;14.999998;26.999997;,
 17.499998;14.999998;26.999997;,
 17.499998;14.999998;-26.999997;,
 17.499998;14.999998;-26.999997;,
 17.499998;14.999998;-26.999997;;
 12;
 3;20,23,11;,
 3;8,20,11;,
 3;19,14,17;,
 3;22,19,17;,
 3;10,5,2;,
 3;7,10,2;,
 3;21,16,4;,
 3;9,21,4;,
 3;15,13,1;,
 3;3,15,1;,
 3;12,18,6;,
 3;0,12,6;;

 MeshNormals {
  24;
  0.000000;0.000000;1.000000;,
  0.000000;-1.000000;0.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;-1.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  0.000000;-1.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;-1.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;;
  12;
  3;20,23,11;,
  3;8,20,11;,
  3;19,14,17;,
  3;22,19,17;,
  3;10,5,2;,
  3;7,10,2;,
  3;21,16,4;,
  3;9,21,4;,
  3;15,13,1;,
  3;3,15,1;,
  3;12,18,6;,
  3;0,12,6;;
 }

 MeshTextureCoords {
  24;
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;;
 }

 MeshMaterialList {
  5;
  12;
  0,
  0,
  1,
  1,
  1,
  1,
  2,
  2,
  3,
  3,
  4,
  4;

  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;

   TextureFilename {
    "MatchBoxFront.jpg";
   }
  }

  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;

   TextureFilename {
    "MatchboxSide.jpg";
   }
  }

  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;

   TextureFilename {
    "MatchBoxEnd.jpg";
   }
  }

  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;

   TextureFilename {
    "MatchboxBack.jpg";
   }
  }

  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;

   TextureFilename {
    "MatchBoxEnd.jpg";
   }
  }
 }

 VertexDuplicationIndices {
  24;
  8;
  2,
  2,
  2,
  5,
  5,
  5,
  8,
  8,
  8,
  11,
  11,
  11,
  14,
  14,
  14,
  17,
  17,
  17,
  20,
  20,
  20,
  23,
  23,
  23;
 }
}