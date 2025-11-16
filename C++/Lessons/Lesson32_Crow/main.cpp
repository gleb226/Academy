#include "crow.h"

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([]() {
        return "Hello, World!";
    });

    CROW_ROUTE(app, "/user")([]() {
        return "Hello, user!";
    });

    CROW_ROUTE(app, "/html")
    ([]() {
        return R"(
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
    });


    app.port(2020).multithreaded().run();
}
