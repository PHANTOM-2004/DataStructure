set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_executable(TrieTest TrieTest.cc)
add_executable(generate_test generate_test.cc)
add_executable(TheBestShip BestShip.cc)
add_library(Trie SHARED Trie_impl.cpp)

target_link_libraries(TrieTest PUBLIC Trie)