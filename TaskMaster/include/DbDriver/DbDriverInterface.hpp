#pragma once
#include <vector>
#include <string>

class DbDriverInterface
{
public:
    virtual ~DbDriverInterface() {}
    virtual std::vector<std::vector<std::string> > exec(std::string query);
    virtual bool connected();
};
