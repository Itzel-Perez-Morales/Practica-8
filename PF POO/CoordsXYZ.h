#pragma once
struct CoordsXYZ
{
	double x, y, z;

	CoordsXYZ()
	{
		x = 0;
		y = 0;
		z = 0;
	};

	CoordsXYZ(double x, double y, double z)
	{
		CoordsXYZ::x = x;
		CoordsXYZ::y = y;
		CoordsXYZ::z = z;
	}
};