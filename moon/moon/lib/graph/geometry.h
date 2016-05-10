#pragma once

namespace lib
{
	namespace graph
	{

#ifndef _max
#define _max(a, b)	(a > b ? a : b)
#endif
#ifndef _min
#define _min(a, b)	(a < b ? a : b)
#endif
		//矩形
		struct GRect
		{
			int x, y, width, height;
		public:
			//判断是否与另一个矩形相交
			inline bool intersects(const GRect &another) const
			{
				int rx = _max(x, another.x);
				int ry = _max(y, another.y);
				int rw = _min(x + width, another.x + another.width) - rx;
				int rh = _min(y + height, another.y + another.height) - ry;

				if (rw <= 0 || rh <= 0)
					return false;
				return true;
			}
		};

		//点
		struct GPoint
		{
			int x, y;
		};
	}
}
