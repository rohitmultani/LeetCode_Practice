/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function(s) {
    let word={};
    let char;
    for(let i = 0 ; i<s.length ; i++){
        let count = 0;
        if(s[i] in word){
   word[s[i]] = word[s[i]]+1;
        }
        else word[s[i]]=1;
    }
    for(x in word){
        if(word[x]===1){
            char = x;
            break;
        }
        
    }
    
    return s.indexOf(char);
};