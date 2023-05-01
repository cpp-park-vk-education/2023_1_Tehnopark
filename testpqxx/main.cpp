#include <iostream>
#include <pqxx/pqxx>
#include <vector>
#include <string>

std::vector<std::vector<std::string>> result_to_vector(const pqxx::result &res)
{
    std::vector<std::vector<std::string>> result_vector;
    for (auto row = res.begin(); row != res.end(); ++row)
    {
        std::vector<std::string> row_vector;
        for (auto col = row.begin(); col != row.end(); ++col)
        {
            row_vector.push_back(col->c_str());
        }
        result_vector.push_back(row_vector);
    }
    return result_vector;
}

int main(int argc, char *argv[])
{
    try
    {
        // Создаем объект соединения с БД
        pqxx::connection conn("dbname=askme user=postgres password=1474 hostaddr=192.168.137.1 port=5432");

        // Создаем объект транзакции
        pqxx::work txn(conn);

        // Выполняем SQL-запрос
        pqxx::result res = txn.exec("SELECT * FROM askme_answer");

        // Обрабатываем результаты запроса
        auto result_vector = result_to_vector(res);
        
        // выводим все значения ячеек вектора result_vector в консоль
        for (const auto &row : result_vector)
        {
            for (const auto &cell : row)
            {
                std::cout << cell << " ";
            }
            std::cout << std::endl;
        }
        // Фиксируем транзакцию
        txn.commit();

        // Закрываем соединение
        conn.disconnect();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
