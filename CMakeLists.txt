cmake_minimum_required (VERSION 2.8.11)
set(name YoctoGL)
project(${name})

include(CTest)


include(EnvCompilationFlags)

#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_STANDARD_REQUIRED on)


# https://cmake.org/Wiki/CMake_RPATH_handling
if (APPLE)
   set(CMAKE_SKIP_BUILD_RPATH  FALSE)
   set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE) 
   set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
   set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")  
   set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE) 
   # http://www.kitware.com/blog/home/post/510
   # enable @rpath in the install name for any shared library being built
   # note: it is planned that a future version of CMake will enable this by default
   set(CMAKE_MACOSX_RPATH 1)
endif(APPLE)


include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/yocto
)

add_definitions( 
)


set(SOURCES
     yocto/yocto_img.cpp
     yocto/yocto_gltf.cpp
     yocto/yocto_shape.cpp
)


set(EXT_HEADERS
     yocto/ext/json.hpp
)

set(HEADERS
     yocto/yocto_math.h
     yocto/yocto_shape.h
     yocto/yocto_gltf.h
     yocto/YGLTF_API_EXPORT.h 
     yocto/YSHAPE_API_EXPORT.h 
)


add_library(${name} SHARED ${SOURCES}  )
install(TARGETS ${name}  DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include/${name})
install(FILES ${EXT_HEADERS} DESTINATION include/${name}/ext)

add_subdirectory(tests)
