//===============================================================================
// @ IvShaderProgram.h
// 
// Description
// ------------------------------------------------------------------------------
// Copyright (C) 2008  Elsevier, Inc.
//
// Usage notes
//===============================================================================

#ifndef __IvShaderProgram__h__
#define __IvShaderProgram__h__

//-------------------------------------------------------------------------------
//-- Dependencies ---------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
//-- Typedefs, Structs ----------------------------------------------------------
//-------------------------------------------------------------------------------

class IvUniform;

//-------------------------------------------------------------------------------
//-- Classes --------------------------------------------------------------------
//-------------------------------------------------------------------------------

class IvShaderProgram
{
public:
    // interface routines
    virtual IvUniform* GetUniform(char const* name) = 0;
    
protected:
    // constructor/destructor
    IvShaderProgram() {}
	virtual ~IvShaderProgram() {}

private:
    // copy operations (unimplemented so we can't copy)
    IvShaderProgram(const IvShaderProgram& other);
	IvShaderProgram& operator=(const IvShaderProgram& other);
}; 

//-------------------------------------------------------------------------------
//-- Inlines --------------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
//-- Externs --------------------------------------------------------------------
//-------------------------------------------------------------------------------

#endif