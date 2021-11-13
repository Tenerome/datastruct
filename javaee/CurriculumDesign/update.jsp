<%@ page contentType="text/html; charset=UTF-8" %>
<%@ page import="entity.student" %>
<%@ page import="entity.db" %>
<%
String id=request.getParameter("id")==null?"":request.getParameter("id");
student stu = db.getStudentByID(id);
%>
<meta charset="UTF-8">
<link rel="stylesheet" type="text/css" href="./css/main.css">
<title>
修改
</title>
<div class="frame">
	<br><br>
	<br><br>
<div id="enter">
	<form id='' name='enterstudent' action="update" method="post">
	        <input type="hidden" name="id" value=<%=stu.getId() %>>
		<div>
			<label>学&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;号:</label>
			<input type="text" id="sno" name="sno" value=<%=stu.getSno() %>>
			<span class="spants">请输入学生学号</span>
		</div>
		<div>
			<label>姓&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;名:</label>
			<input type="text" id="sname" name="sname" value=<%=stu.getSname() %>>
			<span class="spants">请输入学生姓名</span>
		</div>
		<div>
			<label>性&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;别:</label>
			男<input type="radio" id="ssex" name="ssex" value="男" <%=stu.getSsex().equals("男")?"checked":"" %>
				style="width:15px;vertical-align:-3px;margin-right:30px;">
			女<input type="radio" id="ssex" name="ssex" value="女" <%=stu.getSsex().equals("女")?"checked":"" %>
				style="width:15px;vertical-align:-3px;">
		</div>
		<div>
			<label>专&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;业:</label>
			<input type="text" id="smajor" name="smajor" value=<%=stu.getSmajor() %>>			    
			<span class="spants">请输入学生所学专业</span>
		</div>
		<div>
			<label>成&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;绩:</label>
			<input type="text" id="sgrade" name="sgrade" maxlength="4" value=<%=stu.getSgrade() %>>	
			<span class="spants">请输入学生年级</span>		
		</div>	
		<div class="addbt" style="border:0;">
			<input type="submit" value="修改" style="width:65px;"/>
			<input type="reset" value="取消" style="width:65px;"/>
		</div>
		
	</form>
</div>
</div>