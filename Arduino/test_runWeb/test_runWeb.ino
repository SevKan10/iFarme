#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
const char* ssid = "MINH KHA";
const char* password = "0855508877";

ESP8266WebServer webServer(80);
//-----------------------------------------------Trang chính
const char MainPage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Add vegetable</title>
    <style>
        body {text-align:center;}
        body{
            background-image: url('https://mygarden.vn/wp-content/uploads/2020/09/dat-gi-trong-cay-tot-nhat-1.jpg');
        }
        .send{
            border-radius: 25px;
            background: lightblue;
            padding: 5px;
            width: 90px;
            height: 30px;
        }
        .re{
            border-radius: 25px;
            background: orange;
            padding: 5px;
            width: 90px;
            height: 30px;
        }
        
    </style>
</head>
<body>
    <font style="color: red;">
        <h1>Add vegetables</h1>
    </font>
    <p>
        <!-- Tên cây -->
        <label for="text">Name vegetable: </label>
        <input type="text" name="txtName" id="txtName"  required onfocus="doico1()" onblur="doilai1()">
        <!-- Nhiệt độ -->
        <p>
        <label for="text">Temp: </label>
        <input type="number" name="txtTemp" id="txtTemp" required onfocus="doico2()" onblur="doilai2()">
        </p>
        <!-- Độ ẩm -->
        <p>
            <label for="text">Hum: </label>
            <input type="number" name="txtHum" id="txtHum" required onfocus="doico3()" onblur="doilai3()">
        </p>
        <p>
        <label for="text">Tray planting: </label>
            <select class="form-select" id="tray" name="tray">
                <option value="">Tray</option>
                <option value="1" id="tray1">1</option>
                <option value="2" id="tray2">2</option>
                <option value="3" id="tray3">3</option>
                <option value="4" id="tray4">4</option>
            </select>
        </p>
        <label for="text">Day, month, year planting: </label>
        <!-- day -->
        <select class="form-select" id="day" name="day">
            <option value="">Day</option>
            <option value="01">01</option>
            <option value="02">02</option>
            <option value="03">03</option>
            <option value="04">04</option>
            <option value="05">05</option>
            <option value="06">06</option>
            <option value="07">07</option>
            <option value="08">08</option>
            <option value="09">09</option>
            <option value="10">10</option>
            <option value="11">11</option>
            <option value="12">12</option>
            <option value="13">13</option>
            <option value="14">14</option>
            <option value="15">15</option>
            <option value="16">16</option>
            <option value="17">17</option>
            <option value="18">18</option>
            <option value="19">19</option>
            <option value="20">20</option>
            <option value="21">21</option>
            <option value="22">22</option>
            <option value="23">23</option>
            <option value="24">24</option>
            <option value="25">25</option>
            <option value="26">26</option>
            <option value="27">27</option>
            <option value="28">28</option>
            <option value="29">29</option>
            <option value="30">30</option>
            <option value="31">31</option>
        </select>
        <!-- month -->
        <select class="form-select" id="month" name="month">
            <option value="">Month</option>
            <option value="01"> 1</option>
            <option value="02"> 2</option>
            <option value="03"> 3</option>
            <option value="04"> 4</option>
            <option value="05"> 5</option>
            <option value="06"> 6</option>
            <option value="07"> 7</option>
            <option value="08"> 8</option>
            <option value="09"> 9</option>
            <option value="10"> 10</option>
            <option value="11"> 11</option>
            <option value="12"> 12</option>
        </select>
        <!-- years -->
        <select class="form-select" id="year" name="year">
            <option value="">Year</option>
            <option value="2023">2023</option>
        </select>
    </p>
   
    <p>
        <label for="chAcpt">
            <input type="checkbox" name="chAcpt" id="chAcpt"/> You agree to enter informationn </p> <br>
        </label>
    <button class="send"onclick="checkDangky(),submitValue()">Send data</button>
    <button class="re" type="button" onclick="tai_lai_trang()">Retype</button>


    <div id="ketqua"></div>
    <script>

        function submitValue() {
            var Tray = document.getElementById('tray').value;
            
            if  (Tray==="1"){
                // Get the value entered by the user
                var input = document.getElementById('txtName');
                var value = input.value;
                
                localStorage.setItem('name1', value);
                
                window.location.href = 'testout.html';//liên kết qua trang hiển thị
            }
            else if (Tray==="2"){
                var input = document.getElementById('txtName');
                var value = input.value;
                
                localStorage.setItem('name2', value);
                
                window.location.href = 'testout.html';//liên kết qua trang hiển thị
            }
            else if  (Tray==="3"){
                // Get the value entered by the user
                var input = document.getElementById('txtName');
                var value = input.value;
                
                localStorage.setItem('name3', value);
                
                window.location.href = 'testout.html';//liên kết qua trang hiển thị
            }
            else if (Tray==="4"){
                var input = document.getElementById('txtName');
                var value = input.value;
                
                localStorage.setItem('name4', value);
                
                window.location.href = 'testout.html';//liên kết qua trang hiển thị
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
            
            document.getElementById("ketqua").innerHTML = 'Plant name: ' + name + '<br>Check: ' + accept  + "<br>Temp: " + temp +"<br>Hum: " + hum + "<br>Number Tray: "+ Tray + "<br> Plating date: " + Day +" Month " + Month +" Year "+ Year;


          
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
           //tên cây
           function doico1(){
                document.getElementById('txtName').style.color="black";
                document.getElementById('txtName').style.fontSize="30px";
            }
            function doilai1(){
                document.getElementById('txtName').style.color="red";
                document.getElementById('txtName').style.fontSize="15px";
            }
            //nhiệt
            function doico2(){
                document.getElementById('txtTemp').style.color="black";
                document.getElementById('txtTemp').style.fontSize="30px";
            }
            function doilai2(){
                document.getElementById('txtTemp').style.color="red";
                document.getElementById('txtTemp').style.fontSize="15px";
            }    
            //ẩm
            //
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
    </script>
   
</body>
</html>
)=====";

const char outPage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Progress tracking</title>
    <style>
        body {text-align:center;}
        .circle {
            fill: #456BD9;
            stroke: #0F1C3F;
            stroke-width: 0.1875em;
          }
        body{
            background-image: url('');
        }
        .button1 {  display: inline-block;  border-radius: 4px;  background-color: rgb(243, 243, 66);  border: none;  color: black;  text-align: center;  font-size: 16px;  padding: 20px;  width: 200px;  transition: all 0.5s;  cursor: pointer;  margin: 5px;}
        .button1 span {  cursor: pointer;  display: inline-block;  position: relative;  transition: 0.5s;}
        .button1 span:after {  content: '\00bb';  position: absolute;  opacity: 0;  top: 0;  right: -20px;  transition: 0.5s;}
        .button1:hover span {  padding-right: 25px;}
        .button1:hover span:after {  opacity: 1;  right: 0;}
    </style> 
</head>
<body>
    <font style="color: red;">
        <h1> Plant tracking</h1>
    </font>

    <table border="2" cellpadding="5" cellspacing="0" align="center">
        <h1>
            <tr>
              <th>Number trays</th>
              <th>Name</th>
            </tr>
        </h1>
            <tr>
              <td><button class="button1" style="vertical-align:middle" onclick="window.location.href='dataTray1.html'"><span><b>Tray 1</b></span></button></td>
              <td id="value-output1"></td>
            </tr>
            <tr>
                <td><button class="button1" style="vertical-align:middle" onclick="window.location.href='dataTray2.html'"><span><b>Tray 2</b></span></button></td>
                <td id="value-output2"></td>
            </tr>
            <tr>
                <td><button class="button1" style="vertical-align:middle" onclick="window.location.href='dataTray3.html'"><span><b>Tray 3</b></span></button></td>
                <td id="value-output3"></td>
            </tr>
            <tr>
                <td><button class="button1" style="vertical-align:middle" onclick="window.location.href='dataTray4.html'"><span><b>Tray 4</b></span></button></td>
                <td id="value-output4"></td>
            </tr>
          </table>
    </table>
    <script>
      window.onload = function() {
        // Get the value from localStorage
        var value = localStorage.getItem('name1');
        // Display the value on the page
        var output = document.getElementById('value-output1');
        output.innerText = value;

        var value = localStorage.getItem('name2');
        // Display the value on the page
        var output = document.getElementById('value-output2');
        output.innerText = value;

        // Get the value from localStorage
        var value = localStorage.getItem('name3');
        // Display the value on the page
        var output = document.getElementById('value-output3');
        output.innerText = value;
        
        var value = localStorage.getItem('name4');
        // Display the value on the page
        var output = document.getElementById('value-output4');
        output.innerText = value;
      };
    </script>
</body>
</html>
)=====";

void setup(void) {
  Serial.begin(9600);
  Serial.println();
  Serial.println("Booting programs...");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    WiFi.begin(ssid, password);
    Serial.println("WiFi failed, retrying.");
  }
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
//-----------------------------------
   webServer.on("/", [] {
    String s = MainPage;
    webServer.send(200, "text/html", s);
  });
  webServer.on("/testout.html", []() {
    String s = outPage;
    webServer.send(200, "text/html", s);
  });
  webServer.begin();
  Serial.println("Web Server is started!");
}

void loop(void) {
  webServer.handleClient();
}
