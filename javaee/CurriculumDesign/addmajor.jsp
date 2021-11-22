<%@ page contentType="text/html; charset=UTF-8" %>
<meta charset="UTF-8">
<link rel="stylesheet" type="text/css" href="./css/main.css">
<script src="./js/content.js"></script>
<script src="./js/particles.js" ></script>
<title>
专业维护
</title>
<div id="particles-js">
<canvas class="particles-js-canvas-el"></canvas>
<div class="frame">
	<br><br>
	<br><br>
<div id="enter">
	<form  name='entermajor' action="addmajor" method="post">
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
			<input type="submit" value="添加" />
			<input type="reset" value="取消" />
		</div>
	</form>
</div>
</div>
</div> 