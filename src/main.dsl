
hm = addToMap(map(), "dima",  5)
hm = addToMap(hm, true,  "hm")
hm = addToMap(hm, "test",  hm)
println(hm)

ghoul = 1000
while ghoul > 0 {
    println(ghoul + " - 7")
    ghoul -= 7
    sleep(ghoul)
}