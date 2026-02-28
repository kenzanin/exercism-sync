package raindrops

import "core:fmt"
import "core:strings"

convert :: proc(number: int) -> string {
    if number % 3 != 0 && number % 5 != 0 && number % 7 != 0 {
        return fmt.tprint(number)
    }

    // "PlingPlangPlong" is 15 bytes. A 16-byte buffer is plenty.
    buf: [16]u8
    n := 0
    if number % 3 == 0 { copy(buf[n:], "Pling"); n += 5 }
    if number % 5 == 0 { copy(buf[n:], "Plang"); n += 5 }
    if number % 7 == 0 { copy(buf[n:], "Plong"); n += 5 }

    // This copies the stack bytes into the temp allocator to return a safe string
    return strings.clone_from_bytes(buf[:n], context.temp_allocator)
}
