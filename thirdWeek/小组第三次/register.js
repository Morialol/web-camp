// JavaScript Document
var usernamenum = 0,
	passwordnum = 0,
	repasswordnum = 0,
	mailboxnum = 0,
	phonenum = 0,
	vercodenum = 0;

window.onload = function() {
	username();
	password();
	repassword();
	mailbox();
	phone();
	vercode();
	submit();
}

function changeSucceedStyle(nameID, spanID) { //输入成功样式
	spanID.firstChild.nodeValue = "*";
	spanID.style.fontSize = "larger";
	spanID.style.color = "green";
	nameID.style.borderColor = "limegreen";
}

function changeFailedStyle(nameID, spanID) { //失败而且焦点不在该输入框时的样式
	spanID.firstChild.nodeValue = "*"; 
	spanID.style.fontSize = "larger";
	spanID.style.color = "red";
	nameID.style.borderColor = "red";
}

function changeFailingStyle(nameID, spanID) { //输入失败时但是焦点还在该输入框时的样式
 	spanID.style.color = "red";
	nameID.style.borderColor = "red";
}

function spanValue(spanID, spanValue) { //匹配失败时，修改提示语
	switch(spanValue) {
		case "usernameSpan":
			spanID.firstChild.nodeValue = "6-16位：英文.数字.下划线";
			break;
		case "passwordSpan":
			spanID.firstChild.nodeValue = "6-16位：非空字符";
			break;
		case "repasswordSpan":
			spanID.firstChild.nodeValue = "请确认密码";
			break;
		case "repasswordSpan1":
			spanID.firstChild.nodeValue = "两次密码不一致";
			break;
		case "mailboxSpan":
			spanID.firstChild.nodeValue = "x(5-18位)@x.com";
			break;
		case "phoneSpan":
			spanID.firstChild.nodeValue = "号码格式不正确";
			break;
		case "usernameAgain":
			spanID.firstChild.nodeValue = "用户名已存在！";
	}
}

function username() {
	var username = document.getElementById("username"); 
	var usernameSpan = document.getElementById("usernameSpan"); 
	var pattern = /^[0-9a-zA-Z_]{6,16}$/;//四则表达式
	var userAgain = 0; //1为用户名不存在且输入正确
	username.onkeyup = function() {//输入时 
		if(pattern.test(username.value)) { //匹配成功
			changeSucceedStyle(username, usernameSpan); 
			if(!checkUsername(username.value + "username")) {//如果用户名存在
				spanValue(usernameSpan, "usernameAgain"); 
				changeFailingStyle(username, usernameSpan);
				userAgain = 0; 
			} else {
				userAgain = 1; 
			}
		} else { 
			spanValue(usernameSpan, "usernameSpan"); 
			changeFailingStyle(username, usernameSpan);
		}
	}
	username.onblur = function() { //失去焦点时
		if(pattern.test(username.value) && userAgain) { //匹配成功
			changeSucceedStyle(username, usernameSpan); 
			usernamenum = 1;
		} else { //匹配失败
			changeFailedStyle(username, usernameSpan); 
			usernamenum = 0;
		}
	}
	username.onfocus = function() { //获得焦点时
		if(!pattern.test(username.value)) {
			spanValue(usernameSpan, "usernameSpan"); 
			changeFailingStyle(username, usernameSpan); 
		} else {//如果用户名存在
			if(userAgain == 0) {
				spanValue(usernameSpan, "usernameAgain"); 
				changeFailingStyle(username, usernameSpan); 
			}
		}
	}
}

function password() {
	var password = document.getElementById("password"); 
	var passwordSpan = document.getElementById("passwordSpan");
	var pattern = /^\S{6,16}$/;
	var repassword = document.getElementById("repassword");
	password.onfocus = function() { //获得焦点时
		if(!pattern.test(password.value)) {
			spanValue(passwordSpan, "passwordSpan"); 
			changeFailingStyle(password, passwordSpan);
		}
	}
	password.onkeyup = function() { //输入内容时
		if(pattern.test(password.value)) { //匹配成功
			changeSucceedStyle(password, passwordSpan);
			if(repassword.value != "") { //如果此时确认密码不为空，需要重新进行确认
				repassword.onfocus();
			}
		} else { //匹配失败
			spanValue(passwordSpan, "passwordSpan"); 
			changeFailingStyle(password, passwordSpan);
			if(repassword.value != "") {
				repassword.onfocus();
			}
		}
	}

	password.onblur = function() { //失去焦点时
		if(repassword.value == "") {//如果确认密码没填
			if(pattern.test(password.value)) { //匹配成功
				changeSucceedStyle(password, passwordSpan);
				passwordnum = 1;
			} else { //匹配失败
				changeFailedStyle(password, passwordSpan);
				passwordnum = 0;
			}
		} else {//如果确认密码填了
			if(password.value != repassword.value) {
				repassword.onfocus();
				repasswordnum = 0;
			}
		}

	}

}

function repassword() {
	var password = document.getElementById("password");
	var repassword = document.getElementById("repassword"); 
	var repasswordSpan = document.getElementById("repasswordSpan");

	repassword.onfocus = function() {
		if(!(password.value == repassword.value && password.value != "")) { //如果两次密码的值不相等
			spanValue(repasswordSpan, "repasswordSpan"); 
			changeFailingStyle(repassword, repasswordSpan);
		} else { 
			changeSucceedStyle(repassword, repasswordSpan);
		}
	}
	repassword.onkeyup = function() {
		if(password.value == repassword.value && password.value != "") { //如果两次密码的值相等，且密码不为空
			changeSucceedStyle(repassword, repasswordSpan);
		} else {
			spanValue(repasswordSpan, "repasswordSpan1");
			changeFailingStyle(repassword, repasswordSpan);
		}
	}
	repassword.onblur = function() {
		if(password.value == repassword.value && password.value != "") { //如果两次密码的值相等
			changeSucceedStyle(repassword, repasswordSpan);
			repasswordnum = 1;
		} else {
			spanValue(repasswordSpan, "repasswordSpan");
			changeFailedStyle(repassword, repasswordSpan);
			repasswordnum = 0;
		}
	}
}

function mailbox() {
	var mailbox = document.getElementById("mailbox"); 
	var mailboxSpan = document.getElementById("mailboxSpan");
	var pattern = /^[0-9a-zA-Z_]{5,18}@[0-9a-z]+.com$/;
	mailbox.onfocus = function() {
		if(!pattern.test(mailbox.value)) {
			spanValue(mailboxSpan, "mailboxSpan");
			changeFailingStyle(mailbox, mailboxSpan);
		}
	}
	mailbox.onkeyup = function() {
		if(pattern.test(mailbox.value)) {
			changeSucceedStyle(mailbox, mailboxSpan);
		} else {
			spanValue(mailboxSpan, "mailboxSpan");
			changeFailingStyle(mailbox, mailboxSpan);
		}
	}
	mailbox.onblur = function() {
		if(pattern.test(mailbox.value)) {
			changeSucceedStyle(mailbox, mailboxSpan);
			mailboxnum = 1;
		} else {
			changeFailedStyle(mailbox, mailboxSpan);
			mailboxnum = 0;
		}
	}
}

function phone() {
	var phone = document.getElementById("phone");
	var phoneSpan = document.getElementById("phoneSpan");
	var pattern = /^1[3458][0-9]([1-9]{4}|0[1-9]{3}|[1-9]0[1-9]{2}|[1-9][1-9]0[1-9]|[1-9][1-9][1-9]0)\d{4}$/;
	phone.onfocus = function() {
		if(!pattern.test(phone.value)) {
			spanValue(phoneSpan, "phoneSpan");
			changeFailingStyle(phone, phoneSpan);
		}
	}
	phone.onkeyup = function() {
		if(pattern.test(phone.value)) {
			changeSucceedStyle(phone, phoneSpan);
		} else {
			spanValue(phoneSpan, "phoneSpan");
			changeFailingStyle(phone, phoneSpan);
		}
	}
	phone.onblur = function() {
		if(pattern.test(phone.value)) {
			changeSucceedStyle(phone, phoneSpan);
			phonenum = 1;
		} else {
			changeFailedStyle(phone, phoneSpan);
			phonenum = 0;
		}
	}
}

function vercode() {
	var vercode = document.getElementById("vercode");
	var vercodeSpan = document.getElementById("vercodeSpan");
	vercode.onfocus = function() {
		if(vercode.value == "" || vercodeSpan.style.color == "red" || vercodeSpan.style.color == "") { //如果内容为空点击产生验证码
			produceCode(); 
		} else { 
			if(vercodeSpan.style.color == "red") { 
				vercodeSpan.style.color = "red"; 
				vercode.style.borderColor = "red";
			}
		}
	}
	vercode.onkeyup = function() {
		var vercodeSpan = document.getElementById("vercodeSpan");
		if(vercode.value == vercodeSpan.firstChild.nodeValue) {
			changeSucceedStyle(vercode, vercodeSpan);
		} else {
			vercodeSpan.style.color = "red";
			vercode.style.borderColor = "red";
		}
	}
	vercode.onblur = function() {
		if(vercodeSpan.style.color == "green") {
			changeSucceedStyle(vercode, vercodeSpan);
			vercodenum = 1;
		} else {
			changeFailedStyle(vercode, vercodeSpan);
			vercodenum = 0
		}
	}

	function produceCode() { //产生验证码
		var code = ""; 
		for(var i = 0; i < 4; i++) { 
			var num = Math.floor(Math.random() * 10);
			code += num; //产生一个数字加到验证码上
		}
		vercodeSpan.firstChild.nodeValue = code; 
	}
}

function checkUsername(userName) {
	var cookie = unescape(document.cookie); 
	var cookieArray = cookie.split(";"); //以；分组得到一个数组
	for(var i = 0; i < cookieArray.length; i++) { 
		var value = cookieArray[i].split("=")[0]; //再次以=分组直接
		if(userName == value) { //如果此时的值与用户输入的值相同返回0
			return 0; //如果有存在的直接返回0 
		}
	}
	return 1; //如果不存在的话返回1
}

function submit() { //对提交按钮进行设置
	var submit = document.getElementById("submit");
	var username = document.getElementById("username");
	var password = document.getElementById("password");
	var repassword = document.getElementById("repassword");
	var mailbox = document.getElementById("mailbox");
	var phone = document.getElementById("phone");
	var vercode = document.getElementById("vercode");
	submit.onclick = function() {
		if(usernamenum && passwordnum && repasswordnum && mailboxnum && phonenum && vercodenum) { //如果各项内容都填写正确，写入cookie
			var date = new Date(); //新建一个时间类
			date.setDate(date.getDate() + 30); //设置时间 为 当前日期加上30天
			document.cookie =username.value + "username" + "=" + username.value + ";" + username.value + "password" + "=" + password.value + ";" + username.value + "mailbox" + "=" + mailbox.value + ";" + username.value + "phone" + "=" + phone.value+ ";expires=" + date.toGMTString();
			alert("注册完成！(•‾̑⌣‾̑•)✧˖°");
			location.href = "index.html";
			return false;//取消浏览器默认刷新行为
		} else { //否则对填写错误的那项进行聚焦，来提示错误
			if(!usernamenum) {
				username.onfocus();
			}
			if(!passwordnum) {
				password.onfocus();
			}
			if(!repasswordnum) {
				repassword.onfocus();
			}
			if(!mailboxnum) {
				mailbox.onfocus();
			}
			if(!phonenum) {
				phone.onfocus();
			}
			if(!vercodenum) {
				vercode.onfocus();
			}
			alert("请确认信息填写正确！( °◇ °)");
			return false;
		}
	}
}