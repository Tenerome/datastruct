<%@ page import="java.sql.*" language="java" contentType="text/html;chatset=UTF-8" pageEncoding="UTF-8"%>
<html>
 <head> 
 <title>输出学生信息</title>
 </head> 
 <body>
 <%
    
    Class.forName("com.mysql.jdbc.Driver");  
    Connection conn=DriverManager.getConnection("jdbc:mysql://127.0.0.1:3306/test?characterEncoding=UTF-8",
"guest",
"123456");
 Statement stmt = conn.createStatement();
 ResultSet rs =stmt.executeQuery("select * from student");
 out.println("<table width=800 border=1 align='center'>");
 out.println("<tr>");
 out.println("<td>学号</td>");
 out.println("<td>姓名</td>");
 out.println("<td>性别</td>");
 out.println("<td>专业</td>");
 out.println("</tr>");
 while(rs.next()){
 out.println("<tr>");
 out.println("<td>"+rs.getString("sno")+"</td>");
 out.println("<td>"+rs.getString("sname")+"</td>");
 out.println("<td>"+rs.getString("ssex")+"</td>");
 out.println("<td>"+rs.getString("smajor")+"</td>");
 out.println("</tr>");
}
 out.println("</table>");
 rs.close();
 stmt.close();
 conn.close(); 
 %>
 </body>
</html>