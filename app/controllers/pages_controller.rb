class PagesController < ApplicationController
  def home
    @title = "Home" if signed_in?
    @offer = Offer.all if signed_in?
    
  end

  def contact
    @title = "Contact"
  end
  
  def about
    @title = "About"
  end
  
  def help
    @title = "Help"
  end
  
 

end
