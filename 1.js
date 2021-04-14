const fs = require('fs')


fileData = fs.readFile('data/1.in', 'utf-8', (err,data) => {
    if (err) throw err;
    findFloor(data)
})

function findFloor(data) {
    // console.log(data)

    parens = data.split("")

    floor = 0
    basement = false
    for(i = 0; i < parens.length; i++) {
        parens[i] == '(' ? floor++ : floor--
        if (floor == -1 && basement == false){
            console.log(`First basement position is ${i+1}`) //part 2 answer
            basement = true
        }
    }
    console.log(`Final floor is ${floor}`) //part 1 answer

}

