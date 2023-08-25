var tempData = 0;
var humData = 0;
var dayData = 0;

  let myChart = document.getElementById('myChart').getContext('2d');

  Chart.defaults.global.defaultFontFamily = 'Lato';
  Chart.defaults.global.defaultFontSize = 18;
  Chart.defaults.global.defaultFontColor = '#777';

  let massPopChart = new Chart(myChart, {
    type:'bar', // bar, horizontalBar, pie, line, doughnut, radar, polarArea
    data:{
      labels:['Temp', 'Hum', 'Day'],
      datasets:[{
        label:'',
        data:[
        tempData,
        humData,
        dayData,
        ],
        backgroundColor:[
          'rgba(255, 99, 132, 0.6)',
          'rgba(54, 162, 235, 0.6)',
          'rgba(255, 206, 86, 0.6)',
          'rgba(75, 192, 192, 0.6)',
          'rgba(153, 102, 255, 0.6)',
          'rgba(255, 159, 64, 0.6)',
          'rgba(255, 99, 132, 0.6)'
        ],
        borderWidth:1,
        borderColor:'#777',
        hoverBorderWidth:3,
        hoverBorderColor:'#000'
      }]
    },
    options:{
      title:{
        display:true,
        text:'Process plant tray 2',
        fontSize:25
      },
      legend:{
        display:true,
        position:'right',
        labels:{
          fontColor:'#000'
        }
      },
      layout:{
        padding:{
          left:50,
          right:0,
          bottom:0,
          top:0
        }
      },
      tooltips:{
        enabled:true
      }
    }
  });

  // Hàm để cập nhật biểu đồ
  function updateChart() {
    // Cập nhật dữ liệu trong biểu đồ
    massPopChart.data.datasets[0].data = [tempData, humData, dayData];
    massPopChart.update();
  }

  // Đặt dữ liệu mới khi nhận được từ ESP8266
  function receiveDataFromESP(newTemp, newHum, newDay) {
    tempData = newTemp;
    humData = newHum;
    dayData = newDay;
    document.getElementById('temperature') = newTemp;
    document.getElementById('humidity') = newHum;
    document.getElementById('day') = newDay;
    updateChart(); // Cập nhật biểu đồ với dữ liệu mới
  }
