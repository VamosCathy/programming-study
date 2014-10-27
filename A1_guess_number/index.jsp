<%@ page language="java" contentType = "text/html;charset=utf-8" %>
<html>
<head>
	<title>猜数字游戏</title>
</head>
<body>
	<center>
	<br><br>
	<h1>猜数字游戏</h1>
	<hr>
	<form action="result.jsp" method="post">
		<h3>请输入你猜的数字（0~100整数）</h3>
		<input type="text" name="gusnum"><br>
		<input type="submit" value="猜一猜"><br>
	</form>
	</center>
	<% int number = (int)(Math.random()*100 + 1);
	session.setAttribute("count",new Integer(0));//猜测次数
	session.setAttribute("save",new Integer(number));//正确的数
	session.setAttribute("minNumber",new Integer(1));//存储最小值
	session.setAttribute("maxNumber",new Integer(100));//存储最大值
	%>
</body>
</html>