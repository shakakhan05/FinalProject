class Product < ActiveRecord::Base
  has_many :product_groups
end
