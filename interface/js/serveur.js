var config = {
    relayURL: "ws://10.0.0.10:1234 ",
    //relayURL: "ws://192.168.0.16:1234 ",
    //relayURL: "ws://localhost:1234",
    remoteHost: "www.google.com",
    remotePort: 80
};

function RelayClient(config, msg, handler) {
    $('#div1').text(config.relayURL);
    var connected = false;
    var connectHandler = handler;
    var socket = new WebSocket(config.relayURL);
    socket.onopen = function () {
        socket.send(JSON.stringify(msg));
    };
    socket.onmessage = function (event) {
        $('#div1').text(event.data);
        if (!connected && event.data == 'connected') {
            $('#div2').text("received connected")
            connected = true;
            connectHandler(socket);
        }
        else if (event.data == "Video started")
        {
            startPlay();
        }
        else if (event.data == "Video ended")
        {
            startNextInPlayList();
        }
        else if (event.data == "Playlist ended")
        {
            alert('endPlay');
            endPlay();
        }
    }
}

function clickFunction(msg, jsonObj)
{
    $('#div3').text(msg)

    var client = new RelayClient(config, jsonObj, function (socket) {
        socket.onmessage = function (event) {
            $('#div3').text(event.data)
        };
    });
}

$(document).ready(function () {
    $("#StartPubPathe").click(function () {
        clickFunction("Send Pathe", {
            mediaName: "Pathe",
            mediaType: "video"
        });
        /* $('#div3').text("Send Pathe")
         var msg = {
         type: "Pathe",
         action: "start"
         };
         
         var client = new RelayClient(config, msg, function (socket) {
         socket.onmessage = function (event) {
         $('#div3').text(event.data)
         };
         });*/
    });

    $("#StartLive").click(function () {
        clickFunction("Send Live", {
            mediaName: "Live",
            mediaType: "video"
        });

    });

    $("#StartPub1").click(function () {
        clickFunction("Send Pub1", {
            mediaName: "Pub1",
            mediaType: "video"
        });

    });

    $("#StartPub2").click(function () {
        clickFunction("Send Pub2", {
            mediaName: "Pub2",
            mediaType: "video"
        });
    });

    $("#StartSoon").click(function () {
        clickFunction("Send StartSoon", {
            mediaName: "StartSoon",
            mediaType: "video"
        });
    });
    $("#BlackScreen").click(function () {
        clickFunction("Send BlackScreen", {
            mediaName: "BlackScreen",
            mediaType: "video"
        });
    });
    $("#ErrDiff").click(function () {
        clickFunction("Send ErrDiff", {
            mediaName: "ErrDiff",
            mediaType: "video"
        });
    });
    $("#mute").click(function () {
        clickFunction("Send mute", {
            mediaName: "mute",
            mediaType: "audio"
        });
    });
    $("#muteLeft").click(function () {
        clickFunction("Send muteLeft", {
            mediaName: "muteLeft",
            mediaType: "audio"
        });
    });
    $("#muteRight").click(function () {
        clickFunction("Send muteRight", {
            mediaName: "muteRight",
            mediaType: "audio"
        });
    });
});