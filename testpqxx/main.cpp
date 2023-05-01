#include <iostream>
#include <pqxx/pqxx>
#include <vector>
#include <fstream>
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
    setlocale(LC_ALL, "Russian");
    try
    {
        // Создаем объект соединения с БД
        pqxx::connection conn("hostaddr=95.165.158.58 port=28009 dbname=GraduateDBtest user=umlaut-super password=kT7/Haw~k'dTm2e@");

        // Создаем объект транзакции
        pqxx::work txn(conn);

        // Выполняем SQL-запрос
        pqxx::result res = txn.exec("SELECT Name FROM Locations");

        // Обрабатываем результаты запроса
        auto result_vector = result_to_vector(res);
        std::cout << "debug";
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
        std::ofstream myfile;
        myfile.open ("example.txt");
        auto message = e.what();
        auto ptr = message;
        while(*ptr)
        {
            std::cout << printf("%x",*ptr)<<" ";
            ptr++;
        }
        myfile << e.what();
        myfile.close();
        return 1;
    }

    return 0;
}
