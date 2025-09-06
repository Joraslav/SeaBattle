# Морской бой

Веб-версия классической игры "Морской бой" с бэкендом на C++ и фронтендом на JavaScript.

## Правила

[Правила разработки](backend/README.md)

## Особенности

## Структура проекта

Данный проект старается придерживаться следующей структуры

```planetext
SeaBattle/
├── backend/                 # C++ бэкенд
│   ├── src/
│   │   ├── game/           # Логика игры
│   │   │   ├── Game.cpp
│   │   │   ├── Game.hpp
│   │   │   ├── Player.cpp
│   │   │   ├── Player.hpp
│   │   │   ├── Board.cpp
│   │   │   ├── Board.hpp
│   │   │   ├── Ship.cpp
│   │   │   └── Ship.hpp
│   │   ├── network/        # Сетевая часть
│   │   │   ├── Server.cpp
│   │   │   ├── Server.hpp
│   │   │   ├── ClientHandler.cpp
│   │   │   └── ClientHandler.hpp
│   │   ├── utils/          # Утилиты
│   │   │   ├── Logger.cpp
│   │   │   └── Logger.hpp
│   │   └── main.cpp        # Точка входа
│   ├── include/            # Заголовочные файлы
│   ├── third_party/        # Сторонние библиотеки
│   ├── CMakeLists.txt      # CMake конфигурация
│   └── package.json        # Для сборки WASM (опционально)
├── frontend/               # JavaScript фронтенд
│   ├── src/
│   │   ├── js/
│   │   │   ├── game/       # Логика игры на клиенте
│   │   │   │   ├── GameManager.js
│   │   │   │   ├── BoardRenderer.js
│   │   │   │   ├── ShipPlacer.js
│   │   │   │   └── AnimationManager.js
│   │   │   ├── network/    # Сетевое взаимодействие
│   │   │   │   ├── WebSocketClient.js
│   │   │   │   └── ApiClient.js
│   │   │   ├── ui/         # Пользовательский интерфейс
│   │   │   │   ├── UIManager.js
│   │   │   │   ├── ModalManager.js
│   │   │   │   └── EventHandlers.js
│   │   │   └── utils/      # Утилиты
│   │   │       ├── Constants.js
│   │   │       └── Helpers.js
│   │   ├── css/
│   │   │   ├── style.css
│   │   │   ├── board.css
│   │   │   └── modal.css
│   │   ├── assets/         # Изображения, звуки
│   │   │   ├── images/
│   │   │   └── sounds/
│   │   └── index.html      # Главная страница
│   ├── package.json
│   ├── webpack.config.js   # Конфигурация сборки
│   └── .babelrc
├── shared/                 # Общие файлы для бэкенда и фронтенда
│   ├── protobuf/          # Протоколы сообщений (опционально)
│   └── types/             # Общие типы данных
├── scripts/               # Вспомогательные скрипты
│   ├── build.sh
│   ├── run-server.sh
│   └── deploy.sh
├── tests/                 # Тесты
│   ├── backend_tests/
│   └── frontend_tests/
├── docs/                  # Документация
├── docker/                # Docker конфигурация
│   ├── Dockerfile.backend
│   ├── Dockerfile.frontend
│   └── docker-compose.yml
├── CMakeLists.txt         # Корневой CMake файл
├── .gitignore
├── README.md
└── LICENSE
```
