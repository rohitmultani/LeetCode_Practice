/**
 * @param {string} s
 * @return {number}
 */
const code ={
    'I':1,
    'V':5,
    'X':10,
    'L':50,
    'C':100,
    'D':500,
    'M':1000
}
var romanToInt = function(s) {
    let value = 0;
    for(let i = 0;i < s.length ; i++){
        if(code[s[i]]<code[s[i+1]]){
            value-=code[s[i]];
        }
        else value+=code[s[i]];
    }
    return value;
};