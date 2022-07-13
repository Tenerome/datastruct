
public class test{//一个class类
    public static int add(int x,int y){//add()函数
        return x+y;
    }
    public static void print(int x){//print()函数
        System.out.println(x);//java常用的输出语句
    }
    public static void main(String[] args) {//主函数
        int a=12,b=15;
        int c=add(a,b);//调用add
        print(c);//调用print
    }
}
