//
//  GLShaderCompiler.hpp
//  3DToolViz
//
//  Created by Mahesh Manni on 08/04/22.
//

#ifndef GLShaderCompiler_hpp
#define GLShaderCompiler_hpp

#include <stdio.h>

class GLShaderCompiler
{
public:
    GLShaderCompiler();
    ~GLShaderCompiler();
    
    bool Compile(const char* vs_path, const char* fs_path, const char* gs_path = nullptr);
};
#endif /* GLShaderCompiler_hpp */
