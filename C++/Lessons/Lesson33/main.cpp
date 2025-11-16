#include "crow.h"

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "Hello, World!";
    });

    CROW_ROUTE(app, "/about")([](){
        return "First Site!";
    });

    CROW_ROUTE(app, "/html")
    ([](){
        crow::response res;
        res.set_header("Content-Type", "text/html");
        res.body =  R"(
            <!DOCTYPE html>
            <html>
            <head>
                <title>Crow Server</title>
                <meta charset="utf-8">
            </head>
            <body>
                <h1>Привіт з Crow! 🚀</h1>
                <p>Це HTML сторінка згенерована C++ кодом!</p>
            </body>
            </html>
        )";
        return res;
    });

    // Приклад маршруту з поясненнями
    CROW_ROUTE(app, "/hello")
    .methods("GET"_method)
    ([](const crow::request& req){
        // 4️⃣ Тіло обробника
        std::string name = req.url_params.get("name");

        // 5️⃣ Створення відповіді
        crow::response res(200);
        res.body = "Hello, " + name;

        // 6️⃣ Повернення відповіді
        return res;
    });

    CROW_ROUTE(app, "/users/<int>")
    ([](int user_id){
        return "User ID: " + std::to_string(user_id);
    });

    app.port(8080)
        .multithreaded()
        .run();
}