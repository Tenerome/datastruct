<%@ page contentType="text/html; charset=UTF-8" %>

<div id="enter">
	<form id='' name='enterstudent' action="find" method="post">
		<div>
			<label>学&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;号：</label>
			<input type="text" id="no" name="no">
			<span class="spants"></span>
		</div>
		<div>
			<label>姓&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;名：</label>
			<input type="text" id="name" name="name">
			<span class="spants"></span>
		</div>
		<div>
			<label>性&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;别：</label>
			男<input type="radio" id="sex" name="sex" value="男"
				style="width:15px;vertical-align:-3px;margin-right:30px;">
			女<input type="radio" id="sex" name="sex" value="女"
				style="width:15px;vertical-align:-3px;">
		</div>
		<div>
			<label>出生日期：</label>
			<input type="text" id="birthday" name="birthday">
			<span class="spants"></span>
		</div>
		<div>
			<label>专&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;业：</label>
			<input type="text" id="major" name="major"/>			    
			<span class="spants"></span>
		</div>
		<div>
			<label>年&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;级：</label>
			<input type="text" id="grade" name="grade" maxlength="4">	
			<span class="spants"></span>		
		</div>
		<div>
			<label>籍&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;贯：</label>
			<input type="text" id="origin" name="origin" />				
		</div>		
		<div class="addbt" style="border:0;">
			<input type="submit" value="查询" style="width:40px;"/>
			<input type="reset" value="取消" style="width:40px;"/>
		</div>
	</form>
</div>
