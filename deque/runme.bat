cmake CMakeLists.txt
cmake --install .
cmake --build .
copy src\kursiokai.txt Debug\kursiokai.txt
cd Debug\
Deque.exe
pause