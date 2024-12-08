function naiveStringSearch(str, pat){
    let flag = false
    for(let i = 0; i < str.length; i++){
        for(let j = 0; j < pat.length; j++){
            if(str[i+j] !== pat[j]) break;


            if(j == pat.length - 1) { flag = true; break;}
        }
    }
    return flag
}

naiveStringSearch("awesome", "me")

function naiveStringCount(str, pat){
    let count = 0
    for(let i = 0; i < str.length; i++){
        for(let j = 0; j < pat.length; j++){
            if(str[i+j] !== pat[j]) break;


            if(j == pat.length - 1) { count++ }
        }
    }
    return count
}

naiveStringCount("lololololollloll", "lo")