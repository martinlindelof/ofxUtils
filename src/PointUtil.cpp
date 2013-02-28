#include "PointUtil.h"

namespace utils{

	//--------------------------------------------------------------
	float Point::angle( ofPoint p0 ){

		// get the angle
		return (atan2(p0.y, p0.x));

	};

	//--------------------------------------------------------------
	float Point::angleBetween( ofPoint p0, ofPoint p1 ){

		// get the angle between first point and second point
		// return atan2( (p1.y - p0.y), (p1.x - p0.x) ) * (180 / PI);
		float a = toDeg(atan2((p1.y - p0.y), (p1.x - p0.x)));
		a = a < 0 ? 360+a : a;
		return a;

	};

	//--------------------------------------------------------------
	float Point::cross( ofPoint p0, ofPoint p1 ){

		// get the cross product
		return (p0.x*p1.y - p0.y*p1.x);

	};

	//--------------------------------------------------------------
	float Point::distance( ofPoint p0, ofPoint p1 ){

		// get the distance between first and second point
		return (sqrt((p0.x-p1.x)*(p0.x-p1.x) + (p0.y-p1.y)*(p0.y-p1.y)));

	};

	//--------------------------------------------------------------
	float Point::distanceSqr( ofPoint p0, ofPoint p1 ){

		// get the distance squared between first and second point
		return ((p0.x-p1.x)*(p0.x-p1.x) + (p0.y-p1.y)*(p0.y-p1.y));

	};

	//--------------------------------------------------------------
	float Point::length( ofPoint p0 ){

		// get the length
		return (sqrt(p0.x*p0.x + p0.y*p0.y));

	};

	//--------------------------------------------------------------
	float Point::lengthSqr( ofPoint p0 ){

		// get length squared
		return float(p0.x*p0.x + p0.y*p0.y);

	};

	//--------------------------------------------------------------
	ofPoint Point::lerp( ofPoint p0, ofPoint p1, float factor ){

		// to interpolate between first and second point, with a factor
		factor = abs(factor);
		factor = factor > 1.0 ? 1.0 : factor;

		ofPoint p;
		p.x = (p1.x - p0.x) * factor + p0.x;
		p.y = (p1.y - p0.y) * factor + p0.y;

		return p;

	};

	//--------------------------------------------------------------
	ofPoint Point::pivot( ofPoint p0, ofPoint p1, float angle ){

		// to get the point, by rotating the first point with the second point as pivot
		float x = p0.x - p1.y;
		float y = p0.y - p1.y;
		float length = sqrt(x*x + y*y);
		float angle2 = atan2(y, x)+angle;

		ofPoint p;
		p.x = p1.x + length*cos(angle2); // this seems weird,
		p.y = p1.y + length*sin(angle2); // should it be angle2?

		return p;

	};

	//--------------------------------------------------------------
	ofPoint Point::polar( int length, float angle ){

		// get the polar point from length and angle
		angle = toRad(angle);
		ofPoint p;
		p.x = length*cos(angle);
		p.y = length*sin(angle);
		return p;

	};

	//--------------------------------------------------------------
	bool Point::proximity( ofPoint p0, ofPoint p1, float tolerance ){

		// see whether first point is almost equal with second point
		// *with a tolerance value
		float x = abs(p0.x - p1.x);
		float y = abs(p0.y - p1.y);
		if( x <= tolerance && y <= tolerance ) return true;
		else return false;

	};

	//--------------------------------------------------------------
	float Point::toDeg( float radians ){

		// from radians to degrees
		// return (radians*(180/PI)); // calculation
		return ofRadToDeg(radians);

	};

	//--------------------------------------------------------------
	float Point::toRad( float angle ){

		// from degrees to radians
		// return (angle*(PI/180)); // calculation
		return ofDegToRad(angle);

	};
}; // namespace