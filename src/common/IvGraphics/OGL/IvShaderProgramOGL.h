//===============================================================================
// @ IvShaderProgramOGL.h
// 
// Description
// ------------------------------------------------------------------------------
// Copyright (C) 2008   Elsevier, Inc.
//
// Change history:
//
// Usage notes
//===============================================================================

#ifndef __IvShaderProgramOGL__h__
#define __IvShaderProgramOGL__h__

//-------------------------------------------------------------------------------
//-- Dependencies ---------------------------------------------------------------
//-------------------------------------------------------------------------------

#include <map>
#include <string>

#include "../IvShaderProgram.h"
#include "../IvVertexFormats.h"
#ifdef PLATFORM_OSX
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

//-------------------------------------------------------------------------------
//-- Typedefs, Structs ----------------------------------------------------------
//-------------------------------------------------------------------------------

class IvResourceManagerOGL;
class IvUniformOGL;

//-------------------------------------------------------------------------------
//-- Classes --------------------------------------------------------------------
//-------------------------------------------------------------------------------

class IvShaderProgramOGL : public IvShaderProgram
{
public:
    // interface routines
    virtual IvUniform* GetUniform(char const* name);

    friend class IvResourceManagerOGL;
    friend class IvRendererOGL;
    
private:
    // constructor/destructor
    IvShaderProgramOGL();
	~IvShaderProgramOGL();
    
    // initialization
    bool Create( GLuint vertexShaderID, GLuint fragmentShaderID );
    
    // destruction
    void Destroy();
    
    // make this the active program
    bool MakeActive();
    
private:
    // copy operations
    IvShaderProgramOGL(const IvShaderProgramOGL& other);
	IvShaderProgramOGL& operator=(const IvShaderProgramOGL& other);

	GLuint				mProgramID;
	unsigned int		mNextTextureStage;
    std::map<std::string, IvUniformOGL*> mUniforms;
};


//-------------------------------------------------------------------------------
//-- Inlines --------------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
//-- Externs --------------------------------------------------------------------
//-------------------------------------------------------------------------------

#endif