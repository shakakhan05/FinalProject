class CreateOffers < ActiveRecord::Migration
  def change
    create_table :offers do |t|
      t.integer :prodgrpid
      t.string :sDate
      t.string :eDate
      t.string :Name
      t.string :Status
      t.string :discounttype
      t.integer :discountAmt

      t.timestamps
    end
  end
end
