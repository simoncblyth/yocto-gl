#pragma once

#if defined (_WIN32) 

   #if defined(YGLTF_EXPORTS)
       #define  YGLTF_API __declspec(dllexport)
   #else
       #define  YGLTF_API __declspec(dllimport)
   #endif

#else

   #define YGLTF_API  __attribute__ ((visibility ("default")))

#endif


