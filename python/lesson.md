#### python深度学习

##### 用神经网络预测酸奶销量

①预测酸奶日销量1

```python
import numpy as np
import tensorflow as tf
```

自造数据集

```python
np.random.seed(50)
x = np.random.rand(32, 2)
np.random.seed(50)
y_ = [[x1 + x2 + (np.random.rand()/10 - 0.05)] for (x1, x2) in x]
w = tf.Variable(tf.random.normal([2,1], stddev=1, seed=1))
x = tf.cast(x, dtype=tf.float32)
epochs = 15000 #迭代次数
lr = 0.001 #学习率
for epoch in range(epochs):
    with tf.GradientTape() as tape:
        y = tf.matmul(x, w)
        loss_mse = tf.reduce_mean(tf.square(y_ - y)) 
    grads = tape.gradient(loss_mse, w)
    w.assign_sub(lr*grads)
    if epoch % 500 == 0:
        print('After %d training steps, w is' %epoch)
        print(w)
print('Final w is:', w)
```

    After 0 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[-0.8101696],
           [ 1.485255 ]], dtype=float32)>
    After 500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[-0.36370227],
           [ 1.7091383 ]], dtype=float32)>
    After 1000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[-0.09182037],
           [ 1.7943552 ]], dtype=float32)>
    After 1500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.08338203],
           [1.8075756 ]], dtype=float32)>
    After 2000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.20414291],
           [1.7845508 ]], dtype=float32)>
    After 2500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.29343665],
           [1.7443693 ]], dtype=float32)>
    After 3000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.3638279],
           [1.6971394]], dtype=float32)>
    After 3500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.4222504],
           [1.6481372]], dtype=float32)>
    After 4000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.47258648],
           [1.6000549 ]], dtype=float32)>
    After 4500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.51706064],
           [1.5541908 ]], dtype=float32)>
    After 5000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.55699277],
           [1.5111096 ]], dtype=float32)>
    After 5500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.59320575],
           [1.4709893 ]], dtype=float32)>
    After 6000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.6262438],
           [1.433812 ]], dtype=float32)>
    After 6500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.65649307],
           [1.3994584 ]], dtype=float32)>
    After 7000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.6842485],
           [1.3677669]], dtype=float32)>
    After 7500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.70974827],
           [1.3385594 ]], dtype=float32)>
    After 8000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.73319244],
           [1.3116561 ]], dtype=float32)>
    After 8500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.75475615],
           [1.286884  ]], dtype=float32)>
    After 9000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.7745957],
           [1.2640779]], dtype=float32)>
    After 9500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.79285145],
           [1.2430849 ]], dtype=float32)>
    After 10000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.8096513],
           [1.2237617]], dtype=float32)>
    After 10500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.82511204],
           [1.2059764 ]], dtype=float32)>
    After 11000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.83934104],
           [1.1896064 ]], dtype=float32)>
    After 11500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.85243684],
           [1.1745398 ]], dtype=float32)>
    After 12000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.8644893],
           [1.1606735]], dtype=float32)>
    After 12500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.875582 ],
           [1.1479106]], dtype=float32)>
    After 13000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.88579136],
           [1.1361648 ]], dtype=float32)>
    After 13500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.89518756],
           [1.1253542 ]], dtype=float32)>
    After 14000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.90383554],
           [1.1154041 ]], dtype=float32)>
    After 14500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.9117948],
           [1.106246 ]], dtype=float32)>
    Final w is: <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[0.91910625],
           [1.0978338 ]], dtype=float32)>

迭代15000次后,w的值array[\[0.91910625\],[1.0978338 ]]

②预测酸奶日销量2---自定义损失函数

```python
import numpy as np
import tensorflow as tf
np.random.seed(50) 
x = np.random.rand(32, 2)
np.random.seed(50) 
y_ = [[x1 + x2 + (np.random.rand()/10-0.05)] for (x1, x2) in x]
w = tf.Variable(tf.random.normal([2,1], stddev=1,seed=1)) 
x = tf.cast(x, dtype=tf.float32)
epochs = 15000
lr = 0.001
for epoch in range(epochs):
    with tf.GradientTape() as tape:
        y = tf.matmul(x, w) 
        loss_zdy = tf.reduce_sum(tf.where(tf.greater(y, y_), (y-y_)*1, (y_-y)*4)) #
    grads = tape.gradient(loss_zdy, w) 
    w.assign_sub(lr*grads) 
    if epoch % 500 == 0:
        print('After %d training steps, w is' %epoch)
        print(w)
print('Final w is:', w)
```

    After 0 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.370413 ],
           [0.5765818]], dtype=float32)>
    After 500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0180757],
           [1.0245619]], dtype=float32)>
    After 1000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0155951],
           [1.0255655]], dtype=float32)>
    After 1500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.021677 ],
           [1.0315355]], dtype=float32)>
    After 2000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0152975],
           [1.0235618]], dtype=float32)>
    After 2500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0181403],
           [1.0245162]], dtype=float32)>
    After 3000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0163339],
           [1.0265371]], dtype=float32)>
    After 3500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0176959],
           [1.0252694]], dtype=float32)>
    After 4000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0168865],
           [1.0268477]], dtype=float32)>
    After 4500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0151399],
           [1.0238928]], dtype=float32)>
    After 5000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0149177],
           [1.0242693]], dtype=float32)>
    After 5500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0161328],
           [1.0257585]], dtype=float32)>
    After 6000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0190191],
           [1.0278224]], dtype=float32)>
    After 6500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0135769],
           [1.0243819]], dtype=float32)>
    After 7000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0164632],
           [1.0264457]], dtype=float32)>
    After 7500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0147166],
           [1.0234908]], dtype=float32)>
    After 8000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0183642],
           [1.0287908]], dtype=float32)>
    After 8500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0166177],
           [1.0258359]], dtype=float32)>
    After 9000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0163954],
           [1.0262125]], dtype=float32)>
    After 9500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0169363],
           [1.0266844]], dtype=float32)>
    After 10000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0166706],
           [1.0259515]], dtype=float32)>
    After 10500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0157741],
           [1.0253109]], dtype=float32)>
    After 11000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0155519],
           [1.0256875]], dtype=float32)>
    After 11500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0153732],
           [1.0271735]], dtype=float32)>
    After 12000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0166917],
           [1.0247964]], dtype=float32)>
    After 12500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.016513 ],
           [1.0262824]], dtype=float32)>
    After 13000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0156165],
           [1.0256418]], dtype=float32)>
    After 13500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0223292],
           [1.0315195]], dtype=float32)>
    After 14000 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0166693],
           [1.0225317]], dtype=float32)>
    After 14500 training steps, w is
    <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0148629],
           [1.0245526]], dtype=float32)>
    Final w is: <tf.Variable 'Variable:0' shape=(2, 1) dtype=float32, numpy=
    array([[1.0177649],
           [1.0252362]], dtype=float32)>

迭代15000次后,w的最后值array[\[1.0177649],[1.0252362]],与第一个例子相比,模型趋向于将w的值变大

##### 用神经网络实现鸢尾花分类

对鸢尾花数据集使用tensorflow进行预测,可视化acc,loss曲线

导入所需模块

```python
import tensorflow as tf
from sklearn.datasets import load_iris
import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
```

①获取数据,分割训练集和测试集

```python
X = load_iris().data
y = load_iris().target
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25, random_state = 0)
```

②搭建模型

```python
model = tf.keras.models.Sequential() 
model.add(tf.keras.layers.Dense(10, activation='relu')) 
model.add(tf.keras.layers.Dense(3, activation='softmax')) 
```

③编译模型,迭代500次

```python
model.compile(optimizer='adam', loss='sparse_categorical_crossentropy',
metrics=['sparse_categorical_accuracy'])
```

④训练模型

```python
history = model.fit(X_train, y_train, batch_size=16, epochs=500)
```

    Epoch 1/500
    7/7 [==============================] - 1s 3ms/step - loss: 1.8005 - sparse_categorical_accuracy: 0.3661
    Epoch 2/500
    7/7 [==============================] - 0s 3ms/step - loss: 1.6582 - sparse_categorical_accuracy: 0.3661
    Epoch 3/500
    7/7 [==============================] - 0s 4ms/step - loss: 1.5358 - sparse_categorical_accuracy: 0.3661
    Epoch 4/500
    7/7 [==============================] - 0s 3ms/step - loss: 1.4318 - sparse_categorical_accuracy: 0.3661
    Epoch 5/500
    7/7 [==============================] - 0s 4ms/step - loss: 1.3399 - sparse_categorical_accuracy: 0.3661
    Epoch 6/500
    7/7 [==============================] - 0s 4ms/step - loss: 1.2528 - sparse_categorical_accuracy: 0.3661
    Epoch 7/500
    7/7 [==============================] - 0s 4ms/step - loss: 1.1853 - sparse_categorical_accuracy: 0.3661
    Epoch 8/500
    7/7 [==============================] - 0s 4ms/step - loss: 1.1038 - sparse_categorical_accuracy: 0.3661
    Epoch 9/500
    7/7 [==============================] - 0s 4ms/step - loss: 1.0455 - sparse_categorical_accuracy: 0.3661
    Epoch 10/500
    7/7 [==============================] - 0s 4ms/step - loss: 0.9959 - sparse_categorical_accuracy: 0.3661
    Epoch 11/500
    7/7 [==============================] - 0s 4ms/step - loss: 0.9488 - sparse_categorical_accuracy: 0.3661
    Epoch 12/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.9152 - sparse_categorical_accuracy: 0.3661
    Epoch 13/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.8913 - sparse_categorical_accuracy: 0.4196
    Epoch 14/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.8702 - sparse_categorical_accuracy: 0.6161
    Epoch 15/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.8582 - sparse_categorical_accuracy: 0.6875
    Epoch 16/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.8431 - sparse_categorical_accuracy: 0.6964
    Epoch 17/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.8303 - sparse_categorical_accuracy: 0.6964
    Epoch 18/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.8184 - sparse_categorical_accuracy: 0.6964
    Epoch 19/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.8061 - sparse_categorical_accuracy: 0.6964
    Epoch 20/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.7946 - sparse_categorical_accuracy: 0.6964
    Epoch 21/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.7832 - sparse_categorical_accuracy: 0.6964
    Epoch 22/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.7740 - sparse_categorical_accuracy: 0.6964
    Epoch 23/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.7617 - sparse_categorical_accuracy: 0.6964
    Epoch 24/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.7516 - sparse_categorical_accuracy: 0.6964
    Epoch 25/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.7426 - sparse_categorical_accuracy: 0.6964
    Epoch 26/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.7321 - sparse_categorical_accuracy: 0.6964
    Epoch 27/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.7223 - sparse_categorical_accuracy: 0.6964
    Epoch 28/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.7134 - sparse_categorical_accuracy: 0.6964
    Epoch 29/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.7052 - sparse_categorical_accuracy: 0.6964
    Epoch 30/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.6961 - sparse_categorical_accuracy: 0.6964
    Epoch 31/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.6870 - sparse_categorical_accuracy: 0.6964
    Epoch 32/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.6788 - sparse_categorical_accuracy: 0.6964
    Epoch 33/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.6717 - sparse_categorical_accuracy: 0.6964
    Epoch 34/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.6630 - sparse_categorical_accuracy: 0.6964
    Epoch 35/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.6569 - sparse_categorical_accuracy: 0.6964
    Epoch 36/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.6478 - sparse_categorical_accuracy: 0.6964
    Epoch 37/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.6411 - sparse_categorical_accuracy: 0.6964
    Epoch 38/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.6337 - sparse_categorical_accuracy: 0.6964
    Epoch 39/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.6271 - sparse_categorical_accuracy: 0.6964
    Epoch 40/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.6205 - sparse_categorical_accuracy: 0.6964
    Epoch 41/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.6137 - sparse_categorical_accuracy: 0.6964
    Epoch 42/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.6076 - sparse_categorical_accuracy: 0.6964
    Epoch 43/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.6011 - sparse_categorical_accuracy: 0.6964
    Epoch 44/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.5951 - sparse_categorical_accuracy: 0.6964
    Epoch 45/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.5893 - sparse_categorical_accuracy: 0.6964
    Epoch 46/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.5835 - sparse_categorical_accuracy: 0.6964
    Epoch 47/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.5780 - sparse_categorical_accuracy: 0.6964
    Epoch 48/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.5728 - sparse_categorical_accuracy: 0.6964
    Epoch 49/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.5672 - sparse_categorical_accuracy: 0.6964
    Epoch 50/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.5624 - sparse_categorical_accuracy: 0.6964
    Epoch 51/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.5567 - sparse_categorical_accuracy: 0.6964
    Epoch 52/500
    7/7 [==============================] - 0s 4ms/step - loss: 0.5528 - sparse_categorical_accuracy: 0.7054
    Epoch 53/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.5470 - sparse_categorical_accuracy: 0.7054
    Epoch 54/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.5423 - sparse_categorical_accuracy: 0.7054
    Epoch 55/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.5383 - sparse_categorical_accuracy: 0.7054
    Epoch 56/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.5331 - sparse_categorical_accuracy: 0.7054
    Epoch 57/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.5300 - sparse_categorical_accuracy: 0.7054
    Epoch 58/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.5244 - sparse_categorical_accuracy: 0.7143
    Epoch 59/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.5204 - sparse_categorical_accuracy: 0.7143
    Epoch 60/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.5160 - sparse_categorical_accuracy: 0.7143
    Epoch 61/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.5117 - sparse_categorical_accuracy: 0.7143
    Epoch 62/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.5076 - sparse_categorical_accuracy: 0.7143
    Epoch 63/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.5040 - sparse_categorical_accuracy: 0.7143
    Epoch 64/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.5003 - sparse_categorical_accuracy: 0.7143
    Epoch 65/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4963 - sparse_categorical_accuracy: 0.7143
    Epoch 66/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4924 - sparse_categorical_accuracy: 0.7143
    Epoch 67/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4896 - sparse_categorical_accuracy: 0.7321
    Epoch 68/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4850 - sparse_categorical_accuracy: 0.7500
    Epoch 69/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4814 - sparse_categorical_accuracy: 0.7411
    Epoch 70/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4782 - sparse_categorical_accuracy: 0.7321
    Epoch 71/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4750 - sparse_categorical_accuracy: 0.7500
    Epoch 72/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4710 - sparse_categorical_accuracy: 0.7500
    Epoch 73/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4676 - sparse_categorical_accuracy: 0.7500
    Epoch 74/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4647 - sparse_categorical_accuracy: 0.7500
    Epoch 75/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4612 - sparse_categorical_accuracy: 0.7589
    Epoch 76/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4579 - sparse_categorical_accuracy: 0.7768
    Epoch 77/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4559 - sparse_categorical_accuracy: 0.7589
    Epoch 78/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4519 - sparse_categorical_accuracy: 0.7768
    Epoch 79/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4484 - sparse_categorical_accuracy: 0.8304
    Epoch 80/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4455 - sparse_categorical_accuracy: 0.8304
    Epoch 81/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4429 - sparse_categorical_accuracy: 0.8304
    Epoch 82/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4396 - sparse_categorical_accuracy: 0.8304
    Epoch 83/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4368 - sparse_categorical_accuracy: 0.8304
    Epoch 84/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4345 - sparse_categorical_accuracy: 0.8304
    Epoch 85/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4309 - sparse_categorical_accuracy: 0.8482
    Epoch 86/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4279 - sparse_categorical_accuracy: 0.8482
    Epoch 87/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4251 - sparse_categorical_accuracy: 0.8393
    Epoch 88/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.4233 - sparse_categorical_accuracy: 0.8393
    Epoch 89/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.4201 - sparse_categorical_accuracy: 0.8393
    Epoch 90/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4167 - sparse_categorical_accuracy: 0.8393
    Epoch 91/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4147 - sparse_categorical_accuracy: 0.8393
    Epoch 92/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4115 - sparse_categorical_accuracy: 0.8393
    Epoch 93/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4090 - sparse_categorical_accuracy: 0.8482
    Epoch 94/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4061 - sparse_categorical_accuracy: 0.8661
    Epoch 95/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4036 - sparse_categorical_accuracy: 0.8750
    Epoch 96/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.4014 - sparse_categorical_accuracy: 0.8661
    Epoch 97/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3987 - sparse_categorical_accuracy: 0.8839
    Epoch 98/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3958 - sparse_categorical_accuracy: 0.8839
    Epoch 99/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3939 - sparse_categorical_accuracy: 0.8839
    Epoch 100/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3912 - sparse_categorical_accuracy: 0.8839
    Epoch 101/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3882 - sparse_categorical_accuracy: 0.9018
    Epoch 102/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3859 - sparse_categorical_accuracy: 0.9196
    Epoch 103/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3835 - sparse_categorical_accuracy: 0.9196
    Epoch 104/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3815 - sparse_categorical_accuracy: 0.9196
    Epoch 105/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3785 - sparse_categorical_accuracy: 0.9196
    Epoch 106/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3769 - sparse_categorical_accuracy: 0.9107
    Epoch 107/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3751 - sparse_categorical_accuracy: 0.9286
    Epoch 108/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3715 - sparse_categorical_accuracy: 0.9286
    Epoch 109/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3691 - sparse_categorical_accuracy: 0.9286
    Epoch 110/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3668 - sparse_categorical_accuracy: 0.9196
    Epoch 111/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3651 - sparse_categorical_accuracy: 0.9196
    Epoch 112/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3622 - sparse_categorical_accuracy: 0.9196
    Epoch 113/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3603 - sparse_categorical_accuracy: 0.9196
    Epoch 114/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3581 - sparse_categorical_accuracy: 0.9286
    Epoch 115/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3561 - sparse_categorical_accuracy: 0.9464
    Epoch 116/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3533 - sparse_categorical_accuracy: 0.9554
    Epoch 117/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3516 - sparse_categorical_accuracy: 0.9375
    Epoch 118/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3486 - sparse_categorical_accuracy: 0.9286
    Epoch 119/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3465 - sparse_categorical_accuracy: 0.9286
    Epoch 120/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3444 - sparse_categorical_accuracy: 0.9286
    Epoch 121/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3420 - sparse_categorical_accuracy: 0.9464
    Epoch 122/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3407 - sparse_categorical_accuracy: 0.9464
    Epoch 123/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3377 - sparse_categorical_accuracy: 0.9554
    Epoch 124/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3356 - sparse_categorical_accuracy: 0.9554
    Epoch 125/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3338 - sparse_categorical_accuracy: 0.9554
    Epoch 126/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3324 - sparse_categorical_accuracy: 0.9464
    Epoch 127/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3291 - sparse_categorical_accuracy: 0.9554
    Epoch 128/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3272 - sparse_categorical_accuracy: 0.9554
    Epoch 129/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3262 - sparse_categorical_accuracy: 0.9375
    Epoch 130/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3225 - sparse_categorical_accuracy: 0.9464
    Epoch 131/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3206 - sparse_categorical_accuracy: 0.9554
    Epoch 132/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3187 - sparse_categorical_accuracy: 0.9554
    Epoch 133/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3168 - sparse_categorical_accuracy: 0.9554
    Epoch 134/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3147 - sparse_categorical_accuracy: 0.9554
    Epoch 135/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3126 - sparse_categorical_accuracy: 0.9554
    Epoch 136/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3104 - sparse_categorical_accuracy: 0.9554
    Epoch 137/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3084 - sparse_categorical_accuracy: 0.9554
    Epoch 138/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3065 - sparse_categorical_accuracy: 0.9554
    Epoch 139/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3050 - sparse_categorical_accuracy: 0.9554
    Epoch 140/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3026 - sparse_categorical_accuracy: 0.9554
    Epoch 141/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.3006 - sparse_categorical_accuracy: 0.9554
    Epoch 142/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2984 - sparse_categorical_accuracy: 0.9554
    Epoch 143/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2975 - sparse_categorical_accuracy: 0.9643
    Epoch 144/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2947 - sparse_categorical_accuracy: 0.9643
    Epoch 145/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2926 - sparse_categorical_accuracy: 0.9643
    Epoch 146/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2908 - sparse_categorical_accuracy: 0.9643
    Epoch 147/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2891 - sparse_categorical_accuracy: 0.9554
    Epoch 148/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2869 - sparse_categorical_accuracy: 0.9643
    Epoch 149/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2852 - sparse_categorical_accuracy: 0.9643
    Epoch 150/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2831 - sparse_categorical_accuracy: 0.9643
    Epoch 151/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2819 - sparse_categorical_accuracy: 0.9643
    Epoch 152/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2793 - sparse_categorical_accuracy: 0.9643
    Epoch 153/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2778 - sparse_categorical_accuracy: 0.9643
    Epoch 154/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2758 - sparse_categorical_accuracy: 0.9643
    Epoch 155/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2737 - sparse_categorical_accuracy: 0.9643
    Epoch 156/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2724 - sparse_categorical_accuracy: 0.9643
    Epoch 157/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2712 - sparse_categorical_accuracy: 0.9643
    Epoch 158/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2685 - sparse_categorical_accuracy: 0.9643
    Epoch 159/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2666 - sparse_categorical_accuracy: 0.9643
    Epoch 160/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2654 - sparse_categorical_accuracy: 0.9643
    Epoch 161/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2630 - sparse_categorical_accuracy: 0.9643
    Epoch 162/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2616 - sparse_categorical_accuracy: 0.9643
    Epoch 163/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2598 - sparse_categorical_accuracy: 0.9643
    Epoch 164/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2590 - sparse_categorical_accuracy: 0.9643
    Epoch 165/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2562 - sparse_categorical_accuracy: 0.9643
    Epoch 166/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2545 - sparse_categorical_accuracy: 0.9643
    Epoch 167/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.2532 - sparse_categorical_accuracy: 0.9643
    Epoch 168/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.2520 - sparse_categorical_accuracy: 0.9643
    Epoch 169/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2497 - sparse_categorical_accuracy: 0.9821
    Epoch 170/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2478 - sparse_categorical_accuracy: 0.9732
    Epoch 171/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2470 - sparse_categorical_accuracy: 0.9643
    Epoch 172/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2445 - sparse_categorical_accuracy: 0.9643
    Epoch 173/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2431 - sparse_categorical_accuracy: 0.9643
    Epoch 174/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2415 - sparse_categorical_accuracy: 0.9643
    Epoch 175/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2399 - sparse_categorical_accuracy: 0.9643
    Epoch 176/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2383 - sparse_categorical_accuracy: 0.9643
    Epoch 177/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2375 - sparse_categorical_accuracy: 0.9643
    Epoch 178/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2358 - sparse_categorical_accuracy: 0.9643
    Epoch 179/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2338 - sparse_categorical_accuracy: 0.9643
    Epoch 180/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2322 - sparse_categorical_accuracy: 0.9732
    Epoch 181/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2333 - sparse_categorical_accuracy: 0.9732
    Epoch 182/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2290 - sparse_categorical_accuracy: 0.9732
    Epoch 183/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2276 - sparse_categorical_accuracy: 0.9732
    Epoch 184/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2267 - sparse_categorical_accuracy: 0.9643
    Epoch 185/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2250 - sparse_categorical_accuracy: 0.9643
    Epoch 186/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2242 - sparse_categorical_accuracy: 0.9643
    Epoch 187/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2220 - sparse_categorical_accuracy: 0.9732
    Epoch 188/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2206 - sparse_categorical_accuracy: 0.9732
    Epoch 189/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2205 - sparse_categorical_accuracy: 0.9821
    Epoch 190/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2180 - sparse_categorical_accuracy: 0.9732
    Epoch 191/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2163 - sparse_categorical_accuracy: 0.9732
    Epoch 192/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2151 - sparse_categorical_accuracy: 0.9732
    Epoch 193/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2139 - sparse_categorical_accuracy: 0.9643
    Epoch 194/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2129 - sparse_categorical_accuracy: 0.9732
    Epoch 195/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2116 - sparse_categorical_accuracy: 0.9732
    Epoch 196/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2108 - sparse_categorical_accuracy: 0.9732
    Epoch 197/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2086 - sparse_categorical_accuracy: 0.9643
    Epoch 198/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2072 - sparse_categorical_accuracy: 0.9732
    Epoch 199/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2067 - sparse_categorical_accuracy: 0.9821
    Epoch 200/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2052 - sparse_categorical_accuracy: 0.9821
    Epoch 201/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2037 - sparse_categorical_accuracy: 0.9821
    Epoch 202/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2021 - sparse_categorical_accuracy: 0.9732
    Epoch 203/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.2010 - sparse_categorical_accuracy: 0.9732
    Epoch 204/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1997 - sparse_categorical_accuracy: 0.9732
    Epoch 205/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1993 - sparse_categorical_accuracy: 0.9821
    Epoch 206/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1973 - sparse_categorical_accuracy: 0.9821
    Epoch 207/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1962 - sparse_categorical_accuracy: 0.9732
    Epoch 208/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1950 - sparse_categorical_accuracy: 0.9732
    Epoch 209/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1938 - sparse_categorical_accuracy: 0.9732
    Epoch 210/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.1931 - sparse_categorical_accuracy: 0.9732
    Epoch 211/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1920 - sparse_categorical_accuracy: 0.9732
    Epoch 212/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1904 - sparse_categorical_accuracy: 0.9821
    Epoch 213/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1899 - sparse_categorical_accuracy: 0.9732
    Epoch 214/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1881 - sparse_categorical_accuracy: 0.9732
    Epoch 215/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1888 - sparse_categorical_accuracy: 0.9732
    Epoch 216/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1861 - sparse_categorical_accuracy: 0.9821
    Epoch 217/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1851 - sparse_categorical_accuracy: 0.9732
    Epoch 218/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1843 - sparse_categorical_accuracy: 0.9821
    Epoch 219/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1830 - sparse_categorical_accuracy: 0.9821
    Epoch 220/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1821 - sparse_categorical_accuracy: 0.9732
    Epoch 221/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1806 - sparse_categorical_accuracy: 0.9821
    Epoch 222/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1796 - sparse_categorical_accuracy: 0.9821
    Epoch 223/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1785 - sparse_categorical_accuracy: 0.9821
    Epoch 224/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1778 - sparse_categorical_accuracy: 0.9732
    Epoch 225/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1767 - sparse_categorical_accuracy: 0.9732
    Epoch 226/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1762 - sparse_categorical_accuracy: 0.9821
    Epoch 227/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1743 - sparse_categorical_accuracy: 0.9821
    Epoch 228/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1741 - sparse_categorical_accuracy: 0.9732
    Epoch 229/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1729 - sparse_categorical_accuracy: 0.9732
    Epoch 230/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1716 - sparse_categorical_accuracy: 0.9821
    Epoch 231/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1707 - sparse_categorical_accuracy: 0.9821
    Epoch 232/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1699 - sparse_categorical_accuracy: 0.9821
    Epoch 233/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1688 - sparse_categorical_accuracy: 0.9821
    Epoch 234/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1680 - sparse_categorical_accuracy: 0.9821
    Epoch 235/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1669 - sparse_categorical_accuracy: 0.9821
    Epoch 236/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1661 - sparse_categorical_accuracy: 0.9732
    Epoch 237/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1652 - sparse_categorical_accuracy: 0.9732
    Epoch 238/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1641 - sparse_categorical_accuracy: 0.9821
    Epoch 239/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1635 - sparse_categorical_accuracy: 0.9821
    Epoch 240/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1627 - sparse_categorical_accuracy: 0.9732
    Epoch 241/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1617 - sparse_categorical_accuracy: 0.9732
    Epoch 242/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1612 - sparse_categorical_accuracy: 0.9821
    Epoch 243/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1601 - sparse_categorical_accuracy: 0.9821
    Epoch 244/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1590 - sparse_categorical_accuracy: 0.9732
    Epoch 245/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1585 - sparse_categorical_accuracy: 0.9732
    Epoch 246/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1573 - sparse_categorical_accuracy: 0.9821
    Epoch 247/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1569 - sparse_categorical_accuracy: 0.9821
    Epoch 248/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1558 - sparse_categorical_accuracy: 0.9732
    Epoch 249/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1552 - sparse_categorical_accuracy: 0.9821
    Epoch 250/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1543 - sparse_categorical_accuracy: 0.9821
    Epoch 251/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1534 - sparse_categorical_accuracy: 0.9821
    Epoch 252/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1527 - sparse_categorical_accuracy: 0.9821
    Epoch 253/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1519 - sparse_categorical_accuracy: 0.9732
    Epoch 254/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1511 - sparse_categorical_accuracy: 0.9821
    Epoch 255/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1502 - sparse_categorical_accuracy: 0.9821
    Epoch 256/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1496 - sparse_categorical_accuracy: 0.9821
    Epoch 257/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1509 - sparse_categorical_accuracy: 0.9732
    Epoch 258/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.1479 - sparse_categorical_accuracy: 0.9732
    Epoch 259/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1471 - sparse_categorical_accuracy: 0.9821
    Epoch 260/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1463 - sparse_categorical_accuracy: 0.9821
    Epoch 261/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1457 - sparse_categorical_accuracy: 0.9821
    Epoch 262/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1450 - sparse_categorical_accuracy: 0.9821
    Epoch 263/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1443 - sparse_categorical_accuracy: 0.9821
    Epoch 264/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1435 - sparse_categorical_accuracy: 0.9821
    Epoch 265/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1429 - sparse_categorical_accuracy: 0.9821
    Epoch 266/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1422 - sparse_categorical_accuracy: 0.9821
    Epoch 267/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1420 - sparse_categorical_accuracy: 0.9732
    Epoch 268/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1409 - sparse_categorical_accuracy: 0.9732
    Epoch 269/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1401 - sparse_categorical_accuracy: 0.9821
    Epoch 270/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1395 - sparse_categorical_accuracy: 0.9821
    Epoch 271/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1390 - sparse_categorical_accuracy: 0.9821
    Epoch 272/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1384 - sparse_categorical_accuracy: 0.9821
    Epoch 273/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1382 - sparse_categorical_accuracy: 0.9821
    Epoch 274/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1368 - sparse_categorical_accuracy: 0.9821
    Epoch 275/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1367 - sparse_categorical_accuracy: 0.9821
    Epoch 276/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1359 - sparse_categorical_accuracy: 0.9821
    Epoch 277/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1349 - sparse_categorical_accuracy: 0.9821
    Epoch 278/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1343 - sparse_categorical_accuracy: 0.9821
    Epoch 279/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.1337 - sparse_categorical_accuracy: 0.9821
    Epoch 280/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1330 - sparse_categorical_accuracy: 0.9821
    Epoch 281/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1324 - sparse_categorical_accuracy: 0.9821
    Epoch 282/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1319 - sparse_categorical_accuracy: 0.9821
    Epoch 283/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1313 - sparse_categorical_accuracy: 0.9821
    Epoch 284/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1307 - sparse_categorical_accuracy: 0.9821
    Epoch 285/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1299 - sparse_categorical_accuracy: 0.9821
    Epoch 286/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1298 - sparse_categorical_accuracy: 0.9821
    Epoch 287/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1290 - sparse_categorical_accuracy: 0.9821
    Epoch 288/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1283 - sparse_categorical_accuracy: 0.9821
    Epoch 289/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1279 - sparse_categorical_accuracy: 0.9821
    Epoch 290/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1279 - sparse_categorical_accuracy: 0.9732
    Epoch 291/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1266 - sparse_categorical_accuracy: 0.9821
    Epoch 292/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1262 - sparse_categorical_accuracy: 0.9821
    Epoch 293/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1256 - sparse_categorical_accuracy: 0.9821
    Epoch 294/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1250 - sparse_categorical_accuracy: 0.9821
    Epoch 295/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1244 - sparse_categorical_accuracy: 0.9821
    Epoch 296/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1238 - sparse_categorical_accuracy: 0.9821
    Epoch 297/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1237 - sparse_categorical_accuracy: 0.9732
    Epoch 298/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1228 - sparse_categorical_accuracy: 0.9821
    Epoch 299/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1224 - sparse_categorical_accuracy: 0.9821
    Epoch 300/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1219 - sparse_categorical_accuracy: 0.9821
    Epoch 301/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1221 - sparse_categorical_accuracy: 0.9821
    Epoch 302/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1208 - sparse_categorical_accuracy: 0.9821
    Epoch 303/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1206 - sparse_categorical_accuracy: 0.9821
    Epoch 304/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1205 - sparse_categorical_accuracy: 0.9821
    Epoch 305/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1195 - sparse_categorical_accuracy: 0.9821
    Epoch 306/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1189 - sparse_categorical_accuracy: 0.9821
    Epoch 307/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1184 - sparse_categorical_accuracy: 0.9821
    Epoch 308/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1177 - sparse_categorical_accuracy: 0.9821
    Epoch 309/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1181 - sparse_categorical_accuracy: 0.9821
    Epoch 310/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1174 - sparse_categorical_accuracy: 0.9821
    Epoch 311/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1168 - sparse_categorical_accuracy: 0.9821
    Epoch 312/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1164 - sparse_categorical_accuracy: 0.9821
    Epoch 313/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1159 - sparse_categorical_accuracy: 0.9821
    Epoch 314/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1150 - sparse_categorical_accuracy: 0.9821
    Epoch 315/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1147 - sparse_categorical_accuracy: 0.9821
    Epoch 316/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1140 - sparse_categorical_accuracy: 0.9821
    Epoch 317/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1141 - sparse_categorical_accuracy: 0.9821
    Epoch 318/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1137 - sparse_categorical_accuracy: 0.9821
    Epoch 319/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1129 - sparse_categorical_accuracy: 0.9821
    Epoch 320/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1124 - sparse_categorical_accuracy: 0.9821
    Epoch 321/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.1121 - sparse_categorical_accuracy: 0.9821
    Epoch 322/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1121 - sparse_categorical_accuracy: 0.9732
    Epoch 323/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1112 - sparse_categorical_accuracy: 0.9732
    Epoch 324/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1108 - sparse_categorical_accuracy: 0.9821
    Epoch 325/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1102 - sparse_categorical_accuracy: 0.9821
    Epoch 326/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1101 - sparse_categorical_accuracy: 0.9821
    Epoch 327/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1098 - sparse_categorical_accuracy: 0.9821
    Epoch 328/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1096 - sparse_categorical_accuracy: 0.9821
    Epoch 329/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1091 - sparse_categorical_accuracy: 0.9821
    Epoch 330/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1082 - sparse_categorical_accuracy: 0.9821
    Epoch 331/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1077 - sparse_categorical_accuracy: 0.9821
    Epoch 332/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1074 - sparse_categorical_accuracy: 0.9821
    Epoch 333/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1072 - sparse_categorical_accuracy: 0.9821
    Epoch 334/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1070 - sparse_categorical_accuracy: 0.9821
    Epoch 335/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1072 - sparse_categorical_accuracy: 0.9821
    Epoch 336/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1057 - sparse_categorical_accuracy: 0.9821
    Epoch 337/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1057 - sparse_categorical_accuracy: 0.9821
    Epoch 338/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1050 - sparse_categorical_accuracy: 0.9821
    Epoch 339/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1048 - sparse_categorical_accuracy: 0.9821
    Epoch 340/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1044 - sparse_categorical_accuracy: 0.9821
    Epoch 341/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1038 - sparse_categorical_accuracy: 0.9821
    Epoch 342/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.1036 - sparse_categorical_accuracy: 0.9821
    Epoch 343/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.1033 - sparse_categorical_accuracy: 0.9821
    Epoch 344/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1033 - sparse_categorical_accuracy: 0.9821
    Epoch 345/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1024 - sparse_categorical_accuracy: 0.9821
    Epoch 346/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1027 - sparse_categorical_accuracy: 0.9821
    Epoch 347/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.1017 - sparse_categorical_accuracy: 0.9821
    Epoch 348/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.1014 - sparse_categorical_accuracy: 0.9821
    Epoch 349/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1016 - sparse_categorical_accuracy: 0.9821
    Epoch 350/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.1007 - sparse_categorical_accuracy: 0.9821
    Epoch 351/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.1010 - sparse_categorical_accuracy: 0.9821
    Epoch 352/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.1001 - sparse_categorical_accuracy: 0.9821
    Epoch 353/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0996 - sparse_categorical_accuracy: 0.9821
    Epoch 354/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0992 - sparse_categorical_accuracy: 0.9821
    Epoch 355/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0991 - sparse_categorical_accuracy: 0.9821
    Epoch 356/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0997 - sparse_categorical_accuracy: 0.9821
    Epoch 357/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0987 - sparse_categorical_accuracy: 0.9821
    Epoch 358/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0989 - sparse_categorical_accuracy: 0.9821
    Epoch 359/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0980 - sparse_categorical_accuracy: 0.9732
    Epoch 360/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0978 - sparse_categorical_accuracy: 0.9821
    Epoch 361/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0972 - sparse_categorical_accuracy: 0.9821
    Epoch 362/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0969 - sparse_categorical_accuracy: 0.9821
    Epoch 363/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0964 - sparse_categorical_accuracy: 0.9821
    Epoch 364/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0960 - sparse_categorical_accuracy: 0.9821
    Epoch 365/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0960 - sparse_categorical_accuracy: 0.9821
    Epoch 366/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0960 - sparse_categorical_accuracy: 0.9821
    Epoch 367/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0951 - sparse_categorical_accuracy: 0.9821
    Epoch 368/500
    7/7 [==============================] - 0s 4ms/step - loss: 0.0954 - sparse_categorical_accuracy: 0.9821
    Epoch 369/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0949 - sparse_categorical_accuracy: 0.9821
    Epoch 370/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0945 - sparse_categorical_accuracy: 0.9821
    Epoch 371/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0941 - sparse_categorical_accuracy: 0.9821
    Epoch 372/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0942 - sparse_categorical_accuracy: 0.9821
    Epoch 373/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0935 - sparse_categorical_accuracy: 0.9821
    Epoch 374/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0931 - sparse_categorical_accuracy: 0.9821
    Epoch 375/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0928 - sparse_categorical_accuracy: 0.9821
    Epoch 376/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0926 - sparse_categorical_accuracy: 0.9821
    Epoch 377/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0929 - sparse_categorical_accuracy: 0.9821
    Epoch 378/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0935 - sparse_categorical_accuracy: 0.9821
    Epoch 379/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0917 - sparse_categorical_accuracy: 0.9821
    Epoch 380/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0921 - sparse_categorical_accuracy: 0.9821
    Epoch 381/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0921 - sparse_categorical_accuracy: 0.9821
    Epoch 382/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0913 - sparse_categorical_accuracy: 0.9821
    Epoch 383/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0908 - sparse_categorical_accuracy: 0.9821
    Epoch 384/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0906 - sparse_categorical_accuracy: 0.9821
    Epoch 385/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0903 - sparse_categorical_accuracy: 0.9821
    Epoch 386/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0901 - sparse_categorical_accuracy: 0.9821
    Epoch 387/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0897 - sparse_categorical_accuracy: 0.9821
    Epoch 388/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0894 - sparse_categorical_accuracy: 0.9821
    Epoch 389/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0893 - sparse_categorical_accuracy: 0.9821
    Epoch 390/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0889 - sparse_categorical_accuracy: 0.9821
    Epoch 391/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0885 - sparse_categorical_accuracy: 0.9821
    Epoch 392/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0884 - sparse_categorical_accuracy: 0.9821
    Epoch 393/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0882 - sparse_categorical_accuracy: 0.9821
    Epoch 394/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0884 - sparse_categorical_accuracy: 0.9821
    Epoch 395/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0877 - sparse_categorical_accuracy: 0.9821
    Epoch 396/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0887 - sparse_categorical_accuracy: 0.9821
    Epoch 397/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0871 - sparse_categorical_accuracy: 0.9821
    Epoch 398/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0874 - sparse_categorical_accuracy: 0.9821
    Epoch 399/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0870 - sparse_categorical_accuracy: 0.9821
    Epoch 400/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0866 - sparse_categorical_accuracy: 0.9821
    Epoch 401/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0865 - sparse_categorical_accuracy: 0.9821
    Epoch 402/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0866 - sparse_categorical_accuracy: 0.9821
    Epoch 403/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0860 - sparse_categorical_accuracy: 0.9821
    Epoch 404/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0854 - sparse_categorical_accuracy: 0.9821
    Epoch 405/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0852 - sparse_categorical_accuracy: 0.9821
    Epoch 406/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0853 - sparse_categorical_accuracy: 0.9821
    Epoch 407/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0849 - sparse_categorical_accuracy: 0.9821
    Epoch 408/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0854 - sparse_categorical_accuracy: 0.9821
    Epoch 409/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0842 - sparse_categorical_accuracy: 0.9821
    Epoch 410/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0842 - sparse_categorical_accuracy: 0.9821
    Epoch 411/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0839 - sparse_categorical_accuracy: 0.9821
    Epoch 412/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0837 - sparse_categorical_accuracy: 0.9821
    Epoch 413/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0834 - sparse_categorical_accuracy: 0.9821
    Epoch 414/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0832 - sparse_categorical_accuracy: 0.9821
    Epoch 415/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0830 - sparse_categorical_accuracy: 0.9821
    Epoch 416/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0830 - sparse_categorical_accuracy: 0.9821
    Epoch 417/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0825 - sparse_categorical_accuracy: 0.9821
    Epoch 418/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0825 - sparse_categorical_accuracy: 0.9821
    Epoch 419/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0841 - sparse_categorical_accuracy: 0.9821
    Epoch 420/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0822 - sparse_categorical_accuracy: 0.9821
    Epoch 421/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0854 - sparse_categorical_accuracy: 0.9821
    Epoch 422/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0819 - sparse_categorical_accuracy: 0.9732
    Epoch 423/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0812 - sparse_categorical_accuracy: 0.9821
    Epoch 424/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0812 - sparse_categorical_accuracy: 0.9821
    Epoch 425/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0810 - sparse_categorical_accuracy: 0.9821
    Epoch 426/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0811 - sparse_categorical_accuracy: 0.9821
    Epoch 427/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0805 - sparse_categorical_accuracy: 0.9821
    Epoch 428/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0804 - sparse_categorical_accuracy: 0.9821
    Epoch 429/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0806 - sparse_categorical_accuracy: 0.9821
    Epoch 430/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0799 - sparse_categorical_accuracy: 0.9821
    Epoch 431/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0798 - sparse_categorical_accuracy: 0.9821
    Epoch 432/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0800 - sparse_categorical_accuracy: 0.9821
    Epoch 433/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0795 - sparse_categorical_accuracy: 0.9821
    Epoch 434/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0791 - sparse_categorical_accuracy: 0.9821
    Epoch 435/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0790 - sparse_categorical_accuracy: 0.9821
    Epoch 436/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0789 - sparse_categorical_accuracy: 0.9821
    Epoch 437/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0788 - sparse_categorical_accuracy: 0.9821
    Epoch 438/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0784 - sparse_categorical_accuracy: 0.9821
    Epoch 439/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0783 - sparse_categorical_accuracy: 0.9821
    Epoch 440/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0780 - sparse_categorical_accuracy: 0.9821
    Epoch 441/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0779 - sparse_categorical_accuracy: 0.9821
    Epoch 442/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0780 - sparse_categorical_accuracy: 0.9821
    Epoch 443/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0774 - sparse_categorical_accuracy: 0.9821
    Epoch 444/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0774 - sparse_categorical_accuracy: 0.9821
    Epoch 445/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0773 - sparse_categorical_accuracy: 0.9821
    Epoch 446/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0770 - sparse_categorical_accuracy: 0.9821
    Epoch 447/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0768 - sparse_categorical_accuracy: 0.9821
    Epoch 448/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0767 - sparse_categorical_accuracy: 0.9821
    Epoch 449/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0764 - sparse_categorical_accuracy: 0.9821
    Epoch 450/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0764 - sparse_categorical_accuracy: 0.9821
    Epoch 451/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0768 - sparse_categorical_accuracy: 0.9821
    Epoch 452/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0762 - sparse_categorical_accuracy: 0.9821
    Epoch 453/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0757 - sparse_categorical_accuracy: 0.9821
    Epoch 454/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0755 - sparse_categorical_accuracy: 0.9821
    Epoch 455/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0757 - sparse_categorical_accuracy: 0.9821
    Epoch 456/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0761 - sparse_categorical_accuracy: 0.9821
    Epoch 457/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0757 - sparse_categorical_accuracy: 0.9821
    Epoch 458/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0750 - sparse_categorical_accuracy: 0.9821
    Epoch 459/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0752 - sparse_categorical_accuracy: 0.9821
    Epoch 460/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0752 - sparse_categorical_accuracy: 0.9821
    Epoch 461/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0751 - sparse_categorical_accuracy: 0.9821
    Epoch 462/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0742 - sparse_categorical_accuracy: 0.9821
    Epoch 463/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0742 - sparse_categorical_accuracy: 0.9821
    Epoch 464/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0743 - sparse_categorical_accuracy: 0.9821
    Epoch 465/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0740 - sparse_categorical_accuracy: 0.9821
    Epoch 466/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0737 - sparse_categorical_accuracy: 0.9821
    Epoch 467/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0735 - sparse_categorical_accuracy: 0.9821
    Epoch 468/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0732 - sparse_categorical_accuracy: 0.9821
    Epoch 469/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0732 - sparse_categorical_accuracy: 0.9821
    Epoch 470/500
    7/7 [==============================] - 0s 3ms/step - loss: 0.0731 - sparse_categorical_accuracy: 0.9821
    Epoch 471/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0730 - sparse_categorical_accuracy: 0.9821
    Epoch 472/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0727 - sparse_categorical_accuracy: 0.9821
    Epoch 473/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0726 - sparse_categorical_accuracy: 0.9821
    Epoch 474/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0729 - sparse_categorical_accuracy: 0.9821
    Epoch 475/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0731 - sparse_categorical_accuracy: 0.9821
    Epoch 476/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0727 - sparse_categorical_accuracy: 0.9821
    Epoch 477/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0721 - sparse_categorical_accuracy: 0.9821
    Epoch 478/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0721 - sparse_categorical_accuracy: 0.9821
    Epoch 479/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0720 - sparse_categorical_accuracy: 0.9821
    Epoch 480/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0716 - sparse_categorical_accuracy: 0.9821
    Epoch 481/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0714 - sparse_categorical_accuracy: 0.9821
    Epoch 482/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0714 - sparse_categorical_accuracy: 0.9821
    Epoch 483/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0712 - sparse_categorical_accuracy: 0.9821
    Epoch 484/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0712 - sparse_categorical_accuracy: 0.9821
    Epoch 485/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0712 - sparse_categorical_accuracy: 0.9821
    Epoch 486/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0708 - sparse_categorical_accuracy: 0.9821
    Epoch 487/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0705 - sparse_categorical_accuracy: 0.9821
    Epoch 488/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0704 - sparse_categorical_accuracy: 0.9821
    Epoch 489/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0704 - sparse_categorical_accuracy: 0.9821
    Epoch 490/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0703 - sparse_categorical_accuracy: 0.9821
    Epoch 491/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0701 - sparse_categorical_accuracy: 0.9821
    Epoch 492/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0703 - sparse_categorical_accuracy: 0.9821
    Epoch 493/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0699 - sparse_categorical_accuracy: 0.9821
    Epoch 494/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0697 - sparse_categorical_accuracy: 0.9821
    Epoch 495/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0700 - sparse_categorical_accuracy: 0.9821
    Epoch 496/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0704 - sparse_categorical_accuracy: 0.9821
    Epoch 497/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0696 - sparse_categorical_accuracy: 0.9821
    Epoch 498/500
    7/7 [==============================] - 0s 2ms/step - loss: 0.0692 - sparse_categorical_accuracy: 0.9821
    Epoch 499/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0689 - sparse_categorical_accuracy: 0.9821
    Epoch 500/500
    7/7 [==============================] - 0s 1ms/step - loss: 0.0690 - sparse_categorical_accuracy: 0.9821

⑤结果评估

1,训练过程可视化

```python
import matplotlib.pyplot as plt
pd.DataFrame(history.history).plot()
plt.show()
```

![png](lesson_files/lesson_24_0.png)

2,整体准确率

```python
test_loss, test_acc = model.evaluate(X_test, y_test, verbose=2)
print(' %.2f%%' %(test_acc*100))
```

    2/2 - 0s - loss: 0.1298 - sparse_categorical_accuracy: 0.9737 - 271ms/epoch - 135ms/step
     97.37%

3,预测样本

```python
predictions = model.predict(X_test, verbose=2)
print(predictions[0])
print(' %d %.2f%%' %(tf.argmax(predictions[0]), max(predictions[0])*100))
```

    2/2 - 0s - 104ms/epoch - 52ms/step
    [8.3498879e-09 1.8262751e-03 9.9817371e-01]
     2 99.82%

```python
print(predictions)
```

    [[8.3498879e-09 1.8262751e-03 9.9817371e-01]
     [3.2518408e-03 9.8306483e-01 1.3683353e-02]
     [9.9939382e-01 6.0616154e-04 4.0472346e-14]
     [5.1105918e-08 1.5814977e-02 9.8418498e-01]
     [9.9613428e-01 3.8657226e-03 1.1263443e-11]
     [5.0845561e-10 4.7897341e-04 9.9952102e-01]
     [9.9715734e-01 2.8426135e-03 4.8997234e-12]
     [7.0876861e-04 9.6024650e-01 3.9044708e-02]
     [4.2222903e-04 9.3484229e-01 6.4735457e-02]
     [4.0413835e-03 9.8746198e-01 8.4966142e-03]
     [1.2660873e-06 4.3164853e-02 9.5683390e-01]
     [1.3402370e-03 9.7123307e-01 2.7426608e-02]
     [8.4431336e-04 9.0923429e-01 8.9921355e-02]
     [4.3927005e-04 9.0233898e-01 9.7221702e-02]
     [4.7115324e-04 8.2901543e-01 1.7051351e-01]
     [9.9828017e-01 1.7199020e-03 1.7988909e-12]
     [5.4972956e-04 8.3909136e-01 1.6035888e-01]
     [8.9530699e-04 8.0865324e-01 1.9045144e-01]
     [9.9046409e-01 9.5359245e-03 1.5190581e-10]
     [9.9846578e-01 1.5342035e-03 4.7513046e-13]
     [5.6102238e-07 1.9395353e-02 9.8060405e-01]
     [5.0135364e-04 7.1416974e-01 2.8532892e-01]
     [9.9001676e-01 9.9832211e-03 2.1078256e-10]
     [9.9051952e-01 9.4804186e-03 3.4175113e-10]
     [2.6071793e-05 2.8323361e-01 7.1674031e-01]
     [9.9886900e-01 1.1309125e-03 1.0174007e-12]
     [9.9197525e-01 8.0247913e-03 6.7378651e-11]
     [2.3211068e-03 9.8043609e-01 1.7242851e-02]
     [1.7626515e-02 9.7543079e-01 6.9427858e-03]
     [9.9145693e-01 8.5430704e-03 8.4697659e-11]
     [2.2322536e-06 7.6802179e-02 9.2319554e-01]
     [3.9311437e-04 5.9891444e-01 4.0069246e-01]
     [9.9688905e-01 3.1109049e-03 4.3471437e-12]
     [2.7264292e-05 2.6483223e-01 7.3514050e-01]
     [8.7741050e-09 2.8957480e-03 9.9710423e-01]
     [2.0027638e-03 8.8426864e-01 1.1372862e-01]
     [9.9712950e-01 2.8704719e-03 1.3951041e-12]
     [7.7986178e-06 1.2152320e-01 8.7846905e-01]]

4,输出混淆矩阵

```python
from sklearn.metrics import confusion_matrix, classification_report
y_true = y_test
y_pred = np.argmax(predictions, axis=1)
print(confusion_matrix(y_true, y_pred))
```

    [[13  0  0]
     [ 0 15  1]
     [ 0  0  9]]

分类报告

```python
print(classification_report(y_true, y_pred))
```

                  precision    recall  f1-score   support
    
               0       1.00      1.00      1.00        13
               1       1.00      0.94      0.97        16
               2       0.90      1.00      0.95         9
    
        accuracy                           0.97        38
       macro avg       0.97      0.98      0.97        38
    weighted avg       0.98      0.97      0.97        38

模型结构

```python
print(model.summary())
```

    Model: "sequential"
    _________________________________________________________________
     Layer (type)                Output Shape              Param #   
    =================================================================
     dense (Dense)               (None, 10)                50        
    
     dense_1 (Dense)             (None, 3)                 33        
    
    =================================================================
    Total params: 83
    Trainable params: 83
    Non-trainable params: 0
    _________________________________________________________________
    None

##### 用tensorflow实现fashion-mnist服饰分类

```python
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import tensorflow as tf
```

①导数据集

```python
(x_train, y_train), (x_test, y_test) = tf.keras.datasets.fashion_mnist.load_data()
```

    Downloading data from https://storage.googleapis.com/tensorflow/tf-keras-datasets/train-labels-idx1-ubyte.gz
    29515/29515 [==============================] - 0s 6us/step
    Downloading data from https://storage.googleapis.com/tensorflow/tf-keras-datasets/train-images-idx3-ubyte.gz
    26421880/26421880 [==============================] - 18s 1us/step
    Downloading data from https://storage.googleapis.com/tensorflow/tf-keras-datasets/t10k-labels-idx1-ubyte.gz
    5148/5148 [==============================] - 0s 0s/step
    Downloading data from https://storage.googleapis.com/tensorflow/tf-keras-datasets/t10k-images-idx3-ubyte.gz
    4422102/4422102 [==============================] - 4s 1us/step

②探索数据

1,基本描述信息

```python
print( "x_train shape:", x_train.shape, "y_train shape:", y_train.shape)
print( "x_test shape:", x_test.shape, "y_test shape:", y_test.shape)
print(y_train[:20]) #前20个label
print(len(x_train)) #训练集样本个数
```

    x_train shape: (60000, 28, 28) y_train shape: (60000,)
    x_test shape: (10000, 28, 28) y_test shape: (10000,)
    [9 0 0 3 0 2 7 2 5 5 0 9 5 5 7 9 1 0 6 4]
    60000

2,显示单张图片

```python
plt.imshow(x_train[0], cmap = 'gray')
plt.colorbar()
plt.grid(False)
plt.show()
```

![png](lesson_files/lesson_44_0.png)

3,显示多张图片

```python
class_names = ['T-shirt', 'Trouser', 'Pullover', 'Dress', 'Coat', 'Sandal', 'Shirt', 'Sneaker', 'Bag', 'Ankle boot']
plt.figure(figsize=(10,10))
for i in range(25):
    plt.subplot(5,5,i+1)
    plt.xticks([])
    plt.yticks([])
    plt.grid(False)
    plt.imshow(x_train[i], cmap=plt.cm.binary)
    plt.xlabel(class_names[y_train[i]])
plt.show()
```

![png](lesson_files/lesson_46_0.png)

4,标准化

```python
x_train = x_train / 255.0
x_test = x_test / 255.0
```

③构建模型

1,定义层

```python
model = tf.keras.models.Sequential([tf.keras.layers.Flatten(input_shape = (28, 28)),
 tf.keras.layers.Dense(128, activation ='relu'),
 tf.keras.layers.Dropout(0.05),
 tf.keras.layers.Dense(10, activation ='softmax')
])
```

2,编译模型

```python
model.compile(optimizer='adam',
 loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=False),
 metrics=['accuracy'])
```

3,查看模型结构

```python
model.summary()
```

    Model: "sequential_1"
    _________________________________________________________________
     Layer (type)                Output Shape              Param #   
    =================================================================
     flatten (Flatten)           (None, 784)               0         
    
     dense_2 (Dense)             (None, 128)               100480    
    
     dropout (Dropout)           (None, 128)               0         
    
     dense_3 (Dense)             (None, 10)                1290      
    
    =================================================================
    Total params: 101,770
    Trainable params: 101,770
    Non-trainable params: 0
    _________________________________________________________________

④训练模型

1,训练集训练,迭代10次

```python
history = model.fit(x_train, y_train, epochs=10)
```

    Epoch 1/10
    1875/1875 [==============================] - 6s 3ms/step - loss: 0.5066 - accuracy: 0.8221
    Epoch 2/10
    1875/1875 [==============================] - 4s 2ms/step - loss: 0.3800 - accuracy: 0.8615
    Epoch 3/10
    1875/1875 [==============================] - 4s 2ms/step - loss: 0.3409 - accuracy: 0.8751
    Epoch 4/10
    1875/1875 [==============================] - 4s 2ms/step - loss: 0.3187 - accuracy: 0.8837
    Epoch 5/10
    1875/1875 [==============================] - 4s 2ms/step - loss: 0.3024 - accuracy: 0.8886
    Epoch 6/10
    1875/1875 [==============================] - 3s 2ms/step - loss: 0.2891 - accuracy: 0.8931
    Epoch 7/10
    1875/1875 [==============================] - 4s 2ms/step - loss: 0.2781 - accuracy: 0.8962
    Epoch 8/10
    1875/1875 [==============================] - 3s 2ms/step - loss: 0.2672 - accuracy: 0.9004
    Epoch 9/10
    1875/1875 [==============================] - 4s 2ms/step - loss: 0.2577 - accuracy: 0.9037
    Epoch 10/10
    1875/1875 [==============================] - 4s 2ms/step - loss: 0.2508 - accuracy: 0.9056

显示每个epoch loss和accuracy的历史值

```python
history.history
```

    {'loss': [0.506623387336731,
      0.37999778985977173,
      0.3408657908439636,
      0.3187374770641327,
      0.3024260997772217,
      0.2890622913837433,
      0.27812787890434265,
      0.26724332571029663,
      0.2576807737350464,
      0.25076183676719666],
     'accuracy': [0.8220666646957397,
      0.8614500164985657,
      0.8751000165939331,
      0.8837000131607056,
      0.888616681098938,
      0.8930500149726868,
      0.8961833119392395,
      0.9004499912261963,
      0.9036833047866821,
      0.9056166410446167]}

图形化训练过程

```python
def plot_learning_curves(history):
    pd.DataFrame(history.history).plot(figsize = (8, 5))
    plt.grid(True)
    plt.gca().set_ylim(0,1)
    plt.show()
plot_learning_curves(history)
```

![png](lesson_files/lesson_62_0.png)

2,用测试集评估准确率

```python
test_loss, test_acc = model.evaluate(x_test, y_test, verbose=2) 
print('\nTest accuracy:', test_acc) 
predictions = model.predict(x_test) 
print(predictions[0]) 
print(' %d , %.2f%%' %(np.argmax(predictions[0]), max((predictions[0]))*100)) 
```

    313/313 - 1s - loss: 0.3281 - accuracy: 0.8826 - 1s/epoch - 4ms/step
    
    Test accuracy: 0.8826000094413757
    313/313 [==============================] - 1s 2ms/step
    [2.8944891e-07 9.0106245e-10 3.1913419e-08 1.7882961e-09 3.8579850e-07
     4.8054244e-02 1.7083392e-08 1.9777216e-01 1.4086240e-06 7.5417143e-01]
     9 , 75.42%

##### 用卷积神经网络实现fashion-mnist服饰分类

```python
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
import tensorflow as tf
from tensorflow import keras
from sklearn.metrics import confusion_matrix, classification_report
import os
```

①读取数据,理解图像

```python
(x_train, y_train), (x_test, y_test) = tf.keras.datasets.fashion_mnist.load_data() 
x_train = x_train.reshape(-1, 28, 28, 1).astype('float32')
x_test = x_test.reshape(-1, 28, 28, 1).astype('float32') 
input_shape = (28, 28, 1)
```

②标准化

```python
x_train = x_train / 255.0
x_test = x_test / 255.0
```

③搭建模型

1,第一个卷积层

```python
model = keras.models.Sequential() 
model.add(keras.layers.Conv2D(filters=128, kernel_size=(3,3), input_shape=input_shape))
model.add(keras.layers.BatchNormalization()) 
model.add(keras.layers.Activation('relu'))
model.add(keras.layers.MaxPool2D(pool_size=(2,2), strides=2))
```

2,第二个卷积层

```python
model.add(keras.layers.Conv2D(filters=64, kernel_size=(3,3)))
model.add(keras.layers.BatchNormalization())
model.add(keras.layers.Activation('relu')) 
model.add(keras.layers.MaxPool2D(pool_size=(2,2), strides=2))
model.add(keras.layers.Dropout(0.2)) 
```

3,全连接层

```python
model.add(keras.layers.Flatten())
model.add(keras.layers.Dense(128, activation = 'relu'))
model.add(keras.layers.Dropout(0.2))
model.add(keras.layers.Dense(64, activation = 'relu')) 
model.add(keras.layers.Dropout(0.2)) #
model.add(keras.layers.Dense(10, activation = 'softmax')) 
```

④编译模型

```python
model.compile(loss = 'sparse_categorical_crossentropy', optimizer = 'adam', metrics =['sparse_categorical_accuracy'])
model.summary()
```

    Model: "sequential_2"
    _________________________________________________________________
     Layer (type)                Output Shape              Param #   
    =================================================================
     conv2d (Conv2D)             (None, 26, 26, 128)       1280      
    
     batch_normalization (BatchN  (None, 26, 26, 128)      512       
     ormalization)                                                   
    
     activation (Activation)     (None, 26, 26, 128)       0         
    
     max_pooling2d (MaxPooling2D  (None, 13, 13, 128)      0         
     )                                                               
    
     conv2d_1 (Conv2D)           (None, 11, 11, 64)        73792     
    
     batch_normalization_1 (Batc  (None, 11, 11, 64)       256       
     hNormalization)                                                 
    
     activation_1 (Activation)   (None, 11, 11, 64)        0         
    
     max_pooling2d_1 (MaxPooling  (None, 5, 5, 64)         0         
     2D)                                                             
    
     dropout_1 (Dropout)         (None, 5, 5, 64)          0         
    
     flatten_1 (Flatten)         (None, 1600)              0         
    
     dense_4 (Dense)             (None, 128)               204928    
    
     dropout_2 (Dropout)         (None, 128)               0         
    
     dense_5 (Dense)             (None, 64)                8256      
    
     dropout_3 (Dropout)         (None, 64)                0         
    
     dense_6 (Dense)             (None, 10)                650       
    
    =================================================================
    Total params: 289,674
    Trainable params: 289,290
    Non-trainable params: 384
    _________________________________________________________________

⑤训练

1,断点续训

```python
checkpoint_save_path = 'checkpoint_CNN/mnist.ckpt'
if os.path.exists(checkpoint_save_path + '.index'):
    print('----------load the model----------')
    model.load_weights(checkpoint_save_path)
cp_callback = tf.keras.callbacks.ModelCheckpoint(filepath=checkpoint_save_path, save_weights_only=True,
save_best_only=True)
```

2,训练

迭代30次,一次需要80s,进40mins

```python
history = model.fit(x_train, y_train, epochs = 30, validation_data = (x_test, y_test),
callbacks=[cp_callback]) 
```

    Epoch 1/30
    1875/1875 [==============================] - 84s 44ms/step - loss: 0.5458 - sparse_categorical_accuracy: 0.8037 - val_loss: 0.4283 - val_sparse_categorical_accuracy: 0.8342
    Epoch 2/30
    1875/1875 [==============================] - 83s 44ms/step - loss: 0.3664 - sparse_categorical_accuracy: 0.8682 - val_loss: 0.3810 - val_sparse_categorical_accuracy: 0.8411
    Epoch 3/30
    1875/1875 [==============================] - 87s 47ms/step - loss: 0.3224 - sparse_categorical_accuracy: 0.8842 - val_loss: 0.2943 - val_sparse_categorical_accuracy: 0.8939
    Epoch 4/30
    1875/1875 [==============================] - 85s 45ms/step - loss: 0.2976 - sparse_categorical_accuracy: 0.8929 - val_loss: 0.3043 - val_sparse_categorical_accuracy: 0.8864
    Epoch 5/30
    1875/1875 [==============================] - 87s 46ms/step - loss: 0.2754 - sparse_categorical_accuracy: 0.8986 - val_loss: 0.2799 - val_sparse_categorical_accuracy: 0.8988
    Epoch 6/30
    1875/1875 [==============================] - 77s 41ms/step - loss: 0.2570 - sparse_categorical_accuracy: 0.9059 - val_loss: 0.2563 - val_sparse_categorical_accuracy: 0.9066
    Epoch 7/30
    1875/1875 [==============================] - 79s 42ms/step - loss: 0.2430 - sparse_categorical_accuracy: 0.9106 - val_loss: 0.2726 - val_sparse_categorical_accuracy: 0.9034
    Epoch 8/30
    1875/1875 [==============================] - 87s 46ms/step - loss: 0.2316 - sparse_categorical_accuracy: 0.9151 - val_loss: 0.2493 - val_sparse_categorical_accuracy: 0.9125
    Epoch 9/30
    1875/1875 [==============================] - 85s 45ms/step - loss: 0.2187 - sparse_categorical_accuracy: 0.9195 - val_loss: 0.2665 - val_sparse_categorical_accuracy: 0.9034
    Epoch 10/30
    1875/1875 [==============================] - 77s 41ms/step - loss: 0.2126 - sparse_categorical_accuracy: 0.9221 - val_loss: 0.2390 - val_sparse_categorical_accuracy: 0.9137
    Epoch 11/30
    1875/1875 [==============================] - 81s 43ms/step - loss: 0.2038 - sparse_categorical_accuracy: 0.9250 - val_loss: 0.2509 - val_sparse_categorical_accuracy: 0.9136
    Epoch 12/30
    1875/1875 [==============================] - 78s 42ms/step - loss: 0.1945 - sparse_categorical_accuracy: 0.9277 - val_loss: 0.2683 - val_sparse_categorical_accuracy: 0.9055
    Epoch 13/30
    1875/1875 [==============================] - 78s 42ms/step - loss: 0.1883 - sparse_categorical_accuracy: 0.9289 - val_loss: 0.2644 - val_sparse_categorical_accuracy: 0.9032
    Epoch 14/30
    1875/1875 [==============================] - 79s 42ms/step - loss: 0.1838 - sparse_categorical_accuracy: 0.9315 - val_loss: 0.2439 - val_sparse_categorical_accuracy: 0.9133
    Epoch 15/30
    1875/1875 [==============================] - 78s 42ms/step - loss: 0.1743 - sparse_categorical_accuracy: 0.9349 - val_loss: 0.2571 - val_sparse_categorical_accuracy: 0.9130
    Epoch 16/30
    1875/1875 [==============================] - 79s 42ms/step - loss: 0.1710 - sparse_categorical_accuracy: 0.9359 - val_loss: 0.2388 - val_sparse_categorical_accuracy: 0.9177
    Epoch 17/30
    1875/1875 [==============================] - 78s 42ms/step - loss: 0.1683 - sparse_categorical_accuracy: 0.9381 - val_loss: 0.2838 - val_sparse_categorical_accuracy: 0.9087
    Epoch 18/30
    1875/1875 [==============================] - 78s 42ms/step - loss: 0.1604 - sparse_categorical_accuracy: 0.9409 - val_loss: 0.2425 - val_sparse_categorical_accuracy: 0.9172
    Epoch 19/30
    1875/1875 [==============================] - 80s 43ms/step - loss: 0.1576 - sparse_categorical_accuracy: 0.9401 - val_loss: 0.2568 - val_sparse_categorical_accuracy: 0.9161
    Epoch 20/30
    1875/1875 [==============================] - 84s 45ms/step - loss: 0.1572 - sparse_categorical_accuracy: 0.9409 - val_loss: 0.2672 - val_sparse_categorical_accuracy: 0.9076
    Epoch 21/30
    1875/1875 [==============================] - 82s 44ms/step - loss: 0.1506 - sparse_categorical_accuracy: 0.9434 - val_loss: 0.2643 - val_sparse_categorical_accuracy: 0.9124
    Epoch 22/30
    1875/1875 [==============================] - 82s 44ms/step - loss: 0.1496 - sparse_categorical_accuracy: 0.9449 - val_loss: 0.2574 - val_sparse_categorical_accuracy: 0.9160
    Epoch 23/30
    1875/1875 [==============================] - 79s 42ms/step - loss: 0.1448 - sparse_categorical_accuracy: 0.9457 - val_loss: 0.2454 - val_sparse_categorical_accuracy: 0.9162
    Epoch 24/30
    1875/1875 [==============================] - 79s 42ms/step - loss: 0.1396 - sparse_categorical_accuracy: 0.9473 - val_loss: 0.2552 - val_sparse_categorical_accuracy: 0.9171
    Epoch 25/30
    1875/1875 [==============================] - 81s 43ms/step - loss: 0.1417 - sparse_categorical_accuracy: 0.9478 - val_loss: 0.2597 - val_sparse_categorical_accuracy: 0.9180
    Epoch 26/30
    1875/1875 [==============================] - 82s 44ms/step - loss: 0.1379 - sparse_categorical_accuracy: 0.9479 - val_loss: 0.2551 - val_sparse_categorical_accuracy: 0.9192
    Epoch 27/30
    1875/1875 [==============================] - 81s 43ms/step - loss: 0.1347 - sparse_categorical_accuracy: 0.9493 - val_loss: 0.3071 - val_sparse_categorical_accuracy: 0.8981
    Epoch 28/30
    1875/1875 [==============================] - 81s 43ms/step - loss: 0.1282 - sparse_categorical_accuracy: 0.9520 - val_loss: 0.2555 - val_sparse_categorical_accuracy: 0.9149
    Epoch 29/30
    1875/1875 [==============================] - 81s 43ms/step - loss: 0.1286 - sparse_categorical_accuracy: 0.9523 - val_loss: 0.2935 - val_sparse_categorical_accuracy: 0.9121
    Epoch 30/30
    1875/1875 [==============================] - 82s 44ms/step - loss: 0.1264 - sparse_categorical_accuracy: 0.9542 - val_loss: 0.2639 - val_sparse_categorical_accuracy: 0.9153

3,绘制acc和loss曲线

```python
def plot_learning_curves(history):
    pd.DataFrame(history.history).plot(figsize=(8,5))
    plt.grid(True)
    plt.ylim(0, 1)
    plt.show()
plot_learning_curves(history)
```

![png](lesson_files/lesson_87_0.png)

4,保存模型

```python
model.save('fashion_model.h5')
```

⑥评估和预测

1,评估evaluate

```python
test_loss, test_acc = model.evaluate(x_test, y_test, verbose=2)
print('\nTest accuracy:', test_acc)
```

    313/313 - 4s - loss: 0.2639 - sparse_categorical_accuracy: 0.9153 - 4s/epoch - 12ms/step
    
    Test accuracy: 0.9153000116348267

2,预测predict

```python
predictions = model.predict(x_test)
print(predictions[0])
print(' %d , %.2f%%' %(np.argmax(predictions[0]), max((predictions[0]))*100))
```

    313/313 [==============================] - 4s 12ms/step
    [1.9348605e-17 2.0841505e-16 7.7804646e-13 1.9641095e-16 8.0456529e-13
     1.6399678e-08 3.9137113e-13 1.6209668e-06 2.5761291e-14 9.9999833e-01]
     9 , 100.00%

⑦查看模型分类效果

1,绘制混淆矩阵

```python
y_true = y_test
y_pred = np.argmax(predictions, axis=1)
pd.crosstab(y_true, y_pred)
confusion_matrix(y_true, y_pred)
```

    array([[800,   1,  18,  27,   1,   0, 145,   0,   8,   0],
           [  1, 982,   0,  10,   1,   0,   3,   0,   3,   0],
           [ 13,   0, 850,   7,  53,   0,  76,   0,   1,   0],
           [  9,   3,  13, 929,  16,   0,  29,   0,   1,   0],
           [  0,   0,  33,  18, 868,   0,  80,   0,   1,   0],
           [  0,   0,   0,   0,   0, 980,   0,  13,   0,   7],
           [ 57,   2,  44,  27,  44,   0, 819,   0,   7,   0],
           [  0,   0,   0,   0,   0,   6,   0, 981,   0,  13],
           [  1,   0,   2,   3,   0,   1,   5,   1, 987,   0],
           [  0,   0,   0,   0,   0,   5,   0,  38,   0, 957]], dtype=int64)

2,打印分类报告

```python
print(classification_report(y_true, y_pred))
```

                  precision    recall  f1-score   support
    
               0       0.91      0.80      0.85      1000
               1       0.99      0.98      0.99      1000
               2       0.89      0.85      0.87      1000
               3       0.91      0.93      0.92      1000
               4       0.88      0.87      0.88      1000
               5       0.99      0.98      0.98      1000
               6       0.71      0.82      0.76      1000
               7       0.95      0.98      0.97      1000
               8       0.98      0.99      0.98      1000
               9       0.98      0.96      0.97      1000
    
        accuracy                           0.92     10000
       macro avg       0.92      0.92      0.92     10000
    weighted avg       0.92      0.92      0.92     10000
