// global javascript
function sendMsg(request, target, redirect){
    if(redirect == true){
        if(request == recentRequest){			
            return;
        }
		window.location = '#'+request;
		recentRequest = request;
    }
    
    $('#cover').css('display', 'block');
    $(target).css('opacity', '0.5');
    $.ajax({
        type: "POST",
        url: "listener.php",
        data: request,
        success: function(msg){
            $(target).html(msg);
            $('#cover').css('display', 'none');
            $('.order_border').slideDown("fast");
            $('.order_border_abstract').slideDown("fast");
            $(target).css('opacity', '1');
        }
    });	 
}
var recentRequest = '';
