module ApplicationHelper
  def title
    base_title = "NEW PAGE"
    if @title.ni?
      base_title
    else
      "#{base_title} |#{@title}"
    end
  end
  
  def logo
    image_tag("logo.png", :alt => "Kays App", :class => "round")
  end
end
