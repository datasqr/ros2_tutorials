# CMake generated Testfile for 
# Source directory: /home/mz/projects/ros/tutorials/basics/ros2_ws/src/polygon_base
# Build directory: /home/mz/projects/ros/tutorials/basics/ros2_ws/build/polygon_base
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(cppcheck "/usr/bin/python3.10" "-u" "/opt/ros/iron/share/ament_cmake_test/cmake/run_test.py" "/home/mz/projects/ros/tutorials/basics/ros2_ws/build/polygon_base/test_results/polygon_base/cppcheck.xunit.xml" "--package-name" "polygon_base" "--output-file" "/home/mz/projects/ros/tutorials/basics/ros2_ws/build/polygon_base/ament_cppcheck/cppcheck.txt" "--command" "/opt/ros/iron/bin/ament_cppcheck" "--xunit-file" "/home/mz/projects/ros/tutorials/basics/ros2_ws/build/polygon_base/test_results/polygon_base/cppcheck.xunit.xml" "--include_dirs" "/home/mz/projects/ros/tutorials/basics/ros2_ws/src/polygon_base/include")
set_tests_properties(cppcheck PROPERTIES  LABELS "cppcheck;linter" TIMEOUT "300" WORKING_DIRECTORY "/home/mz/projects/ros/tutorials/basics/ros2_ws/src/polygon_base" _BACKTRACE_TRIPLES "/opt/ros/iron/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/iron/share/ament_cmake_cppcheck/cmake/ament_cppcheck.cmake;66;ament_add_test;/opt/ros/iron/share/ament_cmake_cppcheck/cmake/ament_cmake_cppcheck_lint_hook.cmake;87;ament_cppcheck;/opt/ros/iron/share/ament_cmake_cppcheck/cmake/ament_cmake_cppcheck_lint_hook.cmake;0;;/opt/ros/iron/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/iron/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/iron/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/iron/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/iron/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/mz/projects/ros/tutorials/basics/ros2_ws/src/polygon_base/CMakeLists.txt;47;ament_package;/home/mz/projects/ros/tutorials/basics/ros2_ws/src/polygon_base/CMakeLists.txt;0;")
add_test(lint_cmake "/usr/bin/python3.10" "-u" "/opt/ros/iron/share/ament_cmake_test/cmake/run_test.py" "/home/mz/projects/ros/tutorials/basics/ros2_ws/build/polygon_base/test_results/polygon_base/lint_cmake.xunit.xml" "--package-name" "polygon_base" "--output-file" "/home/mz/projects/ros/tutorials/basics/ros2_ws/build/polygon_base/ament_lint_cmake/lint_cmake.txt" "--command" "/opt/ros/iron/bin/ament_lint_cmake" "--xunit-file" "/home/mz/projects/ros/tutorials/basics/ros2_ws/build/polygon_base/test_results/polygon_base/lint_cmake.xunit.xml")
set_tests_properties(lint_cmake PROPERTIES  LABELS "lint_cmake;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/mz/projects/ros/tutorials/basics/ros2_ws/src/polygon_base" _BACKTRACE_TRIPLES "/opt/ros/iron/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/iron/share/ament_cmake_lint_cmake/cmake/ament_lint_cmake.cmake;47;ament_add_test;/opt/ros/iron/share/ament_cmake_lint_cmake/cmake/ament_cmake_lint_cmake_lint_hook.cmake;21;ament_lint_cmake;/opt/ros/iron/share/ament_cmake_lint_cmake/cmake/ament_cmake_lint_cmake_lint_hook.cmake;0;;/opt/ros/iron/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/iron/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/iron/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/iron/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/iron/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/mz/projects/ros/tutorials/basics/ros2_ws/src/polygon_base/CMakeLists.txt;47;ament_package;/home/mz/projects/ros/tutorials/basics/ros2_ws/src/polygon_base/CMakeLists.txt;0;")
add_test(uncrustify "/usr/bin/python3.10" "-u" "/opt/ros/iron/share/ament_cmake_test/cmake/run_test.py" "/home/mz/projects/ros/tutorials/basics/ros2_ws/build/polygon_base/test_results/polygon_base/uncrustify.xunit.xml" "--package-name" "polygon_base" "--output-file" "/home/mz/projects/ros/tutorials/basics/ros2_ws/build/polygon_base/ament_uncrustify/uncrustify.txt" "--command" "/opt/ros/iron/bin/ament_uncrustify" "--xunit-file" "/home/mz/projects/ros/tutorials/basics/ros2_ws/build/polygon_base/test_results/polygon_base/uncrustify.xunit.xml")
set_tests_properties(uncrustify PROPERTIES  LABELS "uncrustify;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/mz/projects/ros/tutorials/basics/ros2_ws/src/polygon_base" _BACKTRACE_TRIPLES "/opt/ros/iron/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/iron/share/ament_cmake_uncrustify/cmake/ament_uncrustify.cmake;70;ament_add_test;/opt/ros/iron/share/ament_cmake_uncrustify/cmake/ament_cmake_uncrustify_lint_hook.cmake;43;ament_uncrustify;/opt/ros/iron/share/ament_cmake_uncrustify/cmake/ament_cmake_uncrustify_lint_hook.cmake;0;;/opt/ros/iron/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/iron/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/iron/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/iron/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/iron/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/mz/projects/ros/tutorials/basics/ros2_ws/src/polygon_base/CMakeLists.txt;47;ament_package;/home/mz/projects/ros/tutorials/basics/ros2_ws/src/polygon_base/CMakeLists.txt;0;")
add_test(xmllint "/usr/bin/python3.10" "-u" "/opt/ros/iron/share/ament_cmake_test/cmake/run_test.py" "/home/mz/projects/ros/tutorials/basics/ros2_ws/build/polygon_base/test_results/polygon_base/xmllint.xunit.xml" "--package-name" "polygon_base" "--output-file" "/home/mz/projects/ros/tutorials/basics/ros2_ws/build/polygon_base/ament_xmllint/xmllint.txt" "--command" "/opt/ros/iron/bin/ament_xmllint" "--xunit-file" "/home/mz/projects/ros/tutorials/basics/ros2_ws/build/polygon_base/test_results/polygon_base/xmllint.xunit.xml")
set_tests_properties(xmllint PROPERTIES  LABELS "xmllint;linter" TIMEOUT "60" WORKING_DIRECTORY "/home/mz/projects/ros/tutorials/basics/ros2_ws/src/polygon_base" _BACKTRACE_TRIPLES "/opt/ros/iron/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/iron/share/ament_cmake_xmllint/cmake/ament_xmllint.cmake;50;ament_add_test;/opt/ros/iron/share/ament_cmake_xmllint/cmake/ament_cmake_xmllint_lint_hook.cmake;18;ament_xmllint;/opt/ros/iron/share/ament_cmake_xmllint/cmake/ament_cmake_xmllint_lint_hook.cmake;0;;/opt/ros/iron/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/iron/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;21;ament_execute_extensions;/opt/ros/iron/share/ament_lint_auto/cmake/ament_lint_auto_package_hook.cmake;0;;/opt/ros/iron/share/ament_cmake_core/cmake/core/ament_execute_extensions.cmake;48;include;/opt/ros/iron/share/ament_cmake_core/cmake/core/ament_package.cmake;66;ament_execute_extensions;/home/mz/projects/ros/tutorials/basics/ros2_ws/src/polygon_base/CMakeLists.txt;47;ament_package;/home/mz/projects/ros/tutorials/basics/ros2_ws/src/polygon_base/CMakeLists.txt;0;")
