/**
 * @param {string[]} words
 * @return {number}
 */
const coded = {
   "a":".-",
   "b":"-...",
   "c":"-.-.",
   "d":"-..",
   "e":".",
   "f":"..-.",
   "g":"--.",
   "h":"....",
   "i":"..",
   "j":".---",
   "k":"-.-",
   "l":".-..",
   "m":"--",
   "n":"-.",
   "o":"---",
   "p":".--.",
   "q":"--.-",
   "r":".-.",
   "s":"...",
   "t":"-",
   "u":"..-",
   "v":"...-",
   "w":".--",
   "x":"-..-",
   "y":"-.--",
   "z":"--.."
}
var transform =function(word){
    let transformed=" ";
    for(let i = 0;i<word.length;i++){
    
        transformed+=coded[word[i]];
    }
    return transformed;
}
var uniqueMorseRepresentations = function(words) {
    // console.log(coded.a)
    function onlyUnique(value, index, self) {
  return self.indexOf(value) === index;
}
    const nArray = [];
    for(let i = 0;i<words.length;i++){
        let ans = transform(words[i]);
        nArray[i] = ans;
    }
    var unique = nArray.filter(onlyUnique);
    return unique.length;
    
};