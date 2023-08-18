// đặt tên cây
function submitValue() {
    var Tray = document.getElementById('tray').value;
    
    if  (Tray==="1"){
        var input = document.getElementById('txtName');
        var value = input.value;
        
        localStorage.setItem('name1', value);
        window.location.href = 'flow.html';
    }
    else if (Tray==="2"){
        var input = document.getElementById('txtName');
        var value = input.value;
        
        localStorage.setItem('name2', value);
        window.location.href = 'flow.html';
    }
    else if  (Tray==="3"){
        var input = document.getElementById('txtName');
        var value = input.value;
        
        localStorage.setItem('name3', value);
        window.location.href = 'flow.html';
    }
    else if (Tray==="4"){
        var input = document.getElementById('txtName');
        var value = input.value;
        
        localStorage.setItem('name4', value);
        window.location.href = 'flow.html';
    }
    
}
// in ra thông tin
function checkDangky(){
    var name = document.getElementById("txtName").value;
    var accept = document.getElementById("chAcpt").checked;
    var temp = document.getElementById("txtTemp").value;
    var hum = document.getElementById("txtHum").value;
    var Tray = document.getElementById("tray").value;
    var Day = document.getElementById("day").value;
    var Month = document.getElementById("month").value;
    var Year = document.getElementById("year").value;
    
    document.getElementById("ketqua").innerHTML = 'Entered information is:<br>' +'Plant name: ' + name + '<br>Check: ' + accept  + "<br>Temp: " + temp +"<br>Hum: " + hum + "<br>Number Tray: "+ Tray + "<br> Plating date: " + Day +" Month " + Month +" Year "+ Year;

  //thông báo nhập thiếu
    if (name === "") {
        alert("Please enter the NAME of the plant");
        
    }
    else if (temp ===""){
        alert("Please enter the TEMPERATURE");
    }
    else if (hum ===""){
        alert("Please enter the HUMIDITY");
    }
    else if (Day ===""){
        alert("Please enter the DAY");
    }
    else if (Month ===""){
        alert("Please enter the MONTH");
    }
    else if (Year ===""){
        alert("Please enter the YEAR");
    }
}
   // đổi khung tên cây
   function doico1(){
        document.getElementById('txtName').style.color="black";
        document.getElementById('txtName').style.fontSize="30px";
    }
    function doilai1(){
        document.getElementById('txtName').style.color="red";
        document.getElementById('txtName').style.fontSize="15px";
    }
    //đổi khung nhiệt
    function doico2(){
        document.getElementById('txtTemp').style.color="black";
        document.getElementById('txtTemp').style.fontSize="30px";
    }
    function doilai2(){
        document.getElementById('txtTemp').style.color="red";
        document.getElementById('txtTemp').style.fontSize="15px";
    }    
    //đổi khung độ ẩm
    function doico3(){
        document.getElementById('txtHum').style.color="black";
        document.getElementById('txtHum').style.fontSize="30px";
    }
    function doilai3(){
        document.getElementById('txtHum').style.color="red";
        document.getElementById('txtHum').style.fontSize="15px";
    }   

    function tai_lai_trang(){
    location.reload();
    }