package entity;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

public class db {
    public static Connection getConnection(String driver, String url, String username, String password) { // 链接数据库方法
        Connection conn = null;
        try {
            Class.forName(driver);
            conn = DriverManager.getConnection(url, username, password);
        } catch (ClassNotFoundException e) {
            System.out.println("数据库驱动加载失败");
            e.printStackTrace();
        } catch (SQLException e) {
            System.out.println("数据库连接失败");
            e.printStackTrace();
        }
        return conn;

    }

    public static Connection getConnection() { // 重载
        String driver = "com.mysql.cj.jdbc.Driver";
        String url = "jdbc:mysql://127.0.0.1:3306/test?characterEncoding=UTF-8&serverTimezone=GMT%2B8";
        String username = "guest";
        String password = "123456";
        Connection conn = null;
        conn = getConnection(driver, url, username, password);
        return conn;
    }

    public static List<Student> getStudents(Student stu,int page,int record){//查询所有学生信息,page,recode存页数和每页记录数
		List<Student> students = new ArrayList<Student>();
		Connection conn = getConnection();
		ResultSet rs = null;
		if(conn==null) 
			return students;
		Statement stmt=null;		
	    String sql = "select * from student";
	    if(!stu.isAllEmpty()) {
	    	sql+=" where ";
	    	if(!stu.getNo().equals(""))
	    		sql+="no like '%"+stu.getNo()+"%' and ";
	    	if(!stu.getName().equals(""))
	    		sql+="name like '%"+stu.getName()+"%' and ";
	    	if(!stu.getSex().equals(""))
	    		sql+="sex like '%"+stu.getSex()+"%' and ";
	    	if(!stu.getBirthday().equals(""))
	    		sql+="birthday like '%"+stu.getBirthday()+"%' and ";
	    	if(!stu.getMajor().equals(""))
	    		sql+="major like '%"+stu.getMajor()+"%' and ";
	    	if(!stu.getGrade().equals(""))
	    		sql+="grade like '%"+stu.getGrade()+"%' and ";
	    	if(!stu.getPhone().equals(""))
	    		sql+="phone like '%"+stu.getPhone()+"%' and ";
	    	if(!stu.getOrigin().equals(""))
	    		sql+="origin like '%"+stu.getOrigin()+"%' and ";
	    	sql = sql.substring(0,sql.length()-5);	    	
	    }
	    sql+=" order by id";
	    if(page>0) {
    		int begin = (page-1)*record;
    		sql+=" limit "+begin+","+record;
    	}

    // for test
    public static void main(String[] args) {
        db.getConnection();
    }
}