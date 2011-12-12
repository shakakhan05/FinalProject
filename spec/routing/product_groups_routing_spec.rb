require "spec_helper"

describe ProductGroupsController do
  describe "routing" do

    it "routes to #index" do
      get("/product_groups").should route_to("product_groups#index")
    end

    it "routes to #new" do
      get("/product_groups/new").should route_to("product_groups#new")
    end

    it "routes to #show" do
      get("/product_groups/1").should route_to("product_groups#show", :id => "1")
    end

    it "routes to #edit" do
      get("/product_groups/1/edit").should route_to("product_groups#edit", :id => "1")
    end

    it "routes to #create" do
      post("/product_groups").should route_to("product_groups#create")
    end

    it "routes to #update" do
      put("/product_groups/1").should route_to("product_groups#update", :id => "1")
    end

    it "routes to #destroy" do
      delete("/product_groups/1").should route_to("product_groups#destroy", :id => "1")
    end

  end
end
