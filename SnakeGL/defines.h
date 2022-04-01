#pragma once

#define WindowX 500
#define WindowY 500

#define MapX 50
#define MapY 50

#define RelationWindowXY (double(WindowX)/double(WindowY))
#define RelationWindowYX (double(WindowY)/double(WindowX))

#define ResolutionWX (double(WindowX)/double(MapX))
#define ResolutionWY (double(WindowY)/double(MapY))
#define ResolutionGLX (double(MapX)/double(WindowX))
#define ResolutionGLY (double(MapY)/double(WindowY))

#define PixelX (1.0/MapX)
#define PixelY (1.0/MapY)

#define S_Wall 2
#define S_Void 1
#define S_Snake 3
#define S_Apple 4
