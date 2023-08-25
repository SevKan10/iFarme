const firebaseConfig = {
  apiKey: "AIzaSyDNVI6MfggzOLtCoP1uVAvajd9lKtS22LU",
  authDomain: "ifarme-df868.firebaseapp.com",
  databaseURL: "https://ifarme-df868-default-rtdb.asia-southeast1.firebasedatabase.app",
  projectId: "ifarme-df868",
  storageBucket: "ifarme-df868.appspot.com",
  messagingSenderId: "124564135650",
  appId: "1:124564135650:web:e969f361eb2d8611fb48bb",
  measurementId: "G-V3SCKCZMV9"
}

const app = firebase.initializeApp(firebaseConfig);

const value = firebase.database();
const dataValue = value.ref('Data'); // Thay 'test/value' bằng 'Data'

var tempData = 0;
var humData = 0;
var dayData = 0;

// Hàm để cập nhật biểu đồ
function updateChart(temperature, humidity, day) {
    var xValues = ["Temperature", "Humidity", "Day"];
    var barColors = ["orange", "blue", "yellow"];

    // Cập nhật dữ liệu biểu đồ
    new Chart("myChart", {
        type: "bar",
        data: {
            labels: xValues,
            datasets: [{
                backgroundColor: barColors,
                data: [temperature, humidity, day]
            }]
        },
        options: {
            legend: { display: false },
            title: {
                display: true,
                text: "Plant Process Tray 1",
                fontSize: 25
            }
        }
    });
}

dataValue.once('value')
    .then((snapshot) => {
        const data = snapshot.val();
        var dataElement = document.getElementById("temperature");
        dataElement.textContent = data.Temp; // Lấy giá trị nhiệt độ từ 'Temp' trong 'Data'

        var humElement = document.getElementById("humidity");
        humElement.textContent = data.Hum; // Lấy giá trị độ ẩm từ 'Hum' trong 'Data'

        var dayElement = document.getElementById("day");
        dayElement.textContent = data.Day; // Lấy giá trị ngày từ 'Day' trong 'Data'

        tempData = parseFloat(data.Temp);
        humData = parseFloat(data.Hum);
        dayData = parseInt(data.Day);

        if (!isNaN(tempData) && !isNaN(humData) && !isNaN(dayData)) {
            console.log("Temperature data:", tempData);
            console.log("Humidity data:", humData);
            console.log("Day data:", dayData);
        } else {
            console.error("Invalid data");
        }

        updateChart(tempData, humData, dayData); // Cập nhật biểu đồ ban đầu
    })
    .catch((error) => {
        console.error("Error reading data: ", error);
    });

const temperatureRef = firebase.database().ref('Data/Temp'); // Theo dõi nhiệt độ
const humidityRef = firebase.database().ref('Data/Hum'); // Theo dõi độ ẩm
const dayRef = firebase.database().ref('Data/Day'); // Theo dõi ngày

function updateTemperature(temperature) {
    const temperatureElement = document.getElementById("temperature");
    temperatureElement.textContent = temperature;
    updateChart(temperature, humData, dayData); // Cập nhật biểu đồ khi có sự thay đổi nhiệt độ
}

function updateHumidity(humidity) {
    const humidityElement = document.getElementById("humidity");
    humidityElement.textContent = humidity;
    updateChart(tempData, humidity, dayData); // Cập nhật biểu đồ khi có sự thay đổi độ ẩm
}

function updateDay(day) {
    const dayElement = document.getElementById("day");
    dayElement.textContent = day;
    updateChart(tempData, humData, day); // Cập nhật biểu đồ khi có sự thay đổi ngày
}

// Đọc giá trị nhiệt độ, độ ẩm và ngày
temperatureRef.on('value', (snapshot) => {
    const temperature = snapshot.val();
    if (temperature !== null) {
        updateTemperature(temperature);
    } else {
        updateTemperature("No data available");
    }
});

humidityRef.on('value', (snapshot) => {
    const humidity = snapshot.val();
    if (humidity !== null) {
        updateHumidity(humidity);
    } else {
        updateHumidity("No data available");
    }
});

dayRef.on('value', (snapshot) => {
    const day = snapshot.val();
    if (day !== null) {
        updateDay(day);
    } else {
        updateDay("No data available");
    }
});
