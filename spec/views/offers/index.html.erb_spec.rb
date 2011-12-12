require 'spec_helper'

describe "offers/index.html.erb" do
  before(:each) do
    assign(:offers, [
      stub_model(Offer,
        :prodgrpid => 1,
        :sDate => "S Date",
        :eDate => "E Date",
        :Name => "Name",
        :Status => "Status"
      ),
      stub_model(Offer,
        :prodgrpid => 1,
        :sDate => "S Date",
        :eDate => "E Date",
        :Name => "Name",
        :Status => "Status"
      )
    ])
  end

  it "renders a list of offers" do
    render
    # Run the generator again with the --webrat flag if you want to use webrat matchers
    assert_select "tr>td", :text => 1.to_s, :count => 2
    # Run the generator again with the --webrat flag if you want to use webrat matchers
    assert_select "tr>td", :text => "S Date".to_s, :count => 2
    # Run the generator again with the --webrat flag if you want to use webrat matchers
    assert_select "tr>td", :text => "E Date".to_s, :count => 2
    # Run the generator again with the --webrat flag if you want to use webrat matchers
    assert_select "tr>td", :text => "Name".to_s, :count => 2
    # Run the generator again with the --webrat flag if you want to use webrat matchers
    assert_select "tr>td", :text => "Status".to_s, :count => 2
  end
end
