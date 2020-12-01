def solution(bridge_length, weight, truck_weights)
    lap_time  = 0
    
    wait_truck = []
    landing_truck = []
    past_truck = []	
	  
    truck_weights.each do |a|
      lHash = {}
      lHash[:truck_weights] = a       
      wait_truck << lHash 
      
    end    

	while wait_truck != [] || landing_truck != []    

	  lap_time+=1
	  
      if landing_truck != []
      
        if landing_truck[0][:Entry_time] +  bridge_length == lap_time 
          past_truck << landing_truck[0]
          landing_truck.delete_at(0)          
        end
      
      end
	  
	  landing_trucks_weight = 0
      landing_truck.each do |a|       
	    landing_trucks_weight = landing_trucks_weight + a[:truck_weights]	  
	  end
      
      if wait_truck != []
        trucks_weight_sum = wait_truck[0][:truck_weights] + landing_trucks_weight
        
        if trucks_weight_sum <= weight
          wait_truck[0][:Entry_time] = lap_time
          landing_truck << wait_truck[0] 
          wait_truck.delete_at(0)      
        end
      end


	end

	return lap_time  


end