// JavaScript Document
var usernamenum = 0,
	passwordnum = 0,
	vercodenum = 0;

function changeSucceedStyle(nameID, spanID) { //成功样式
	spanID.firstChild.nodeValue = "*";
	spanID.style.fontSize = "larger";
	spanID.style.color = "green";
	nameID.style.borderColor = "limegreen";
}

function changeFailedStyle(nameID, spanID) { //失败样式
	spanID.firstChild.nodeValue = "*"; 
	spanID.style.fontSize = "larger";
	spanID.style.color = "red";
	nameID.style.borderColor = "red";
}

function changeFailingStyle(nameID, spanID) { //失败时但是焦点还在该输入框时的样式
	spanID.style.fontSize = "small";
	spanID.style.color = "red";
	nameID.style.borderColor = "red";
}

function getCookie(username) {
	var cookie = unescape(document.cookie); //得到解码后的cookie*/
	var cookieArray = cookie.split(";"); //第一次分组
	for(var i = 0; i < cookieArray.length; i++) { 
		var value = cookieArray[i].split("="); //第二次分组
		if(value[0] == username) { 
			return value[1]; 
		}
	}
}

function vercode() {
	var vercode = document.getElementById("vercode");
	var vercodeSpan = document.getElementById("vercodeSpan");
	vercode.onfocus = function() {//对象获得焦点时发生
		if(vercode.value == "" || vercodeSpan.style.color == "red" || vercodeSpan.style.color == "") { //如果内容为空点击产生验证码
			produceCode(); 
		} else { //对验证码对错进行验证
			if(vercodeSpan.style.color == "red") { //如果验证码不正确
				vercodeSpan.style.color = "red"; 
				vercode.style.borderColor = "red";
			} else { 
				changeSucceedStyle(vercode, vercodeSpan);
			}
		}
	}
	vercode.onkeyup = function() {//键盘按键被松开时发生
		var vercodeSpan = document.getElementById("vercodeSpan");
		if(vercode.value == vercodeSpan.firstChild.nodeValue) { //如果验证码正确
			changeSucceedStyle(vercode, vercodeSpan);
		} else {
			vercodeSpan.style.color = "red"; 
			vercode.style.borderColor = "red";
		}
	}
	vercode.onblur = function() {//对象失去焦点时发生
		if(vercodeSpan.style.color == "green") {
			changeSucceedStyle(vercode, vercodeSpan);
			vercodenum = 1;
		} else {
			changeFailedStyle(vercode, vercodeSpan);
			vercodenum = 0
		}
	}

	function produceCode() { //产生验证码
		var code = ""; //初始化一个字符串型的空验证码
		for(var i = 0; i < 4; i++) {
			var num = Math.floor(Math.random() * 10);
			code += num; //产生一个数字加到验证码上
		}
		vercodeSpan.firstChild.nodeValue = code; //设置span为验证码
	}
}

function username() {
	var username = document.getElementById("username"); 
	var usernameSpan = document.getElementById("usernameSpan"); 
	var usernameCookie;
	var password = document.getElementById("password");
	username.onfocus = function() { //获得焦点时
		usernameCookie = getCookie(username.value+ "username");
		if(!(username.value == usernameCookie)) { //输入不正确
			usernameSpan.firstChild.nodeValue = "账户不存在"; 
			changeFailingStyle(username, usernameSpan);
		} else {
			changeSucceedStyle(username, usernameSpan);
			usernamenum = 1;
		}
	}
	username.onkeyup = function() { //输入内容时
		usernameCookie = getCookie(username.value + "username");
		if(username.value == usernameCookie) { //匹配成功
			changeSucceedStyle(username, usernameSpan); 
		} else { //匹配失败
			usernameSpan.firstChild.nodeValue = "账户不存在"; 
			changeFailingStyle(username, usernameSpan);
		}
	}
	username.onblur = function() { //失去焦点时
		usernameCookie = getCookie(username.value + "username");
		if(username.value == usernameCookie) { //匹配成功
			changeSucceedStyle(username, usernameSpan); 
			usernamenum = 1;
		} else { //匹配失败
			changeFailedStyle(username, usernameSpan); 
			usernamenum = 0;
		}
	}
}

function password() {
	var password = document.getElementById("password");
	var passwordSpan = document.getElementById("passwordSpan"); 
	var username = document.getElementById("username"); 
	var vercode = document.getElementById("vercode");
	
	var usernameCookie;
	var passwordCookie;

	password.onfocus = function() { //获得焦点时
		//再次得到密码和用户名，防止填写完密码后修改用户名导致用户名和密码不一致
		usernameCookie = getCookie(username.value + "username");
		passwordCookie = getCookie(username.value + "password");
		if(!(password.value == passwordCookie) || !(username.value == usernameCookie)) { //输入不正确
			passwordSpan.firstChild.nodeValue = "密码错误"; 
			changeFailingStyle(password, passwordSpan); 
		} else {
			changeSucceedStyle(password, passwordSpan);
		}
	}
	password.onkeyup = function() { //输入内容
		usernameCookie = getCookie(username.value + "username");
		passwordCookie = getCookie(username.value + "password");
		if(password.value == passwordCookie && username.value == usernameCookie) { //如果密码与账户正确
			changeSucceedStyle(password, passwordSpan); 
		} else { //匹配失败
			passwordSpan.firstChild.nodeValue = "密码错误";
			changeFailingStyle(password, passwordSpan);
		}
	}
	password.onblur = function() { //失去焦点时
		usernameCookie = getCookie(username.value + "username");
		passwordCookie = getCookie(username.value + "password");
		if(password.value == passwordCookie && username.value == usernameCookie) { //匹配成功的话
			changeSucceedStyle(password, passwordSpan);
			passwordnum = 1;
		} else { //匹配失败
			changeFailedStyle(password, passwordSpan);
			passwordnum = 0;
		}
	}
}


function user() {/*用户登录按钮*/
	var user = document.getElementById("user");
	var username = document.getElementById("username");
	user.onclick = function() {
		if(usernamenum && passwordnum && vercodenum) {
			document.cookie = "ID=1;"; //代表用户登录
			document.cookie = "login=" + username.value;
			location.href = "index.html";//转页面
		} else {
			alert("请确认填写的信息全部正确！");
			return false;
		}
	}
}


window.onload = function() {
	vercode();
	username();
	password();
	user();
	var Username = document.getElementById("username");
}