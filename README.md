Запуск из папки со всеми файлами:

cmake -S. bin //-DBUILD_TESTS=OFF для гугл тестов

cmake --build bin

Запуск main:

./bin/time_main

Запуск googletest:

./bin/tests/test_app

P.S. googletest -ы ещё не сделаны
