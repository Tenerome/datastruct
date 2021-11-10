<%@ page contentType="text/html; charset=UTF-8" %>
<%@ page import="servlets.major" %>
<% major major=new major(); %>
<div id="enter">
	<form id='' name='enterstudent' action="add" method="post">
		<div>
			<label>学&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;号:</label>
			<input type="text" id="sno" name="sno">
			<span class="spants">请输入学生学号</span>
		</div>
		<div>
			<label>姓&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;名:</label>
			<input type="text" id="sname" name="sname">
			<span class="spants">请输入学生姓名</span>
		</div>
		<div>
			<label>性&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;别:</label>
			男<input type="radio" id="ssex" name="ssex" value="男"
				style="width:15px;vertical-align:-3px;margin-right:30px;">
			女<input type="radio" id="ssex" name="ssex" value="女"
				style="width:15px;vertical-align:-3px;">
		</div>
		<div>
			<label>专&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;业:</label>
			<select id="smajor" name="smajor">
			     <option value="-1">--请选择专业--</option>
			     <%=major.getMajorforSelect()%>
			    		      
			</select>			
			<span class="spants">请选择学生所学专业</span>
		</div>
		<div>
			<label>成&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;绩:</label>
			<input type="text" id="sgrade" name="sgrade" maxlength="4">	
			<span class="spants">请输入学生年级</span>		
		</div>		
		<div class="addbt" style="border:0;">
			<input type="submit" value="添加&raquo" style="width:65px;"/>
			<input type="reset" value="取消" style="width:65px;"/>
		</div>
	</form>
</div>
