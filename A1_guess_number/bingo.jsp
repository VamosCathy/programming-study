<%@ page language="java" contentType = "text/html;charset=utf-8" %>
<html>
<head>
	<title>猜数字游戏</title>
</head>
<body>
	<%
	int count = ((Integer)session.getAttribute("count")).intValue();
	int num = ((Integer)session.getAttribute("save")).intValue();
	long startTime = session.getCreationTime();
	long endTime = session.getLastAccessedTime();
	%>
	<center>
	<h1><%=num%>！</h1>
	<h1>Bingo！猜对了！</h1>
	<hr>
	<h3>您共猜了<%=count%>次</h3>
	<h3>用时<%=(endTime - startTime)/1000 %>秒</h3>
	</center>
	<% session.invalidate(); %>
</body>
</html>