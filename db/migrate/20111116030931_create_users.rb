class CreateUsers < ActiveRecord::Migration
  def change
    create_table :users do |t|
      t.string :name
      t.string :email

      t.timestamps
    end
    add_column  :users, :encrypted_password, :string
    add_column :users, :salt, :string
  end
end
