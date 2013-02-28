#pragma once

#include "ofMain.h"

namespace utils {
	class Point
	{
		public:

			static float angle( ofPoint p0 );
			static float angleBetween( ofPoint p0, ofPoint p1 );
			static float cross( ofPoint p0, ofPoint p1 );
			static float distance( ofPoint p0, ofPoint p1 );
			static float distanceSqr( ofPoint p0, ofPoint p1 );
			static float length( ofPoint p0 );
			static float lengthSqr( ofPoint p0 );
			static ofPoint lerp( ofPoint p0, ofPoint p1, float factor );
			static ofPoint pivot( ofPoint p0, ofPoint p1, float angle );
			static ofPoint polar( int length, float angle );
			static bool proximity( ofPoint p0, ofPoint p1, float tolerance );
			static float toDeg( float radians );
			static float toRad( float angle );
	};
}; // namespace