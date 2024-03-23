# C++ tasks

Пояснение: в директории `tasks/taskN` (где N - номер задачи) находятся все необходимые файлы. В текстовых файлах `inputK.txt` содержатся входные тестовые данные, а в `outputK.txt` - соответствующие выходные данные (ответы). Файл `taskN.cpp` трогать нельзя.

1. Даны массив вещественных чисел и 4 вида операций: +, -, *, /.
Какое максимальное значение можно получить, используя эти операции? Вычисления осуществляются последовательно (без учета приоритетности).

Примеры:

```
[1, 2, 3, 4]
1 + 2 * 3 * 4 = 36

[3, -3, 0.2, -6]
3 * (-3) / 0.2 * (-6) = 270
```

```bash
git remote add REMOTE_NAME REMOTE_REPO_URL_1
git remote set-url --add --push REMOTE_NAME REMOTE_REPO_URL_1
git remote set-url --add --push REMOTE_NAME REMOTE_REPO_URL_2
...
git remote set-url --add --push REMOTE_NAME REMOTE_REPO_URL_N

or

git remote add REMOTE_NAME REMOTE_REPO_URL_1
for (( i=1; i<=N; i++ ))
do
  git remote set-url --add --push REMOTE_NAME REMOTE_REPO_URL_I
done
```
