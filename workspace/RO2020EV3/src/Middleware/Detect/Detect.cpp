#include <Detect.h>
#include "../Drive/DriveManager.h"
#include "../DriveEngine/DriveEngine.h"

namespace Detect
{
	ReadColor GetColor()
	{
		const RGB rgb = RyujiEv3Engine::GetColorSensor()->getRGB();
		const TraceColor traceColor = DriveEngine::GetDrive()->getLineTraceDrive()->getTraceColor();

		const float gray = (traceColor.black + traceColor.white) / 2.0f;

		// 青検知
		if ((rgb.r + rgb.g) < rgb.b)
		{
			return ReadColor::BLUE;
		}
		// 白検知
		else if ((rgb.r + rgb.g + rgb.b) / 3 > gray)
		{
			return ReadColor::WHITE;
		}
		else
		{
			return ReadColor::BLACK;
		}
	}
}