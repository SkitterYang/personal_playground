var testapp;
var testapp2;

window.onload = function () {
    testapp = new Vue({
        el: '#app',
        data: {
            message: new Date().toLocaleString()
        }
    });
    setInterval(function(){
        testapp.message = new Date().toLocaleString();
    }, 500);
    testapp2 = new Vue({
        el: '#app2',
        data: {
            message: new Date().toLocaleString()
        }
    });
    setInterval(function(){
        testapp2.message = new Date().toLocaleString();
    }, 500);
}

window.addEventListener('click', get_current_time);
window.addEventListener('click', function(){
    testapp2.message = '当前时间： ' + new Date().toLocaleString();
});

function get_current_time() {
    testapp.message = '当前时间： ' + new Date().toLocaleString();
}
