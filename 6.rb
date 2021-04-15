#Ruby is like a slightly worse Python
def changeLights(data, part)
    lightArray = Array.new(1000) {Array.new(1000)}
    for la in lightArray
        la.fill(0)
    end
    for d in data
        #puts(d)
        c1 = Array.new(2)
        c2 = Array.new(2)
        c1[0] = d.split(",")[0].split(" ")[-1].to_i
        c1[1] = d.split(",")[1].split(" ")[0].to_i
        c2[0] = d.split(",")[1].split(" ")[-1].to_i
        c2[1] = d.split(",")[2].to_i
    
        action = 2 # 2 is toggle
        if d[0..7] == "turn off"
            action = 0
        elsif d[0..6] == "turn on"
            action = 1
        end
    
        for i in c1[0]..c2[0]
            for j in c1[1]..c2[1]
                if action == 2
                    if part == 1
                        lightArray[i][j] = lightArray[i][j] == 1 ? 0 : 1
                    else
                        lightArray[i][j] += 2
                    end
                elsif action == 1
                    if part == 1
                        lightArray[i][j] = 1
                    else
                        lightArray[i][j] += 1
                    end
                else
                    if part == 1
                        lightArray[i][j] = 0
                    else
                        lightArray[i][j] = [lightArray[i][j]-1, 0].max{ |a,b| a<=>b}
                    end
                end
            end
        end
    
    end
    
    lightsLit = 0
    
    for i in 0..999
        for j in 0..999
            if part == 1
                if lightArray[i][j] == 1
                    lightsLit += 1
                end
            else
                lightsLit += lightArray[i][j]
            end
        end
    end

    return lightsLit
end

data = File.read("data/6.in").split("\n")

puts(changeLights(data,1)) #Part 1 answer
puts(changeLights(data,2)) #Part 2 answer
