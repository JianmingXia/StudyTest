## 说明
- AB 测试不同源
- C  测试不同源
## nginx配置

```
server
{
    listen       80;
    server_name  parent.a.com;

    location / {
		root F:\web\StudyTest\PostMessage\A;
        index index.html  index.php;
    }
}

server
{
    listen       80;
    server_name  child.b.com;

    location / {
		root F:\web\StudyTest\PostMessage\B;
        index index.html  index.php;
    }
}

server
{
    listen       80;
    server_name  parentchild.c.com;

    location / {
		root F:\web\StudyTest\PostMessage\C;
        index index.html  index.php;
    }
}
```