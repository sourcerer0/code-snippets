#pragma once

#ifdef WIN32
  #define hello_world_EXPORT __declspec(dllexport)
#else
  #define hello_world_EXPORT
#endif

hello_world_EXPORT void hello_world();
