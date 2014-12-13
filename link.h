#ifndef LINKS_H
#define LINKS_H

#include <string>

class Link {
public:
    Link();
    Link(std::string s, std::string c);
    std::string s_ID;
    std::string c_ID;
};

#endif // LINKS_H
