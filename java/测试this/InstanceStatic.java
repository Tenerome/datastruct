public class InstanceStatic {

    int x = 3;// 类的实例变量，初始化值为3
    static int y = 4;// 类的静态变量，初始化值为4

    public static void staticmethod()// 静态方法
    {
        //System.out.println(x);  X  静态方法不能直接调用实例成员
        System.out.println("实例变量x = " + new InstanceStatic().x);// 在静态方法中访问类的实例变量需首先进行类的实例化
        System.out.println("静态变量y = " + y);// 在静态方法中可直接访问类的静态变量
        staticmethod1();//静态方法可以调用其他静态方法
        // instancemethod();  X 静态方法不能访问实例方法
        new InstanceStatic().instancemathod1();
    }

    public static void  staticmethod1(){  //静态方法2
        System.out.println("另一个静态方法");
    }
    public void instancemathod(){
        System.out.println(x);//实力访问可以直接访问实例变量，类变量，实例方法，类方法
        System.out.println(y);
        staticmethod1();
        instancemathod1();
    }
    public void instancemathod1(){
        System.out.println("另一个实例方法");
    }
    public static void main(String[] args) {
        System.out.println("====类方法====");
        InstanceStatic.staticmethod();
        System.out.println("====实例方法===");
        InstanceStatic cc=new InstanceStatic();
        cc.instancemathod();
    }
}
