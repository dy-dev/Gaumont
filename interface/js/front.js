var curMediaName = "Pathe";
var curMediaType = "video";
var elementToPlay = "";
var playListPathe = ['Pathé 1', 'Pathé 2'];
var playListPub1 = ['Oasis', 'MMS'];
var playListPub2 = ['Printemps'];
var curPlaylist = playListPathe;
var currentIndex = 1;

var currentScreen = "proj_ads";

var acc = document.getElementsByClassName("accordion");
var i;

function accordion(num) {
	if (num == 1) {
		$('li.accordion').removeClass('active');
		$('li.subMenu2').css('display', 'none');
		$('li.subPathe').addClass('active');
		$('li.subMenu1').css('display', 'block');
	} else {
		$('li.accordion').removeClass('active');
		$('li.subMenu1').css('display', 'none');
		$('li.subPub').addClass('active');
		$('li.subMenu2').css('display', 'block');
	}
}


// for (i = 0; i < acc.length; i++) {
// 	console.log("test");
//     acc[i].onclick = function(){
//         //Toggle between adding and removing the "active" class,
//         to highlight the button that controls the panel */
//         this.classList.toggle("active");

//         //Toggle between hiding and showing the active panel */
//         // var panel = this.nextElementSibling;
//         var panel = this.children();
//         if (panel.style.display === "block") {
//             panel.style.display = "none";
//         } else {
//             panel.style.display = "block";
//         }
        
//     }
// }


// ordre de visibilité des écrans de projection de 2 à 4
// 		param 1: position live
// 		param 2: position publicité
// 		param 3: position carton
function positionProjection(a, b ,c) {
		$('video#proj_stream').css('z-index', a);
		$('video#proj_ads').css('z-index', b);
		$('#img_proj').css('z-index', c);

}

function selection(value) {
	$('li.selection').removeClass('selection');
	$('ul#wagons li:eq('+value+')').addClass('selection');
}


function startPlay()
{
	document.getElementById(currentScreen).play();
}

function startNextInPlayList(  )
{
	wagon(curPlaylist[currentIndex]);
	curMediaName = "";
	launch( $("#ads").get(0));
}

function endPlay()
{
	document.getElementById("vid_proj").stop();
	currentIndex = 0;
}


// rajouter carton si fin de la pub et du live
function endWagon() {
	// $(document.getElementById("btn_stream")).css("background-color", "DarkGreen");
	// $('#btn_stream').addClass('selected');
	if ($('img.carton').hasClass('selected')) {
		$(document.getElementById("btn_ads")).css("background-color", "DarkRed");
		$('#btn_ads').removeClass('selected');
		positionProjection(3,2,4);
	} else {
		positionProjection(3,4,2);
		var url = "";
		var url = document.getElementById("src_adsproj").src;
		var vid = url.substr(url.lastIndexOf('/') + 1);
		if (vid == "GaumontPathe1.mp4") {
			$('video#proj_ads source').attr('src', 'videos/GaumontPathe2.mp4');
			$('video#proj_ads').load();
			//document.getElementById("proj_ads").play();
			selection(2);
		} else if (vid == "GaumontPathe2.mp4")  {
			$('video#proj_ads source').attr('src', 'videos/PubPrintempsCine.mp4');
			$('video#proj_ads').load();
			//document.getElementById("proj_ads").play();
			selection(3);
		} else if (vid == "PubPrintempsCine.mp4")  {
			$('video#vid_ads source').attr('src', 'videos/PubOasis.mp4');
			$('video#vid_ads').load();
			selection(5);
			$(document.getElementById("btn_ads")).css("background-color", "DarkRed");
			$('#btn_ads').removeClass('selected');
			positionProjection(4, 2, 3);
		} else if (vid == "PubOasis.mp4")  {
			$('video#proj_ads source').attr('src', 'videos/pubmms.mp4');
			$('video#proj_ads').load();
			//document.getElementById("proj_ads").play();
			selection(6);
		} else if (vid == "pubmms.mp4")  {
			$('video#vid_ads source').attr('src', 'videos/GaumontPathe1.mp4');
			$('video#vid_ads').load();
			selection(1);
			$(document.getElementById("btn_ads")).css("background-color", "DarkRed");
			$('#btn_ads').removeClass('selected');
			positionProjection(4, 2, 3);
			// // carton avant reprise
			// $( "img.selected" ).removeClass('selected');
			// $('div#welcome > img').addClass('selected');
			// document.getElementById("img_proj").src = document.getElementById("carton_welcome").src;
			// positionProjection(3,2,4);
			// // sleep
			// console.log("sleep");
			// setTimeout(function(){}, 1000);
		} else {
			$(document.getElementById("btn_ads")).css("background-color", "DarkRed");
			$('#btn_ads').removeClass('selected');
			positionProjection(4, 2, 3);
		}

		// $("video#proj_stream").prop('muted', false);
	}
}

function launchStream() {
	//document.getElementById("proj_stream").load();
	/*if ( $('#btn_stream').hasClass('selected') ) {
		if ($('#btn_ads').hasClass('selected') || $('img.carton').hasClass('selected')) {
			if (!confirmReturnLive()) {
				return;
			} else {
				positionProjection(4, 2, 3);
			}
		}
	} else {*/
		positionProjection(4, 2, 3);
		currentScreen = "proj_stream";
		$('video#proj_stream').load();
		//document.getElementById("proj_stream").play();
	//}
	// } else {
	// 	alert("probleme reception signal live");
	// }
	$(document.getElementById("btn_stream")).css("background-color", "DarkGreen");
	$('#btn_stream').addClass('selected');
	$(document.getElementById("btn_ads")).css("background-color", "DarkRed");
	$('#btn_ads').removeClass('selected');

	$( "img.selected" ).removeClass('selected');
	clickFunction("Send Live", {
		mediaName: "Live",
		mediaType: "video"
	});

}

function launchAds() {
	var input = $('video#vid_ads source').attr('src');

	if (input) {
		// $(document.getElementById("btn_stream")).css("background-color", "DarkRed");
		// $('#btn_stream').removeClass('selected');
		$(document.getElementById("btn_ads")).css("background-color", "DarkGreen");
		$('#btn_ads').addClass('selected');

		$('video#proj_ads source').attr('src', input);

		positionProjection(2,4,3);
		$('video#proj_ads').load();
		currentScreen = "proj_ads";
		//document.getElementById("proj_ads").play();
		clickFunction("Send " + curMediaName, {
                        mediaName: curMediaName,
                        mediaType: curMediaType
                    });

		var url1 = document.getElementById("src_ads").src;
		var vid1 = url1.substr(url1.lastIndexOf('/') + 1);
		if (vid1 == "GaumontPathe1.mp4")
			selection(1);

	} else {
		alert("probleme d'envoie de signal publicitaire");
		// !!! sécuriser avec l'envoie d'un carton automatiquement
		positionProjection(3,2,4);
		document.getElementById("img_proj").src = document.getElementById("carton_error").src;
		$( "img.selected" ).removeClass('selected');
		$('div#error > img').addClass('selected');
	}
	$( "img.selected" ).removeClass('selected');
}


function entract() {
	// $( "img.selected" ).removeClass('selected');
	// $('div#welcome > img').addClass('selected');
	// document.getElementById("img_proj").src = document.getElementById("carton_welcome").src;
	// positionProjection(3,2,4);
	// // sleep
	// console.log("sleep");
	// setTimeout(function(){}, 1000);
	
	// $('video#proj_ads source').attr('src', 'videos/PubOasis.mp4');
	// $('video#proj_ads').load();
	// positionProjection(2,4,3);
	// selection(5);
	// document.getElementById("proj_ads").play();
}

function launch(output){
	$("video#proj_stream").prop('muted', true);
	if (output)
		if (output.getAttribute('id') == "stream") {
			launchStream();
			// window.setTimeout(entract(), 60000);
		}
		else if (output.getAttribute('id') == "ads") {
			launchAds();
		}
		else
			alert("output inconnu");
	else
		alert("error script launch");
}

function carton(e){
	if (e) {
		// gestion de la différence vidéo/carton
		positionProjection(3,2,4);
		// document.getElementById("proj_stream").pause();
		$("video#proj_stream").prop('muted', true);

		if (e.getAttribute('id') == "welcome") {
			if ($('img#carton_welcome').hasClass('selected')) {
				if ($('#btn_ads').hasClass('selected')) {
					positionProjection(2,4,3);
					$( "img.selected" ).removeClass('selected');
				}else {
					positionProjection(4,2,3);
					// $("video#proj_stream").prop('muted', false);
					$( "img.selected" ).removeClass('selected');
				}
			} else {
				$( "img.selected" ).removeClass('selected');
				$('div#welcome > img').addClass('selected');
				document.getElementById("img_proj").src = document.getElementById("carton_welcome").src;
			}
					clickFunction("Send StartSoon", {
				mediaName: "StartSoon",
				mediaType: "video"
			});

		}
		else if (e.getAttribute('id') == "error") {
			if ($('img#carton_error').hasClass('selected')) {
				positionProjection(4,2,3);
				// $("video#proj_stream").prop('muted', false);
				$( "img.selected" ).removeClass('selected');
			} else {
				$( "img.selected" ).removeClass('selected');
				$('div#error > img').addClass('selected');
				document.getElementById("img_proj").src = document.getElementById("carton_error").src;
				// document.getElementById("img_proj").src = document.getElementById("error").img.src;
			}
			clickFunction("Send ErrDiff" , {
			mediaName: "ErrDiff",
			mediaType: "video"
		});
		}
		else {
			alert("carton inconnu");
		}
	}
	else
		alert("error script launch");
}


function playPause(e) {
	// alert("test");
	var myVideo = document.getElementById("vid_stream");

	if (e.getAttribute("id") == "vid_stream") {
		if (myVideo.paused){
			myVideo.play();
		} else {
			myVideo.pause();
		}
	} else if (e.getAttribute("id") == "vid_ads") {
		var myVideo = document.getElementById("vid_ads");
		if (myVideo.paused){
			myVideo.play();
		} else {
			myVideo.pause();
		}
	}
}


function wagon(e) {
	switch(e) {
		case 'Pathé 1':
			$('video#vid_ads source').attr('src', 'videos/GaumontPathe1.mp4');
			$('video#vid_ads').load();
			curMediaName = "Pathe";
			curMediaType="video"
			curPlaylist = playListPathe;
			currentIndex = 1;
			selection(1);
			break;
		case 'Pathé 2':
			$('video#vid_ads source').attr('src', 'videos/GaumontPathe2.mp4');
			$('video#vid_ads').load();
			curPlaylist = playListPathe;
			currentIndex = 2;
			selection(2);
			break;
		case 'Printemps':
			$('video#vid_ads source').attr('src', 'videos/PubPrintempsCine.mp4');
			$('video#vid_ads').load();
			curMediaName = "Pub1";
			curMediaType="video"
			curPlaylist = playListPub1;
			currentIndex = 1;
			selection(3);
			break;
		case 'Oasis':
			$('video#vid_ads source').attr('src', 'videos/PubOasis.mp4');
			$('video#vid_ads').load();
			curPlaylist = playListPub1;
			selection(5);
			break;
		case 'MMS':
			$('video#vid_ads source').attr('src', 'videos/pubmms.mp4');
			$('video#vid_ads').load();
			curMediaName = "Pub2";
			curMediaType="video"
			curPlaylist = playListPub2;
			currentIndex = 1;
			selection(6);
			break;
		default:
			$('video#vid_ads source').attr('src', 'videos/GaumontPathe1.mp4');
			$('video#vid_ads').load();
			selection(1);
	}
}


function confirmReturnLive() {
    return (confirm("Voulez-vous forcer le retour au live"));
}