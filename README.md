# C++ tasks

1. Даны массив вещественных чисел и 4 вида операций: +, -, *, /.
Какое максимальное значение можно получить, используя эти операции? Вычисления осуществляются последовательно.

Примеры:

```
[1, 2, 3, 4]
1 + 2 * 3 * 4 = 36

[1, -3, 0.1, -5]
1 * (-3) / 0.1 * (-5) = 150
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
