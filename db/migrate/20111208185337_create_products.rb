class CreateProducts < ActiveRecord::Migration
  def change
    create_table :products do |t|
      t.integer :prodgrpid
      t.string :name
      t.integer :upc

      t.timestamps
    end
  end
end
