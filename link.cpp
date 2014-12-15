#include "linkrepository.h"

Link::Link() {
   s_ID = "";
   c_ID = "";
}

Link::Link(std::string s, std::string c) {
   s_ID = s;
   c_ID = c;
}
