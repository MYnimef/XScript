//
// Some example of code that could be written
//

func main() {
    ghoul = 1000
    while ghoul > 0 {
        println(ghoul + " - 7")
        ghoul -= 7
        sleep(ghoul)
    }
}

func donut() {
    A = 0; B = 0; k = 0;
    //float z[1760]
    //char b[1760]

    while true {
        //memset(b, 32, 1760)
        //memset(z, 0, 7040)

        j = 0
        while j < 6.28 {
            i = 0
            while i < 6.28 {
                c = sin(i)
                d = cos(j)
                e = sin(A)
                f = sin(j)
                g = cos(A)
                h = d + 2
                D = 1 / (c * h * e + f * g + 5)
                l = cos(i)
                m = cos(B)
                n = sin(B)
                t = c * h * g - f * e

                x = int(40 + 30 * D * (l * h * m - t * n))
                y = int(12 + 15 * D * (l * h * n + t * m))
                o = int(x + 80 * y)
                N = int(8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n))

                //if 22 > y && y > 0 && x > 0 && 80 > x && D > z[o] {
                    //z[o] = D;
                    //b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                //}
                i += 0.02
            }
            j += 0.07
        }

        clc()

        k = 0
        while k < 1761 {
            if k % 80 {
                //print(b[k])
            } else {
                //print("\n")
            }

            A += 0.00004
            B += 0.00002

            k++
        }

        sleep(30000)
    }
}

func test() {
    print("hi")
    if 5 < 3 {
        print("hi")
    } else if 7 > 8 {
        print("hh")
    } else {
        print("gaga")
    }
}

func test2() {
    i = int(input())
    print( i * 2)
}

func test3(i) {
    sleep(i)
    i *= 2
}

func AA() {
    a = 4
    BB(a)
    print(a)
}

func BB(a) {
    print(a)
    a *= 2
}

main()
