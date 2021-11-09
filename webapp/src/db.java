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

	public static boolean add(student stu) {//添加
		boolean state = false;
		Connection conn = getConnection();
		if(conn==null) 
			return state;
		PreparedStatement stmt=null;
		String sql = "insert into student(sno,sname,ssex,smajor,sgrade) values(?,?,?,?,?)";
		try {
			stmt = conn.prepareStatement(sql);
			stmt.setInt(1, Integer.parseInt(stu.getSno()));
			stmt.setString(2, stu.getSname());
			stmt.setString(3, stu.getSsex());
			stmt.setString(4, stu.getSmajor());
			stmt.setString(5, stu.getSgrade());
			stmt.executeUpdate();
			state = true;
			stmt.close();
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}			
		return state;
	}
	
	public static boolean update(student stu) {  //更新
		boolean state = false;
		Connection conn = getConnection();
		if(conn==null) 
			return state;
		PreparedStatement stmt=null;
		String sql = "update student set sname=?,ssex=?,smajor=?,sgrade=? where sno=?";
		try {
			stmt = conn.prepareStatement(sql);
			stmt.setString(1, stu.getSname());
			stmt.setString(2, stu.getSsex());
			stmt.setString(3, stu.getSmajor());
			stmt.setString(4, stu.getSgrade());
			stmt.setInt(5, Integer.parseInt(stu.getSno()));
			stmt.executeUpdate();
			state = true;
			stmt.close();
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}			
		return state;
	}
	
	public static boolean delete(String sno) {//删除
		boolean state = false;
		Connection conn = getConnection();
		if(conn==null) 
			return state;
		PreparedStatement stmt=null;
		String sql = "delete from student where sno=?";
		try {
			stmt = conn.prepareStatement(sql);
			stmt.setInt(1, Integer.parseInt(sno));			
			stmt.executeUpdate();
			state = true;
			stmt.close();
			conn.close();
		} catch (SQLException e) {
			e.printStackTrace();
		}
		return state;
	}
	public static String getStuHTML(student stu,int page,int record) {//返回html表格
		String html="";
		List<student> students = getStudents(stu,page,record);
		html+="<div>\n";
		html+="<table align='center' border='2'>\n";
		html+="<tr>";
		html+="<th>学号</th>";
		html+="<th>姓名</th>";
		html+="<th>性别</th>";
		html+="<th>专业</th>";
		html+="<th>年级</th>";
		html+="<th>成绩</th>";
		html+="<th></th>";
		html+="</tr>\n";
		for(int i=0;i<students.size();i++) {
			html+="<tr>";
			html+="<td>"+students.get(i).getSno()+"</td>";
			html+="<td>"+students.get(i).getSname()+"</td>";
			html+="<td>"+students.get(i).getSsex()+"</td>";
			html+="<td>"+students.get(i).getSmajor()+"</td>";
			html+="<td>"+students.get(i).getSgrade()+"</td>";
			html+="<td><a href='main.jsp?operate=upedit.jsp&id="+students.get(i).getSno()+"'>修改</a>&nbsp;&nbsp;<a href='Delete?id="+students.get(i).getSno()+"'>删除</a></td>";
			html+="</tr>\n";
		}
		html+="</table>\n";
		html+="<div>\n";
		//html+="<a href=''>第一页</a>";	
		//html+="<a href=''>上一页</a>";	
		//html+="<a href=''>下一页</a>";	
		//html+="<a href=''>最后一页</a>";	
		html+="</div>\n";
		html+="</div>\n";
		
		return html;
	}
	// for test
	// public static void main(String[] args) {
	// 	db.getConnection();
	// 	//student stud=new student("201215155","库巴","女","食品工程","99");
	// 	db.delete("201215155");
	// 	//System.out.print(db.getStudents().get(1).getSno());//arraylist 的get的方法:E get(int location),返回第location个对象，从0开始

	// }
}