#pragma once

#define WindowX 900
#define WindowY 900

#define MapX 25
#define MapY 25

#define RelationWindowXY (double(WindowX)/double(WindowY))
#define RelationWindowYX (double(WindowY)/double(WindowX))

#define ResolutionWX (double(WindowX)/double(MapX))
#define ResolutionWY (double(WindowY)/double(MapY))
#define ResolutionGLX (double(MapX)/double(WindowX))
#define ResolutionGLY (double(MapY)/double(WindowY))

#define PixelX (1.0/double(MapX))
#define PixelY (1.0/double(MapY))

#define S_Wall 2
#define S_Void 1
#define S_Snake 3
#define S_Apple 4
