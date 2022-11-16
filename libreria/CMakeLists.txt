## >>>>>>>>>>>>>>>
## >>>>>>>>>>>>>>>
add_library(libreria agos.cpp almi.cpp libreria.h loren.cpp pochi.cpp )
## <<<<<<<<<<<<<<<
## <<<<<<<<<<<<<<<

target_include_directories(libreria PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
