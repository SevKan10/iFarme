const firebaseConfig = {
  apiKey: "AIzaSyDC5wI0d2s3wyxur0I6N1ZwOMhRb_0L5Vs",
  authDomain: "connect-web-e0c6b.firebaseapp.com",
  databaseURL: "https://connect-web-e0c6b-default-rtdb.asia-southeast1.firebasedatabase.app",
  projectId: "connect-web-e0c6b",
  storageBucket: "connect-web-e0c6b.appspot.com",
  messagingSenderId: "34003392367",
  appId: "1:34003392367:web:f684b1de93c9a17856ba9a"
};

// initialize firebase
firebase.initializeApp(firebaseConfig);

// reference your database
var contactFormDB = firebase.database().ref("connectWeb");

document.getElementById("connectWeb").addEventListener("submit", submitForm);

function submitForm(e) {
  e.preventDefault();

  var name = getElementVal("name");
  var emailid = getElementVal("emailid");
  var msgContent = getElementVal("msgContent");

  saveMessages(name, emailid, msgContent);

  //   enable alert
  document.querySelector(".alert").style.display = "block";

  //   remove the alert
  setTimeout(() => {
    document.querySelector(".alert").style.display = "none";
  }, 3000);

  //   reset the form
  document.getElementById("contactForm").reset();
}

const saveMessages = (name, emailid, msgContent) => {
  var newContactForm = contactFormDB.push();

  newContactForm.set({
    name: name,
    emailid: emailid,
    msgContent: msgContent,
  });
};

const getElementVal = (id) => {
  return document.getElementById(id).value;
};
