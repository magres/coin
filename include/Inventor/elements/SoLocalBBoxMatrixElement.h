/**************************************************************************\
 * 
 *  Copyright (C) 1998-1999 by Systems in Motion.  All rights reserved.
 *
 *  This file is part of the Coin library.
 *
 *  This file may be distributed under the terms of the Q Public License
 *  as defined by Troll Tech AS of Norway and appearing in the file
 *  LICENSE.QPL included in the packaging of this file.
 *
 *  If you want to use Coin in applications not covered by licenses
 *  compatible with the QPL, you can contact SIM to aquire a
 *  Professional Edition license for Coin.
 *
 *  Systems in Motion AS, Prof. Brochs gate 6, N-7030 Trondheim, NORWAY
 *  http://www.sim.no/ sales@sim.no Voice: +47 22114160 Fax: +47 67172912
 *
\**************************************************************************/

#ifndef _SO_LOCAL_BOUNDING_BOX_MATRIX_ELEMENT_H_
#define _SO_LOCAL_BOUNDING_BOX_MATRIX_ELEMENT_H_

#include <Inventor/confdep.h>
#if defined(COIN_EXCLUDE_SOLOCALBBOXMATRIXELEMENT)
#error "Configuration settings disable this class!"
#endif // COIN_EXCLUDE_SOLOCALBBOXMATRIXELEMENT

#include <Inventor/elements/SoModelMatrixElement.h>

class SoLocalBBoxMatrixElement : public SoElement {
  typedef SoElement inherited;

//$ BEGIN TEMPLATE ElementHeader( SoLocalBBoxMatrixElement )
public:
  static SoType classTypeId;
  static SoType getClassTypeId(void);
  static void * createInstance(void);
public:
  static int getClassStackIndex(void);
  virtual ~SoLocalBBoxMatrixElement(void);

  static void initClass(void);
  static void cleanClass(void);

protected:
  SoLocalBBoxMatrixElement(void);
  static int classStackIndex;
//$ END TEMPLATE ElementHeader

public:
  virtual void init( SoState * state );

  virtual void push( SoState * state );

  static void makeIdentity( SoState * const state );

  static void set( SoState * const state, const SbMatrix & matrix );

  static void mult( SoState * const state, const SbMatrix & matrix );
  static void translateBy( SoState * const state,
			   const SbVec3f & translation );
  static void rotateBy( SoState * const state, const SbRotation & rotation );
  static void scaleBy( SoState * const state, const SbVec3f & scaleFactor );

  static SbMatrix pushMatrix( SoState * const state );
  static void popMatrix( SoState * const state, const SbMatrix & matrix );

  static void resetAll( SoState * const state );

  static const SbMatrix & get( SoState * const state );

  virtual SbBool matches( const SoElement * element ) const;
  virtual SoElement * copyMatchInfo( void ) const;

  virtual void print( FILE * file ) const;

protected:
  SbMatrix localMatrix;

private:
  SbMatrix modelInverseMatrix;

};

#endif // ! _SO_LOCAL_BOUNDING_BOX_MATRIX_ELEMENT_H_
