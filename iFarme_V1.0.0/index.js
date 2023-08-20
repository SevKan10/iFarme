function login() {
    var name = prompt("ADMIN:");
    var pass = prompt("Password:");
      //-----------------đổi tên và mật khẩu
      var user ="khang"; 
      var pin ="1234";
      //-----------------------------------  
    if (name === user && pass === pin) {
      showMainContent(); 
    } else {
      alert("Wrong");
      window.location.href = "";
    }
  }
  function showMainContent() {
    var mainContent = document.getElementById("main-content");
  }

  login();