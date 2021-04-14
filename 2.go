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
		var e [3]int //edges
		for j := 0; j < 3; j++ {
			var err error
			e[j], err = strconv.Atoi(dims[j])
			check(err)
		}
		s := []int{e[0] * e[1], e[1] * e[2], e[0] * e[2]}                   //sides
		p := []int{2 * (e[0] + e[1]), 2 * (e[1] + e[2]), 2 * (e[0] + e[2])} //perimeters of each face
		volume := e[0] * e[1] * e[2]

		sort.Ints(p)
		sort.Ints(s)

		totalWrapping += 2*s[0] + 2*s[1] + 2*s[2] + s[0]
		totalRibbon += p[0] + volume

	}

	fmt.Printf("Wrapping paper needed: %d\n", totalWrapping) //Part 1 solution
	fmt.Printf("Ribbon needed: %d", totalRibbon)             //Part 2 solution
}

func main() {

	data, err := ioutil.ReadFile("data/2.in")
	check(err)
	findWrapping(string(data))
}
