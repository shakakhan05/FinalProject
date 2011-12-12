require 'spec_helper'

describe "offers/edit.html.erb" do
  before(:each) do
    @offer = assign(:offer, stub_model(Offer,
      :prodgrpid => 1,
      :sDate => "MyString",
      :eDate => "MyString",
      :Name => "MyString",
      :Status => "MyString"
    ))
  end

  it "renders the edit offer form" do
    render

    # Run the generator again with the --webrat flag if you want to use webrat matchers
    assert_select "form", :action => offers_path(@offer), :method => "post" do
      assert_select "input#offer_prodgrpid", :name => "offer[prodgrpid]"
      assert_select "input#offer_sDate", :name => "offer[sDate]"
      assert_select "input#offer_eDate", :name => "offer[eDate]"
      assert_select "input#offer_Name", :name => "offer[Name]"
      assert_select "input#offer_Status", :name => "offer[Status]"
    end
  end
end
