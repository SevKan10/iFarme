const firebaseConfig = {
  apiKey: "AIzaSyDcwnDwysnt_iRw06jdzjC2DiEnGNF504M",
  authDomain: "demoweb-174ea.firebaseapp.com",
  databaseURL: "https://demoweb-174ea-default-rtdb.asia-southeast1.firebasedatabase.app",
  projectId: "demoweb-174ea",
  storageBucket: "demoweb-174ea.appspot.com",
  messagingSenderId: "449858198762",
  appId: "1:449858198762:web:bceb9cebe9862cc612cb93"
};

// initialize firebase
firebase.initializeApp(firebaseConfig);

// reference your database
var contactFormDB = firebase.database().ref("contactForm");

document.getElementById("contactForm").addEventListener("submit", submitForm);

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