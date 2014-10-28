<%@ page language="java" contentType = "text/html;charset=utf-8" %>
<html>
<head>
	<title>猜数字游戏</title>
</head>
<body>
	<h1>猜数字游戏</h1>
	<h3>请输入你猜的数字（0-100）</h3>
	<form action="GuessingServletUrl" method=post>
		<input type="text" name="guessNumber">
		<input type="submit" value="猜一猜">
	</form>
</body>
</html>