class UserController < ApplicationController
  def new
    @user = user.new
  end
  
  def create
    @user = student.new(params[:user])
    if @user.save
      redirect_to new_user_path
    end
  end
end
