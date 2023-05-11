#include "DbDriverInterface.hpp"
#include <vector>
#include <string>

class DbDriver : public DbDriverInterface
{
public:
    DbDriver();
    std::vector<std::vector<std::string>> Exec(const std::string& query) override;
    bool Connected() const override;
};
