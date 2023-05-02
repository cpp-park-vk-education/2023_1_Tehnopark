#pragma once
#include <vector>
#include <string>

class DbDriverInterface
{
public:
    virtual ~DbDriverInterface() {}
    virtual std::vector<std::vector<std::string> > Exec(const std::string& query);
    virtual bool Connected() const;
};
