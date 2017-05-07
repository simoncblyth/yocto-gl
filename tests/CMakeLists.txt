cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
set(name YoctoGLTests)
project(${name})

set(TEST_SOURCES
   ygltf_reader.cc
)

set(_TEST_SOURCES
)


foreach(TEST_SOURCE ${TEST_SOURCES})

    get_filename_component(TGT ${TEST_SOURCE} NAME_WE)
    add_executable(${TGT} ${TEST_SOURCE})

    set(testname ${name}.${TGT})

    # see cmakex-
    add_test(${testname} ${TGT})

    if(WIN32)
       # MAYBE AVOID THIS MESS JUST BY SETTING PATH FOR VS PROCESS ? 
       # https://cmake.org/pipermail/cmake/2010-December/041176.html
       set(PATH_STRING   "PATH=${CMAKE_INSTALL_PREFIX}/lib;$ENV{PATH}")
       STRING(REPLACE "\\;" ";" PATH_STRING "${PATH_STRING}")
       STRING(REPLACE ";" "\\;" PATH_STRING "${PATH_STRING}")
       set_property(TEST ${testname} PROPERTY ENVIRONMENT ${PATH_STRING})
    endif(WIN32)

    #add_dependencies(check ${TGT})
    target_link_libraries(${TGT} ${LIBRARIES} YoctoGL)
    install(TARGETS ${TGT} DESTINATION lib)
endforeach()




