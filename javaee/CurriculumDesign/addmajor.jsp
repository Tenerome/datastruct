<%@ page contentType="text/html; charset=UTF-8" %>
<meta charset="UTF-8">
<link rel="stylesheet" type="text/css" href="./css/main.css">
<title>
专业维护
</title>
<div class="frame">
	<br><br>
	<br><br>
<div id="enter">
	<form id='' name='entermajor' action="addmajor" method="post">
		<div>
			<label>专&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;业：</label>
			<input type="text" id="mname" name="mname">
			<span class="spants">请输入学生专业</span>
		</div>
		<div>
			<label>学&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;院：</label>
			<input type="text" id="college" name="college">
			<span class="spants">请输入学生所在学院</span>
		</div>
			
		<div class="addbt" style="border:0;">
			<input type="submit" value="添加" style="width:65px;"/>
			<input type="reset" value="取消" style="width:65px;"/>
		</div>
	</form>
</div>
</div>