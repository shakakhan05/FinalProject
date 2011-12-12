require 'spec_helper'

describe "product_groups/new.html.erb" do
  before(:each) do
    assign(:product_group, stub_model(ProductGroup,
      :prodgrpid => 1,
      :name => "MyString"
    ).as_new_record)
  end

  it "renders new product_group form" do
    render

    # Run the generator again with the --webrat flag if you want to use webrat matchers
    assert_select "form", :action => product_groups_path, :method => "post" do
      assert_select "input#product_group_prodgrpid", :name => "product_group[prodgrpid]"
      assert_select "input#product_group_name", :name => "product_group[name]"
    end
  end
end
