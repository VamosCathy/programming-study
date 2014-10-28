<%@ page language="java" contentType = "text/html;charset=utf-8" %>
<html>
<head>
	<title>猜数字游戏</title>
</head>
<body>
<% 
Int maxNumber = (Int)session.getAttribute("maxNumber");
Int minNumber = (Int)session.getAttribute("minNumber");
String hint = (String)session.getAttribute("hint");
%>
	<h1>猜数字游戏</h1>
	<h3><%=hint%></h3>
	<br>请再输入你的猜测 ，从<%=minNumber%>到<%=maxNumber%>
	<form action="GuessingServletUrl" method=post>
		<input type=text name="guessNumber"> 
		<Input type=submit value="猜一猜">
	</form>
</body>
</html>