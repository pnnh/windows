### 预处理

```bash
gcc -E CLanguage.c -o bin/CLanguage.i
```

### 汇编

```bash
gcc -S bin/CLanguage.i -o bin/CLanguage.s
```

### 编译

```bash
gcc -c bin/CLanguage.s -o bin/CLanguage.obj
```

### 链接

```bash
gcc CLanguage.c -o CLanguage.exe
```