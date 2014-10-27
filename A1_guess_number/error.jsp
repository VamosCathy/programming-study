<%@ page language="java" isErrorPage="true" contentType="text/html;charset=utf-8" %>
<html>
<head>
	<title>输入错误！</title>
</head>
<body>
	<div align="center">
		<br><br>
		<h1>O_o</h1>
		<h1>Oops！出错啦！</h1>
		<hr>
		<h3><%=exception.toString()%></h3>
		<br><br>
		<a href="javascript:history.back();">返回</a>
	</div>
</body>
</html>