package main

import (
	"fmt"
	"io/ioutil"
	"sort"
	"strconv"
	"strings"
)

func check(e error) {
	if e != nil {
		panic(e)
	}
}

func findWrapping(data string) {
	packages := strings.Split(data, "\r\n")

	totalWrapping := 0
	totalRibbon := 0
	for i := 0; i < len(packages); i++ {

		dims := strings.Split(packages[i], "x")
		var edges [3]int
		for j := 0; j < 3; j++ {
			var err error
			edges[j], err = strconv.Atoi(dims[j])
			check(err)
		}
		sides := []int{edges[0] * edges[1], edges[1] * edges[2], edges[0] * edges[2]}
		perimeters := []int{2 * (edges[0] + edges[1]), 2 * (edges[1] + edges[2]), 2 * (edges[0] + edges[2])}
		volume := edges[0] * edges[1] * edges[2]

		sort.Ints(perimeters)
		sort.Ints(sides)

		totalWrapping += 2*sides[0] + 2*sides[1] + 2*sides[2] + sides[0]
		totalRibbon += perimeters[0] + volume

	}

	fmt.Printf("Wrapping paper needed: %d\n", totalWrapping)
	fmt.Printf("Ribbon needed: %d", totalRibbon)
}

func main() {

	data, err := ioutil.ReadFile("data/2.in")
	check(err)
	findWrapping(string(data))
}
