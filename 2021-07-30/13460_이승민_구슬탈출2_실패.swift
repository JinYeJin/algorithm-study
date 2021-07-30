// 구슬탈출 2
// 시간: 1시간

import Foundation

let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let (n, m) = (input[0], input[1])
var g = Array(repeating: Array(repeating: "#", count: m), count: n)
var (b, r, h) = ([0, 0], [0, 0], [0, 0])
var visited = Array(repeating: Array(repeating: false, count: m), count: n)
let d = [[-1, 0], [1, 0], [0, -1], [0, 1]]
var (bToh, rToh) = (true, true)
var ans = 0

for i in 0..<n {
    let line = Array(readLine()!)
    for j in 0..<line.count {
        if String(line[i]) == "B" {
            b = [i, j]
            continue
        }
        if String(line[i]) == "R" {
            r = [i, j]
            continue
        }
        if String(line[i]) == "O" {
            r = [i, j]
            continue
        }
        g[i][j] = String(line[j])
    }
}

func move(i: Int, j: Int, k: Int) -> [Int] {
    var (i, j) = (i, j)
    while true {
        let (ni, nj) = (i + d[k][0], j + d[k][1])
        if g[ni][nj] == "B" || g[ni][nj] == "#" || visited[ni][nj] == true {
            break
        }
        (g[ni][nj], g[i][j]) = (g[i][j], g[ni][nj])
        visited[ni][nj] = true
        (i, j) = (ni, nj)
    }
    return [i, j]
}

func bfs() {
    var q = [[Int]]()
    q.append([r[0], r[1]])
    visited[r[0]][r[1]] = true
    
    while q.count > 0 {
        let data = q.removeFirst()
        var (i, j) = (data[0], data[1])
        if [i, j] == h {
            print(ans)
            return
        }
        for k in 0..<4 {
            if k == 0 {
                let data = move(i: i, j: j, k: 0)
                (i, j) = (data[0], data[1])
                r = [i, j]
                q.append([i, j])
            }
            if k == 1 {
                let data = move(i: i, j: j, k: 1)
                (i, j) = (data[0], data[1])
                q.append([i, j])
            }
            if k == 2 {
                let data = move(i: i, j: j, k: 2)
                (i, j) = (data[0], data[1])
                q.append([i, j])
            }
            if k == 3 {
                let data = move(i: i, j: j, k: 3)
                (i, j) = (data[0], data[1])
                q.append([i, j])
            }
        }
    }
    print(-1)
}
