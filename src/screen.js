api.receive('initport', (arg) => {
    document.getElementById('port').value = arg;
})

api.receive('initpassword', (arg) => {
    document.getElementById('password').value = arg;
})
api.receive('log', (arg) => {
    let today = new Date();
    let time = today.getHours() + ":" + String(today.getMinutes()).padStart(2, "0") + ":" + String(today.getSeconds()).padStart(2, "0") + " ";
    document.getElementById('logs').innerHTML = time + arg.concat('\n', document.getElementById('logs').innerHTML)
})

api.receive('version', (arg) => {
    document.getElementById('version').innerHTML = arg;
})

document.getElementById("changePortBtn").addEventListener("click", function () {
    var port = document.getElementById("port").value;
    api.send('changePort', port)
});

document.getElementById("changePasswordBtn").addEventListener("click", function () {
    var password = document.getElementById("password").value;
    api.send('changePassword', password)
});