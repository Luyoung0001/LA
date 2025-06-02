# LA
Loongarch 挑战赛

## difftest

由于框架 **SimpleLACore** 提供的 difftest 能力有限，它不能进行 CSR difftest。比如对于实验 EXP=18，首先让 **OpenLA500** under **SimpleLACore** 下进行 difftest。验证等价性后，让 **MyCPU** under **OpenLA500** 进行 difftest。

**OpenLA500** 可以提供相当高自由度的 difftest，可以更加精准的定位错误。

