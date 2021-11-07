
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

	public static List<student> getStudents(student stu, int page, int record) {// 查询所有学生信息,page,recode存页数和每页记录数
		List<student> students = new ArrayList<student>();
		Connection conn = getConnection();
		ResultSet rs = null;
		if (conn == null)
			return students;
		Statement stmt = null;
		String sql = "select * from student";
		if (!stu.isAllEmpty()) {
			sql += " where ";
			if (!stu.getSno().equals(""))
				sql += "sno like '%" + stu.getSno() + "%' and ";
			if (!stu.getSname().equals(""))
				sql += "sname like '%" + stu.getSname() + "%' and ";
			if (!stu.getSsex().equals(""))
				sql += "ssex like '%" + stu.getSsex() + "%' and ";
			if (!stu.getSmajor().equals(""))
				sql += "smajor like '%" + stu.getSmajor() + "%' and ";
			if (!stu.getSgrade().equals(""))
				sql += "sgrade like '%" + stu.getSgrade() + "%' and ";
			sql = sql.substring(0, sql.length() - 5); // 去掉and
		}
		sql += " order by sno";
		if (page > 0) {
			int begin = (page - 1) * record;
			sql += " limit " + begin + "," + record;// sql分页查询
		}
		try {
			stmt = conn.createStatement();
			rs = stmt.executeQuery(sql);
			while (rs.next()) {
				students.add(new student(rs.getString("sno"), rs.getString("sname"),
						rs.getString("ssex"),rs.getString("smajor"), rs.getString("sgrade")));//arraylist的add(E object),调用student的构造方法
						                                                                      
			}
			rs.close();
			stmt.close();
			conn.close();
		} catch (SQLException e) {
			
			e.printStackTrace();
		}

		return students;
	}

	public static List<student> getStudents(student stu) {//重载，不分页
		return getStudents(stu, 0, 0);
	}
	
	public static List<student> getStudents() {//重载
		return getStudents(new student(), 0, 0);
	}

	// for test
	public static void main(String[] args) {
		db.getConnection();
		student stud=new student("2012151","","","","");
		db.getStudents(stud);
		System.out.print(db.getStudents().get(1).getSno());//arraylist 的get的方法:E get(int location),返回第location个对象，从0开始

	}
}