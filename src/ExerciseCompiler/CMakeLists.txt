add_library(
    ExerciseCompiler SHARED
    private/module.cpp
    private/function.cpp
    private/basicBlock.cpp
    public/module.h
    public/function.h
    public/basicBlock.h
)

target_include_directories(ExerciseCompiler PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/public")
target_include_directories(ExerciseCompiler PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/private")