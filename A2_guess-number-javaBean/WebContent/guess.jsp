<%@page pageEncoding="UTF-8" contentType="text/html; charset=UTF-8"%>
<%@ page import="ling.lingGuess" %> 
<HTML>
<BODY>
<jsp:useBean id="guess" class="ling.lingGuess" scope="session" >
</jsp:useBean>
<jsp:setProperty  name= "guess"  property="guessNumber" param="guessNumber" />
<BR>
<jsp:getProperty  name= "guess"  property="hint" />
<br>这是第
<jsp:getProperty  name= "guess"  property="numGuess" />
   猜
<BR>我猜的数
<jsp:getProperty  name= "guess"  property="guessNumber" />
<% String str=response.encodeRedirectURL("guess.jsp");
%>
<Form action="<%=str%>" method=post >
<BR>再输入你的猜测 <Input type=text name="guessNumber">
<Input type=submit value="提交">
</FORM>
<% String str1=response.encodeRedirectURL("getNumber.jsp");
%>
<BR><FORM action="<%=str1%>" method="post" name="f">
     <Input type="submit" value="重新开始"> 
     </FORM>
</BODy>
</HTML>