/*
  Copyright 2013 Jesse 'Jeaye' Wilkerson
  See licensing in LICENSE file, or at:
    http://www.opensource.org/licenses/BSD-3-Clause

  File: main.cpp
  Author: Jesse 'Jeaye' Wilkerson
  Description:
    TODO
*/

#include "game.h"

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
  INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
#else
  int main(int argc, char **argv)
#endif
  {
    game app;
    try
    { app.go(); }
    catch(Ogre::Exception &e)
    {
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
      MessageBox(nullptr, e.getFullDescription().c_str(),
                 "An exception has occured!",
                 MB_OK | MB_ICONERROR | MB_TASKMODAL);
#else
      log_error("An exception has occured: %%", e.getFullDescription());
#endif
    }
    catch(std::exception &e)
    { log_error("An exception was thrown: %%", e.what()); }
    catch(...)
    { log_error("An unkown exception was thrown"); }
  }

#ifdef __cplusplus
}
#endif

