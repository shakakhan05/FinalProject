function load() {
	setInterval(RDirect, 1000);
    $('#search_field').focus();
	
	$("#search_submit").click(function () {
		call_search(0, null);
	});
	$("#search_field").keyup(function(event){
  		if(event.keyCode == 13){
			call_search(0, null);
		}
	});

    $(".button").mouseover(function () {
        $(this).css("box-shadow", "inset 0 0 10px rgba(255, 255, 255, 0.9)");
    });
    $(".button").mouseleave(function () {
        $(this).css("box-shadow", "0 0 3px #000");
    });	
    $(".button").mousedown(function () {
        $(this).removeClass("button");
        $(this).addClass("button_on");
    });
    $(".button").mouseup(function () {
        $(this).removeClass("button_on");
        $(this).addClass("button");
    });	
			
    $("#menu_ul li").mouseover(function () {
        $(this).css("box-shadow", "inset 0 0 5px #004891");
    });
    $("#menu_ul li").mouseleave(function () {
        $(this).css("box-shadow", "none");
    });
	
    $(".histry_a").click(function () {
        sendHistryMsg($(this).attr('link').replace("#", ""), $('#right_container'));
    });
    $(".stats_a").click(function () {
        sendStatsMsg($(this).attr('link').replace("#", ""), $('#right_container'));
    });	
    RDirect();	
}

function RDirect() {
    _GET = new Array();
    url = window.location.toString();
    url = url.split('#');
    if (typeof (url[1]) == 'string') {
        eval('_GET["url"]="' + url[1] + '"');
    }
    if (_GET['url'] != null && _GET['url'] != '' )
    {
        sendMsg(decodeURI(_GET['url']),$("#right_container"), true);
    }
	else if(_GET['url'] == null){
		sendMsg("action=stats&date_type=all&filter=0",$("#right_container"), true);
	}
}

function call_search(filter, request){
	str = '';
	if(filter){
		str = $('#search_keywords').val();
	}
	else{
		str = $("#search_field").val();
	}
    if(jQuery.trim(str) == ''){
        $('#search_submit').focus();
        alert("What are you searching? Type something!");
    }
    else if(jQuery.trim(str).length < 3){
        alert("keyword is too short");		
    }
    else{
		$('#search_field').val(str);		
		sendSearchMsg("action=search&keywords="+str+"&apply_filter=" + filter + "&" + request, $("#right_container"));
    }
}

function sendUPCMsg( upc, start_date, end_date ){
	if(start_date && end_date){
    	sendHistryMsg("upc="+upc+"&action=histry&type=user&start_date="+start_date+"&end_date="+end_date, $("#right_container"));
	}
	else{
		sendHistryMsg("upc="+upc+"&action=histry&type=user", $("#right_container"));
	}
}

function sendHistryMsg( request, target){
    sendMsg(request+"&detail="+show_histry_detail+"&row="+histry_rows+"&filter="+show_histry_filter, target, true);
}

function sendSearchMsg( request, target){
    sendMsg(request+"&row="+search_rows+"&filter="+show_search_filter, target, true);
}

function sendStatsMsg( request, target){
    sendMsg(request+'&filter='+show_stats_filter, target, true);
}

function sendChartMsg( request){
    if(request.substr(request.length-6)=='OTHERS'){
        return;
    }
    req = request;
    action = req.split('#');
    request = "action=stats&source="+action[0]+"&"+action[1];
    if(action[0]=='line'){
        sendMsg(request, $("#right_container"), true);
    }
    else{
        sendMsg(request, $("#spending_hidden"), false);
    }
}

var search_rows = 8;
var histry_rows = 16;
var show_histry_detail = 0;
var show_histry_filter = 0;
var show_search_filter = 0;
var show_stats_filter = 0;
var default_left_pie = 0;
var default_right_pie = 0;

