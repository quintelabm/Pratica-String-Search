file(GLOB source_files *.cpp)
add_library(rb-lib ${source_files})
#target_include_directories(sb-lib PUBLIC ${PROJECT_SOURCE_DIR}/include)