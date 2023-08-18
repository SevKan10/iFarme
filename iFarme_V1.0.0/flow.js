window.onload = function() {
    //chậu1
    var value = localStorage.getItem('name1');
    var output = document.getElementById('value-output1');
    output.innerText = value;
    //chậu2
    var value = localStorage.getItem('name2');
    var output = document.getElementById('value-output2');
    output.innerText = value;
    //chậu3
    var value = localStorage.getItem('name3');
    var output = document.getElementById('value-output3');
    output.innerText = value;
    //chậu4
    var value = localStorage.getItem('name4');
    var output = document.getElementById('value-output4');
    output.innerText = value;
  };