//测试抛出异常
public class test1 {
        public static void main(String[] args) {
            try{
                throwChecked(-3);
            }catch(Exception e) {
                System.out.println(e.getMessage());
            }
            throwRuntime(3);
        }
        //该方法内抛出一个Exception异常对象，必须捕获或抛给调用者
        public static void throwChecked(int a) throws Exception {
            if(a < 0) {
                throw new Exception("a的值应大于0，不符合要求");
            }
        }
        //该方法内抛出一个RuntimeException对象，可以不理会直接交给JVM处理
        public static void throwRuntime(int a) {
            if(a < 0) {
                throw new RuntimeException("a的值应大于0，不符合要求");
            }
        }
    }
    

