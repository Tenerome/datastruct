<%@ page language="java" contentType="text/html;chatset=UTF-8" pageEncoding="UTF-8"%>
<!doctype html>
<html>
<head>
<meta charset="UTF-8">
<link rel="stylesheet" type="text/css" href="./css/main.css">
<title>
查询
</title>
</head>
<body>

<div id="enter">
	<form id='' name='enterstudent' action="find" method="post">
		<div>
			<label>学&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;号:</label>
			<input type="text" id="sno" name="sno">
			<span class="spants"></span>
		</div>
		<div>
			<label>姓&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;名:</label>
			<input type="text" id="sname" name="sname">
			<span class="spants"></span>
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
			<input type="text" id="smajor" name="smajor"/>			    
			<span class="spants"></span>
		</div>
		<div>
			<label>成&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;绩:</label>
			<input type="text" id="sgrade" name="sgrade" maxlength="4">	
			<span class="spants"></span>		
		</div>	
		<div class="addbt" style="border:0;">
			<input type="submit" value="查询" style="width:40px;"/>
			<input type="reset" value="取消" style="width:40px;"/>
		</div>
	</form>
</div>
</body>
</html>
