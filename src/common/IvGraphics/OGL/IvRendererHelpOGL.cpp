//===============================================================================
// @ IvRendererHelp.cpp
// 
// Helper routines to set up basic rendering functionality
// ------------------------------------------------------------------------------
// Copyright (C) 2008 by Elsevier, Inc. All rights reserved.
//
//===============================================================================

//-------------------------------------------------------------------------------
//-- Dependencies ---------------------------------------------------------------
//-------------------------------------------------------------------------------

#include <stdlib.h>

#ifdef PLATFORM_OSX
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <IvRenderer.h>
#include "IvRendererHelp.h"
#include <IvVector3.h>
#include <IvVector4.h>
#include <IvMatrix44.h>
#include <IvMatrix33.h>
#include <IvLineSegment3.h>
#include <IvMath.h>
#include <IvQuat.h>

//-------------------------------------------------------------------------------
//-- Functions ------------------------------------------------------------------
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
// @ SetDefaultViewer()
//-------------------------------------------------------------------------------
// Set default viewer location, looking at origin
//-------------------------------------------------------------------------------
void 
IvSetDefaultViewer( float xPos, float yPos, float zPos )
{
    IvVector3 eye(xPos, yPos, zPos);
    IvVector3 lookAt(0.0f, 0.0f, 0.0f);
    IvVector3 up(0.0f, 0.0f, 1.0f);

    // compute view vectors
    IvVector3 view = lookAt - eye;
    view.Normalize();
    
    IvVector3 right =  view.Cross( up );
    right.Normalize();
    
    IvVector3 viewUp =  right.Cross( view );
    viewUp.Normalize();

    // now set up matrices
    // world->view rotation
    IvMatrix33 rotate;
    rotate.SetRows( right, viewUp, -view );

    // world->view translation
    IvVector3 xlate = -(rotate*eye);

    // build 4x4 matrix
    IvMatrix44 matrix(rotate);
    matrix(0,3) = xlate.GetX();
    matrix(1,3) = xlate.GetY();
    matrix(2,3) = xlate.GetZ();

    IvRenderer::mRenderer->SetViewMatrix( matrix );
    
}   // End of IvSetDefaultViewer()



