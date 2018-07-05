cmake_minimum_required (VERSION 3.5)
set(name YoctoGL)
project(${name} VERSION 0.1.0)

include(CTest)
include(OpticksBuildOptions)

include(GNUInstallDirs)
set(CMAKE_INSTALL_INCLUDEDIR "externals/include/${name}")
set(CMAKE_INSTALL_LIBDIR     "externals/lib")
set(CMAKE_INSTALL_BINDIR     "lib")

find_package(BCM REQUIRED)
include(BCMDeploy)

set(SOURCES
     yocto/yocto_img.cpp
     yocto/yocto_gltf.cpp
#     yocto/yocto_shape.cpp
)

set(HEADERS_EXT
     yocto/ext/json.hpp
)

set(HEADERS
     yocto/yocto_math.h
     yocto/yocto_shape.h
     yocto/yocto_gltf.h
     yocto/YGLTF.h 
     yocto/YGLTF_API_EXPORT.h 
     yocto/YSHAPE_API_EXPORT.h 
)

add_library(${name} SHARED ${SOURCES})

target_include_directories(${name} PUBLIC
   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/yocto>
)

target_compile_features(${name} 
   PUBLIC 
      cxx_constexpr
)



install(TARGETS ${name}  DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ${HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${HEADERS_EXT} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/ext)

bcm_deploy(TARGETS ${name} NAMESPACE Opticks:: SKIP_HEADER_INSTALL)

add_subdirectory(tests)

