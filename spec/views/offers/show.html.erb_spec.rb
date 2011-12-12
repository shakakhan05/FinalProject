require 'spec_helper'

describe "offers/show.html.erb" do
  before(:each) do
    @offer = assign(:offer, stub_model(Offer,
      :prodgrpid => 1,
      :sDate => "S Date",
      :eDate => "E Date",
      :Name => "Name",
      :Status => "Status"
    ))
  end

  it "renders attributes in <p>" do
    render
    # Run the generator again with the --webrat flag if you want to use webrat matchers
    rendered.should match(/1/)
    # Run the generator again with the --webrat flag if you want to use webrat matchers
    rendered.should match(/S Date/)
    # Run the generator again with the --webrat flag if you want to use webrat matchers
    rendered.should match(/E Date/)
    # Run the generator again with the --webrat flag if you want to use webrat matchers
    rendered.should match(/Name/)
    # Run the generator again with the --webrat flag if you want to use webrat matchers
    rendered.should match(/Status/)
  end
end
