
/*
*  Input: [base != 0, power = R(R = 0, ret = 1)]
*  Returns: return a number
*/

function quickpow(base: number, power: int): number {
    let ret: number = 1.0;
    while(power > 0) {
        if((power & 1) == 1) {
            ret *= base;
        }
        base *= base;
        power >>>= 1;
    }

    return ret;
}

/*
*   Input: 0
*   Output: 57
*/

function test(x: number): number {
    return x ?? 57;
}

let x: number = test(0);

print_number_ln(x);
