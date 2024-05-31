file(REMOVE_RECURSE
  "staticscript"
  "staticscript.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/staticscript.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
