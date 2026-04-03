// For loop (classic)
for i := 0; i < n; i++ {
    // ...
}

// Range loop (like for each)
for i, v := range slice {
    // i = index, v = value
}

// While equivalent
for condition {
    // ...
}

// Vector equivalent (slice) initialized to a value
dp := make([]int, 26)        // all zeros
dp := make([]int, 26)
for i := range dp { dp[i] = 1 }  // specific value

// 2D slice
grid := make([][]int, rows)
for i := range grid {
    grid[i] = make([]int, cols)
}

// Unordered map equivalent
freq := make(map[int]int)
freq[key]++
val, exists := freq[key]  // check existence
delete(freq, key)

// Stack equivalent (just use a slice)
stack := []int{}
stack = append(stack, val)        // push
top := stack[len(stack)-1]        // peek
stack = stack[:len(stack)-1]      // pop

// String to chars
for i, c := range s {
    // c is a rune
}
// or
for i := 0; i < len(s); i++ {
    c := s[i]  // byte, use for 'a'-'z' arithmetic
}

// Sort
import "sort"
sort.Ints(slice)
sort.Slice(slice, func(i, j int) bool {
    return slice[i] < slice[j]
})

// Max/Min (no builtin before Go 1.21)
func max(a, b int) int {
    if a > b { return a }
    return b
}

// Strings
import "strings"
s := "hello"
n := len(s)
sub := s[1:3]          // "el"