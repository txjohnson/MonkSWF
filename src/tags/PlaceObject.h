/*
 *  PlaceObject.h
 *  MonkSWF
 *
 *  Created by Micah Pearlman on 3/26/09.
 *  Copyright 2009 MP Engineering. All rights reserved.
 *
 */

#ifndef __PlaceObject_h__
#define __PlaceObject_h__

#include "mkTag.h"
#include <vg/openvg.h>
#include <vg/vgu.h>

namespace MonkSWF {

	class PlaceObject2Tag : public IPlaceObjectTag {
	public:
		PlaceObject2Tag( TagHeader& h ) 
			:	IPlaceObjectTag( h )
			,	_name(0)
			,	_offsetScale(1.0f)
			,	_rotation(0)
		{
			_offsetTranslate[0] = _offsetTranslate[1] = 0.0f;
			_translation[0] = _translation[1] = 0.0f;
			_scale[0] = _scale[1] = 1.0f;
		}
		
		virtual ~PlaceObject2Tag() {
			if ( _name ) {
				delete [] _name;
				_name = 0;
			}
		}
		
		virtual bool read( Reader* reader );
		virtual void print();
		virtual void draw( SWF* swf );
		virtual void copyTransform( IPlaceObjectTag* other );
		
		virtual void setOffsetTranslate( float t[2] ) {
			_offsetTranslate[0] = t[0];
			_offsetTranslate[1] = t[1];
		}
		virtual void getOffsetTranslate( float t[2] ) const  {
			t[0] = _offsetTranslate[0];
			t[1] = _offsetTranslate[1];
		}
		virtual void setOffsetScale( float s ) {
			_offsetScale = s;
		}
		virtual float offsetScale() const {
			return _offsetScale;
		}
		
		
		static ITag* create( TagHeader* header ) {
			return (ITag*)(new PlaceObject2Tag( *header ));
		}
		

	private:
	
		// offset
		VGfloat		_offsetTranslate[2];
		VGfloat		_offsetScale;
		
		VGfloat		_translation[2];
		VGfloat		_scale[2];
		VGfloat		_rotation;
		char*		_name;
	};
}
#endif // __PlaceObject_h__