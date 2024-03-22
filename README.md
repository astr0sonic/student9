# C++ tasks

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
