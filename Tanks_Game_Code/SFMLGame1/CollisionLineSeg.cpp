//#include "CollisionLineSeg.h"
//
//
//CollisionLineSeg::CollisionLineSeg()
//{
//	vertical = false;
//}
//
//
//CollisionLineSeg::~CollisionLineSeg()
//{
//}
//
//void CollisionLineSeg::twoPointsSetup(sf::Vector2f fpa, sf::Vector2f fpb)
//{
//	points[0] = fpa;
//	points[1] = fpb;
//	if (fpb.x == fpa.x)
//	{
//		vertical = true;
//	}
//	else
//	{
//		slope = (fpb.y - fpa.y) / (fpb.x - fpa.x);
//	}
//	
//	if (fpa.x > fpb.x)
//	{
//		xbounds[0] = fpb.x;
//		xbounds[1] = fpa.x;
//	}
//	else
//	{
//		xbounds[1] = fpb.x;
//		xbounds[0] = fpa.x;
//	}
//
//	if (fpa.y > fpb.y)
//	{
//		ybounds[0] = fpb.y;
//		ybounds[1] = fpa.y;
//	}
//	else
//	{
//		ybounds[1] = fpb.y;
//		ybounds[0] = fpa.y;
//	}
//}
//
//
//
//bool CollisionLineSeg::checkIntersect(CollisionLineSeg lineB)
//{
//	bool intersects = false;
//	sf::Vector2f poi;
//
//	if (!checkConnected(lineB))
//	{
//		if (vertical)
//		{
//			poi.x = points[0].x;
//			if (lineB.getVertical())
//			{
//				if (points[0].x == lineB.getPoint(0).x)
//				{
//					if (!((ybounds[1] < lineB.getYbound(0)) || (ybounds[0] > lineB.getYbound(1))))
//					{
//						intersects = true;
//					}
//				}
//			}
//			else
//			{
//				poi.y = lineB.slope * (poi.x - lineB.getPoint(0).x) + lineB.getPoint(0).y;
//				if (checkInBounds(poi) && lineB.checkInBounds(poi))
//				{
//					intersects = true;
//				}
//			}
//
//			
//		}
//		else if (lineB.getVertical())
//		{
//			poi.x = lineB.getPoint(0).x;
//			poi.y = slope * (poi.x - points[0].x) + points[0].y;
//			if (checkInBounds(poi) && lineB.checkInBounds(poi))
//			{
//				intersects = true;
//			}
//
//		}
//		else
//		{
//			if (slope == lineB.slope)
//			{
//				if (points[0].y - slope * points[0].x == lineB.getPoint(0).y - slope * lineB.getPoint(0).x)
//				{
//					if (!((xbounds[1] < lineB.getXbound(0)) || (xbounds[0] > lineB.getXbound(1))))
//					{
//						intersects = true;
//					}
//				}
//			}
//			else
//			{
//				poi.x = (slope * points[0].x - lineB.slope * lineB.getPoint(0).x + lineB.getPoint(0).y - points[0].y) / (slope - lineB.slope);
//				poi.y = slope * (poi.x - points[0].x) + points[0].y;
//				if (checkInBounds(poi) && lineB.checkInBounds(poi))
//				{
//					intersects = true;
//				}
//			}
//		}	
//	}
//
//	return intersects;
//}
//
//bool CollisionLineSeg::getVertical()
//{
//	return vertical;
//}
//
//sf::Vector2f CollisionLineSeg::getPoint(bool index)
//{
//	return points[index];
//}
//
//double CollisionLineSeg::getXbound(bool index)
//{
//	return xbounds[index];
//}
//
//double CollisionLineSeg::getYbound(bool index)
//{
//	return ybounds[index];
//}
//
//bool CollisionLineSeg::checkConnected(CollisionLineSeg lineB)
//{
//	bool connected = false;
//
//	if ((points[0] == lineB.getPoint(0)) || (points[0] == lineB.getPoint(1)) || (points[1] == lineB.getPoint(0)) || (points[1] == lineB.getPoint(1)))
//	{
//		connected = true;
//	}
//
//	return connected;
//}
//
//bool CollisionLineSeg::checkInBounds(sf::Vector2f point)
//{
//	bool inside = false;
//	if ((point.x <= xbounds[1]) && (point.x >= xbounds[0]) && (point.y <= ybounds[1]) && (point.y >= ybounds[0]))
//	{
//		inside = true;
//	}
//	return inside;
//}
