<%@ page language="java" contentType = "text/html;charset=utf-8" %>
<html>
<head>
	<title>猜数字游戏</title>
</head>
<body>
	<%
	int max = ((Integer)session.getAttribute("maxNumber")).intValue();
	int min = ((Integer)session.getAttribute("minNumber")).intValue();
	%>
	<center>
	<h1>猜数字游戏</h1>
	<hr>
	<h3>猜的数字比实际的小，再猜猜：</h3>
	<h3>从<%=min%>到<%=max%></h3>
	<form action="result.jsp" method="post">
	<input type="text" name="gusnum"><br>
	<input type="submit" value="猜一猜" name="submit">
	</form>
	</center>
</body>
</html>