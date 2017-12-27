#include "PreCompiled.h"
#include "Setting.h"
#include "Magick++.h"
#include "direct.h"

using namespace Magick;

int main(int argc, char **argv)
{
	CommandParser::getInstance().init(argc, argv);
	Setting::getInstance().init();

	//InitializeMagick
	Image image;
	try {
		// Read a file into image object 
		image.read(Setting::getInstance().path() + "1.png");

		// Crop the image to specified size (width, height, xOffset, yOffset)
		image.crop(Geometry(100, 100, 100, 100));

		// Write the image to a file 
		image.write(Setting::getInstance().path() + "logo.png");
	}
	catch (Exception &error_)
	{
		llogln("Caught exception: %s", error_.what());
		return 1;
	}
	/*Signal s;
	s.wait();*/
}