#pragma once

#if defined (_WIN32) 

   #if defined(YSHAPE_EXPORTS)
       #define  YSHAPE_API __declspec(dllexport)
   #else
       #define  YSHAPE_API __declspec(dllimport)
   #endif

#else

   #define YSHAPE_API  __attribute__ ((visibility ("default")))

#endif


