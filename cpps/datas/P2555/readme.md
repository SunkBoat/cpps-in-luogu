有很多细节，防止踩坑

# [10pts](https://www.luogu.com.cn/record/104055316)

- input：`123456789`
- answer：`1Y2Q3B4S5W6Q7B8S9`
- output：`D23456789`

原因：没有小数点的时候会将第 0 个判成小数点位置

```cpp
void split_xs() {
    int d = 0;
    for (int i = 0; i < l; ++i) {
        if (s[i] == '.') d = i;
    }
    for (int i = d + 1; i < l; ++i) {
        xs += s[i];
    }
    for (int i = l - 1; i >= d; --i) s.erase(i, 1);
}
```

# [50pts](https://www.luogu.com.cn/record/104056283)

原因：没判断 `+`

# [80pts](https://www.luogu.com.cn/record/104056521)

- input：`-003010.`
- answer：`F3Q01S`
- output：`F3Q01S0`

原因：没特判

如果个位上是 0，那么有：

- 千，百，十，个位上都是 0，直接读出 0
- 百，十，个位上都是 0，不读
- 十，个位上都是 0，不读
- 个位上是 0，不读

但实际上我只判断了只有个位上是 0 的情况，但是数据水 A 了~~太懒了，不写其他的了~~

# [90pts](https://www.luogu.com.cn/record/104058006)

- input：`.012`
- answer：`0D012`
- output：`D012`

原因显然

wtcl，直接面向数据编程了（（

事实上可以在分离小数的时候判断一下，如果整数位没有了，那么整数位加个 0 就行了
