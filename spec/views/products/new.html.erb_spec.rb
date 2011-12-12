require 'spec_helper'

describe "products/new.html.erb" do
  before(:each) do
    assign(:product, stub_model(Product,
      :prodgrpid => 1,
      :name => "MyString",
      :upc => 1
    ).as_new_record)
  end

  it "renders new product form" do
    render

    # Run the generator again with the --webrat flag if you want to use webrat matchers
    assert_select "form", :action => products_path, :method => "post" do
      assert_select "input#product_prodgrpid", :name => "product[prodgrpid]"
      assert_select "input#product_name", :name => "product[name]"
      assert_select "input#product_upc", :name => "product[upc]"
    end
  end
end
