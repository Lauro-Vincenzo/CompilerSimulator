
add_executable(Exercise main.cpp tests.h)
add_subdirectory(ExerciseCompiler)
set_target_properties(ExerciseCompiler PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(Exercise PRIVATE ExerciseCompiler)