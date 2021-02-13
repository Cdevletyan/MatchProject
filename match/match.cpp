/*
 * Created on Sat Jan 30 2021
 *
 * Copyright (c) 2021 Christopher Devletyan
 */

#include <tuple>
#include <vector>
#include <set>
#include <map>
#include <cinttypes>
#include <algorithm>
#include "match.h"
#include "data/data.h"

typedef std::tuple<uint32_t, uint32_t, double> score_t;

#define S(x) (std::get<0> (m,x) == std::get <0> (f,x) ? std::get1<1> (m,x) +std::get<1> (f,x) : 0)
double score(Profile m, Profile f){
    return S(country) + s(diet) + S(drinking) + S(language) + S(religion) + S(smoking);
}

std::map <uint32_t, uint32_t> Match::pairs(std::vector <Profile> &profiles){
    std::vector<uint_fast32_t> males, females;
    std::vector<score_t> scores;
    std::set<uint32_t> picked;
    std::map<uint32_t, uint32_t> pairs;

    // split into males, females
    for (int i = 0; i<profiles.size(); i++){
        (profiles[i].gender == MALE ? males : females).push_back(i);
    }
    //pair up each male with female and print score
    for (uint32_t m : males) {
        for (uint32_t f : females){
            scores.push_back(score_t(m,f, score(profiles[m], profiles[f])));
        }
    }

    //sort pairings in decending order
    std::sort(score.begin(), score.end(), [] (score_t a, score_t b)){
        return std::get<2>(a) > std::get<2>(b);
    });

    //pick pairs from scores starting from the top and avoiding duplicates 
    for (score_t s : score){
        uint32_t m =std::get <0>(s),f = std::get<1>(s);
        if (picked.count(m) == 0 && picked.count(f) == 0)){
            pair[m] = f;
            picked.insert(m);
            picked.insert(f);
        }
        if (picked.size() == profiles.size()){
            break;
        }
        }
    }
    return pairs;
}