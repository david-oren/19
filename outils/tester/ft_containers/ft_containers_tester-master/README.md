# ft_containers_tester

Tester for ft_containers.
To run this gtest has to be installed: `gtest_installer.sh`
If it doesn't work you have to install cmake first: `brew install cmake`

### To use the test 
Place your hpp files in the includes folder and uncomment the files you have 
in ft.hpp. It is expected that the containers are names as in the 
subject in namespace ft with lowercase name as ft::vector. For map and multimap
it's also expecting them to use ft::pair. If you used std::pair you will have to 
replace LIBRARY::pair in those tests with std::pair and LIBRARY:make_pair with
std::make_pair.

### To run the test
``make && ./unitTester`` to run the basic tests
``make bonus && ./unitTester`` to run the bonus tests 
``make all && ./unitTester`` to run the all tests 
``make ``container_name``&& ./unitTester`` to run the container_name test
``make stdlib && ./unitTester`` to run the tests with the STL containers

or use the filter to select specific tests
``--gtest_filter=Vector*`` or ``--gtest_filter=*Insert*``

### To add tests
[How to use googletest](https://github.com/google/googletest/blob/master/googletest/docs/primer.md?fbclid=IwAR3Y-Dj-IpBjt_PDk9_hwQyVFbaOf_eJUB8O9SOUgP0NaZm4NUkBSfZ1ivY)

