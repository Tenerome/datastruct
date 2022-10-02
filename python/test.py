import gevent
import time
from gevent import monkey
monkey.patch_all()

def run_time(f):
    def inner():
        start=time.time()
        f()
        end=time.time()
        print('执行时间为%.3f ms'%((end-start)*1000))
    return inner

def f(n):
    for i in range(n):
        print(gevent.getcurrent(),i)
        time.sleep(0.5)#time.sleep()会被自动替换成gevent.sleep()

@run_time
def gevent_test():
    print('1')
    g1=gevent.spawn(f,5)
    print('2')
    g2=gevent.spawn(f,5)
    print('3')
    g3=gevent.spawn(f,5)
    g1.join()
    g2.join()
    g3.join()
if __name__=="__main__":
    gevent_test()