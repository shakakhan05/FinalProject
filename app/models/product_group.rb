class ProductGroup < ActiveRecord::Base
  belongs_to :offer
  belongs_to :product
end
