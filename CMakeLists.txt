cmake_minimum_required(VERSION 3.5.0)

project(StudentSystem)

aux_source_directory(./src DIR)

include_directories(./header)


add_executable(StudentSystem ${DIR})

