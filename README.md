My modifications to [https://github.com/rapid7/mettle/tree/master/libreflect](https://github.com/rapid7/mettle/tree/master/libreflect).

Mostly just wrapping it up for easy use.

**Typical workflow:**

```bash
wget -O /dev/shm/lr-exec http://raw.githubusercontent.com/stacksparrow4/lr-exec/main/lr-exec
/lib64/ld-linux-x86-64.so.2 /dev/shm/lr-exec /bin/ls
```
