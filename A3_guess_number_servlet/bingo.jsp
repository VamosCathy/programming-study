<%@ page language="java" contentType = "text/html;charset=utf-8" %>
<html>
<head>
	<title>猜数字游戏</title>
</head>
<body>
<%
Int guessCount = (Int)session.getAttribute("guessCount");
long startTime = session.getCreationTime();
long endTime = session.getLastAccessedTime();
%>
	<h1>Bingo！猜对啦！</h1>
	<h3>你一共猜了<%=guessCount%>次</h3>
	<h3>用时<%=(endTime - startTime)/1000 %>秒</h3>
</body>
</html>