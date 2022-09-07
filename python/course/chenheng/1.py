import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
#sep:数据分隔符,header:数据列名在第几行
df=pd.read_csv('C:/DATA/repository/code/python/course/chenheng/data/house.txt',sep=',',header=0)
#c:color
plt.scatter(df['area'],df['price'],c='b')